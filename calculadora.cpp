// calculadora.cpp (Versión mejorada con función de raíz cuadrada)
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
        cout << "Error: División por cero no permitida." << endl;
        return 0;
    }
    return a / b;
}

double raizCuadrada(double a) {
    if (a < 0) {
        cout << "Error: Raíz cuadrada de número negativo no permitida." << endl;
        return 0;
    }
    return sqrt(a);
}

int main() {
    double num1, num2;
    char operacion;

    cout << "Ingrese operación (+, -, *, /, r): ";
    cin >> operacion;

    if (operacion == 'r') {
        cout << "Ingrese un número: ";
        cin >> num1;
        cout << "Resultado: " << raizCuadrada(num1) << endl;
    } else if (operacion == '+' || operacion == '-' || operacion == '*' || operacion == '/') {
        cout << "Ingrese el primer número: ";
        cin >> num1;
        cout << "Ingrese el segundo número: ";
        cin >> num2;

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
        }
    } else {
        cout << "Operación no válida." << endl;
    }

    return 0;
}