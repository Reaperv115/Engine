#include "EGPCH.h"
#include "Application.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Engine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

    int Application::createShader(const std::string& vertexShader, const std::string& pixelShader)
    {
        unsigned int program = glCreateProgram();
        unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
        unsigned int ps = compileShader(GL_FRAGMENT_SHADER, pixelShader);

        glAttachShader(program, vs);
        glAttachShader(program, ps);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vs);
        glDeleteShader(ps);

        return program;
    }

    unsigned int Application::compileShader(unsigned int type, const std::string& source)
    {
        unsigned int id = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            int length;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*)_malloca(length * sizeof(char));
            glGetShaderInfoLog(id, length, &length, message);
            std::cout << "Failed to compile " << 
                (type == GL_VERTEX_SHADER ? "vertex" : "pixel") << "shader" <<  std::endl;
            std::cout << message << std::endl;
            glDeleteShader(id);
            return 0;
        }

        return id;
    }


	int Application::Run()
	{
		/*while (true);*/
        GLFWwindow* window;

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

        float positions[] =
        {
           -0.5f, -0.5f, // 0
            0.5f, -0.5f, // 1
            0.0f,  0.5f, // 2
        };

        unsigned int indices[] =
        {
            0, 1, 2
        };

        unsigned int buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 3 * 2 * sizeof(float), positions, GL_DYNAMIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        unsigned int ibo;
        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(unsigned int), indices, GL_DYNAMIC_DRAW);

        Shaders shaders("../Engine/src/res/shaders/Vertex.glsl", "../Engine/src/res/shaders/Pixel.glsl");

        glm::mat4 wvp = camera.projMat * camera.viewMat * camera.worldMat;

        shaders.setmatrixUniform("WVP", wvp);
        shaders.Use();
        
        shaders.setFloat("u_Color", 0.4f, 0.0f, 0.0f, 1.0f);
        shaders.Use();

        float r = 0.0f;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {


            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);
            camera.Move();
            wvp = camera.projMat * camera.viewMat * camera.worldMat;

            shaders.setFloat("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);
            shaders.setmatrixUniform("WVP", wvp);
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

            


            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
        glDeleteProgram(shaders.getID());

        glfwTerminate();
        return 1;
	}
}