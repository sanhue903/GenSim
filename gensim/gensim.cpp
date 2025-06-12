#include <gensim.hpp>

namespace gensim {
    double foo(int bar) {
        sketch::hll_t hll(bar); 
        for(uint64_t i(0); i < 100000ull; ++i) hll.addh(i);
        
        return hll.report(); 
    }
}
