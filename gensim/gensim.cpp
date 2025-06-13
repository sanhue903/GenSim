#include <gensim.hpp>

namespace gensim {
    SketchPair make_pair(const std::string &str, int k) {
        SketchPair pair(14, 8);
        
        if (k <= 0) {
            std::cerr << "Error: k must be greater than 0.\n";

            return pair;
        }

        size_t i = 0;
        std::string substr;

        while ((substr = str.substr(i,k)).size() == k) {
            pair.add(substr);

            i++;
        }

        return pair;
    }

    std::vector<SketchPair> read_fasta(const std::string& filepath) {
        std::vector<SketchPair> sequences;
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
                    sequences.push_back(gensim::make_pair(current_sequence.str()));

                    current_sequence.str("");
                    current_sequence.clear();
                }

                continue; 
            } 
            else {
                current_sequence << line;
            }
        }
        
        if (!current_sequence.str().empty()) {
            sequences.push_back(gensim::make_pair(current_sequence.str()));
        }

        return sequences;
    }

    bool cb_criterion(sketch::hll_t A, sketch::hll_t B, double threshold) {
        if (A.report() < B.report()*threshold) return false;

        return true;
    }

    bool hll_a_criterion(SketchPair A, SketchPair B, double threshold) {
        sketch::hll_t union_aux = A.aux + B.aux;

        double bound_kp = (A.primary.report() + B.primary.report() - union_aux.report())/union_aux.report(); 

        if (bound_kp < threshold) return false;
        return true;
    }

    double foo(int bar) {
        sketch::hll_t hll(bar); 
        for(uint64_t i(0); i < 100000ull; ++i) hll.addh(i);
        
        return hll.report(); 
    }
}

