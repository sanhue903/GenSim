#include <iostream>
#include <cstdlib>     
#include <gensim.hpp>  

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <precisión_entera (1 a 16)> <k-mer tamaño>\n";
        return 1;
    }

    int p = std::atoi(argv[1]);
    int k = std::atoi(argv[2]);

    if (p < 2 || p > 16) {
        std::cerr << "Error: la precisión debe estar entre 2 y 16.\n";
        return 1;
    }

    if (k < 1) {
        std::cerr << "Error: el tamaño de k-mer debe ser mayor que 0.\n";
        return 1;
    }

    double estimate = gensim::foo(p);
    std::cout << "Estimación de cardinalidad con precisión " << p << ": " << estimate << "\n";
    
    std::vector<std::string> sequences = {"ACTGACTG", "CGTACGTA"}; // Example sequences
    std::string criterion = "example_criterion";

    auto results = gensim::compute_selection(sequences, k, criterion);

    std::cout << "\nResultados del algoritmo de selección:\n";
    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << "Secuencia " << i + 1 << ":\n";
        std::cout << "  Estimación HLL: " << results[i].hll_estimation << "\n";
        std::cout << "  K-mers auxiliares:\n";
        for (const auto& kmer : results[i].auxiliary_kmers) {
            std::cout << "    " << kmer << "\n";
        }
    }

    
    return 0;

}