workspace "Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

IncludeDir = {}
IncludeDir["GLFW"] = "Engine/Helper_Libraries/GLFW/include"
IncludeDir["Glad"] = "Engine/Helper_Libraries/Glad/include"
IncludeDir["glm"] = "Engine/Helper_Libraries/glm"

include "Engine/Helper_Libraries/GLFW"
include "Engine/Helper_Libraries/Glad"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "EGPCH.h"
	pchsource "Engine/src/EGPCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/Helper_Libraries/glm/**.hpp",
		"%{prj.name}/Helper_Libraries/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EG_PLATFORM_WINDOWS",
			"EG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
	
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/App")
		}

	filter "configurations:Debug"
		defines "EG_DEBUG"
		symbols "On"

		filter "configurations:Release"
		defines "EG_RELEASE"
		symbols "On"

		filter "configurations:Dist"
		defines "EG_Dist"
		symbols "On"

project "App"
	location "App"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		"Engine/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"EG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "EG_DEBUG"
		symbols "On"

		filter "configurations:Release"
		defines "EG_RELEASE"
		symbols "On"

		filter "configurations:Dist"
		defines "EG_Dist"
		symbols "On"
