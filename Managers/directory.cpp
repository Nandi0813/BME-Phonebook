//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include "directory.h"

using std::cout;
using std::cin;
using std::endl;

void Directory::addContact()
{
    String last_name;
    while (last_name.getLength() == 0)
    {
        String s;
        cout << endl << "Add meg a vezeték nevet: ";
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

    String number;
    while (number.getLength() == 0)
    {
        String s;
        cout << "Add meg a ház számot: ";
        cin >> s;

        if (s.getLength() > 0)
            number = s;
    }

    String worknumber;
    while (worknumber.getLength() == 0)
    {
        String s;
        cout << "Add meg a munkahelyi telefonszámot: ";
        cin >> s;

        if (s.getLength() != 11)
            cout << endl << "Az telefonszámnak pontosan 11 karakterből kell álni." << endl;
        else if (s[0] != '0' || s[1] != '6')
            cout << endl << "A telefonszám a következő formátumot kell, hogy kövesse: 06301234567 (06-al kell kezdődnie)" << endl;
        else
            worknumber = s;
    }

    String privatenumber;
    while (privatenumber.getLength() == 0)
    {
        String s;
        cout << "Add meg a privát telefonszámot: ";
        cin >> s;

        if (s.getLength() != 11)
            cout << endl << "Az telefonszámnak pontosan 11 karakterből kell álni." << endl;
        else if (s[0] != '0' || s[1] != '6')
            cout << endl << "A telefonszám a következő formátumot kell, hogy kövesse: 06301234567 (06-al kell kezdődnie)" << endl;
        else
            privatenumber = s;
    }

    Contact contact(Name(last_name, first_name, nickname), Address(postcode, city, street, number), Phone(worknumber, privatenumber));
    addContact(contact);
    cout << endl << "Sikeresen hozzáadtál egy új névjegyet!";
}

void Directory::listContacts()
{
    if (size == 0)
    {
        cout << endl << "A telefönkönyv üres." << endl;
        return;
    }

    for (int i = 0; i < size; i++)
        contacts[i]->print(cout, false);
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

Contact *Directory::searchByNumber(const String &s, Directory::numberType numberType) const
{
    for (int i = 0; i < size; i++)
    {
        switch (numberType) {
            case work:
                if (contacts[i]->getPhone().getWorkNumber() == s) return contacts[i];
                continue;
            case priv:
                if (contacts[i]->getPhone().getPrivateNumber() == s) return contacts[i];
                continue;
        }
    }
    return nullptr;
}

void Directory::importData(String &fileName)
{
    std::ifstream file(fileName.getData());
    if (!file)
        throw "Nem sikerült beolvasni a telefonkönyv fájlt.";
    if (!file.is_open()) return;

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
