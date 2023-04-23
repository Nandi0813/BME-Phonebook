//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include <cstring>
#include <iostream>

#include "String.h"

using std::endl;

class Contact
{
private:
    String last_name;
    String first_name;
    String nickname;
    String address;
    String work_number;
    String private_number;
public:
    Contact() = default;

    Contact(const String& last_name, const String& first_name, const String& nickname, const String& address, const String& work_number, const String& private_number);

    String getLastname() const { return last_name; }
    void setLastname(const String &s) { this->last_name = s; }

    String getFirstname() const { return first_name; }
    void setFirstname(const String &s) { this->first_name = s; }

    String getFullname() const { return first_name + " " + last_name; }

    String getNickname() const { return nickname; }
    void setNickname(const String &s) { this->nickname = s; }

    String getAddress() const { return address; }
    void setAddress(const String &s) { this->address = s; }

    String getWorkNumber() const { return work_number; }
    void setWorkNumber(const String &s) { this->work_number = s; }

    String getPrivateNumber() const { return private_number; }
    void setPrivateNumber(const String &s) { this->private_number = s; }

    void print(std::ostream& os);

    bool operator==(const Contact&) const;

    ~Contact() = default;
};