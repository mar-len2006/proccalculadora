// calculadora.cpp (Versión inicial sin punteros)
#include <iostream>
#include <cmath> 
using namespace std;

double sumar(double a, double b) {
    return a + b;
}

double restar(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}

double dividir(double a, double b) {
    if (b == 0) {
        cout << "Error: Division por cero no permitida." << endl;
        return 0;
    }
    return a / b;
}

// Función para calcular la potencia (base elevada a un exponente)
double potencia(double base, double exponente) {
    return pow(base, exponente); // Utiliza la función pow de cmath
}

int main() {
    double num1, num2;
    char operacion;

    cout << "Ingrese dos números: ";
    cin >> num1 >> num2;

    cout << "Ingrese operacion (+, -, *, /): ";
    cin >> operacion;

    switch (operacion) {
        case '+':
            cout << "Resultado: " << sumar(num1, num2) << endl;
            break;
        case '-':
            cout << "Resultado: " << restar(num1, num2) << endl;
            break;
        case '*':
            cout << "Resultado: " << multiplicar(num1, num2) << endl;
            break;
        case '/':
            cout << "Resultado: " << dividir(num1, num2) << endl;
            break;
        case '^': // Nuevo caso para la potencia
            cout << "Resultado: " << potencia(num1, num2) << endl;
            break;
        default:
            cout << "Operacion no válida." << endl;
            break;
    }
    return 0;
}