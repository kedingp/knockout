//
// Created by phili on 09.03.2020.
//

#include <sstream>
#include "knockout_functional.h"

using namespace std;

string choosePreference(const vector<string> &titles, istream& istream)
{
    if(titles.size() == 1)
    {
        return titles[0];
    }
    else
    {
        unsigned int preference;
        cout << "\nChoose between the following titles by selecting the number: " << endl;
        for(size_t title_index = 0; title_index < titles.size(); title_index++)
        {
            cout << title_index + 1 << ": " << titles[title_index] << endl;
        }
        istream >> preference;

        cout << "Your choice: " << titles[preference-1] << endl;
        return titles[preference-1];
    }
}

vector<vector<string>> makePackages(const vector<string>& titles, unsigned int sizeOfPackages)
{
    vector<vector<string>> packedTitles;
    vector<string> package;
    for (const auto& it : titles)
    {
        package.push_back(it);
        if(package.size() == sizeOfPackages)
        {
           packedTitles.push_back(package);
           package.clear();
        }
    }

    if(!package.empty())
    {
        packedTitles.push_back(package);
    }

    return packedTitles;
}

vector<string> playOneLevel(const vector<string>& titles, istream& istream,
                            unsigned int sizeOfPackages)
{
    auto packedTitles = makePackages(titles, sizeOfPackages);
    vector<string> titlesForNextLevel;
    for (const auto& it : packedTitles)
    {
        titlesForNextLevel.push_back(choosePreference(it, istream));
    }
    return titlesForNextLevel;
}

string playAllLevels(const vector<string>& titles, istream& istream)
{
    vector<string> activeTitles = titles;
    unsigned int levelNumber = 0;
    while(activeTitles.size() > 1)
    {
        levelNumber++;
        cout << "*************************************************************" << endl;
        cout << "Level " << levelNumber << " selection" << endl;
        activeTitles = playOneLevel(activeTitles, istream);
    }
    cout << "Enjoy the movie!" << endl;
    return activeTitles[0];
}

vector<string> selectTitlesFromTSVFile(istream& istream, unsigned int amountOfTitles)
{
    vector<string> titles;
    string contentOfRow;
    for(size_t rowIndex = 0; rowIndex < amountOfTitles; rowIndex++)
    {
        getline(istream, contentOfRow);
        stringstream contentBuffer (contentOfRow);
        string tempColumnEntry;
        vector<string> cleanContentOfRow;
        while(getline(contentBuffer, tempColumnEntry, '\t') )
        {
            cleanContentOfRow.push_back(tempColumnEntry);
        }
        titles.push_back(cleanContentOfRow[2]);
    }
    return titles;
}

string mainRoutine(istream& titleDatabase, istream& selectionMode)
{
    //remove the headers from the Database
    string headers;
    getline(titleDatabase, headers);

    vector<string> titlesFromDatabase = selectTitlesFromTSVFile(titleDatabase);
    string favouriteTitle = playAllLevels(titlesFromDatabase, selectionMode);
    return favouriteTitle;
}