//
// Created by Nikki on 4/30/2016.
//
#include <iostream>
#include <cmath>
#include <regex>

#include "Contact.h"

using std::cout;
using std::endl;

namespace __yesalusky_database
{
    unsigned int Contact::__idGen = 0;

    Contact::Contact():
    __id(++__idGen), __first_name(" "), __last_name(" ")
    {}

    Contact::Contact(string f_name, string l_name):
    __id(++__idGen), __first_name(f_name), __last_name(l_name)
    {}

    Contact::Contact(string f_name, string l_name, unsigned mobile):
    __id(++__idGen), __first_name(f_name), __last_name(l_name),
    __mobile_phone(mobile)
    {}

    Contact::Contact(const Contact& other):
    __id(other.__id), __first_name(other.__first_name),
    __middle_initial(other.__middle_initial), __last_name(other.__last_name),
    __company_name(other.__company_name), __home_phone(other.__home_phone),
    __mobile_phone(other.__mobile_phone), __work_phone(other.__work_phone),
    __email(other.__email)
    {
        if(!other.__contact_affiliates.empty())
        {
            __contact_affiliates = other.__contact_affiliates;
        }
    }

    Contact &Contact::operator=(const Contact &other)
    {
        if(this != &other)
        {
            __id = ++__idGen; __first_name = other.__first_name;
            __middle_initial = other.__middle_initial; __last_name = other.__last_name;
            __company_name = other.__company_name; __home_phone = other.__home_phone;
            __mobile_phone = other.__mobile_phone; __work_phone = other.__work_phone;
            __email = other.__email;

            if(!other.__contact_affiliates.empty())
            {
                __contact_affiliates = other.__contact_affiliates;
            }
        }
        return *this;
    }

    Contact::~Contact()
    {
        if(__contact_affiliates.size() > 0)
        {
            for(auto it = __contact_affiliates.begin(); it != __contact_affiliates.end(); ++it)
            {
                __contact_affiliates.erase(it);
            }
        }
    }

    string Contact::idPadder(const unsigned& __id) const
    {
        string prntbleID = "";
        prntbleID.reserve(9);
        prntbleID = std::to_string(__id);
        if(prntbleID.length() < 9)
        {
            prntbleID.insert(0, 9 - prntbleID.length(), '0');
        }
        return prntbleID;
    }

    //accessors
    void Contact::setFName(string f_name)
    { __first_name = f_name; }

    void Contact::setMInitial(char midI)
    { __middle_initial = midI; }

    void Contact::setLName(string l_name)
    { __last_name = l_name; }

    void Contact::setCo(string co_name)
    { __company_name = co_name; }

    void Contact::setHomeNum(unsigned ho_num)
    { __home_phone = ho_num; }

    void Contact::setMobile(unsigned mo_num)
    { __mobile_phone = mo_num; }

    void Contact::setWorkNum(unsigned wo_num)
    { __work_phone = wo_num; }

    void Contact::setEmail(string email)
    { __email = email; }

    void Contact::addAffiliate(affiliate new_affiliate)
    {
        __contact_affiliates.push_back(new_affiliate);
    }

    //mutators
    int Contact::getID() const
    { return __id; }

    string Contact::getFName() const
    { return __first_name; }

    string Contact::getLName() const
    { return __last_name; }

    string Contact::getCoName() const
    { return __company_name; }

    unsigned Contact::getHomeNum() const
    { return __home_phone; }

    unsigned Contact::getMobile() const
    { return __mobile_phone; }

    unsigned Contact::getWorkNum() const
    { return __work_phone; }

    list<affiliate> Contact::getAffiliates() const
    {
        return __contact_affiliates;
    }

    ostream &operator<<(ostream &os, const Contact &contact)
    {
        os << contact.idPadder(contact.__id) << '\n';
        os << contact.__first_name << '\n';
        os << contact.__middle_initial << '\n';
        os << contact.__last_name << '\n';
        os << contact.__company_name << '\n';
        os << contact.__home_phone << '\n';
        os << contact.__work_phone << '\n';
        os << contact.__email << '\n';
        os << contact.__mobile_phone << '\n';
        for(auto it = contact.__contact_affiliates.begin();
            it != contact.__contact_affiliates.end(); ++it)
        { os << *it << '\n';}
        os << "|\n";

        return os;
    }

    istream &operator>>(istream &is, Contact &contact)
    {
        return is;
    }
}