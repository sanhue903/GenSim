#include <iostream>
#include <cstdlib>     
#include <gensim.hpp>  

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <precisión_entera (1 a 16)>\n";
        return 1;
    }

    int p = std::atoi(argv[1]);

    if (p < 2 || p > 16) {
        std::cerr << "Error: la precisión debe estar entre 2 y 16.\n";
        return 1;
    }

    double estimate = gensim::foo(p);
    std::cout << "Estimación de cardinalidad con precisión " << p << ": " << estimate << "\n";
    return 0;
}