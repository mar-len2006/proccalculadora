#include <iostream> // Para entrada/salida estándar (cin, cout)
#include <cmath>    // Para funciones matemáticas como pow, sqrt, log, log10
#include <limits>   // Para numeric_limits
#include <string>   // Para std::string

// Función para la suma de dos números
double suma(double a, double b) {
    return a + b;
}

// Función para la resta de dos números
double resta(double a, double b) {
    return a - b;
}

// Función para la multiplicación de dos números
double multiplicacion(double a, double b) {
    return a * b;
}

// Función para la división de dos números
double division(double a, double b) {
    // Verifica si el divisor es cero para evitar errores
    if (b == 0) {
        std::cerr << "Error: No se puede dividir por cero." << std::endl;
        return 0; // Retorna 0 o podrías lanzar una excepción
    }
    return a / b;
}

// Función para calcular la potencia (base elevada a un exponente)
double potencia(double base, double exponente) {
    return pow(base, exponente); // Utiliza la función pow de cmath
}

// Función para calcular la raíz cuadrada de un número
double raizCuadrada(double num) {
    // Verifica si el número es negativo, ya que la raíz cuadrada de negativos no es real
    if (num < 0) {
        std::cerr << "Error: No se puede calcular la raíz cuadrada de un número negativo." << std::endl;
        return 0;
    }
    return sqrt(num); // Utiliza la función sqrt de cmath
}

// Función para calcular el logaritmo base 10 de un número
double logaritmo(double num) {
    // Verifica si el número es positivo, ya que el logaritmo solo está definido para positivos
    if (num <= 0) {
        std::cerr << "Error: El logaritmo (base 10) solo está definido para números positivos." << std::endl;
        return 0;
    }
    return log10(num); // Utiliza la función log10 de cmath
}

// Función para calcular el logaritmo natural (base e) de un número
double logaritmoNatural(double num) {
    // Verifica si el número es positivo, ya que el logaritmo natural solo está definido para positivos
    if (num <= 0) {
        std::cerr << "Error: El logaritmo natural solo está definido para números positivos." << std::endl;
        return 0;
    }
    return log(num); // Utiliza la función log de cmath (logaritmo natural)
}

// Función auxiliar para limpiar el buffer de entrada después de leer datos
void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    double num1, num2, resultado;
    char operacion; // Usamos char para el operador

    std::cout << "--- Calculadora C++ Interactiva ---" << std::endl;
    std::cout << "Operaciones disponibles:" << std::endl;
    std::cout << "+ (Suma)" << std::endl;
    std::cout << "- (Resta)" << std::endl;
    std::cout << "* (Multiplicación)" << std::endl;
    std::cout << "/ (División)" << std::endl;
    std::cout << "^ (Potencia: base ^ exponente)" << std::endl;
    std::cout << "s (Raíz Cuadrada: s numero)" << std::endl;
    std::cout << "l (Logaritmo base 10: l numero)" << std::endl;
    std::cout << "n (Logaritmo Natural: n numero)" << std::endl;
    std::cout << "q (Salir)" << std::endl;

    // Bucle principal de la calculadora
    while (true) {
        std::cout << "\nIngrese la operación (ej. 5 + 3, 9 s, 10 l, q para salir): ";
        
        // Intenta leer el primer número
        std::cin >> num1;

        // Comprueba si la entrada falló (por ejemplo, si el usuario ingresó una letra en lugar de un número)
        if (std::cin.fail()) {
            std::string input_str;
            std::cin.clear(); // Limpia el estado de error de cin
            std::cin >> input_str; // Intenta leer la entrada como una cadena
            
            // Si la entrada es 'q' o 'Q', salir del programa
            if (input_str == "q" || input_str == "Q") {
                std::cout << "Saliendo de la calculadora. ¡Hasta luego!" << std::endl;
                break; // Sale del bucle while
            } else {
                // Si no es 'q', es una entrada inválida
                std::cerr << "Entrada inválida. Por favor, ingrese un número o 'q' para salir." << std::endl;
                limpiarBuffer(); // Limpia el buffer para futuras entradas
                continue; // Vuelve al inicio del bucle
            }
        }

        // Lee el operador
        std::cin >> operacion;

        // Manejo de operaciones unarias (raíz cuadrada, logaritmo, logaritmo natural)
        if (operacion == 's' || operacion == 'l' || operacion == 'n') {
            // No necesitamos un segundo número para estas operaciones, así que limpiamos el buffer
            limpiarBuffer(); 
            switch (operacion) {
                case 's':
                    resultado = raizCuadrada(num1);
                    std::cout << "Resultado (Raíz Cuadrada): " << resultado << std::endl;
                    break;
                case 'l':
                    resultado = logaritmo(num1);
                    std::cout << "Resultado (Logaritmo base 10): " << resultado << std::endl;
                    break;
                case 'n':
                    resultado = logaritmoNatural(num1);
                    std::cout << "Resultado (Logaritmo Natural): " << resultado << std::endl;
                    break;
            }
            continue; // Continúa al siguiente ciclo del bucle para una nueva operación
        }

        // Para operaciones binarias, necesitamos leer el segundo número
        std::cin >> num2;
        // Comprueba si la lectura del segundo número falló
        if (std::cin.fail()) {
            std::cerr << "Entrada inválida para el segundo número. Por favor, intente de nuevo." << std::endl;
            limpiarBuffer();
            continue;
        }

        // Realiza la operación según el operador ingresado
        switch (operacion) {
            case '+':
                resultado = suma(num1, num2);
                std::cout << "Resultado: " << resultado << std::endl;
                break;
            case '-':
                resultado = resta(num1, num2);
                std::cout << "Resultado: " << resultado << std::endl;
                break;
            case '*':
                resultado = multiplicacion(num1, num2);
                std::cout << "Resultado: " << resultado << std::endl;
                break;
            case '/':
                resultado = division(num1, num2);
                std::cout << "Resultado: " << resultado << std::endl;
                break;
            case '^':
                resultado = potencia(num1, num2);
                std::cout << "Resultado: " << resultado << std::endl;
                break;
            default:
                std::cerr << "Operación inválida. Por favor, intente de nuevo." << std::endl;
                break;
        }
        limpiarBuffer(); // Limpia el buffer después de cada operación binaria
    }

    return 0; // El programa termina exitosamente
}
