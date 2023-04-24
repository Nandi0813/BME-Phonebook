//
// Created by Dukát Nándor on 2023. 04. 23..
//
#include "contact.h"

void Contact::print(std::ostream& os, bool lastLine)
{
    os
            << "============================================" << endl
            << "Keresztnév: " << name.getFirstname() << ", " << "Vezetéknév: " << name.getLastname() << ", Becenév: " << name.getNickname() << endl
            // << "Teljes név: " << getFullname() << endl
            << "Cím: " << address << endl
            << "Munkahelyi szám: " << phone.getWorkNumber() << endl
            << "Privát szám: " << phone.getPrivateNumber() << endl;
    if (lastLine)
        os << "============================================" << endl;
}

bool Contact::operator==(const Contact &c) const
{
    return phone == c.getPhone();
}
