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

double logaritmoNatural(double a) {
    if (a <= 0) {
        cout << "Error: Logaritmo natural de número no positivo no permitido." << endl;
        return 0;
    }
    return log(a); // log(x) es logaritmo natural en C++
}

int main() {
    double num1, num2;
    char operacion;

    cout << "Ingrese operación (+, -, *, /, r = raíz, l = logaritmo natural): ";
    cin >> operacion;

    if (operacion == 'r' || operacion == 'l') {
        // Operaciones unarias
        cout << "Ingrese un número: ";
        cin >> num1;

        if (operacion == 'r') {
            cout << "Resultado: " << raizCuadrada(num1) << endl;
        } else {
            cout << "Resultado: " << logaritmoNatural(num1) << endl;
        }

    } else if (operacion == '+' || operacion == '-' || operacion == '*' || operacion == '/') {
        // Operaciones binarias
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