//
// Created by Dukát Nándor on 2023. 04. 23..
//

#ifndef PROJECT_DIRECTORY_H
#define PROJECT_DIRECTORY_H

#include <iostream>
#include <fstream>
#include "memtrace.h"

#include "contact.h"
#include "list.hpp"

class Directory
{
private:
    List<Contact*> contacts;
public:
    Directory();

    List<Contact*>& getContacts() { return contacts; }

    void importData(const char *);
    void saveData(const char *) const;

    void listContacts();

    Contact* searchByNumber(const String&) const;

    ~Directory() = default;
};

#endif //PROJECT_DIRECTORY_H