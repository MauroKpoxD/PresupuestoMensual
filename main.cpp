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
#include <cstdlib>  // para system()

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

void clear() {
    std::system(CLEAR_COMMAND);
}

const std::string base_de_datos = "base_de_datos.money";

std::time_t obtener_hora_actual() {
    auto ahora = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(ahora);
}

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

int calcular_balance() {
    std::ifstream archivo(base_de_datos);
    if (!archivo) {
        // No mostrar error si el archivo no existe (primer ejecución)
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

void mostrar_historial() {
    std::ifstream archivo(base_de_datos);
    if (!archivo) {
        std::cerr << "No hay historial aún.\n";
        return;
    }
    std::cout << "\n--- HISTORIAL DE MOVIMIENTOS ---\n";
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << "\n";
    }
    std::cout << "--------------------------------\n";
}

int mostrar_opciones() {
    int opcion;
    std::cout << "\n<------------------------------------------------->\n";
    std::cout << "|  Elige una opcion:                              |\n";
    std::cout << "|  1. Ingresar dinero                             |\n";
    std::cout << "|  2. Sacar dinero                                |\n";
    std::cout << "|  3. Mostrar total (balance)                     |\n";
    std::cout << "|  4. Mostrar historial                           |\n";
    std::cout << "|  5. Salir                                       |\n";
    std::cout << "<------------------------------------------------->\n";
    std::cout << "Opcion: ";
    std::cin >> opcion;
    return opcion;
}

int main() {
    bool salir = false;
    
    while (!salir) {
        clear();
        int opcion = mostrar_opciones();
        
        // Validar que la entrada sea correcta
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida. Debe ser un numero.\n";
            std::cout << "Presiona Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
            continue;
        }
        
        switch (opcion) {
            case 1: { // Ingresar dinero
                clear();
                int dinero;
                std::cout << "Monto a depositar: ";
                std::cin >> dinero;
                if (std::cin.fail() || dinero <= 0) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Monto invalido. Debe ser un numero positivo.\n";
                } else {
                    registrar_ingreso(dinero);
                    std::cout << "Ingreso registrado correctamente.\n";
                }
                break;
            }
            
            case 2: { // Sacar dinero (gasto)
                clear();
                int dinero;
                std::cout << "Monto a retirar: ";
                std::cin >> dinero;
                if (std::cin.fail() || dinero <= 0) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Monto invalido. Debe ser un numero positivo.\n";
                } else {
                    int balance_actual = calcular_balance();
                    if (dinero > balance_actual) {
                        std::cout << "Saldo insuficiente. Balance actual: " << balance_actual << "\n";
                    } else {
                        registrar_gasto(dinero);
                        std::cout << "Gasto registrado correctamente.\n";
                    }
                }
                break;
            }
            
            case 3: { // Mostrar balance total
                clear();
                int balance = calcular_balance();
                std::cout << "Balance actual: " << balance << "\n";
                break;
            }
            
            case 4: { // Mostrar historial
                clear();
                mostrar_historial();
                break;
            }
            
            case 5: { // Salir
                clear();
                std::cout << "Saliendo del programa...\n";
                salir = true;
                break;
            }
            
            default: {
                std::cout << "Opcion invalida. Elige un numero del 1 al 5.\n";
                break;
            }
        }
        
        if (!salir) {
            std::cout << "\nPresiona Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
        }
    }
    
    return 0;
}