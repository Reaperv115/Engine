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

        // creating red sqaure
        std::vector<glm::vec3> positions;
        positions.push_back(glm::vec3(-1.5f, -1.5f, 1.5f));
        positions.push_back(glm::vec3(1.5f, -1.5f, 1.5f));
        positions.push_back(glm::vec3(1.5f, 1.5f, 1.5f));
        positions.push_back(glm::vec3(-1.5f, 1.5f, 1.5f));

        std::vector<unsigned int> indices;
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(2);
        indices.push_back(2);
        indices.push_back(3);
        indices.push_back(0);
        //

        // filling vertex and index buffers
        /*unsigned int buffer = 0;
        float size = positions.size() * sizeof(glm::vec3);
        quad.initvertexbufferObject(0, buffer, size, positions);

        unsigned int ib = 0;
        float indexSize = indices.size() * sizeof(unsigned int);
        quad.initindexbufferObject(ib, indexSize, indices);*/
        //

        // loading quad shaders from file to use
        Shaders quadshaders("../Engine/src/res/shaders/Vertex.glsl", "../Engine/src/res/shaders/Pixel.glsl");

        model.loadModel("../Engine/src/Objects/models/test2.obj", cubePositions, cubeIndices);
        unsigned int cubeBuffer = 1;
        float cubevertexSize = cubePositions.size() * sizeof(glm::vec3);
        cube.initvertexbufferObject(1, cubeBuffer, cubevertexSize, cubePositions);

        unsigned int cubeindexBuffer = 1;
        float cubeindexSize = cubeIndices.size() * sizeof(unsigned int);
        cube.initindexbufferObject(cubeindexBuffer, cubeindexSize, cubeIndices);

        Shaders cubeshaders("../Engine/src/res/shaders/CubeVertex.glsl", "../Engine/src/res/shaders/CubePixel.glsl");

        glm::mat4 wvp = camera.projMat * camera.viewMat * camera.worldMat;

        /*quadshaders.setmatrixUniform("WVP", wvp);
        quadshaders.Use();
        
        quadshaders.setFloat("u_Color", 0.4f, 0.0f, 0.0f, 1.0f);
        quadshaders.Use();*/

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

            /*quadshaders.setFloat("u_Color", r, 0.0f, 0.0f, 1.0f);
            quadshaders.setmatrixUniform("WVP", wvp);*/
            cubeshaders.setFloat("u_Color", 0.0f, 0.0f, 1.0f, 1.0f);
            cubeshaders.setmatrixUniform("WVP", wvp);
            //glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
            glDrawElements(GL_TRIANGLE_STRIP, cubeIndices.size(), GL_UNSIGNED_INT, nullptr);

            


            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
        glDeleteProgram(quadshaders.getID());
        //glDeleteProgram(cubeshaders.getID());

        glfwTerminate();
        return 1;
	}
}