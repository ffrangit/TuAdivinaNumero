#include <iostream>
#include <random>

int main() {

    int numeroSecreto;
    int intento;
    int cantidadIntentos = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribucion(1,100);
    numeroSecreto = distribucion(gen);

    std::cout << "Pense en un numero entre el 1 y el 100.\n";

    do {

        std::cout << "Adivina mi numero: ";
        std::cin >> intento;

        if (std::cin.fail()) {

            std::cout << "ERROR: Entrada invalida. Intenta solo con numeros del 1 al 100.\n";

            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (intento < 1 || intento > 100) {
            std::cout << "ERROR: Entrada invalida, usa numeros entre 1 y 100.\n";
            continue;
        }

        cantidadIntentos++;

        if (intento == numeroSecreto) {
            std::cout << "Adivinaste mi numero en " << cantidadIntentos << " intentos, bien hecho!";
        }
        else if (intento < numeroSecreto) {
            std::cout << "El numero es mayor, intenta de nuevo: " << std::endl;
        }
        else {
            std::cout << "El numero es menor, intenta de nuevo: " << std::endl;
        }

    } while (intento != numeroSecreto);


    return 0;
}

