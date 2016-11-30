//
// Created by Nikki on 11/26/2016.
//

#include "SearchFunctions.h"

void SearchFunctions::searchExact(BSTree &tree)
{
    string value;
    cout << "Enter the ID number of the contact to view." << endl;
    getline(cin, value);
    const string STOI = value;
    int IDNumber = std::stoi(STOI, nullptr, 10);
    Node* contactptr = tree.findNode(IDNumber, tree.Root());
    cout << contactptr->Data() << endl;
}

void SearchFunctions::searchPartial(BSTree &tree)
{}
