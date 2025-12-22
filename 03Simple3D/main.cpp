#include <GLES3/gl3.h>
#include <EGL/egl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <cmath>

#include <GLFW/glfw3.h>
#include <stdio.h>

const char* vertexShaderSource = R"(
    #version 100
    uniform mat4 projection;
    uniform mat4 view;
    uniform mat4 model;
    
    attribute vec3 position;
    attribute vec3 color;
    
    varying vec3 fragColor;
    
    void main() {
        gl_Position = projection * view * model * vec4(position, 1.0);
        fragColor = color;
    }
)";

const char* fragmentShaderSource = R"(
    #version 100
    precision mediump float;
    varying vec3 fragColor;
    
    void main() {
        gl_FragColor = vec4(fragColor, 1.0);
    }
)";

GLuint compileShader(const char* source, GLenum type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader compilation failed: " << infoLog << std::endl;
    }
    return shader;
}

int main(void)
{
    // Step 1: initialize GLFW
    if (!glfwInit()) {
        printf("GLFW init failed\n");
        return 1;
    }

    // Step 2: create a window
    GLFWwindow* window =
        glfwCreateWindow(800, 600, "GLFW Window", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return 1;
    }

    // Step 3: make the context current
    glfwMakeContextCurrent(window);


    // Step 3.5: init GL
    // Cube vertices and colors
    float vertices[] = {
        -1, -1,  1,  1,  0,  0,
         1, -1,  1,  0,  1,  0,
         1,  1,  1,  0,  0,  1,
        -1,  1,  1,  1,  1,  0,
        -1, -1, -1,  1,  0,  1,
         1, -1, -1,  0,  1,  1,
         1,  1, -1,  1,  1,  1,
        -1,  1, -1,  0,  0,  0,
    };

    unsigned int indices[] = {
        0, 1, 2, 2, 3, 0,
        4, 6, 5, 4, 7, 6,
        4, 0, 3, 3, 7, 4,
        1, 5, 6, 6, 2, 1,
        3, 2, 6, 6, 7, 3,
        4, 5, 1, 1, 0, 4,
    };

    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    GLuint vertexShader = compileShader(vertexShaderSource, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glUseProgram(program);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    // Step 3.75: Set hints
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Step 4: event loop

    float angle = 0.0f;
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f));
        glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(1.0f, 1.0f, 0.0f));

        glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(program, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(program, "model"), 1, GL_FALSE, glm::value_ptr(model));

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, (void*)0);
        angle += 1.0f;


        glfwSwapBuffers(window);
    }

    // Step 5: cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}