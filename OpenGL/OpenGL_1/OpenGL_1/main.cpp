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
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>

using namespace std;

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
    
    float positions[6] = {
        -0.5f, -0.5f, // 1st coord
         0.0f,  0.5f, // 2nd coord
         0.5f, -0.5f, // 3rd coord
    };
    unsigned int buffer;
    
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0); // index of attrib - in our case only one attrib
    glVertexAttribPointer(0, // attribute id - in our case there is only one attrib
                          2, // dimensions - in our case 2D
                          GL_FLOAT, // type of values
                          GL_FALSE, // normalized false for float
                          sizeof(float) * 2, // stride to the next vertex - between 1st and 2nd coord i.e.
                          0 // pointer
                          );
    
    cout << "GLFW version                : " << glfwGetVersionString() << endl;
    cout << "GLEW_VERSION                : " << glewGetString( GLEW_VERSION ) << endl;
    cout << "GL_VERSION                  : " << glGetString( GL_VERSION ) << endl;
    cout << "GL_VENDOR                   : " << glGetString( GL_VENDOR ) << endl;
    cout << "GL_RENDERER                 : " << glGetString( GL_RENDERER ) << endl;
    cout << "GL_SHADING_LANGUAGE_VERSION : " << glGetString( GL_SHADING_LANGUAGE_VERSION ) << endl;
    
    
    std::string vertexShader =
        "#version 120\n"
        "\n"
        "attribute vec4 position;"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";
    
    std::string fragmentShader =
        "#version 120\n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_FragColor = vec4(1.0, 0.0, 0.5, 0.5);\n"
        "}\n";
    
    unsigned int shader = createShader(vertexShader, fragmentShader);
        
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glDeleteProgram(shader);
    
    glfwTerminate();
    return 0;
}
