//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include <iostream>
#include <fstream>
#include "contact.h"
#include "list.hpp"

class Directory
{
private:
    List<Contact*> contacts;
public:
    Directory();

    void importData(const char *);
    void saveData(const char *) const;

    void listContacts();

    Contact* searchByNumber(const String&) const;

    ~Directory() = default;
};