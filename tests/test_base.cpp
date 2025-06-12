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

 TEST_CASE("string_to_kmers generates correct k-mers", "[kmers]") {
    std::string genome = "ACTGACTG";
    int k = 3;

    auto kmer_set = gensim::string_to_kmers(genome, k);

    REQUIRE(kmer_set.size() == 6);
    REQUIRE(kmer_set.count("ACT") == 2);
    REQUIRE(kmer_set.count("CTG") == 2);
    REQUIRE(kmer_set.count("TGA") == 1);
    REQUIRE(kmer_set.count("GAC") == 1);
 }

  TEST_CASE("string_to_kmers wrong k", "[kmers]") {
    std::string genome = "ACTGACTG";

    kmers kmer_0 = gensim::string_to_kmers(genome, 0);
    kmers kmer_more_than_genome = gensim::string_to_kmers(genome, 10);

    REQUIRE(kmer_0.size() == 0);
    REQUIRE(kmer_more_than_genome.size() == 0);
 }