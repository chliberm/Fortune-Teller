//
// Created by Celia Liberman on 2/14/2021.
//

#include "FortuneTeller.h"
#include <time.h>
#include <fstream>

using namespace std;

// Converting category from string to enum
void FortuneTeller::convertCategories(string strCategory){
   if(strCategory == "Finance" || strCategory == "finance") {
       category = Finance;
   }
   if(strCategory == "Love" || strCategory == "love") {
       category = Love;
   }
   if(strCategory == "Family" || strCategory == "family") {
       category = Family;
   }
   category = InvalidCategory;
}


// Constructor
FortuneTeller::FortuneTeller() {
    category = InvalidCategory;
    filename = "Default_file.txt";
    financeFortunes = {};
    loveFortunes = {};
    familyFortunes = {};
}

FortuneTeller::FortuneTeller(string file) {
    setFilename(file);
    category = InvalidCategory;
    financeFortunes = {};
    loveFortunes = {};
    familyFortunes = {};
}

FortuneTeller::FortuneTeller(string file, string category) {
    setFilename(file);
    financeFortunes = {};
    loveFortunes = {};
    familyFortunes = {};
    convertCategories(category);
}

FortuneTeller::FortuneTeller(Categories c) {
    filename = "Default_file.txt";
    category = c;
    financeFortunes = {};
    loveFortunes = {};
    familyFortunes = {};
}

FortuneTeller::FortuneTeller(string file, Categories c) {
    setFilename(file);
    category = c;
    financeFortunes = {};
    loveFortunes = {};
    familyFortunes = {};
}

// Get fortune based on category
string FortuneTeller::getFortune(Categories category, int index) {
    setFortunes();
    switch(category) {
        case Finance: {
            return financeFortunes[index];
        }

        case Love: {
            return loveFortunes[index];
        }

        case Family: {
            return familyFortunes[index];
        }

        default: {
            return "Invalid category";
        }
    }
}

void FortuneTeller::setFilename(string file) {
    ifstream inFile("../" + filename);
    if(inFile) {
        filename = file;
    } else {
        filename = "Default_file.txt";
    }
}

void FortuneTeller::setFortunes() {
    // Open file
    ifstream inFile("../" + filename);

    // Read from file
    int numFortunes = 0;
    string fortune;
    string type;
    string newline;
    if (inFile) {
        getline(inFile, type);
        inFile >> numFortunes;
        getline(inFile, newline);
        for(int i = 0; i < numFortunes; i++) {
            getline(inFile, fortune);
            financeFortunes.push_back(fortune);
        }
    }
    if (inFile) {
        getline(inFile, newline);
        getline(inFile, type);
        inFile >> numFortunes;
        getline(inFile, newline);
        for(int i = 0; i < numFortunes; i++) {
            getline(inFile, fortune);
            loveFortunes.push_back(fortune);
        }
    }
    if (inFile) {
        getline(inFile, newline);
        getline(inFile, type);
        inFile >> numFortunes;
        getline(inFile, newline);
        for(int i = 0; i < numFortunes; i++) {
            getline(inFile, fortune);
            familyFortunes.push_back(fortune);
        }
    }
}
