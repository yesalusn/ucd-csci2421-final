#include <iostream>
#include <cmath>
#include <regex>

#include "Contact.h"

//enum fields
//{
//    __id,
//    __first_name,
//    __middle_name,
//    __last_name,
//    __company_name,
//    __home_phone,
//    __work_phone,
//    __email,
//    __mobile_phone,
//    __street_address,
//    __city,
//    __state,
//    __zip_code,
//    __country,
//};
///TODO: save this guy for later

istream& operator>>(istream &is, affiliate a)
{
    getline(is, a.__first_name, ' ');
    getline(is, a.__last_name,',');
    if(is.good()) getline(is, a.__phone,',');
    if(is.good()) getline(is, a.__email);
}

Contact::Contact():
__id(0), __first_name(" "), __last_name(" ")
{}

Contact::Contact(int id, string f_name, string l_name):
__id(id), __first_name(f_name), __last_name(l_name)
{}

Contact::Contact(int id, string f_name, string m_name, string l_name, string c_name, string h_phone, string m_phone,
                 string w_phone, string s_add, string city, string state, string zip, string country, string email,
                list<affiliate>& affiliates):
__id(id), __first_name(f_name), __middle_name(m_name), __last_name(l_name), __company_name(c_name), __home_phone(h_phone), __mobile_phone(m_phone),
__work_phone(w_phone), __street_address(s_add), __city(city), __state(state), __zip_code(zip), __country(country), __email(email),
__contact_affiliates(affiliates)
{}

Contact::Contact(const Contact& other):
__id(other.__id), __first_name(other.__first_name), __middle_name(other.__middle_name), __last_name(other.__last_name),
__company_name(other.__company_name), __home_phone(other.__home_phone), __mobile_phone(other.__mobile_phone), __work_phone(other.__work_phone),
__street_address(other.__street_address), __city(other.__city), __state(other.__state), __zip_code(other.__zip_code),
__country(other.__country), __email(other.__email)
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
        __id = other.__id; __first_name = other.__first_name;
        __middle_name = other.__middle_name; __last_name = other.__last_name;
        __company_name = other.__company_name; __home_phone = other.__home_phone;
        __mobile_phone = other.__mobile_phone; __work_phone = other.__work_phone;
        __email = other.__email;

        if(!__contact_affiliates.empty())
        {
            if (!other.__contact_affiliates.empty())
            {
                __contact_affiliates = other.__contact_affiliates;
            }
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

string Contact::idPadder(const int& __id) const
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
void Contact::setID(int id)
{ __id = id; }

void Contact::setFName(string f_name)
{ __first_name = f_name; }

void Contact::setMName(string m_name)
{ __middle_name = m_name; }

void Contact::setLName(string l_name)
{ __last_name = l_name; }

void Contact::setCoName(string co_name)
{ __company_name = co_name; }

void Contact::setHomeNum(string ho_num)
{ __home_phone = ho_num; }

void Contact::setMobileNum(string mo_num)
{ __mobile_phone = mo_num; }

void Contact::setWorkNum(string wo_num)
{ __work_phone = wo_num; }

void Contact::setStAddress(string st_add)
{ __street_address = st_add; }

void Contact::setCity(string city)
{ __city = city; }

void Contact::setState(string state)
{ __state = state; }

void Contact::setZip(string zip)
{ __zip_code = zip; }

void Contact::setCountry(string country)
{ __country = country; }

void Contact::setEmail(string email)
{ __email = email; }

void Contact::addAffiliate(affiliate new_affiliate)
{ __contact_affiliates.push_back(new_affiliate); }

//mutators
int Contact::getID() const
{ return __id; }

string Contact::getFName() const
{ return __first_name; }

string Contact::getMName() const
{ return __middle_name; }

string Contact::getLName() const
{ return __last_name; }

string Contact::getCoName() const
{ return __company_name; }

string Contact::getHomeNum() const
{ return __home_phone; }

string Contact::getMobile() const
{ return __mobile_phone; }

string Contact::getWorkNum() const
{ return __work_phone; }

string Contact::getStAddress() const
{ return __street_address; }

string Contact::getCity() const
{ return __city; }

string Contact::getState() const
{ return __state; }

string Contact::getZip() const
{ return __zip_code; }

string Contact::getCountry() const
{ return __country; }

string Contact::getEmail() const
{ return __email; }

ostream &operator<<(ostream &os, const Contact &contact)
{
    stringstream ss;
    ss << contact.__id << '\n';
    ss << contact.__first_name << '\n';
    ss << contact.__middle_name << '\n';
    ss << contact.__last_name << '\n';
    ss << contact.__company_name << '\n';
    ss << contact.__home_phone << '\n';
    ss << contact.__work_phone << '\n';
    ss << contact.__email << '\n';
    ss << contact.__mobile_phone << '\n';
    ss << contact.__street_address << '\n';
    ss << contact.__city << '\n';
    ss << contact.__state << '\n';
    ss << contact.__country << '\n';
    ss << contact.__zip_code << '\n';
    auto it = contact.__contact_affiliates.begin();
    if(it->__first_name.size() > 1)
        ss << it->__first_name << "; ";
    if(it->__last_name.size() > 1)
        ss << it->__last_name << "; ";
    if(it->__phone.size() > 1)
        ss << it->__phone << "; ";
    if(it->__email.size() > 1)
        ss << it->__email << "; ";
    string contact_string = ss.str();
    os << contact_string;
    os << "\n|\n\n";

    return os;
}


istream &operator>>(istream &is, Contact &contact)
{
    string value;
    getline(is, value);
    contact.__id = std::stoi(value);
    getline(is, contact.__first_name);
    getline(is, contact.__middle_name);
    getline(is, contact.__last_name);
    getline(is, contact.__company_name);
    getline(is, contact.__home_phone);
    getline(is, contact.__work_phone);
    getline(is, contact.__email);
    getline(is, contact.__mobile_phone);
    getline(is, contact.__street_address);
    getline(is, contact.__city);
    getline(is, contact.__state);
    getline(is, contact.__country);
    getline(is, contact.__zip_code);
    while(is.good() && getline(is, value, ';'))
    {
        affiliate a;
        is >> a;
        contact.__contact_affiliates.push_back(a);
    }
    return is;
}
