#version 330 core
//La primera l�nea siempre es la versi�n. No se debe escribir nada antes.

//Atributos de entrada (vienen desde vertex shader).
in vec4 fragmentColor;

//Atributos de salida (van hacia el buffer).
out vec4 salidaColor;

//Funci�n main.
void main()
{
	salidaColor = fragmentColor;
}