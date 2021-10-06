//
// Created by Celia Liberman on 2/14/2021.
//

#ifndef M1OEP_STYLE_ERRORS_CHLIBERM_FORTUNETELLER_H
#define M1OEP_STYLE_ERRORS_CHLIBERM_FORTUNETELLER_H

#include <iostream>
#include <vector>

/*
* map strings of categories to enum value
*/
enum Categories{
    InvalidCategory,
    Finance,
    Love,
    Family
};

class FortuneTeller {
protected:
    // Fields
    Categories category;
    std::vector<std::string> financeFortunes;
    std::vector<std::string> loveFortunes;
    std::vector<std::string> familyFortunes;
    std::string filename;
public:
    /*
     * enum comparison method
     * Requires: string strCategory
     * Modifies: nothing
     * Effects: returns a enum of Category type based on the string value
     */
    void convertCategories(std::string strCategory);


    /*
     * Default constructor
     * Requires: Nothing
     * Modifies: choice and fortune fields
     * Effects: sets choice to be 0 and fortune to be an
     *          empty string as the default
     */
    FortuneTeller();
    FortuneTeller(std::string file);
    FortuneTeller(std::string file, std::string category);
    FortuneTeller(Categories c);
    FortuneTeller(std::string file, Categories c);

    /*
     * Get a fortune
     * Requires: Category category, int index
     * Modifies: nothing
     * Effects: returns a fortune as string based on the category and
     * index
     */
    std::string getFortune(Categories category, int index);

    /*
     * Sets the fortunes
     * Requires: nothing
     * Modifies: fortunes
     * Effects: adds the fortunes read from a file into each vector
     * based on category and adds those vectors to the vector of vectors
     */
    void setFortunes();

    /* Set filename */
    void setFilename(std::string file);

};
#endif //M1OEP_STYLE_ERRORS_CHLIBERM_FORTUNETELLER_H

