#ifndef GENSIM_HPP
#define GENSIM_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>
#include <sstream>
#include <sketch/hll.h>

namespace gensim {

    //TODO iteracion 2: auxiliary_sketch debe permitir ser hhl o smh
    struct SketchPair {
        sketch::hll_t primary;
        sketch::hll_t aux;

        SketchPair(size_t primary_size, size_t aux_size)
        : primary(primary_size), aux(aux_size) {};

        void add(const std::string& str) {
            primary.addh(str);
            aux.addh(str);
        };

        friend std::ostream& operator<<(std::ostream& os, const SketchPair& sp) {
            os << "primary: " << sp.primary.report() << "\n";
            os << ", auxiliary: " << sp.aux.report();
            return os;
        }
    };

    SketchPair make_pair(const std::string &str, int k = 31);

    std::vector<SketchPair> read_fasta(const std::string& path);

    bool ab_criterion(sketch::hll_t A, sketch::hll_t B, double threshold);

    double foo(int p);
    
}

#endif