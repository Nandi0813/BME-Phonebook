//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include <iostream>
#include <fstream>
#include "contact.h"

class Directory
{
private:
    int size;
    Contact **contacts;
public:
    Directory() : size(0), contacts(nullptr) {};

    int getSize() const { return size; }

    void addContact();
    void addContact(ContactType contactType, const Name&, const Address&, const Phone&);
    bool deleteContact(Contact *contact);

    void importData(String&);
    void saveData(String&);

    void listContacts();

    Contact* searchByNumber(const String&) const;

    ~Directory();
};