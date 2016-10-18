//
// Created by Nikki on 4/30/2016.
//

#ifndef FINALPROJECT_CONTACT_H
#define FINALPROJECT_CONTACT_H

#include <iostream>
#include <string>
#include <list>
#include <sstream>

using std::string;
using std::list;
using std::ostream;
using std::istream;
using std::stringstream;

namespace __yesalusky_database
{
    struct affiliate
    {
        string __first_name;
        string __last_name;
        unsigned __phone;
        string __email;
        bool operator==(affiliate b)
        {return (__first_name == b.__first_name) && (__last_name == b.__last_name)
                && (__email == b.__email) && (__phone == b.__phone);};
    };
    class Contact
    {
        unsigned __id;
        string __first_name;
        string __middle_name;
        string __last_name;
        string __company_name;
        unsigned __home_phone;
        unsigned __mobile_phone;
        unsigned __work_phone;
        unsigned __street_num;
        string __street_name;
        string __city;
        string __state;
        unsigned __zip_code;
        string __country;
        string __email;
        list<affiliate> __contact_affiliates;

    public:

        //all constructors come with an id either generated or copied
        Contact(); // default constructor, empty strings for first and last names
        Contact(unsigned , string,string); // typical constructor, first and last names
        Contact(unsigned , string, string, string, string, unsigned, unsigned, unsigned,
                unsigned , string, string, string, unsigned, string, string, list<affiliate>&); // full constructor
        Contact(const Contact &);
        Contact &operator=(const Contact &);
        ~Contact();
        string idPadder(const unsigned&) const;
        //accessors
        void setID(unsigned);
        void setFName(string);
        void setMName(string);
        void setLName(string);
        void setCoName(string);
        void setHomeNum(unsigned);
        void setMobileNum(unsigned);
        void setWorkNum(unsigned);
        void setStreetNum(unsigned);
        void setStreetName(string);
        void setState(string);
        void setZip(unsigned);
        void setCountry(string);
        void setEmail(string);
        void addAffiliate(affiliate);
        //mutators
        int getID() const;
        string getFName() const;
        string getLName() const;
        string getCoName() const;
        unsigned getHomeNum() const;
        unsigned getMobile() const;
        unsigned getWorkNum() const;

        list<affiliate> getAffiliates() const;

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
}

#endif //FINALPROJECT_CONTACT_H
