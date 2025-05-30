#include "gensim/gensim.hpp"

int main() {
    double estimate = gensim::foo(42);
    std::cout << "Estimated cardinality: " << estimate << std::endl;
    
    return 0;
}