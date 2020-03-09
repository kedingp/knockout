#ifndef KNOCKOUT_H
#define KNOCKOUT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

class Knockout
{
public:
    Knockout(istream &titleDatabase_, istream &selectionMode_ = cin,
             unsigned int sizeOfPackages_ = 3, unsigned int amountOfTitles_ = 9);
    ~Knockout();
    string solve() const;
private:
    const unsigned int sizeOfPackages;
    const unsigned int amountOfTitles;
    istream& titleDatabase;
    istream& selectionMode;

    string choosePreference(const vector<string>& titles) const;
    vector<vector<string>> makePackages(const vector<string> &titles) const;
    vector<string> playOneLevel(const vector<string>& titles) const;
    string playAllLevels(const vector<string>& titles) const;
    vector<string> selectTitlesFromTSVFile() const;
};


#endif
