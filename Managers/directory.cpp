//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include "directory.h"

Directory::~Directory()
{
    for (int i = 0; i < size; i++)
        delete contacts[i];
    delete[] contacts;
}

void Directory::addContact(Contact &contact)
{
    try {
        auto **tempDirectory = new Contact*[size + 1];

        for (int i = 0; i < size; i++)
            tempDirectory[i] = contacts[i];
        delete[] contacts;

        contacts = tempDirectory;
        contacts[size++] = new Contact(contact);
    } catch(std::bad_alloc&) {
        std::cout << "Hiba történt a telefonkönyv memória foglalása közben!";
    }
}

bool Directory::deleteContact(Contact &contact)
{
    for (int i = 0; i < size; i++)
    {
        if (*contacts[i] == contact)
        {
            size--;
            auto **tempDirectory = new Contact*[size];

            return true;
        }
    }
    return false;
}
