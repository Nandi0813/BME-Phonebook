//
// Created by Dukát Nándor on 2023. 04. 24..
//

#ifndef PROJECT_ADDRESS_H
#define PROJECT_ADDRESS_H

#include "memtrace.h"
#include "string.h"

class Address
{
private:
    String postcode; // Irányítószám
    String city; // Ország
    String street; // Utca
    String houseNumber; // Házszám
public:
    /*
     * Konsturktor
     * Beállítja az attribútumokat
     */
    Address(const String& postcode, const String& city, const String& street, const String& number)
    {
        this->postcode = postcode;
        this->city = city;
        this->street = street;
        this->houseNumber = number;
    }

    /*
     * Irányítószám getter
     * @return - postcode
     */
    String getPostcode() const { return postcode; }
    /*
     * Irányítósztám setter
     * @param s - új postcode
     */
    void setPostcode(const String& s) { this->postcode = s; }

    /*
     * Város getter
     * @return - city
     */
    String getCity() const { return city; }
    /*
     * Város setter
     * @param s - új város
     */
    void setCity(const String& s) { this->city = s; }

    /*
     * Utca getter
     * @return - street
     */
    String getStreet() const { return street; }
   /*
    * Utca setter
    * @param s - új utca
    */
    void setStreet(const String& s) { this->street = s; }

    /*
     * Házszám getter
     * @return - housenumber
     */
    String getHouseNumber() const { return houseNumber; }
    /*
     * Házszám setter
     * @param s - új házszám
     */
    void setHouseNumber(const String& s) { this->houseNumber = s; }

    // Default destruktor
    ~Address() = default;
};

/*
 * Kiírja a címet a kapott ostream-re.
 * @param os - ostream objektum
 * @param address - cím amit kiír a függvény
 * @return ostream
 */
inline std::ostream& operator<<(std::ostream& os, const Address& address)
{
    return os << address.getPostcode() << " " << address.getCity() << " " << address.getStreet() << " " << address.getHouseNumber();
}

#endif //PROJECT_ADDRESS_H