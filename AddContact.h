#ifndef ADDCONTACT_H
#define ADDCONTACT_H

#include <fstream>
#include <sstream>
#include "BSTree.h"
#include "Contact.h"

class AddContact
{
public:
    void fromFile(BSTree &);
    void manual(BSTree &);
};


#endif // ADDCONTACT_H
