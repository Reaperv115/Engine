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
        float size = 3 * 2 * sizeof(float);
        vao.createvertexBuffer(1, buffer, size, *positions);
        vao.enablevertexArray(0, 2, sizeof(float) * 2, 0);
        /*glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 3 * 2 * sizeof(float), positions, GL_DYNAMIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);*/

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