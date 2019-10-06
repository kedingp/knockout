#include "knockout.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::ifstream imdbInput("..//tests//data.tsv");
    mainRoutine(imdbInput);
}
