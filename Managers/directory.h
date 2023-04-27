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
    Directory() : size(0), contacts(nullptr)
    {
        this->importData("data.txt");
    };

    int getSize() const { return size; }

    void addContact();
    bool addContact(ContactType contactType, const Name&, const Address&, const Phone&);
    bool addContact(Contact *contact);
    bool deleteContact(Contact *contact);

    void importData(const char *);
    void saveData(const char *) const;

    bool contains(const Contact *contact) const;
    void searchContact();
    bool modifyContact(Contact *contact);
    void listContacts();

    Contact* searchByNumber(const String&) const;

    static String readInString();

    ~Directory();
};