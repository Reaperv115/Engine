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

        std::vector<Vertex> cube;

        model.loadModel("../Engine/src/Objects/models/test2.obj", cube);

        cubeMesh.push_back(new Mesh(cube, cube.size(), model.modelIndices, model.modelIndices.size()));

        Shaders cubeshaders("../Engine/src/res/shaders/CubeVertex.glsl", "../Engine/src/res/shaders/CubePixel.glsl");

        glm::mat4 wvp = camera.projMat * camera.viewMat * camera.worldMat;

        cubeshaders.setmatrixUniform("WVP", wvp);
        cubeshaders.Use();

        

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

            //checking for camera movement
            camera.Move();
            
            // getting mouse position and adjusting camera
            glfwGetCursorPos(window, &camera.mouseX, &camera.mouseY);
            camera.getmouseInput();
            camera.updatemouseInput(camera.mouseoffsetX, camera.mouseoffsetY);

            glFrontFace(GL_CCW);
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);
            glDisable(GL_CULL_FACE);
            glEnable(GL_CULL_FACE);
            
            // updating world, view, and projection matrices
            wvp = camera.projMat * camera.viewMat * camera.worldMat;
            cubeshaders.setmatrixUniform("WVP", wvp);

            cubeshaders.setFloat("u_Color", 0.0f, 1.0f, 0.0f, 0.0f);

            // drawing
            for (int i = 0; i < cubeMesh.size(); ++i)
                glDrawElements(GL_TRIANGLE_STRIP, cubeMesh[i]->numofIndices, GL_UNSIGNED_INT, nullptr);
                


            


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