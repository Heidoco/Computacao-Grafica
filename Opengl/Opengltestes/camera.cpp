#include"camera.h"



Camera::Camera(int largura, int altura, glm::vec3 vetorPosicao)
{
	Camera::largura = largura;
	Camera::altura = altura;
	vetorPosicao = vetorPosicao;
}

void Camera::Matriz(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	// Camera olha pra frente
	view = glm::lookAt(vetorPosicao, vetorPosicao + orientacao, cima);

	//perspectiva
	projection = glm::perspective(glm::radians(FOVdeg), (float)largura / altura, nearPlane, farPlane);

	// Exports the camera matrix to the Vertex Shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}



void Camera::Inputs(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		vetorPosicao += velocidade * orientacao;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		vetorPosicao += velocidade * -glm::normalize(glm::cross(orientacao, cima));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		vetorPosicao += velocidade * -orientacao;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		vetorPosicao += velocidade * glm::normalize(glm::cross(orientacao, cima));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		vetorPosicao += velocidade * cima;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		vetorPosicao += velocidade * -cima;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		velocidade = 0.4f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		velocidade = 0.1f;
	}


	// mouse
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		// Hides mouse cursor
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Prevents camera from jumping on the first click
		if (firstClick)
		{
			glfwSetCursorPos(window, (largura / 2), (altura / 2));
			firstClick = false;
		}

		// Stores the coordinates of the cursor
		double mouseX;
		double mouseY;
		// Fetches the coordinates of the cursor
		glfwGetCursorPos(window, &mouseX, &mouseY);

		// Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
		// and then "transforms" them into degrees 
		float rotX = sensibilidade * (float)(mouseY - (altura / 2)) / altura;
		float rotY = sensibilidade * (float)(mouseX - (largura / 2)) / largura;

		// Calculates cimacoming vertical change in the orientacao
		glm::vec3 neworientacao = glm::rotate(orientacao, glm::radians(-rotX), glm::normalize(glm::cross(orientacao, cima)));

		// Decides whether or not the next vertical orientacao is legal or not
		if (abs(glm::angle(neworientacao, cima) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			orientacao = neworientacao;
		}

		// Rotates the orientacao left and right
		orientacao = glm::rotate(orientacao, glm::radians(-rotY), cima);

		// Sets mouse cursor to the middle of the screen so that it doesn't end cima roaming around
		glfwSetCursorPos(window, (largura / 2), (altura / 2));
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		// Unhides cursor since camera is not looking around anymore
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		// Makes sure the next time the camera looks around it doesn't jump
		firstClick = true;
	}
}