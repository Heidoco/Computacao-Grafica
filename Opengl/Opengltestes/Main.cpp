//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------

#include<iostream>
#include "glad/glad.h"
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"camera.h"

const int largura = 800, altura= 800;

// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	      0.0f, 0.0f,
	0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,   	5.0f, 0.0f,
	0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,  	2.5f, 5.0f
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};



int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Cria janela
	GLFWwindow* window = glfwCreateWindow(largura, altura, "Window(s)", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);


	gladLoadGL();

	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);



	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");



	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));

	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");




	Texture junior("junior.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	junior.texUnit(shaderProgram, "tex0", 0);



	float rotacao = 0.0f;
	double anterior = glfwGetTime();

	glEnable(GL_DEPTH_TEST);

	


	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.00f, 0.0f, 0.0f, 1.0f);

		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shaderProgram.Activate();

		double atual = glfwGetTime();
		if (atual -anterior >= 1/60){
			rotacao += 0.5f;
			anterior = atual;
		}

		glm::mat4 modelo = glm::mat4(1.0f);
		glm::mat4 visao = glm::mat4(1.0f);
		glm::mat4 projecao = glm::mat4(1.0f);

		modelo = glm::rotate(modelo,glm::radians(rotacao), glm::vec3(1.0f,1.0f,1.0f));
		visao = glm::translate(visao,glm::vec3(0.0f,-0.5f, -2.0f));
		projecao = glm::perspective(glm::radians(45.0f), (float)(1), 0.1f, 100.0f);

		int modeloLoc = glGetUniformLocation(shaderProgram.ID,"modelo");
		glUniformMatrix4fv(modeloLoc, 1, GL_FALSE, glm::value_ptr(modelo));
		int visaoLoc = glGetUniformLocation(shaderProgram.ID,"visao");
		glUniformMatrix4fv(visaoLoc, 1, GL_FALSE, glm::value_ptr(modelo));
		int projecaoLoc = glGetUniformLocation(shaderProgram.ID,"projecao");
		glUniformMatrix4fv(projecaoLoc, 1, GL_FALSE, glm::value_ptr(modelo));

		glUniform1f(uniID, 0.5f);
		// Binds texture so that is appears in rendering
		junior.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	junior.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}