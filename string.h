//
// Created by Dukát Nándor on 2023. 04. 23..
//

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include "memtrace.h"

class String
{
private:
    char *data; // char pointer
    size_t length; // szó hossza a \0 nélkül
public:
    /*
     * Konstruktor egy \0-val zárt stringből
     * @param s - char tömb
     */
    String(const char *s = "");
    /*
     * Konstruktor egy char-ból
     * @param c - char
     */
    String(char c);
    /*
     * Másoló konstruktor
     * @param s - String
     */
    String(const String&);

    /*
     * String-et vissza adja a függvény
     * @return data;
     */
    const char* getData() const { return data; }
    char* getData() { return data; };

    /*
     * Értékadó operátor
     * @param s - String
     */
    String& operator=(const String&);
    String& operator=(const char*);

    /*
     * Egyenlőség operátor - Összehasonlít két stringet
     * @param s - String
     * @return - Hasonlít-e a két string egymásra
     */
    bool operator==(const String&) const;

    /*
     * Egyenlőtlenség operátor - Összehasonlít két stringet
     * @param s - String
     * @return - Hasonlít-e a két string egymásra
     */
    bool operator!=(const String&) const;

    /*
     * Összeadó operátor - Összefűz két stringet
     * @param s - String amit hozzáad
     * @return - Az összefűzött string
     */
    String operator+(const String&) const;

    /*
     * Összeadó operátor - Összefűz egy stringet és egy char-t
     * @param c - Char amit hozzáad
     * @return - Az összefűzött string
     */
    String operator+(char) const;

    /*
     * Destruktor
     */
    ~String();
};

/*
 * Kiírja a stringet az ostream-re
 * @param os - ostream
 * @param string - string amit kiír
 * @return os
 */
std::ostream& operator<<(std::ostream& os, String const&);

/*
 * istream-ről beolvas egy stringet
 * @param is - istream
 * @param s0 - string amibe beolvas
 * @return is
 */
std::istream& operator>>(std::istream& is, String& s0);

#endif