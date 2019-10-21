#include "knockout.h"
#include <sstream>

std::string choosePreference(const std::vector<std::string> &titles, std::istream& istream)
{
    if(titles.size() == 1)
    {
        return titles[0];
    }
    else
    {
        unsigned int preference;
        std::cout << "\nChoose between the following titles by selecting the number: " << std::endl;
        for(unsigned int title_index = 0; title_index < titles.size(); title_index++)
        {
            std::cout << title_index+1 << ": " << titles[title_index] << std::endl;
        }
        istream >> preference;
       
        std::cout << "Your choice: " << titles[preference-1] << std::endl;
        return titles[preference-1];
    }
}



std::vector<std::vector<std::string> > makePackages(const std::vector<std::string>& titles, unsigned int sizeOfPackages)
{
    std::vector<std::vector<std::string>> packedTitles;
    std::vector<std::string> package;
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

std::vector<std::string> playOneLevel(const std::vector<std::string>& titles, std::istream& istream,
                                      unsigned int sizeOfPackages)
{
    auto packedTitles = makePackages(titles, sizeOfPackages);
    std::vector<std::string> titlesForNextLevel;
    for (const auto& it : packedTitles)
    {
        titlesForNextLevel.push_back(choosePreference(it, istream));
    }
    return titlesForNextLevel;
}

std::string playAllLevels(const std::vector<std::string>& titles, std::istream& istream)
{
    std::vector<std::string> activeTitles = titles;
    unsigned int levelNumber = 0;
    while(activeTitles.size() > 1)
    {
        levelNumber++;
        std::cout << "*************************************************************" << std::endl;
        std::cout << "Level " << levelNumber << " selection" << std::endl;
        activeTitles = playOneLevel(activeTitles, istream);
    }
    std::cout << "Enjoy the movie!" << std::endl;
    return activeTitles[0];
}

std::vector<std::string> selectTitlesFromTSVFile(std::istream& istream, unsigned int amountOfTitles)
{
    std::vector<std::string> titles;
    std::string contentOfRow;
    for(std::size_t rowIndex = 0; rowIndex < amountOfTitles; rowIndex++)
    {
        std::getline(istream, contentOfRow);
        std::stringstream contentBuffer (contentOfRow);
        std::string tempColumnEntry;
        std::vector<std::string> cleanContentOfRow;
        while(std::getline(contentBuffer, tempColumnEntry, '\t') )
        {
            cleanContentOfRow.push_back(tempColumnEntry);
        }
        titles.push_back(cleanContentOfRow[2]);
    }
    return titles;
}

std::string mainRoutine(std::istream& titleDatabase, std::istream& selectionMode)
{
    //remove the headers from the Database
    std::string headers;
    std::getline(titleDatabase, headers);

    std::vector<std::string> titlesFromDatabase = selectTitlesFromTSVFile(titleDatabase);
    std::string favouriteTitle = playAllLevels(titlesFromDatabase, selectionMode);
    return favouriteTitle;
}




