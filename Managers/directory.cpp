//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include "directory.h"

using std::cout;
using std::endl;

Directory::Directory()
{
    this->importData("data.txt");
}

void Directory::listContacts()
{
    if (contacts.getSize() == 0)
    {
        cout << endl << "A telefönkönyv üres." << endl;
        return;
    }

    for (int i = 0; i < contacts.getSize(); i++)
        contacts[i]->print(cout);
}

Contact *Directory::searchByNumber(const String &s) const
{
    for (int i = 0; i < contacts.getSize(); i++)
        if (contacts[i]->getPhone().getNumber() == s)
            return contacts[i];
    return nullptr;
}

void Directory::importData(const char* fileName)
{
    std::ifstream file(fileName);
    if (!file || !file.is_open())
        throw "Nem sikerült beolvasni a telefonkönyv fájlt.";

    int size = 0;
    file >> size;

    if (size > 0)
    {
        for (int i = 0; i < size; i++)
        {
            int cT;
            file >> cT;
            auto contactType = ContactType(cT);

            String companyName, lastName, firstName, nickname, postcode, city, street, houseNumber, phoneNum;

            switch (contactType)
            {
                case person:
                    file >> lastName;
                    file >> firstName;
                    file >> nickname;
                    file >> postcode;
                    file >> city;
                    file >> street;
                    file >> houseNumber;
                    file >> phoneNum;
                    contacts.add(new Person(Name(lastName, firstName, nickname), Address(postcode, city, street, houseNumber), Phone(phoneNum)));
                    break;
                case company:
                    file >> companyName;
                    file >> postcode;
                    file >> city;
                    file >> street;
                    file >> houseNumber;
                    file >> phoneNum;
                    contacts.add(new Company(companyName, Address(postcode, city, street, houseNumber), Phone(phoneNum)));
                    break;
            }
        }
    }

    file.close();
}

void Directory::saveData(const char* fileName) const
{
    // File beolvasás
    std::ofstream file(fileName);
    if (!file || !file.is_open())
        throw "Nem sikerült beolvasni a telefonkönyv fájlt.";

    // Névjegyek méretének beírása a file-ba.
    file << contacts.getSize() << std::endl;

    if (contacts.getSize() > 0)
    {
        // Névjegyek adatainak beírása.
        for (int i = 0; i < contacts.getSize(); i++)
            contacts[i]->saveToFile(file);
    }

    file.close();
}
