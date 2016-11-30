//
// Created by Nikki on 10/30/2016.
//

#ifndef MAINMENU_H
#define MAINMENU_H

class Menu
{
    //needs the private variables that will be passed around
public:
    void mainMenu(int &);
    void displayContactsAll();
    void searchMenu(int &);
    void printContactsToFile();
    void addContact(int &);
    void editContact(int &);
    void deleteContact(int &);
};


#endif //MAINMENU_H
