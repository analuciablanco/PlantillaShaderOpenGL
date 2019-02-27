#include "stdafx.h"
#include "Shader.h"

GLuint Shader::getID()
{
	return shaderID;
}

Shader::Shader(const char * rutaVertex, const char * rutaFragment)
{
	// Vertex
	// Guardar en variables de texto los codigos de los shaders
	string codigoVertexShader;
	ifstream vertexShaderStream(rutaVertex, ios::in);

	if (vertexShaderStream.is_open())
	{
		string linea;

		while (getline(vertexShaderStream, linea))
		{
			codigoVertexShader += linea + "\n";
		}

		vertexShaderStream.close();
	}
	else cout << "No se pudo abrir el archivo " << rutaVertex << endl;

	// Fragment
	// Guardar en variables de texto los codigos de los shaders
	string codigoFragmentShader;
	ifstream fragmentShaderStream(rutaFragment, ios::in);

	if (fragmentShaderStream.is_open())
	{
		string linea;

		while (getline(fragmentShaderStream, linea))
		{
			codigoFragmentShader += linea + "\n";
		}

		fragmentShaderStream.close();
	}
	else cout << "No se pudo abrir el archivo " << rutaFragment << endl;

	// Convertir de string a cadena de char
	const char* cadenaCodigoVertex		= codigoVertexShader.c_str();
	const char* cadenaCodigoFragment	= codigoFragmentShader.c_str();

	// 1. Crear el programa de Shader
	// Un programa es la uni�n de un vertex shader y un fragment shader
	shaderID = glCreateProgram();
	GLuint vertexShaderID		= glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID		= glCreateShader(GL_FRAGMENT_SHADER);

	// 2. Cargar el c�digo del shader
	glShaderSource(vertexShaderID, 1, &cadenaCodigoVertex, NULL);
	glShaderSource(fragmentShaderID, 1, &cadenaCodigoFragment, NULL);

	// 3. Compilar los shaders
	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);	
}

// 4. Verificar errores de compilaci�n
void Shader::verificarCompilacion(GLuint ID)
{
	GLint resultado = GL_FALSE;
	int longitudLog = 0;
}