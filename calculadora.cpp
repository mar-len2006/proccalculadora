// calculadora.cpp (Versión inicial sin punteros)
#include <iostream>
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
        default:
            cout << "Operacion no válida." << endl;
            break;
    }
    return 0;
}