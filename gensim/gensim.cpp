#include <gensim.hpp>

namespace gensim {
    std::vector<std::string> read_fasta(const std::string& filepath) {
        std::vector<std::string> sequences;
        std::ifstream infile(filepath);

        if (!infile) {
            std::cerr << "Error: no se pudo abrir el archivo " << filepath << "\n";
            return sequences;
        }

        std::string line;
        
        std::stringstream current_sequence;

        while (std::getline(infile, line)) {
            if (line.empty()) continue;

            if (line[0] == '>') {
                // Si venimos leyendo una secuencia, la guardamos
                if (!current_sequence.str().empty()) {
                    sequences.push_back(current_sequence.str());
                    current_sequence.str("");
                    current_sequence.clear();
                }
                continue; // Ignora línea del encabezado
            } else {
                current_sequence << line;
            }
        }

        // Guarda la última secuencia si el archivo no termina con '>'
        if (!current_sequence.str().empty()) {
            sequences.push_back(current_sequence.str());
        }

        return sequences;
    }


    double foo(int bar) {
        sketch::hll_t hll(bar); 
        for(uint64_t i(0); i < 100000ull; ++i) hll.addh(i);
        
        return hll.report(); 
    }
}
