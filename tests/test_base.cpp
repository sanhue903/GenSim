#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <gensim.hpp>


TEST_CASE("read_fasta reads multiple sequences", "[fasta]") {
    // Crear archivo FASTA de prueba
    std::string test_file = "tests/test_sample.fasta";
    std::ofstream out(test_file);
    out << ">seq1\nACTGACTG\n>seq2\nCGTACGTA\n";
    out.close();

    auto sequences = gensim::read_fasta(test_file);

    REQUIRE(sequences.size() == 2);
    REQUIRE(sequences[0] == "ACTGACTG");
    REQUIRE(sequences[1] == "CGTACGTA");
}