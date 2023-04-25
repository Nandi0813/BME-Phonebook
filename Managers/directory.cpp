//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include "directory.h"

using std::cout;
using std::cin;
using std::endl;

void Directory::addContact()
{
    ContactType contactType = null;
    while (contactType == 0) {
        String s;
        cout << endl << "Add meg, hogy milyen típusú kontaktot szeretnél felvinni a rendszerbe." << endl << "Személy : sz - Cég: c ";
        cin >> s;

        if (s != "sz" && s != "c")
            cout << endl << "Használd a 'sz' vagy 'c' betűk egyikét." << endl;
        else
        {
            if (s == "sz")
                contactType = person;
            else
                contactType = company;
        }
    }

    String last_name;
    while (last_name.getLength() == 0)
    {
        String s;
        cout << "Add meg a vezeték nevet: ";
        cin >> s;

        if (s.getLength() < 2)
            cout << endl << "A vezetéknévnek legalább 2 betűből kell álni." << endl;
        else
            last_name = s;
    }

    String first_name;
    while (first_name.getLength() == 0)
    {
        String s;
        cout << "Add meg a kereszt nevet: ";
        cin >> s;

        if (s.getLength() < 2)
            cout << endl << "A keresztnévnek legalább 2 betűből kell álni." << endl;
        else
            first_name = s;
    }

    String nickname;
    while (nickname.getLength() == 0)
    {
        String s;
        cout << "Add meg a becenevet: ";
        cin >> s;

        if (s.getLength() < 2)
            cout << endl << "A becenévnek legalább 2 betűből kell álni." << endl;
        else
            nickname = s;
    }

    String postcode;
    while (postcode.getLength() == 0)
    {
        String s;
        cout << "Add meg az irányító számot: ";
        cin >> s;

        if (s.getLength() != 4)
            cout << endl << "Az irányító számnak 4 betűből kell álni." << endl;
        else
            postcode = s;
    }

    String city;
    while (city.getLength() == 0)
    {
        String s;
        cout << "Add meg a várost: ";
        cin >> s;

        if (s.getLength() > 0)
            city = s;
    }

    String street;
    while (street.getLength() == 0)
    {
        String s;
        cout << "Add meg az utcát: ";
        cin >> s;

        if (s.getLength() > 0)
            street = s;
    }

    String housenumber;
    while (housenumber.getLength() == 0)
    {
        String s;
        cout << "Add meg a ház számot: ";
        cin >> s;

        if (s.getLength() > 0)
            housenumber = s;
    }

    String phonenumber;
    while (phonenumber.getLength() == 0)
    {
        String s;
        cout << "Add meg a telefonszámot: ";
        cin >> s;

        if (s.getLength() != 11)
            cout << endl << "Az telefonszámnak pontosan 11 karakterből kell álni." << endl;
        else if (s[0] != '0' || s[1] != '6')
            cout << endl << "A telefonszám a következő formátumot kell, hogy kövesse: 06301234567 (06-al kell kezdődnie)" << endl;
        else
            phonenumber = s;
    }

    addContact(contactType, Name(last_name, first_name, nickname), Address(postcode, city, street, housenumber), Phone(phonenumber));
}

void Directory::addContact(ContactType contactType, const Name& name, const Address& address, const Phone& phone)
{
    try
    {
        auto **tempDirectory = new Contact*[size + 1];
        for (int i = 0; i < size; i++)
            tempDirectory[i] = contacts[i];
        delete[] contacts;
        contacts = tempDirectory;

        if (contactType == company)
            contacts[size++] = new Company(name, address, phone);
        else
            contacts[size++] = new Person(name, address, phone);

        cout << endl << "Sikeresen hozzáadtál egy új névjegyet!";
    } catch(std::bad_alloc&) {
        std::cout << "Hiba történt a kontakt hozzáadása közben!";
    }
}

void Directory::listContacts()
{
    if (size == 0)
    {
        cout << endl << "A telefönkönyv üres." << endl;
        return;
    }

    for (int i = 0; i < size; i++)
        contacts[i]->print(cout);
}

bool Directory::deleteContact(Contact *contact)
{
    for (int i = 0; i < size; i++)
    {
        if (contacts[i] == contact)
        {
            auto **tempDirectory = new Contact*[size];
            int count = 0;

            for (int j = 0; j < size; j++)
            {
                if (j == i) continue;
                tempDirectory[count++] = contacts[j];
            }
            size--;

            return true;
        }
    }
    return false;
}

Directory::~Directory()
{
    for (int i = 0; i < size; i++)
        delete contacts[i];
    delete[] contacts;
}

Contact *Directory::searchByNumber(const String &s) const
{
    for (int i = 0; i < size; i++)
        if (contacts[i]->getPhone() == s)
            return contacts[i];
    return nullptr;
}

void Directory::importData(String &fileName)
{
    std::ifstream file(fileName.getData());
    if (!file || !file.is_open())
        throw "Nem sikerült beolvasni a telefonkönyv fájlt.";

    int size = 0;
    file >> size;

    if (size <= 0) return;

    std::string fasz;
    while (getline(file, fasz)) {
        // Output the text from the file
        std::cout << fasz;
    }
}

void Directory::saveData(String &) {

}
