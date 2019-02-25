#version 330 core
//La primera línea siempre es la versión. No se debe escribir nada antes.

//Atributos de entrada (vienen desde vertex shader).
in vec4 fragmentColor;

//Atributos de salida (van hacia el buffer).
out vec4 salidaColor;

//Función main.
void main()
{
	salidaColor = fragmentColor;
}