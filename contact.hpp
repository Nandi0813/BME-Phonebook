//
// Created by Dukát Nándor on 2023. 04. 23..
//

#ifndef PROJECT_CONTACT_HPP
#define PROJECT_CONTACT_HPP

#include <iostream>
#include "memtrace.h"

#include "string.h"
#include "name.h"
#include "address.h"
#include "phone.h"

using std::endl;

/*
 * ContactType
 * Fájlba íráshoz és fájlból olvasáshoz szükséges enum.
 */
enum ContactType {
    person, company
};

class Contact
{
protected:
    Address address; // Cím
    Phone phone; // Telefonszám
public:
    /*
     * Konstruktor
     * Beállítja az attribútumokat
     *
     * @param address - Cím
     * @param phone - Telefonszám
     */
    Contact(const Address &address, const Phone &phone)
            : address(address), phone(phone) {}

    /*
     * Cím getter
     * @return address& - Vissza adja a cím referenciáját.
     */
    Address& getAddress() { return address; }

    /*
     * Telefonszám getter
     * @return phone& - Vissza adja a telefonszám referenciáját.
     */
    Phone& getPhone() { return phone; }

    /*
     * Teljesen virtuális print függvény.
     * @param ostream& - ostream objektum
     */
    virtual std::ostream& print(std::ostream&) const = 0;

    /*
     * Fájlba ment
     * Teljesen virtuális függvény.
     * @param ostream& - ostream objektum
     */
    virtual void saveToFile(std::ostream&) const = 0;

    /*
     * Összehasonlítja az objektumot és a @param -ként kapott Contact& objektumot.
     */
    bool operator==(const Contact& c) const {
        if (phone.getNumber() == c.phone.getNumber()) return true;
        return false;
    }

    /*
     * Default destruktor.
     */
    virtual ~Contact() = default;
};

/*
 * Személy osztály örököl a Contact absztrakt osztálytól.
 */
class Person : public Contact
{
private:
    Name name; // A személy neve
public:
    /*
     * Konstruktor
     * Beállítja az attribútumokat
     *
     * @param n - Név
     * @param address - Cím
     * @param phone - Telefonszám
     */
    Person(const Name &n, const Address &address, const Phone &phone) : Contact(address, phone)
    {
        this->name = n;
    }

    /*
     * Név getter
     */
    Name& getName() { return name; }

    /*
     * Kíírja a személy adatait a paraméterként kapott ostream objektumra.
     * @param os - ostream objektum
     */
    std::ostream& print(std::ostream& os) const override {
        return os << "Személy Adatok : " << name.getFullname() << " " << name.getNickname() << " " << address << " " << phone.getNumber() << endl;
    }

    /*
     * Fájlba menti a személy adatait.
     * @param os - ostream objektum
     */
    void saveToFile(std::ostream& os) const override
    {
        os
                << person << endl
                << name.getLastname() << endl
                << name.getFirstname() << endl
                << name.getNickname() << endl
                << address.getPostcode() << endl
                << address.getCity() << endl
                << address.getStreet() << endl
                << address.getHouseNumber() << endl
                << phone.getNumber() << endl;
    }
};

/*
 * Cég osztály örököl a Contact absztrakt osztálytól.
 */
class Company : public Contact
{
private:
    String name;
public:
    /*
     * Konstruktor
     * Beállítja az attribútumokat
     *
     * @param n - Név
     * @param address - Cím
     * @param phone - Telefonszám
     */
    Company(const String &name, const Address &address, const Phone &phone)
            : Contact(address, phone) {
        this->name = name;
    }

    /*
     * Név getter
     */
    String& getName() { return name; }
    /*
     * Név setter
     * @param n - új név
     */
    void setName(const String& n) { name = n; }

    /*
     * Kíírja a cég adatait a paraméterként kapott ostream objektumra.
     * @param os - ostream objektum
     */
    std::ostream& print(std::ostream& os) const override {
        return os << "Cég Adatok : " << name << " " << address << " " << phone.getNumber() << endl;
    }

    /*
     * Fájlba menti a cég adatait.
     * @param os - ostream objektum
     */
    void saveToFile(std::ostream& os) const override
    {
        os
                << company << endl
                << name << endl
                << address.getPostcode() << endl
                << address.getCity() << endl
                << address.getStreet() << endl
                << address.getHouseNumber() << endl
                << phone.getNumber() << endl;
    }
};

#endif //PROJECT_CONTACT_HPP