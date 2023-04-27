#include <iostream>

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
        std::cout << std::endl
                  << "e -> Kilépés" << std::endl
                  << "a -> Névjegy hozzáadása" << std::endl
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
            case 's':
                directory.searchContact();
                break;
            case '5':
                directory.saveData("data.txt");
                break;
            default:
                break;
        }
    }

    directory.saveData("data.txt");
}