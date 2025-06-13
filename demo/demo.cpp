#include <iostream>
#include <vector>
#include <string>
#include <gensim.hpp>

int main(int argc, char* argv[]) {
    // Paths to the genome files
    std::vector<std::string> genome_files = {
        "demo/GCF_000836845.1_ViralProj14021_genomic.fna",
        "demo/GCF_000841225.1_ViralProj14242_genomic.fna"
    };

    std::vector<gensim::SketchPair> all_sequences;

    for (const auto& file : genome_files) {
        auto sequences = gensim::read_fasta(file);
        if (sequences.empty()) {
            std::cerr << "Error: No sequences found in file " << file << "\n";
            continue;
        }

        all_sequences.insert(all_sequences.end(), sequences.begin(), sequences.end());
    }

    std::cout << "\nProcessed Genome Data:\n";
    for (size_t i = 0; i < all_sequences.size(); ++i) {
        std::cout << "Sequence " << i + 1 << ":\n";
        std::cout << "  Primary HLL Estimate: " << all_sequences[i].primary.report() << "\n";
        std::cout << "  Auxiliary HLL Estimate: " << all_sequences[i].aux.report() << "\n";
    }

    auto pairs = gensim::get_similar_pairs(all_sequences, 0.5);

    if (pairs.size() == 0) std::cout << "rip" << std::endl;

    return 0;
}