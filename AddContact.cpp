//
// Created by Nikki on 11/26/2016.
//

#include "AddContact.h"

void AddContact::fromFile(BSTree &tree)
{
    string filename;
    cout << "Please enter the name of the file from which contacts will be imported." << endl;
    getline(cin, filename);

    //adding each contact separated by a | 'pipe' character
    std::fstream infile(filename, std::fstream::in);
    string line;

    if(infile.is_open() && infile.good())
    {
        while(getline(infile, line, '|'))
        {
            std::stringstream contactStream(line);
            Contact aContact;
            contactStream >> aContact;
        }
    }
    infile.close();
}

void AddContact::manual(BSTree &tree)
{

}