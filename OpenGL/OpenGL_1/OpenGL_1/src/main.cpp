//
//  main.cpp
//  OpenGL_1
//
//  Created by mrcrambo on 03/05/2020.
//  Copyright © 2020 mrcrambo. All rights reserved.
//

#define GL_SILENCE_DEPRECATION
#define GLEW_STATIC

#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>

struct ShaderSource
{
    std::string vertex;
    std::string fragment;
};

static ShaderSource parseShader(const std::string& path)
{
    std::ifstream stream(path);
    
    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    
    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else
            ss[(int) type] << line << "\n";
    }
    
    return {ss[0].str(), ss[1].str()};
}

static unsigned int compileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (!result)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << message <<std::endl;
        glDeleteShader(id);
        return 0;
    }
    
    return id;
}

static unsigned int createShader(const std::string& vertexShader,
                                 const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
    
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);
    
    glDeleteShader(vs);
    glDeleteShader(fs);
    
    return program;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;
    
    float positions[] = {
        -0.5f, -0.5f, // 1st coord
         0.5f, -0.5f, // 2nd coord
         0.5f,  0.5f, // 3rd coord
        -0.5f,  0.5f,
    };
    
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * 2 * sizeof(float), positions, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0); // index of attrib - in our case only one attrib
    glVertexAttribPointer(0, // attribute id - in our case there is only one attrib
                          2, // dimensions - in our case 2D
                          GL_FLOAT, // type of values
                          GL_FALSE, // normalized false for float
                          sizeof(float) * 2, // stride to the next vertex - between 1st and 2nd coord i.e.
                          0 // pointer
                          );
    
    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    ShaderSource source = parseShader("basic.shader");
    
    unsigned int shader = createShader(source.vertex, source.fragment);
    glUseProgram(shader);
    
    int location = __glewGetUniformLocation(shader, "u_color");
    __glewUniform4f(location, 0.8f, 0.1f, 0.1f, 1.f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr); // with index buffers , do not forget about UNSIGNED

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glDeleteProgram(shader);
    
    glfwTerminate();
    return 0;
}
