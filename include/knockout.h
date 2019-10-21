#ifndef KNOCKOUT_H
#define KNOCKOUT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

std::string choosePreference(const std::vector<std::string>& titles, std::istream& istream = std::cin);

std::vector<std::vector<std::string>> makePackages(const std::vector<std::string> &titles, unsigned int sizeOfPackages = 3);

std::vector<std::string> playOneLevel(const std::vector<std::string>& titles, std::istream& istream = std::cin,
                                      unsigned int sizeOfPackages = 3);

std::string playAllLevels(const std::vector<std::string>& titles, std::istream& istream = std::cin);

std::vector<std::string> selectTitlesFromTSVFile(std::istream& istream, unsigned int amountOfTitles = 9);

std::string mainRoutine(std::istream& titleDatabase, std::istream& selectionMode = std::cin);

#endif
