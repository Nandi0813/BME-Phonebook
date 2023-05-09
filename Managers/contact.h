//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include <cstring>
#include <iostream>

#include "String.h"
#include "name.h"
#include "address.h"
#include "phone.h"

using std::endl;

enum ContactType
{
    company = 1,
    person = 2
};

class Contact
{
private:
    Name name;
    Address address;
    Phone phone;
public:
    Contact(const Name &name, const Address &address, const Phone &phone)
    : name(name), address(address), phone(phone) {}

    Name getName() const { return name; }
    Address getAddress() const { return address; }
    Phone getPhone() const { return phone; }

    virtual void print(std::ostream&) const = 0;

    virtual void saveToFile(std::ostream&) const = 0;

    bool operator==(const Contact& c) const {
        if (phone.getNumber() == c.getPhone().getNumber()) return true;
        return false;
    }

    virtual ~Contact() = default;
};

class Person : public Contact
{
public:
    Person(const Name &name, const Address &address, const Phone &phone)
    : Contact(name, address, phone) {}

    void print(std::ostream& os) const override {
        os << "Személy Adatok : " << getName().getFullname() << " " << getName().getNickname() << " " << getAddress() << " " << getPhone().getNumber() << endl;
    }

    void saveToFile(std::ostream& os) const override
    {
        os
            << "person" << endl
            << getName().getLastname() << endl
            << getName().getFirstname() << endl
            << getName().getNickname() << endl
            << getAddress().getPostcode() << endl
            << getAddress().getCity() << endl
            << getAddress().getStreet() << endl
            << getAddress().getNumber() << endl
            << getPhone().getNumber() << endl;
    }
};

class Company : public Contact
{
public:
    Company(const Name &name, const Address &address, const Phone &phone)
    : Contact(name, address, phone) {}

    void print(std::ostream& os) const override {
        os << "Cég Adatok : " << getName().getFullname() << " " << getName().getNickname() << " " << getAddress() << " " << getPhone().getNumber() << endl;
    }

    void saveToFile(std::ostream& os) const override
    {
        os
                << "company" << endl
                << getName().getLastname() << endl
                << getName().getFirstname() << endl
                << getName().getNickname() << endl
                << getAddress().getPostcode() << endl
                << getAddress().getCity() << endl
                << getAddress().getStreet() << endl
                << getAddress().getNumber() << endl
                << getPhone().getNumber() << endl;
    }
};