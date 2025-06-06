#include <gensim/gensim.hpp>

namespace gensim {
    void foo(int bar) {
        sketch::hll_t hll(12); // Create a HyperLogLog sketch with precision 12
        hll.addh("example_data", bar); // Add data to the sketch
        double estimate = hll.report(); // Get the estimated cardinality

        return estimate; // Return the estimated cardinality // Output the estimate
    }
}
