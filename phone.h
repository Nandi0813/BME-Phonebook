//
// Created by Dukát Nándor on 2023. 04. 24..
//

#ifndef PROJECT_PHONE_H
#define PROJECT_PHONE_H

#include "string.h"
#include "memtrace.h"

class Phone
{
private:
    String number; // Telefonszám
public:
    /*
     * Konstruktor
     *
     * @param number - Telefonszám
     */
    Phone(const String& number) {
        this->number = number;
    }

    /*
     * Telefonszám getter
     * @return - number
     */
    String getNumber() const { return number; }
    /*
     * Telefonszám setter
     * @param s - új telefonszám
     */
    void setNumber(const String& s) { this->number = s; }

    /*
     * Default destruktor
     */
    ~Phone() = default;
};

#endif //PROJECT_PHONE_H
