//
// Created by Nikki on 10/30/2016.
//

#include <iostream>
#include "Menu.h"
#include "BSTree.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void Menu::mainMenu(int &val)
{
    string value;
    cout << "Main Menu\n" << endl;
    cout << "1> Display All Contacts" << endl;
    cout << "Note: this does not print to a file, only to the monitor." << endl;
    cout << "To print all contacts choose option 3." << endl;
    cout << "To print a subset of this list, choose option 2.\n" << endl;
    cout << "2> Search" << endl;
    cout << "3> Print All Contacts (to file)" << endl;
    cout << "4> Add Contact(s)" << endl;
    cout << "5> Edit Contact" << endl;
    cout << "6> Delete Contact" << endl;
    cout << "7> Exit" << endl;
    getline(cin, value);
    const string STOI = value;
    val = std::stoi(STOI, nullptr, 10);
}

void Menu::displayContactsAll()
{
    cout << endl;
    cout << "All contacts will be displayed." << endl;
}

void Menu::searchMenu(int& val)
{
    string value;
    cout << "Please choose a search option." << endl;
    cout << "1> Search for an exact match." << endl;
    cout << "2> Search for a partial match." << endl;
    getline(cin, value);
    const string STOI = value;
    val = std::stoi(STOI, nullptr, 10);
}

void Menu::printContactsToFile()
{
    cout << endl;
    cout << "All contacts will be printed to a file." << endl;
}

void Menu::addContact(int& val)
{
    string value;
    cout << "Please choose an option below." << endl;
    cout << "1> Add contacts from file." << endl;
    cout << "2> Add a contact manually." << endl;
    getline(cin, value);
    const string STOI = value;
    val = std::stoi(STOI, nullptr, 10);
}

void Menu::editContact(int& val)
{
    string value;
    cout << "Please choose an option below." << endl;
    cout << "1> Search for contact." << endl;
    cout << "2> Enter contact identifier." << endl;
    getline(cin, value);
    const string STOI = value;
    val = std::stoi(STOI, nullptr, 10);
}

void Menu::deleteContact(int& val)
{
    string value;
    cout << "Please choose an option below." << endl;
    cout << "1> Search for contact." << endl;
    cout << "2> Enter contact identifier." << endl;
    getline(cin, value);
    const string STOI = value;
    val = std::stoi(STOI, nullptr, 10);
}
