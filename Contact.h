#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <list>
#include <sstream>

using namespace std;

class affiliate
{
public:
    string __first_name;
    string __last_name;
    string __phone;
    string __email;
    bool operator==(affiliate b)
    {return (__first_name == b.__first_name) && (__last_name == b.__last_name)
            && (__email == b.__email) && (__phone == b.__phone);};

    friend istream& operator>>(istream& is, affiliate a);
};

class Contact
{
    int __id;
    string __first_name;
    string __middle_name;
    string __last_name;
    string __company_name;
    string __home_phone;
    string __work_phone;
    string __email;
    string __mobile_phone;
    string __street_address;
    string __city;
    string __state;
    string __zip_code;
    string __country;
    list<affiliate> __contact_affiliates;

public:
    //all constructors come with an id
    Contact(); // default constructor, empty strings for first and last names
    Contact(int , string,string); // typical constructor, first and last names
    Contact(int , string, string, string, string, string, string, string,
            string , string, string, string, string, string, list<affiliate>&); // full constructor
    Contact(const Contact &);
    Contact &operator=(const Contact &);
    ~Contact();
    string idPadder(const int&) const;
    //accessors
    void setID(int);
    void setFName(string);
    void setMName(string);
    void setLName(string);
    void setCoName(string);
    void setHomeNum(string);
    void setMobileNum(string);
    void setWorkNum(string);
    void setStAddress(string);
    void setCity(string);
    void setState(string);
    void setZip(string);
    void setCountry(string);
    void setEmail(string);
    void addAffiliate(affiliate);
    //mutators
    int getID() const;
    string getFName() const;
    string getMName() const;
    string getLName() const;
    string getCoName() const;
    string getHomeNum() const;
    string getMobile() const;
    string getWorkNum() const;
    string getStAddress() const;
    string getCity() const;
    string getState() const;
    string getZip() const;
    string getCountry() const;
    string getEmail() const;

    //inlined comparison & relational operators
    bool operator==(const Contact& b) { return getID() == b.getID(); };
    bool operator!=(const Contact& b) { return !(getID() == b.getID()); };
    bool operator<(const Contact& b) { return getID() < b.getID(); };
    bool operator>(const Contact& b) { return (b.getID() < getID()); };
    bool operator>=(const Contact& b) { return !(getID() < b.getID()); };
    bool operator<=(const Contact& b) { return !(b.getID() < getID()); };

    friend ostream &operator<<(ostream &, const Contact &);
    friend istream &operator>>(istream &, Contact &);
};

#endif // CONTACT_H
