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

static int createVertex(const std::string& vertexShader,
                        const std::string& fragmentShader)
{
    auto program = glCreatePorgram();
    
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    if (glewInit() != GLEW_OK)
        std::cout << "Error" << std::endl;
    
    std::cout << glGetString(GL_VERSION) << std::endl;
    
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

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
