#ifndef GENSIM_HPP
#define GENSIM_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>
#include <sstream>
#include <sketch/hll.h>

typedef sketch::hll_t kmers;


namespace gensim {

    struct Result {
        double hll_estimation;
        kmers auxiliary_kmers;
    };

    kmers string_to_kmers(std::string &genoma, int k);

    double cardinality(const kmers &A);

    std::vector<std::string> read_fasta(const std::string& path);

    bool ab_criterion(const kmers &A, const kmers &B, double threshold);

    double foo(int p);

    std::vector<Result> compute_selection(const std::vector<std::string>& sequences, int k, const std::string& criterion);
    
}

#endif