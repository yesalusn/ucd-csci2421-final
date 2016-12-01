#include "AddContact.h"

void AddContact::fromFile(BSTree &tree)
{
    string filename;
    cout << "Please enter the name of the file from which contacts will be imported." << endl;
    getline(cin, filename);

    //adding each contact separated by a | 'pipe' character
    std::fstream infile;
    infile.open(filename, fstream::in);
    string line;

    if(infile.is_open() && infile.good())
    {
        while(getline(infile, line, '|'))
        {
            std::stringstream contactStream(line);
            Contact aContact;
            contactStream >> aContact;
            int key = aContact.getID();
            tree.addNode(key, aContact);
        }
    }
    infile.close();
}

void AddContact::manual(BSTree &tree)
{
    string value;
    int key;
    Contact aContact;
    cout << "Please fill in the values for each field" << endl;
    cout << "ID: " << endl;
    getline(cin, value);
    aContact.setID(std::stoi(value));
    key = aContact.getID();
    cout << "First Name: " << endl;
    getline(cin, value);
    aContact.setFName(value);
    cout << "Middle Name: " << endl;
    getline(cin, value);
    aContact.setMName(value);
    cout << "Last Name: " << endl;
    getline(cin, value);
    aContact.setLName(value);
    cout << "Company Name: " << endl;
    getline(cin, value);
    aContact.setCoName(value);
    cout << "Home Phone: " << endl;
    getline(cin, value);
    aContact.setHomeNum(value);
    cout << "Work Phone: " << endl;
    getline(cin, value);
    aContact.setWorkNum(value);
    cout << "Email: " << endl;
    getline(cin, value);
    aContact.setEmail(value);
    cout << "Mobile Phone: " << endl;
    getline(cin, value);
    aContact.setMobileNum(value);
    cout << "Street Address: (do not include City, State and Zip)" << endl;
    getline(cin, value);
    aContact.setStAddress(value);
    cout << "City: " << endl;
    getline(cin, value);
    aContact.setCity(value);
    cout << "State: " << endl;
    getline(cin, value);
    aContact.setState(value);
    cout << "Zip Code: " << endl;
    getline(cin, value);
    aContact.setZip(value);
    cout << "Country: " << endl;
    getline(cin, value);
    aContact.setCountry(value);
    do
    {
        affiliate a;
        cout << "If you would like to add affilliates, type an entry.\nPress the star (*) key when finished." << endl;
        cout << "First Name: " << endl;
        getline(cin, value);
        if(value == "*") break;
        a.__first_name = value;
        cout << "Last Name: " << endl;
        getline(cin, a.__last_name);
        cout << "Phone: " << endl;
        getline(cin, value);
        if(value == "*")
        {
            aContact.addAffiliate(a);
            break;
        }
        a.__phone = value;
        cout << "Email: " << endl;
        getline(cin, value);
        if(value == "*")
        {
            aContact.addAffiliate(a);
            break;
        }
        a.__email = value;
        aContact.addAffiliate(a);
    }while(value != "*");
    tree.addNode(key, aContact);
}