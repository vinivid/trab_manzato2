#include <random>
#include <cstdlib>
#include <iostream>

void gerar_random(int qtt, char** argv) {
    std::random_device rnd;
    std::mt19937 rng(rnd());
    int range = std::atoi(argv[3]);

    std::uniform_int_distribution<int> set(0, range);

    std::cout << qtt << "\n";

    for (int i = 0; i < qtt; ++i) {
        std::cout << set(rng) << "\n";    
    }
}

void gerar_crescente(int qtt, char** argv) {
    int limite_inferior = std::atoi(argv[3]);

    std::cout << qtt << "\n";

    for (int i = 0; i < qtt; ++i) {
        std::cout << limite_inferior << "\n";
        ++limite_inferior;
    }
}

void gerar_decrescente(int qtt, char** argv) {
    int limite_superior = std::atoi(argv[3]);
    std::cout << qtt << "\n";

    for (int i = 0; i < qtt; ++i) {
        std::cout << limite_superior << "\n";
        --limite_superior;
    }
}

int main(int argc, char** argv) {
    int type = std::atoi(argv[1]);
    int qtt = std::atoi(argv[2]);

    switch (type) {
        case 0:
            gerar_random(qtt, argv);
            break;
        case 1:
            gerar_crescente(qtt, argv);
            break;
        case 2:
            gerar_decrescente(qtt, argv);
            break;
        default:
            std::cout << "ERRO TIPO DE CASO INVALIDO";
            return 1;
    }
}