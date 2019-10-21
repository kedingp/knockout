#ifndef KNOCKOUT_H
#define KNOCKOUT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

std::string choosePreference(const std::vector<std::string>& i_title, std::istream& i_istream = std::cin);

std::vector<std::vector<std::string>> makePackages(const std::vector<std::string> &i_titles, unsigned int i_sizeOfPackages = 3);

std::vector<std::string> playOneLevel(const std::vector<std::string>& i_titles, std::istream& i_istream = std::cin,
                                      unsigned int i_sizeOfPackages = 3);

std::string playAllLevels(const std::vector<std::string>& i_titles, std::istream& i_istream = std::cin);

std::vector<std::string> selectTitlesFromTSVFile(std::istream& i_istream, unsigned int i_amountOfTitles = 9);

std::string mainRoutine(std::istream& i_titleDatabase, std::istream& i_selectionMode = std::cin);

#endif
