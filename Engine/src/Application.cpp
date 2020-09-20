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
        window = glfwCreateWindow(640, 480, "Engine", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        float positions[] =
        {
           -0.5f, -0.5f, // 0
            0.5f, -0.5f, // 1
            0.5f,  0.5f, // 2
           -0.5f,  0.5f  // 3
        };

        unsigned int indices[] =
        {
            0, 1, 2,
            2, 3, 0
        };

        unsigned int buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

        unsigned int ibo;
        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

        std::string vertexShader = R"(
                #version 330 core
                layout(location = 0) in vec4 position;
                void main()
                {
                    gl_Position = position;
                }
        )";

        std::string pixelShader = R"(
                #version 330 core
                layout(location = 0) out vec4 color;
                void main()
                {
                    color = vec4(1.0, 0.0, 0.0, 1.0);
                }
        )";

        unsigned int shader = createShader(vertexShader, pixelShader);
        glUseProgram(shader);

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {

            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }

        glfwTerminate();
        return 1;
	}
}