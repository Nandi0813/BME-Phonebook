//
// Created by Dukát Nándor on 2023. 04. 24..
//

#ifndef PROJECT_ADDRESS_H
#define PROJECT_ADDRESS_H

#include "String.h"

class Address {
private:
    String postcode;
    String city;
    String street;
    String houseNumber;
public:
    Address(const String& postcode, const String& city, const String& street, const String& number)
    {
        this->postcode = postcode;
        this->city = city;
        this->street = street;
        this->houseNumber = number;
    }

    String getPostcode() const { return postcode; }
    void setPostcode(String& s) { this->postcode = s; }

    String getCity() const { return city; }
    void setCity(String& s) { this->city = s; }

    String getStreet() const { return street; }
    void setStreet(String& s) { this->street = s; }

    String getHouseNumber() const { return houseNumber; }
    void setHouseNumber(String& s) { this->houseNumber = s; }

    ~Address() = default;
};

inline std::ostream& operator<<(std::ostream& os, const Address& address) {
    return os << address.getPostcode() << " " << address.getCity() << " " << address.getStreet() << " " << address.getHouseNumber();
}

#endif //PROJECT_ADDRESS_H
