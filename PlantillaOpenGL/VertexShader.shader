#version 330 core
//La primera l�nea siempre es la versi�n. No se debe escribir nada antes.

//Atributos de entrada (vienen desde c++).
in vec3 posicion;
in vec4 color;

//Atributos de salida (van hacia el fragment shader).
out vec4 fragmentColor;

//Funci�n main.
void main() 
{
	//Es la posici�n de salida del v�rtice.
	//gl_Position es del tipo vec4.
	gl_Position.xyz = posicion;
	gl_Position.w = 1.0;

	//Establecer valores de atributos de salida.
	fragmentColor = color;
}