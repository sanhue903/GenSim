#ifndef GENSIM_HPP
#define GENSIM_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>
#include <sstream>
#include <sketch/hll.h>

typedef std::unordered_multiset<std::string> kmers;

namespace gensim {
    kmers string_to_kmers(std::string &genoma, int k);
    std::vector<std::string> read_fasta(const std::string& path);

    double foo(int p);

}

#endif