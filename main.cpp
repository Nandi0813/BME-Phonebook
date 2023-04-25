#include <iostream>

#include "Libs/gtest_lite.h"
#include "Managers/directory.h"

using std::cout;
using std::cin;

int main()
{
    Directory directory;

    bool cycle = true;
    while (cycle)
    {
        char command;
        std::cout << "\n"
                  << "e -> Kilépés" << std::endl
                  << "a -> Névjegy hozzáadása" << std::endl
                  << "d -> Névjegy törlése" << std::endl
                  << "l -> Névjegyek listázása" << std::endl
                  << "s -> Keresés a névjegyek között" << std::endl
                  << "5 -> Névjegyek mentése" << std::endl
                  << "Írd be a betűt: ";
        cin >> command;
        switch (command)
        {
            case 'e':
                cycle = false;
                break;
            case 'a':
                directory.addContact();
                break;
            case 'l':
                directory.listContacts();
                break;
            default:
                break;
        }
    }
    /*
    Contact contact = Contact(Name("Dukát", "Nándor", "Nándi"), Address("2045", "Törökbálint", "Meggyes utca", "19.2"), Phone("+36309383747", "+36306106664"));
    contact.print(std::cout);
    directory.addContact(contact);
     */
}