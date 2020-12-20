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
        std::vector<glm::vec3> positions =
        {
           glm::vec3(-1.5f, -1.5f, 1.5f), // 0
            glm::vec3(1.5f, -1.5f, 1.5f), // 1
            glm::vec3(1.5f,  1.5f, 1.5f), // 2
           glm::vec3(-1.5f,  1.5f, 1.5f)// 3
        };

        std::vector<unsigned int> indices =
        {
            0, 1, 2,
            2, 3, 0
        };

        unsigned int buffer = 0;
        float size = positions.size() * sizeof(glm::vec3);
        mesh.initvertexbufferObject(buffer, size, positions);

        unsigned int ib = 0;
        float indexSize = indices.size() * sizeof(unsigned int);
        mesh.initindexbufferObject(ib, indexSize, indices);

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

            if (r < 1.0f)
            {
                r += 0.01f;
            }
            else
            {
                r = 0.03f;
            }
            camera.Move();
            
             glfwGetCursorPos(window, &camera.mouseX, &camera.mouseY);
             camera.getmouseInput();
             camera.updatemouseInput(camera.mouseoffsetX, camera.mouseoffsetY);
            
            wvp = camera.projMat * camera.viewMat * camera.worldMat;

            shaders.setFloat("u_Color", r, 0.0f, 0.0f, 1.0f);
            shaders.setmatrixUniform("WVP", wvp);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            


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