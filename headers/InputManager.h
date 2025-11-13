#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <string>

class InputManager {
public:
    static int leerInt(const char* mensaje);
    static int leerIntEnRango(const char* mensaje, int min, int max);

    static float leerFloat(const char* mensaje);

    static char leerChar(const char* mensaje);
    static char leerCharOpciones(const char* mensaje, const char* opciones);

    static std::string leerString(const char* mensaje);
    static std::string leerLinea(const char* mensaje);
    static int seleccionarOpcion(const char* mensaje, const char* opciones[], int numOpciones); // agregue para estado
    static bool confirmar(const char* mensaje);  // S/N
};
#endif