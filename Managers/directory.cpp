//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include "directory.h"
#include <string>

using std::cout;
using std::endl;

void Directory::addContact()
{
    std::cin.ignore();
    ContactType contactType = null;
    while (contactType == 0)
    {
        cout << endl << "Add meg, hogy milyen típusú kontaktot szeretnél felvinni a rendszerbe." << endl << "Személy : sz - Cég: c ";
        String s = readInString();

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
        cout << "Add meg a vezeték nevet: ";
        String s = readInString();

        if (s.getLength() < 2)
            cout << endl << "A vezetéknévnek legalább 2 betűből kell álni." << endl;
        else
            last_name = s;
    }

    String first_name;
    while (first_name.getLength() == 0)
    {
        cout << "Add meg a kereszt nevet: ";
        String s = readInString();

        if (s.getLength() < 2)
            cout << endl << "A keresztnévnek legalább 2 betűből kell álni." << endl;
        else
            first_name = s;
    }

    String nickname;
    while (nickname.getLength() == 0)
    {
        cout << "Add meg a becenevet: ";
        String s = readInString();

        if (s.getLength() < 2)
            cout << endl << "A becenévnek legalább 2 betűből kell álni." << endl;
        else
            nickname = s;
    }

    String postcode;
    while (postcode.getLength() == 0)
    {
        cout << "Add meg az irányító számot: ";
        String s = readInString();

        if (s.getLength() != 4)
        {
            cout << endl << "Az irányító számnak 4 betűből kell álni." << endl;
            cout << s.getLength();
        }
        else
            postcode = s;
    }

    String city;
    while (city.getLength() == 0)
    {
        cout << "Add meg a várost: ";
        String s = readInString();

        if (s.getLength() > 0)
            city = s;
    }

    String street;
    while (street.getLength() == 0)
    {
        cout << "Add meg az utcát: ";
        String s = readInString();

        if (s.getLength() > 0)
            street = s;
    }

    String housenumber;
    while (housenumber.getLength() == 0)
    {
        cout << "Add meg a ház számot: ";
        String s = readInString();

        if (s.getLength() > 0)
            housenumber = s;
    }

    String phonenumber;
    while (phonenumber.getLength() == 0)
    {
        cout << "Add meg a telefonszámot: ";
        String s = readInString();

        if (s.getLength() != 11)
            cout << endl << "Az telefonszámnak pontosan 11 karakterből kell álni." << endl;
        else if (s[0] != '0' || s[1] != '6')
            cout << endl << "A telefonszám a következő formátumot kell, hogy kövesse: 06301234567 (06-al kell kezdődnie)" << endl;
        else if (searchByNumber(String() = s) != nullptr)
            cout << endl << "A telefonszám már foglalt!" << endl;
        else
            phonenumber = s;
    }

    addContact(contactType, Name(last_name, first_name, nickname), Address(postcode, city, street, housenumber), Phone(phonenumber));
    cout << endl << "Sikeresen hozzáadtál egy új névjegyet!";
}

bool Directory::addContact(ContactType contactType, const Name& name, const Address& address, const Phone& phone)
{
    switch (contactType)
    {
        case company:
            return addContact(new Company(name, address, phone));
        case person:
            return addContact(new Person(name, address, phone));
        default:
            return false;
    }
}

bool Directory::addContact(Contact *contact)
{
    try
    {
        auto **tempDirectory = new Contact*[size + 1];
        for (int i = 0; i < size; i++)
            tempDirectory[i] = contacts[i];

        delete[] contacts;
        contacts = tempDirectory;

        contacts[size++] = contact;

        return true;
    }
    catch(std::bad_alloc&) {
        return false;
    }
}

void Directory::searchContact()
{
    bool cycle = true;
    do {
        cout << endl << "Add meg a keresni kívánt névjegy telefonszámát. Ki tudsz lépni a keresésből az 'e' betű beírásával.";
        String input;
        std::cin >> input;

        if (input == 'e')
            cycle = false;
        else
        {
            Contact* contact = searchByNumber(input);
            if (contact == nullptr)
                cout << endl << "Kontak nem található;";
            else
            {
                if (modifyContact(contact))
                    cycle = false;
            }
        }
    }
    while (cycle);
}

bool Directory::modifyContact(Contact *contact)
{
    do {
        cout << endl << "Az alábbi kontaktot találtuk:" << endl;
        contact->print(cout);
        cout << endl << "Az alábbiakat tudod rajta végrehajtani:"
             << endl << "e -> Kilépés"
             << endl << "b -> Visszalépés"
             << endl << "d -> Törlés"
             << endl << "1 -> Vezetéknév módosítás"
             << endl << "2 -> Keresztnév módosítás"
             << endl << "3 -> Becenév módosítás"
             << endl << "4 -> Irányítószám módosítás"
             << endl << "5 -> Város módosítás"
             << endl << "6 -> Utca módosítás"
             << endl << "7 -> Házszám módosítás"
             << endl << "8 -> Telefonszám módosítás";

        char input;
        std::cin >> input;

        String first_name, last_name, nickname, postcode, city, street, housenum, phone;
        switch (input)
        {
            case 'e':
                return true;
            case 'b':
                return false;
            case 'd':
                deleteContact(contact);
                return true;
            case '1':
                do {
                    cout << "Add meg a vezeték nevet: ";
                    String s = readInString();

                    if (s.getLength() < 2)
                        cout << endl << "A vezetéknévnek legalább 2 betűből kell álni." << endl;
                    else
                        last_name = s;
                }
                while(last_name.getLength() == 0);
                contact->getName().setLastname(last_name);
                break;
            default:
                break;
        }
    } while (true);
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
            auto **tempDirectory = new Contact*[size - 1];

            int count = 0;
            for (int j = 0; j < size; j++)
            {
                if (j == i) continue;
                tempDirectory[count++] = contacts[j];
            }

            delete[] contacts;
            delete contact;

            contacts = tempDirectory;
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

bool Directory::contains(const Contact *contact) const
{
    for (int i = 0; i < size; i++)
        if (contacts[i] == contact)
            return true;
    return false;
}

Contact *Directory::searchByNumber(const String &s) const
{
    for (int i = 0; i < size; i++)
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
            int contactType;
            file >> contactType;

            String lastName;
            file >> lastName;

            String firstName;
            file >> firstName;

            String nickname;
            file >> nickname;

            String postcode;
            file >> postcode;

            String city;
            file >> city;

            String street;
            file >> street;

            String houseNumber;
            file >> houseNumber;

            String phoneNum;
            file >> phoneNum;

            if (!addContact(ContactType(contactType), Name(lastName, firstName, nickname), Address(postcode, city, street, houseNumber), Phone(phoneNum)))
                throw "Adatok fileból való beolvasása közben hiba történt!";
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
    file << size << std::endl;

    if (size > 0)
    {
        // Névjegyek adatainak beírása.
        for (int i = 0; i < size; i++)
            contacts[i]->saveToFile(file);
    }

    file.close();
}

String Directory::readInString()
{
    std::string readIn;
    getline(std::cin, readIn);
    String s = readIn;
    return s;
}
