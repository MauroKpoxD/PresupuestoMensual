/*
    bueno, como no se si habia tarea voy a programar loq se me 
    venga a la cabeza en estos 5m (14/4/2026 22:45hs)
*/ 

/*
    Presupuestador mensual
*/

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

const std::string base_de_datos = "base_de_datos.money";

std::time_t obtener_hora_actual() {
    auto ahora = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(ahora);
}

// Registra un ingreso (signo +)
void registrar_ingreso(int cantidad) {
    std::ofstream archivo(base_de_datos, std::ios::app);
    if (!archivo) {
        std::cerr << "Error al abrir la base de datos.\n";
        return;
    }
    std::time_t t = obtener_hora_actual();
    archivo << "+ " << cantidad << " "
            << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S") << "\n";
}

// Registra un gasto (signo -)
void registrar_gasto(int cantidad) {
    std::ofstream archivo(base_de_datos, std::ios::app);
    if (!archivo) {
        std::cerr << "Error al abrir la base de datos.\n";
        return;
    }
    std::time_t t = obtener_hora_actual();
    archivo << "- " << cantidad << " "
            << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S") << "\n";
}

// Calcula el balance total (ingresos - gastos)
int calcular_balance() {
    std::ifstream archivo(base_de_datos);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para calcular balance.\n";
        return 0;
    }
    int balance = 0;
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        char signo;
        int cantidad;
        if (iss >> signo >> cantidad) {
            if (signo == '+')
                balance += cantidad;
            else if (signo == '-')
                balance -= cantidad;
        }
    }
    return balance;
}

// Muestra todo el historial de movimientos
void mostrar_historial() {
    std::ifstream archivo(base_de_datos);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return;
    }
    std::cout << "\n--- HISTORIAL DE MOVIMIENTOS ---\n";
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << "\n";
    }
    std::cout << "--------------------------------\n";
}

int main() {
    bool salir = false;
    while (!salir) {
        std::cout << "\n<------------------------------------------------->\n";
        std::cout << "|  Elije una opcion:                              |\n";
        std::cout << "|  1. Ingresar dinero                             |\n";
        std::cout << "|  2. Sacar dinero                                |\n";
        std::cout << "|  3. Mostrar total (balance)                     |\n";
        std::cout << "|  4. Mostrar historial                           |\n";
        std::cout << "|  5. Salir                                       |\n";
        std::cout << "<------------------------------------------------->\n";
        
        int opcion;
        std::cin >> opcion;
        
        switch (opcion) {
            case 1: { // Ingresar dinero
                int dinero;
                std::cout << "Monto a depositar: ";
                std::cin >> dinero;
                if (dinero <= 0) {
                    std::cout << "El monto debe ser positivo.\n";
                } else {
                    registrar_ingreso(dinero);
                    std::cout << "Ingreso registrado.\n";
                }
                break;
            }

            case 2: { // Sacar dinero (gasto)
                int dinero;
                std::cout << "Monto a retirar: ";
                std::cin >> dinero;
                if (dinero <= 0) {
                    std::cout << "El monto debe ser positivo.\n";
                } else {
                    // Podríamos verificar si hay suficiente balance, pero opcional
                    registrar_gasto(dinero);
                    std::cout << "Gasto registrado.\n";
                }
                break;
            }

            case 3: { // Mostrar balance total
                int balance = calcular_balance();
                std::cout << "Balance actual: " << balance << "\n";
                break;
            }

            case 4: { // Mostrar historial
                mostrar_historial();
                break;
            }

            case 5: { // Salir
                std::cout << "Saliendo...\n";
                salir = true;
                break;
            }
            
            default: {
                std::cout << "Opcion invalida.\n";
            }
        }
    }
    return 0;
}