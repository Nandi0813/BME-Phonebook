//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include <iostream>
#include <fstream>
#include "contact.h"
#include "list.h"

class Directory
{
private:
    List<Contact*> contacts;
public:
    Directory();

    List<Contact*> getContacts();

    void addContact();

    void importData(const char *);
    void saveData(const char *) const;

    void searchContact();
    bool modifyContact(Contact *contact);
    void listContacts();

    Contact* searchByNumber(const String&) const;

    static String readInString();

    ~Directory() = default;
};