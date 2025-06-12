#ifndef GENSIM_HPP
#define GENSIM_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <sketch/hll.h>

namespace gensim {
    double foo(int bar);
    double cb_criterion();
    std::vector<std::string> read_fasta(const std::string& path);
}

#endif