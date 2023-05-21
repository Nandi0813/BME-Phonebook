//
// Created by Dukát Nándor on 2023. 04. 23..
//

#ifndef PROJECT_DIRECTORY_H
#define PROJECT_DIRECTORY_H

#include <iostream>
#include <fstream>
#include "memtrace.h"

#include "contact.hpp"
#include "list.hpp"

class Directory
{
private:
    List<Contact*> contacts; // Névjegy adatok
public:
    // Default konstruktor
    Directory();

    /*
     * Kontakt lista getter
     * @return contacts referencia
     */
    List<Contact*>& getContacts() { return contacts; }

    /*
     * Importálja fájlból a telefönkönyv adatait.
     * @param char - fájl neve
     */
    void importData(const char *);
    /*
     * Menti a telefonkönyv adatait egy fájlba.
     * @param char - fájl neve
     */
    void saveData(const char *) const;

    /*
     * Telefonszám alapján keres a kontaktok listában
     * @param string - telefonszám
     * @return - A talált kontakt
     */
    Contact* searchByNumber(const String&) const;

    /*
     * Default destruktor
     */
    ~Directory() = default;
};

#endif //PROJECT_DIRECTORY_H