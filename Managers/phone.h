//
// Created by Dukát Nándor on 2023. 04. 24..
//

#ifndef PROJECT_PHONE_H
#define PROJECT_PHONE_H

#include "String.h"

class Phone {
private:
    String work_number;
    String private_number;
public:
    Phone(const String& work_number, const String& private_number)
    {
        this->work_number = work_number;
        this->private_number = private_number;
    }

    String getWorkNumber() const { return work_number; }
    void setWorkNumber(const String &s) { this->work_number = s; }

    String getPrivateNumber() const { return private_number; }
    void setPrivateNumber(const String &s) { this->private_number = s; }

    bool operator==(const Phone& p) const
    {
        if (work_number != p.getWorkNumber()) return false;
        if (private_number != p.getPrivateNumber()) return false;
        return true;
    }

    ~Phone() = default;
};

#endif //PROJECT_PHONE_H
