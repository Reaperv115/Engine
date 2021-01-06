#include "PCH/EGPCH.h"
#include "Application.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace Engine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}


	int Application::Run()
	{
        GLFWwindow* window = nullptr;

        /* Initialize the library */
        if (!glfwInit())
            return -1;

        

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(900, 600, "Engine", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        MeshStructure cube;

        model.loadModel("../Engine/src/Objects/models/test2.obj", cube);
        unsigned int cubeBuffer = 1;
        float cubevertexSize = cube.positions.size() * sizeof(glm::vec3);
        cubeMesh.initvertexbufferObject(1, cubeBuffer, cubevertexSize, cube.positions);

        unsigned int cubeindexBuffer = 1;
        float cubeindexSize = cube.indices.size() * sizeof(unsigned int);
        cubeMesh.initindexbufferObject(cubeindexBuffer, cubeindexSize, cube.indices);

        Shaders cubeshaders("../Engine/src/res/shaders/CubeVertex.glsl", "../Engine/src/res/shaders/CubePixel.glsl");

        glm::mat4 wvp = camera.projMat * camera.viewMat * camera.worldMat;

        cubeshaders.setmatrixUniform("WVP", wvp);
        cubeshaders.Use();

        cubeshaders.setFloat("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);
        cubeshaders.Use();

        float r = 0.0f;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);
            camera.Move();
            
             glfwGetCursorPos(window, &camera.mouseX, &camera.mouseY);
             camera.getmouseInput();
             camera.updatemouseInput(camera.mouseoffsetX, camera.mouseoffsetY);
            
            wvp = camera.projMat * camera.viewMat * camera.worldMat;
            cubeshaders.setFloat("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);
            cubeshaders.setmatrixUniform("WVP", wvp);
            glDrawElements(GL_TRIANGLE_STRIP, cube.indices.size(), GL_UNSIGNED_INT, nullptr);

            


            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
        glDeleteProgram(cubeshaders.getID());

        glfwTerminate();
        return 1;
	}
}