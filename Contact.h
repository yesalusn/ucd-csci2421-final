//
// Created by Nikki on 4/30/2016.
//

#ifndef FINALPROJECT_CONTACT_H
#define FINALPROJECT_CONTACT_H

#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;
using std::ostream;
using std::istream;

namespace __yesalusky_database
{
    struct affiliate
    {
        string __first_name;
        string __last_name;
        unsigned __phone;
        string __email;

        friend ostream& operator<<(ostream& os, const affiliate& af)
        {
            os << af.__first_name << "; ";
            os << af.__last_name << "; ";
            os << af.__phone << "; ";
            os << af.__email << "; ";

            return os;
        }
    };

    struct address
    {
        int __streetNum;
        string __streetName;
        string __city;
        string __state;
        unsigned __zip_code;
        char __country[3];

        friend ostream& operator<<(ostream& os, const address& ad)
        {
            os << ad.__streetNum << '\n';
            os << ad.__streetName << '\n';
            os << ad.__city << '\n';
            os << ad.__state << '\n';
            os << ad.__zip_code << '\n';
            os << ad.__country;

            return os;
        }
    };

    class Contact
    {
        static unsigned int __idGen;
        unsigned __id;
        string __first_name;
        char __middle_initial;
        string __last_name;
        string __company_name;
        unsigned __home_phone;
        unsigned __mobile_phone;
        unsigned __work_phone;
        address __home_address;
        string __email;
        list<affiliate> __contact_affiliates;

    public:

        Contact();

        Contact(string,string);

        Contact(string, string, unsigned);

        Contact(const Contact &);

        Contact &operator=(const Contact &);

        ~Contact();

        string idPadder(const unsigned&) const;

        //accessors
        void setFName(string);

        void setMInitial(char);

        void setLName(string);

        void setCo(string);

        void setHomeNum(unsigned);

        void setMobile(unsigned);

        void setWorkNum(unsigned);

        void setEmail(string);

        void setAddress(address);

        void addAffiliate(affiliate);

        //mutators
        int getID() const;

        string getFName() const;

        string getLName() const;

        string getCoName() const;

        unsigned getHomeNum() const;

        unsigned getMobile() const;

        unsigned getWorkNum() const;

        address getAddress() const;

        list<affiliate> getAffiliates() const;

        friend ostream &operator<<(ostream &, const Contact &);

        friend istream &operator>>(istream &, Contact &);
    };

    //operators
    bool operator==(const Contact& a, const Contact& b) { return a.getID() == b.getID(); };

    bool operator!=(const Contact& a, const Contact& b) { return !(a.getID() == b.getID()); };

    bool operator<(const Contact& a, const Contact& b) { return a.getID() < b.getID(); };

    bool operator>(const Contact& a, const Contact& b) { return (b.getID() < a.getID()); };

    bool operator>=(const Contact& a, const Contact& b) { return !(a.getID() < b.getID()); };

    bool operator<=(const Contact& a, const Contact& b) { return !(b.getID() < a.getID()); };
}

#endif //FINALPROJECT_CONTACT_H
