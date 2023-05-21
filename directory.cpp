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

Contact *Directory::searchByNumber(const String &s) const
{
    for (auto contact : contacts)
        if (contact->getPhone().getNumber() == s)
            return contact;
    return nullptr;
}

void Directory::listContacts(std::ostream& os)
{
    if (contacts.getSize() == 0)
    {
        cout << endl << "A telefönkönyv üres." << endl;
        return;
    }

    for (int i = 0; i < contacts.getSize(); i++)
        contacts[i]->print(os);
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
                    contacts.add(new Person(Name(lastName, firstName, nickname),
                                            Address(postcode, city, street, houseNumber), Phone(phoneNum)));
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

    // Névjegyek adatainak beírása.
    for (auto contact : contacts)
        contact->saveToFile(file);

    file.close();
}
