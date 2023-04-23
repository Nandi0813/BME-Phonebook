//
// Created by Dukát Nándor on 2023. 04. 23..
//
#include "contact.h"

Contact::Contact(const String &last_name, const String &first_name, const String &nickname, const String &address, const String &work_number, const String &private_number)
{
    this->last_name = last_name;
    this->first_name = first_name;
    this->nickname = nickname;
    this->address = address;
    this->work_number = work_number;
    this->private_number = private_number;
}


void Contact::print(std::ostream &os)
{
    os
            << "============================================" << endl
            << "Keresztnév: " << first_name << ", " << "Vezetéknév: " << last_name << endl
            // << "Teljes név: " << getFullname() << endl
            << "Becenév: " << nickname << endl
            << "Cím: " << address << endl
            << "Munkahelyi szám: " << work_number << endl
            << "Privát szám: " << private_number << endl
            << "============================================"
            << endl;
}

bool Contact::operator==(const Contact &c) const
{
    if (work_number != c.work_number) return false;
    if (private_number != c.private_number) return false;
    return true;
}
