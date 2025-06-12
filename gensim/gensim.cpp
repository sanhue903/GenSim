#include <gensim.hpp>

namespace gensim {
    kmers string_to_kmers(std:: string &genoma, int k = 31) {
        kmers kmer_set;
        if (k <= 0 || k > genoma.size()) {
            std::cerr << "Error: k must be greater than 0 and less than or equal to the length of the string.\n";

            return kmer_set;
        }

        for (size_t i = 0; i + k <= genoma.size(); ++i) {
            kmer_set.insert(genoma.substr(i, k));
        }
        return kmer_set;
    }

    std::vector<std::string> read_fasta(const std::string& filepath) {
        std::vector<std::string> sequences;
        std::ifstream infile(filepath);

        if (!infile) {
            std::cerr << "Error: could not open the file " << filepath << "\n";
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

