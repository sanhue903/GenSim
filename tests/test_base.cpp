#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <gensim.hpp>
#include <fstream>
#include <string>

TEST_CASE("make_pair generates correct sketch pair", "[sketch_pair]") {
    std::string genome = "ACTGACTG";
    int k = 3;

    gensim::SketchPair pair = gensim::make_pair(genome, k);


    REQUIRE(pair.primary.report() < 6);
    REQUIRE(pair.aux.report() < 6);

    std::cout << pair << std::endl;
 }

TEST_CASE("make_pair uses wrong k", "[sketch_pair]") {
    std::string genome = "ACTGACTG";

    gensim::SketchPair pair = gensim::make_pair(genome, 0);

    REQUIRE(pair.primary.report() == 0);
    REQUIRE(pair.aux.report() == 0);
}

TEST_CASE("read_fasta reads multiple sequences", "[fasta]") {
    // Crear archivo FASTA de prueba
    std::string test_file = "tests/test_sample.fasta";
    std::ofstream out(test_file);
    
    out << ">seq1\nACTGACTG\n>seq2\nCGTACGTA\n";
    out.close();

    auto sequences = gensim::read_fasta(test_file);

    REQUIRE(sequences.size() == 2);
}

