#pragma region LIBRERÍAS
// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

// Se usan <> para librerías que ya trae el sistema.
// GLEW y GLFW dependen de estas dos librerías, por eso se ponen antes de llamar al GLEW_STATIC.
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

// Se usan "" para librerías personalizadas.
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

#include "Shader.h"
#include "Vertice.h"

using namespace std;
Shader *shader;
GLuint posicionID;
GLuint colorID;

vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;
#pragma endregion

void inicializarTriangulo()
{
	Vertice v1 =
	{
		vec3(0.0f, 0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v2 =
	{
		vec3(-0.3f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v3 =
	{
		vec3(0.3f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	triangulo.push_back(v1);
	triangulo.push_back(v2);
	triangulo.push_back(v3);
}

#pragma region FUNCIONES PARA RUTINA DE DIBUJO
void dibujar() {
	// Elegir el shader
	shader->enlazar();
	// Elegir un vertex array
	glBindVertexArray(vertexArrayTrianguloID);
	// Dibujar
	glDrawArrays(GL_TRIANGLES, 0, triangulo.size());

	// Soltar el vertex array
	glBindVertexArray(0);
	// Soltar el shader
	shader->desenlazar();
}

void actualizar() {

}
#pragma endregion

int main()
{
#pragma region CREAR UN CONTEXTO
	// Un contexto es una ventana de un sistema operativo.
	// OpenGL no gestiona el uso de ventanas.

	// Declaramos apuntador de ventana.
	GLFWwindow * window;

	// Condicionamos en caso de no poder iniciar el GLFW.
	if (!glfwInit()) 
		exit(EXIT_FAILURE);

	// Si GLFW puede iniciar entonces inicia la ventana.
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	// Si puede iniciar GLFW pero no la ventana terminamos la ejecución.
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Establecemos el contexto, donde se mandarán los pixeles generados.
	glfwMakeContextCurrent(window);

	// Una vez establecido el contexto activamos funciones modernas.
	glewExperimental = true;
	GLenum errorGlew = glewInit();

	if (errorGlew != GLEW_OK)
	{
		cout << glewGetErrorString(errorGlew);
	}
#pragma endregion

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	inicializarTriangulo();

	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos.
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader.
	shader->desenlazar();

	//Crea un vertex array.
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);

	//Crear vertex buffer.
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloID);

	//Llenar el buffer.
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)*triangulo.size(), triangulo.data(), GL_STATIC_DRAW);

	//Habilitar tributos de shader.
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se va a comunicar.
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Soltar vertex array y buffer.
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

#pragma region CICLO DE DIBUJO (DRAW LOOP)
	//El while establece que mientras la ventana esté abierta realice lo de su interior.
	while (!glfwWindowShouldClose(window)){
		// Establecemos región de dibujo.
		glViewport(0, 0, 1024, 768);
		// Establecemos color de borrado.
		glClearColor(0.5, 0, 0.5, 1);
		// Borramos.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Rutina de dibujo.
		dibujar();
		actualizar();

		// Cambiar los buffers.
		glfwSwapBuffers(window);
		// Reconocer si hay entradas.
		glfwPollEvents();
	}

	// Para destruir ventana y borrarlo/liberarlo de la memoria.
	glfwDestroyWindow(window);
	glfwTerminate();
#pragma endregion

    return 0;
}

