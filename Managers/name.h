//
// Created by Dukát Nándor on 2023. 04. 24..
//

#ifndef PROJECT_NAME_H
#define PROJECT_NAME_H

#include "String.h"

class Name {
private:
    String last_name;
    String first_name;
    String nickname;
public:
    Name(const String& last_name, const String& first_name, const String& nickname)
    {
        this->last_name = last_name;
        this->first_name = first_name;
        this->nickname = nickname;
    }

    String getLastname() const { return last_name; }
    void setLastname(String& s) { this->last_name = s; }

    String getFirstname() const { return first_name; }
    void setFirstname(String& s) { this->first_name = s; }

    String getNickname() const { return nickname; }
    void setNickname(String& s) { this->nickname = s; }

    String getFullname() const { return first_name + " " + last_name; }

    ~Name() = default;
};

#endif //PROJECT_NAME_H
