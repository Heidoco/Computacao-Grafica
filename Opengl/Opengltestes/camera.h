#pragma once

#include<iostream>
#include "glad/glad.h"
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include "shaderClass.h"

class Camera
{
private:
    /* data */
public:
    Camera(int largura, int altura, glm::vec3 vetorPosicao);
    glm::vec3 vetorPosicao;
    glm::vec3 orientacao = glm::vec3(0.0f,0.0f,-1.0f);
    glm::vec3 cima = glm::vec3(0.0f,1.0f,0.0f);

    int largura, altura;

    bool firstClick = true;

    float velocidade = 1.0f, sensibilidade = 100.f;

    void Matriz(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);

	// Handles camera inputs
	void Inputs(GLFWwindow* window);
};

