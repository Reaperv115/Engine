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

        // creating and loading cube model
        std::vector<Vertex> cube;
        model.loadModel("../Engine/src/objects/models/test.obj", cube);
        cubeMesh.push_back(new Mesh(cube, cube.size(), model.modelIndices, model.modelIndices.size()));

        // loading and creating shaders
        Shaders cubeshaders("../Engine/src/res/shaders/CubeVertex.glsl", "../Engine/src/res/shaders/CubePixel.glsl");

        // creating the matrix used in the vertex shader
        glm::mat4 wvp = camera.projMat * camera.viewMat * camera.worldMat;

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
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            
            // updating world, view, and projection matrices
            wvp = camera.projMat * camera.viewMat * camera.worldMat;

            // updating constant buffers
            cubeshaders.setmatrixUniform("WVP", wvp);
            cubeshaders.Use();
            /*cubeshaders.setFloat("u_Color", 0.0f, 1.0f, 0.0f, 1.0f);
            cubeshaders.Use();*/

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