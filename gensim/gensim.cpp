#include <gensim.hpp>

namespace gensim {
    kmers string_to_kmers(std:: string &genoma, int k = 31) {
        kmers kmer_set;
        if (k <= 0 || k > genoma.size()) {
            std::cerr << "Error: k must be greater than 0 and less than or equal to the length of the string.\n";

            return kmer_set;
        }

        for (size_t i = 0; i + k <= genoma.size(); ++i) {
            kmer_set.addh(genoma.substr(i, k));
        }
        return kmer_set;
    }

    //TODO refactorizar esta funcion para que no guarde las strings completas, sino que guarde los hashes de los k-mers
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

                if (!current_sequence.str().empty()) {
                    sequences.push_back(current_sequence.str());
                    current_sequence.str("");
                    current_sequence.clear();
                }
                continue; 
            } else {
                current_sequence << line;
            }
        }

        
        if (!current_sequence.str().empty()) {
            sequences.push_back(current_sequence.str());
        }

        return sequences;
    }

    double cardinality(const kmers &A) {
        sketch::hll_t hll(14); 
        
        hll.add
        for (const auto &kmer : A) {
            hll.addh(sketch::WangHash()(std::hash<std::string>{}(kmer)));
        }
        return hll.report();
    }



    double foo(int bar) {
        sketch::hll_t hll(bar); 
        for(uint64_t i(0); i < 100000ull; ++i) hll.addh(i);
        
        return hll.report(); 
    }

    std::vector<Result> compute_selection(const std::vector<std::string>& sequences, int k, const std::string& criterion) {
        std::vector<Result> results;

        for (const auto& sequence : sequences) {
            double hll_estimation = foo(k);

            kmers auxiliary_kmers = string_to_kmers(const_cast<std::string&>(sequence), k);

            results.push_back({hll_estimation, auxiliary_kmers});
        }

        return results;
    }
}

