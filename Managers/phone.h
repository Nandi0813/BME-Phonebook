//
// Created by Dukát Nándor on 2023. 04. 24..
//

#ifndef PROJECT_PHONE_H
#define PROJECT_PHONE_H

#include "String.h"

class Phone
{
private:
    String number;
public:
    Phone(const String& number) {
        this->number = number;
    }

    String getNumber() const { return number; }
    void setNumber(const String &s) { this->number = s; }

    bool operator==(const Phone& p) const
    {
        if (number != p.getNumber()) return false;
        return true;
    }

    ~Phone() = default;
};

#endif //PROJECT_PHONE_H
