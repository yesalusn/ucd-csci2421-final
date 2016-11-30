//
// Created by Nikki on 11/26/2016.
//

#include "AppFunctions.h"

void AppFunctions::application()
{
    int choice = 0;
    do
    {
        menu.mainMenu(choice);
        switch (choice)
        {
        case 1 : menu.displayContactsAll();
                 tree.printPreorder(tree.Root());
                break;
        case 2 : menu.searchMenu(choice);
                 if(choice == 1)
                     search.searchPartial(tree);
                else
                     search.searchExact(tree);
                break;
        case 3 : menu.printContactsToFile();
                break;
        case 4 : menu.addContact(choice);
                 if(choice == 1)
                     add.fromFile(tree);
                 else
                     add.manual(tree);
                break;
        case 5 : menu.editContact(choice);
                break;
        case 6 : menu.deleteContact(choice);
                break;
        case 7 :
                break;
        default: cout << "Please enter a valid option" << endl;
        }
    }while(choice != 7);
}