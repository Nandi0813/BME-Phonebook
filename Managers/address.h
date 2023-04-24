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
    String number;
public:
    Address(const String& postcode, const String& city, const String& street, const String& number)
    {
        this->postcode = postcode;
        this->city = city;
        this->street = street;
        this->number = number;
    }

    String getPostcode() const { return postcode; }
    void setPostcode(const String &s) { this->postcode = s; }

    String getCity() const { return city; }
    void setCity(const String &s) { this->city = s; }

    String getStreet() const { return street; }
    void setStreet(const String &s) { this->street = s; }

    String getNumber() const { return number; }
    void setNumber(const String &s) { this->number = s; }

    ~Address() = default;
};

inline std::ostream& operator<<(std::ostream& os, Address const& address) {
    return os << address.getPostcode() << " " << address.getCity() << " " << address.getStreet() << " " << address.getNumber();
}

#endif //PROJECT_ADDRESS_H
