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
	// Un programa es la unión de un vertex shader y un fragment shader
	shaderID = glCreateProgram();
	GLuint vertexShaderID		= glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID		= glCreateShader(GL_FRAGMENT_SHADER);

	// 2. Cargar el código del shader
	glShaderSource(vertexShaderID, 1, &cadenaCodigoVertex, NULL);
	glShaderSource(fragmentShaderID, 1, &cadenaCodigoFragment, NULL);

	// 3. Compilar los shaders
	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	// 4. Verificar errores de compilación
	verificarCompilacion(vertexShaderID);
	verificarCompilacion(fragmentShaderID);

	// 5. Adjuntar shaders al programa
	glAttachShader(shaderID, vertexShaderID);
	glAttachShader(shaderID, fragmentShaderID);

	// 6. Vincular el programa
	glLinkProgram(shaderID);

	// 7. Verificar la vinculación
	verificarVinclulacion(shaderID);

	// 8. Usar el programa
	glUseProgram(shaderID);
}

void Shader::verificarCompilacion(GLuint ID)
{
	GLint resultado = GL_FALSE;
	GLint longitudLog = 0;

	glGetShaderiv(ID, GL_COMPILE_STATUS, &resultado);
	glGetShaderiv(ID, GL_INFO_LOG_LENGTH, &longitudLog);

	if (longitudLog > 0)
	{
		vector<char> mensajeError(longitudLog);

		glGetShaderInfoLog(ID, longitudLog, NULL, &mensajeError[0]);

		for (vector<char>::const_iterator i = mensajeError.begin(); i != mensajeError.end(); i++)
		{
			cout << *i;
		}
	}
}

void Shader::verificarVinclulacion(GLuint ID)
{
	GLint estadoVinculacion, estadoValidacion;

	glGetProgramiv(ID, GL_LINK_STATUS, &estadoVinculacion);
	
	if (estadoVinculacion == GL_FALSE)
	{
		cout << "No se pudo vincular el programa" << endl;
	}

	glGetProgramiv(ID, GL_VALIDATE_STATUS, &estadoValidacion);

	if (estadoVinculacion == GL_FALSE)
	{
		cout << "No se pudo validar la vinculación" << endl;
	}
}

void Shader::enlazar() {

	glUseProgram(shaderID);

}

void Shader::desenlazar() {

	glUseProgram(0);

}
