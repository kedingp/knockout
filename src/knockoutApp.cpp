#include "knockout_functional.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Please specify a filename!" << std::endl;
        return -1;
    }
    std::ifstream imdbInput(argv[1]);
    mainRoutine(imdbInput);

    return 0;
}
