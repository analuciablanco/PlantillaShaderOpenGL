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
#pragma endregion

using namespace std;
Shader *shader;
GLuint posicionID;
GLuint colorID;

vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

vector<Vertice> chichenItza;
GLuint vertexArrayPiramideID;
GLuint bufferPiramide;

vector<Vertice> escaleras;
GLuint vertexArrayEscalerasID;
GLuint bufferEscaleras;

vector<Vertice> entrada;
GLuint vertexArrayEntradaID;
GLuint bufferEntrada;

vector<Vertice> suelo;
GLuint vertexArraySueloID;
GLuint bufferSuelo;

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

void inicializarCuadrado()
{
	Vertice v1 =
	{
		vec3(-0.8f, 0.8f, 0.0f),
		vec4(0.4f, 0.7f, 0.1f, 1.0f)
	};

	Vertice v2 =
	{
		vec3(-0.4f, 0.8f, 0.0f),
		vec4(0.4f, 0.7f, 0.1f, 1.0f)
	};

	Vertice v3 =
	{
		vec3(-0.4f, 0.5f, 0.0f),
		vec4(0.4f, 0.7f, 0.1f, 1.0f)
	};

	Vertice v4 =
	{
		vec3(-0.8f, 0.5f, 0.0f),
		vec4(0.4f, 0.7f, 0.1f, 1.0f)
	};

	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void piramideChichenItza() 
{
	// Entrada
	Vertice vEntrada1 =
	{
		vec3(-0.05f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEntrada2 =
	{
		vec3(0.05f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEntrada3 =
	{
		vec3(0.05f, 0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEntrada4 =
	{
		vec3(-0.05f, 0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	entrada.push_back(vEntrada1);
	entrada.push_back(vEntrada2);
	entrada.push_back(vEntrada3);
	entrada.push_back(vEntrada4);

	// Escaleras
	Vertice vEscalera1 =
	{
		vec3(-0.1f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera2 =
	{
		vec3(-0.1f, -0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera3 =
	{
		vec3(0.1f, -0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	//
	Vertice vEscalera4 =
	{
		vec3(-0.1f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera5 =
	{
		vec3(-0.1f, 0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera6 =
	{
		vec3(0.1f, 0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera7 =
	{
		vec3(0.1f, 0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera8 =
	{
		vec3(-0.1f, 0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera9 =
	{
		vec3(-0.1f, 0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera10 =
	{
		vec3(0.1f, 0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera11 =
	{
		vec3(0.1f, 0.0f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera12 =
	{
		vec3(-0.1f, 0.0f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera13 =
	{
		vec3(-0.1f, -0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera14 =
	{
		vec3(0.1f, -0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera15 =
	{
		vec3(0.1f, -0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera16 =
	{
		vec3(-0.1f, -0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera17 =
	{
		vec3(-0.1f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera18 =
	{
		vec3(0.1f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera19 =
	{
		vec3(0.1f, -0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera20 =
	{
		vec3(-0.1f, -0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera21 =
	{
		vec3(-0.1f, -0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera22 =
	{
		vec3(0.1f, -0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice vEscalera23 =
	{
		vec3(0.1f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	escaleras.push_back(vEscalera1);
	escaleras.push_back(vEscalera2);
	//escaleras.push_back(vEscalera3);
	//escaleras.push_back(vEscalera4);
	escaleras.push_back(vEscalera5);
	escaleras.push_back(vEscalera6);
	escaleras.push_back(vEscalera7);
	escaleras.push_back(vEscalera8);
	escaleras.push_back(vEscalera9);
	escaleras.push_back(vEscalera10);

	escaleras.push_back(vEscalera11);
	escaleras.push_back(vEscalera12);
	escaleras.push_back(vEscalera13);
	escaleras.push_back(vEscalera14);
	escaleras.push_back(vEscalera15);
	escaleras.push_back(vEscalera16);
	escaleras.push_back(vEscalera17);
	escaleras.push_back(vEscalera18);
	escaleras.push_back(vEscalera19);
	escaleras.push_back(vEscalera20);

	escaleras.push_back(vEscalera21);
	escaleras.push_back(vEscalera22);
	escaleras.push_back(vEscalera23);
	//escaleras.push_back(vEscalera24);

	// Lado izquierdo
	Vertice v1 =
	{
		vec3(0.0f, -0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v2 =
	{
		vec3(-1.0f, -0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v3 =
	{
		vec3(-1.0f, -0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v4 =
	{
		vec3(-0.9f, -0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v5 =
	{
		vec3(-0.9f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v6 =
	{
		vec3(-0.8f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v7 =
	{
		vec3(-0.8f, -0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v8 =
	{
		vec3(-0.7f, -0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v9 =
	{
		vec3(-0.7f, -0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v10 =
	{
		vec3(-0.6f, -0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v11 =
	{
		vec3(-0.6f, 0.0f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v12 =
	{
		vec3(-0.5f, 0.0f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v13 =
	{
		vec3(-0.5f, 0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v14 =
	{
		vec3(-0.4f, 0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v15 =
	{
		vec3(-0.4f, 0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v16 =
	{
		vec3(-0.3f, 0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v17 =
	{
		vec3(-0.3f, 0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v18 =
	{
		vec3(-0.2f, 0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v19 =
	{
		vec3(-0.2f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	// Parte de arriba
	Vertice v20 =
	{
		vec3(-0.15f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v21 =
	{
		vec3(-0.15f, 0.6f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice punto_der =
	{
		vec3(0.0f, 0.6f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice punto_izq =
	{
		vec3(0.0f, 0.6f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v22 =
	{
		vec3(0.15f, 0.6f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v23 =
	{
		vec3(0.15f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	// Lado derecho
	Vertice v24 =
	{
		vec3(0.2f, 0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v25 =
	{
		vec3(0.2f, 0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v26 =
	{
		vec3(0.3f, 0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v27 =
	{
		vec3(0.3f, 0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v28 =
	{
		vec3(0.4f, 0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v29 =
	{
		vec3(0.4f, 0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v30 =
	{
		vec3(0.5f, 0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v31 =
	{
		vec3(0.5f, 0.0f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v32 =
	{
		vec3(0.6f, 0.0f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v33 =
	{
		vec3(0.6f, -0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v34 =
	{
		vec3(0.7f, -0.1f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v35 =
	{
		vec3(0.7f, -0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v36 =
	{
		vec3(0.8f, -0.2f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v37 =
	{
		vec3(0.8f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v38 =
	{
		vec3(0.9f, -0.3f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v39 =
	{
		vec3(0.9f, -0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v40 =
	{
		vec3(1.0f, -0.4f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v41 =
	{
		vec3(1.0f, -0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	Vertice v42 =
	{
		vec3(0.0f, -0.5f, 0.0f),
		vec4(1.0f, 0.8f, 0.0f, 1.0f)
	};

	chichenItza.push_back(v1);
	chichenItza.push_back(v2);
	chichenItza.push_back(v3);
	chichenItza.push_back(v4);
	chichenItza.push_back(v5);
	chichenItza.push_back(v6);
	chichenItza.push_back(v7);
	chichenItza.push_back(v8);
	chichenItza.push_back(v9);
	chichenItza.push_back(v10);

	chichenItza.push_back(v11);
	chichenItza.push_back(v12);
	chichenItza.push_back(v13);
	chichenItza.push_back(v14);
	chichenItza.push_back(v15);
	chichenItza.push_back(v16);
	chichenItza.push_back(v17);
	chichenItza.push_back(v18);
	chichenItza.push_back(v19);
	chichenItza.push_back(v20);

	chichenItza.push_back(v21);

	chichenItza.push_back(punto_izq);
	chichenItza.push_back(punto_der);

	chichenItza.push_back(v22);
	chichenItza.push_back(v23);
	chichenItza.push_back(v24);
	chichenItza.push_back(v25);
	chichenItza.push_back(v26);
	chichenItza.push_back(v27);
	chichenItza.push_back(v28);
	chichenItza.push_back(v29);
	chichenItza.push_back(v30);

	chichenItza.push_back(v31);
	chichenItza.push_back(v32);
	chichenItza.push_back(v33);
	chichenItza.push_back(v34);
	chichenItza.push_back(v35);
	chichenItza.push_back(v36);
	chichenItza.push_back(v37);
	chichenItza.push_back(v38);
	chichenItza.push_back(v39);
	chichenItza.push_back(v40);

	chichenItza.push_back(v41);
	chichenItza.push_back(v42);
}

void inicializarSuelo()
{
	Vertice vSuelo1 =
	{
		vec3(-1.0f, -0.5f, 0.0f),
		vec4(0.0f, 0.8f, 0.5f, 1.0f)
	};

	Vertice vSuelo2 =
	{
		vec3(-1.0f, -1.0f, 0.0f),
		vec4(0.0f, 0.8f, 0.5f, 1.0f)
	};

	Vertice vSuelo3 =
	{
		vec3(1.0f, -1.0f, 0.0f),
		vec4(0.0f, 0.8f, 0.5f, 1.0f)
	};

	Vertice vSuelo4 =
	{
		vec3(1.0f, -0.5f, 0.0f),
		vec4(0.0f, 0.8f, 0.5f, 1.0f)
	};

	suelo.push_back(vSuelo1);
	suelo.push_back(vSuelo2);
	suelo.push_back(vSuelo3);
	suelo.push_back(vSuelo4);
}

#pragma region FUNCIONES PARA RUTINA DE DIBUJO
void dibujar() {
	// Elegir el shader
	shader->enlazar();

	#pragma region Triangulo
		// Elegir un vertex array
		glBindVertexArray(vertexArrayTrianguloID);
		// Dibujar
		glDrawArrays(GL_TRIANGLES, 0, triangulo.size());
	#pragma endregion

	#pragma region Cuadrado
		glBindVertexArray(vertexArrayCuadradoID);
		glDrawArrays(GL_POLYGON, 0, cuadrado.size());
	#pragma endregion

	#pragma region Chichen Itza
		glBindVertexArray(vertexArrayPiramideID);
		glDrawArrays(GL_LINE_LOOP, 0, chichenItza.size());

		glBindVertexArray(vertexArrayPiramideID);
		glDrawArrays(GL_LINE_LOOP, 0, chichenItza.size());

		glBindVertexArray(vertexArrayEscalerasID);
		glDrawArrays(GL_LINE_LOOP, 0, escaleras.size());

		glBindVertexArray(vertexArrayEntradaID);
		glDrawArrays(GL_LINE_LOOP, 0, entrada.size());

		glBindVertexArray(vertexArraySueloID);
		glDrawArrays(GL_POLYGON, 0, suelo.size());
	#pragma endregion

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

#pragma region SHADERS
	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//inicializarTriangulo();
	//inicializarCuadrado();
	piramideChichenItza();
	inicializarSuelo();

	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos.
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader.
	shader->desenlazar();

	#pragma region TRIANGULO
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
	#pragma endregion

	#pragma region CUADRADO
		glGenVertexArrays(1, &vertexArrayCuadradoID);
		glBindVertexArray(vertexArrayCuadradoID);

		glGenBuffers(1, &bufferCuadradoID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)*cuadrado.size(), cuadrado.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(posicionID);
		glEnableVertexAttribArray(colorID);

		glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
		glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	#pragma endregion

#pragma region CHICHEN ITZA
		// Pirámide
		glGenVertexArrays(1, &vertexArrayPiramideID);
		glBindVertexArray(vertexArrayPiramideID);

		glGenBuffers(1, &bufferPiramide);
		glBindBuffer(GL_ARRAY_BUFFER, bufferPiramide);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)*chichenItza.size(), chichenItza.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(posicionID);
		glEnableVertexAttribArray(colorID);

		glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
		glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

		// Escaleras
		glGenVertexArrays(1, &vertexArrayEscalerasID);
		glBindVertexArray(vertexArrayEscalerasID);

		glGenBuffers(1, &bufferEscaleras);
		glBindBuffer(GL_ARRAY_BUFFER, bufferEscaleras);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)*escaleras.size(), escaleras.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(posicionID);
		glEnableVertexAttribArray(colorID);

		glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
		glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

		// Entrada
		glGenVertexArrays(1, &vertexArrayEntradaID);
		glBindVertexArray(vertexArrayEntradaID);

		glGenBuffers(1, &bufferEntrada);
		glBindBuffer(GL_ARRAY_BUFFER, bufferEntrada);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)*entrada.size(), entrada.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(posicionID);
		glEnableVertexAttribArray(colorID);

		glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
		glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

		// Suelo
		glGenVertexArrays(1, &vertexArraySueloID);
		glBindVertexArray(vertexArraySueloID);

		glGenBuffers(1, &bufferSuelo);
		glBindBuffer(GL_ARRAY_BUFFER, bufferSuelo);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)*suelo.size(), suelo.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(posicionID);
		glEnableVertexAttribArray(colorID);

		glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
		glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
#pragma endregion

	//Soltar vertex array y buffer.
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#pragma endregion

#pragma region CICLO DE DIBUJO (DRAW LOOP)
	//El while establece que mientras la ventana esté abierta realice lo de su interior.
	while (!glfwWindowShouldClose(window)){
		// Establecemos región de dibujo.
		glViewport(0, 0, 1024, 768);
		// Establecemos color de borrado.
		glClearColor(0, 0.5, 0.8, 1);
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

