//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include <iostream>
#include "contact.h"

class Directory
{
private:
    int size;
    Contact **contacts;
public:
    Directory() : size(0), contacts(nullptr) {};

    int getSize() const { return size; }

    void addContact(Contact &contact);
    bool deleteContact(Contact &contact);

    ~Directory();
};