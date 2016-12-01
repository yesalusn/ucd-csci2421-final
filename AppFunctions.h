#ifndef APPFUNCTIONS_H
#define APPFUNCTIONS_H

#include "BSTree.h"
#include "Menu.h"
#include "SearchFunctions.h"
#include "Printing.h"
#include "AddContact.h"
#include "EditContact.h"
#include "DeleteContact.h"

class AppFunctions
{
    Menu menu;
    BSTree tree;
    SearchFunctions search;
    Printing printing;
    AddContact add;
    EditContact edit;
    DeleteContact deleteOne;
public:
    void application();
};


#endif // APPFUNCTIONS_H
