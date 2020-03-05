#include "knockout.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
 
TEST(KnockoutTest, InputEqualsOutput)
{ 
    std::vector<std::string> movie1 = {"Pulp Fiction"};
    std::vector<std::string> movie2 = {"The good, the bad and the ugly"};
    ASSERT_EQ("Pulp Fiction", choosePreference(movie1));
    ASSERT_EQ("The good, the bad and the ugly", choosePreference(movie2));
}

TEST(KnockoutTest, ChooseBetweenTwo)
{
    std::vector<std::string> movies = {"Pulp Fiction", "The good, the bad and the ugly"};
    std::ifstream testInput1("..//tests//testinput1.txt");
    std::ifstream testInput2("..//tests//testinput2.txt");

    ASSERT_EQ("Pulp Fiction", choosePreference(movies, testInput1));
    ASSERT_EQ("The good, the bad and the ugly", choosePreference(movies, testInput2));
}

TEST(KnockoutTest, MakePackagesOfThree)
{
    std::vector<std::string> movies = {"a", "b", "c", "d", "e", "f"};
    std::vector<std::vector<std::string>> packedMovies = { {"a", "b", "c"}, {"d", "e", "f"} };
    ASSERT_EQ(packedMovies, makePackages(movies));
    std::vector<std::string> moreMovies = {"g", "h", "i", "j", "k", "l"};
    std::vector<std::vector<std::string>> morePackedMovies = { {"g", "h", "i"}, {"j", "k", "l"} };
    ASSERT_EQ(morePackedMovies, makePackages(moreMovies));
}

TEST(KnockoutTest, MakePackagesOfThreeWithResidual)
{
    std::vector<std::string> movies = {"a", "b", "c", "d", "e", "f", "g"};
    std::vector<std::vector<std::string>> packedMovies = { {"a", "b", "c"}, {"d", "e", "f"}, {"g"} };
    ASSERT_EQ(packedMovies, makePackages(movies));
}

TEST(KnockoutTest, MakePackagesOfVariableSizeWithResidual)
{
    std::vector<std::string> movies = {"a", "b", "c", "d", "e", "f", "g"};
    std::vector<std::vector<std::string>> packedMoviesSize2 = { {"a", "b"}, {"c", "d"}, {"e", "f"}, {"g"} };
    std::vector<std::vector<std::string>> packedMoviesSize4 = { {"a", "b", "c", "d"}, {"e", "f", "g"} };
    ASSERT_EQ(packedMoviesSize2, makePackages(movies, 2));
    ASSERT_EQ(packedMoviesSize4, makePackages(movies, 4));
}

TEST(KnockoutTest, PlayOneLevel)
{
    std::vector<std::string> movies = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    std::vector<std::string> moviesForNextLevelDifferentChoice = {"a", "d", "h"};
    std::ifstream testInput1_1_2("..//tests//testinput1_1_2.txt");
    ASSERT_EQ(moviesForNextLevelDifferentChoice, playOneLevel(movies, testInput1_1_2));
    std::vector<std::string> moviesForNextLevel4SizedChoice = {"a", "e", "i"};
    std::ifstream testInput1_1("..//tests//testinput1_1.txt");
    ASSERT_EQ(moviesForNextLevel4SizedChoice, playOneLevel(movies, testInput1_1, 4));
}

TEST(KnockoutTest, PlayAllLevels)
{
    std::vector<std::string> movies = {"j", "k", "l", "m", "n", "o", "p", "q", "r"};
    std::string finalChoice = "n";
    std::ifstream testInput1_2_1_2("..//tests//testinput1_2_1_2.txt");
    ASSERT_EQ(finalChoice, playAllLevels(movies, testInput1_2_1_2));
}

/*TEST(KnockoutTest, ReadFromIMDbFile)
{
    std::ifstream imdbInput("..//tests//data.tsv");
    ASSERT_EQ(9, selectTitlesFromTSVFile(imdbInput).size());
    std::string movie = "Miss Jerry";
    ASSERT_EQ(movie, selectTitlesFromTSVFile(imdbInput)[0]);
    ASSERT_EQ(13, selectTitlesFromTSVFile(imdbInput, 13).size());
}

TEST(KnockoutTest, MainRoutine)
{
    std::ifstream imdbInput("..//tests//data.tsv");
    std::ifstream testInput1_2_1_2("..//tests//testinput1_2_1_2.txt");
    std::string movie = "Blacksmith Scene";
    ASSERT_EQ(movie, mainRoutine(imdbInput, testInput1_2_1_2));
}*/
