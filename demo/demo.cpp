#include <iostream>
#include <vector>
#include <string>
#include <gensim.hpp>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <k-mer size>\n";
        return 1;
    }

    int k = std::atoi(argv[1]);

    if (k < 1) {
        std::cerr << "Error: k-mer size must be greater than 0.\n";
        return 1;
    }

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

    /*
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <precision (1 to 16)> <k-mer size>\n";
        return 1;
    }

    int p = std::atoi(argv[1]);
    int k = std::atoi(argv[2]);

    if (p < 2 || p > 16) {
        std::cerr << "Error: Precision must be between 2 and 16.\n";
        return 1;
    }

    if (k < 1) {
        std::cerr << "Error: k-mer size must be greater than 0.\n";
        return 1;
    }

    std::vector<std::string> sequences = {
        "ACGTACGTACGTACGT",
        "TGCATGCATGCATGCA",
        "GATTACAGATTACA"
    };

    std::string criterion = "example_criterion";
    auto results = gensim::compute_selection(sequences, k, criterion);

    std::cout << "\nSelection Algorithm Results:\n";
    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << "Sequence " << i + 1 << ":\n";
        std::cout << "  HLL Estimate: " << results[i].primary << "\n";
        std::cout << "  Auxiliary k-mers:\n";
        for (const auto& kmer : results[i].auxiliary_kmers) {
            std::cout << "    " << kmer << "\n";
        }
    }
    */

    return 0;
}