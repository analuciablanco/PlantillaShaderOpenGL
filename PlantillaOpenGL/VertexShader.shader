#version 330 core
//La primera línea siempre es la versión. No se debe escribir nada antes.

//Atributos de entrada (vienen desde c++).
in vec3 posicion;
in vec4 color;

//Atributos de salida (van hacia el fragment shader).
out vec4 fragmentColor;

//Función main.
void main() 
{
	//Es la posición de salida del vértice.
	//gl_Position es del tipo vec4.
	gl_Position.xyz = posicion;
	gl_Position.w = 1.0;

	//Establecer valores de atributos de salida.
	fragmentColor = color;
}