#include "knockout.h"
#include <sstream>

Knockout::Knockout(istream& titleDatabase_, istream& selectionMode_,
                   unsigned int sizeOfPackages_, unsigned int amountOfTitles_) :
    sizeOfPackages(sizeOfPackages_), amountOfTitles(amountOfTitles_),
    titleDatabase(titleDatabase_), selectionMode(selectionMode_)
{
}

Knockout::~Knockout()
{}

string Knockout::choosePreference(const vector<string> &titles) const
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
        selectionMode >> preference;

        cout << "Your choice: " << titles[preference-1] << endl;
        return titles[preference-1];
    }
}

vector<vector<string>> Knockout::makePackages(const vector<string>& titles) const
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

vector<string> Knockout::playOneLevel(const vector<string>& titles) const
{
    auto packedTitles = makePackages(titles);
    vector<string> titlesForNextLevel;
    for (const auto& it : packedTitles)
    {
        titlesForNextLevel.push_back(choosePreference(it));
    }
    return titlesForNextLevel;
}

string Knockout::playAllLevels(const vector<string>& titles) const
{
    vector<string> activeTitles = titles;
    unsigned int levelNumber = 0;
    while(activeTitles.size() > 1)
    {
        levelNumber++;
        cout << "*************************************************************" << endl;
        cout << "Level " << levelNumber << " selection" << endl;
        activeTitles = playOneLevel(activeTitles);
    }
    cout << "Enjoy the movie!" << endl;
    return activeTitles[0];
}

vector<string> Knockout::selectTitlesFromTSVFile() const
{
    vector<string> titles;
    string contentOfRow;
    for(size_t rowIndex = 0; rowIndex < amountOfTitles; rowIndex++)
    {
        getline(titleDatabase, contentOfRow);
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

string Knockout::solve() const
{
    //remove the headers from the Database
    string headers;
    getline(titleDatabase, headers);

    vector<string> titlesFromDatabase = selectTitlesFromTSVFile();
    string favouriteTitle = playAllLevels(titlesFromDatabase);
    return favouriteTitle;
}




