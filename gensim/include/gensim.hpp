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
    kmers string_to_kmers(std::string &genoma, int k);

    double cardinality(const kmers &A);

    std::vector<std::string> read_fasta(const std::string& path);

    bool ab_criterion(const kmers &A, const kmers &B, double threshold);

    double foo(int p);

}

#endif