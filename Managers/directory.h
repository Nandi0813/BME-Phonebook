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
    enum numberType { work, priv };

    Directory() : size(0), contacts(nullptr) {};

    int getSize() const { return size; }

    void addContact();
    void addContact(Contact &contact);
    bool deleteContact(Contact *contact);

    void importData(String&);
    void saveData(String&);

    void listContacts();

    Contact* searchByNumber(const String&, numberType) const;

    ~Directory();
};