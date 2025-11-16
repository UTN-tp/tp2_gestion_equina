#include "InputManager.h"
#include <iostream>
#include <limits>
#include "rlutil.h"

using namespace std;
#ifdef max
#undef max
#endif
int InputManager::leerInt(const char* mensaje) {
    int valor;
    while (true) {
        cout << mensaje;    // mesaje para aclarar el tipo de ingroso
        cin >> valor;       // intenta leer el valor ingresado

        if (!cin.fail()) {  // si no hay error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');   // limpia el buffer
            return valor;                           // retorna el valoringresado
        }

        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida. Debe ingresar un numero." << endl;  // si hay error muestra el mensaje
        rlutil::setColor(rlutil::WHITE);

        cin.clear();                                                // limpia el error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');        // limpia lo ingresado
    }
}

int InputManager::leerIntEnRango(const char* mensaje, int min, int max) {
    while (true) {
        int valor = leerInt(mensaje);
        if (valor >= min && valor <= max) return valor;

        rlutil::setColor(rlutil::RED);
        cout << "El valor debe estar entre " << min << " y " << max << endl;
        rlutil::setColor(rlutil::WHITE);
    }
}

float InputManager::leerFloat(const char* mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }

        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida. Debe ingresar un numero decimal." << endl;
        rlutil::setColor(rlutil::WHITE);

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char InputManager::leerChar(const char* mensaje) {
    char c;
    while (true) {
        cout << mensaje;
        cin >> c;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return c;
        }

        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida. Debe ingresar un solo caracter." << endl;
        rlutil::setColor(rlutil::WHITE);

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char InputManager::leerCharOpciones(const char* mensaje, const char* opciones) {
    while (true) {
        char c = leerChar(mensaje);

        for (int i = 0; opciones[i] != '\0'; i++) {
            if (c == opciones[i]) return c;
        }

        rlutil::setColor(rlutil::RED);
        cout << "Caracter invalido. Opciones validas: " << opciones << endl;
        rlutil::setColor(rlutil::WHITE);
    }
}

string InputManager::leerString(const char* mensaje) {
    string s;

    while (true) {
        cout << mensaje;
        cin >> s;

        if (!cin.fail())
            return s;

        rlutil::setColor(rlutil::RED);
        cout << "Entrada invalida." << endl;
        rlutil::setColor(rlutil::WHITE);

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string InputManager::leerLinea(const char* mensaje) {
    string s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << mensaje;
    getline(cin, s);

    while (s.size() == 0) {
        cout << mensaje;
        getline(cin, s);
    }

    return s;
}

bool InputManager::confirmar(const char* mensaje) {
    char c = leerCharOpciones(mensaje, "sSnN");
    return (c == 's' || c == 'S');
}




// agreue para estado general

int InputManager::seleccionarOpcion(const char* mensaje, const char* opciones[], int numOpciones) {
    while (true) {
        cout << "\n--- OPCIONES ---\n";
        for (int i = 0; i < numOpciones; ++i) {
            // Muestra las opciones como 1. Opcion1, 2. Opcion2, etc.
            std::cout << (i + 1) << ". " << opciones[i] << "\n";
        }
         cout << "----------------\n";

        // Llama a la función  leerIntEnRango
        int opcion = leerIntEnRango(mensaje, 1, numOpciones);
        return opcion;
    }
}






