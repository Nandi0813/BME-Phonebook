//
// Created by Dukát Nándor on 2023. 04. 23..
//

#ifndef PROJECT_CONTACT_H
#define PROJECT_CONTACT_H

#include <iostream>
#include "memtrace.h"

#include "String.h"
#include "name.h"
#include "address.h"
#include "phone.h"

using std::endl;

enum ContactType {
    person, company
};

class Contact
{
protected:
    Address address;
    Phone phone;
public:
    Contact(const Address &address, const Phone &phone)
            : address(address), phone(phone) {}

    Address& getAddress() { return address; }
    Phone& getPhone() { return phone; }

    virtual void print(std::ostream&) const = 0;

    virtual void saveToFile(std::ostream&) const = 0;

    bool operator==(const Contact& c) const {
        if (phone.getNumber() == c.phone.getNumber()) return true;
        return false;
    }

    virtual ~Contact() = default;
};

class Person : public Contact
{
private:
    Name name;
public:
    Person(const Name &n, const Address &address, const Phone &phone)
            : name(n), Contact(address, phone) {}

    Name& getName() { return name; }

    void print(std::ostream& os) const override {
        os << "Személy Adatok : " << name.getFullname() << " " << name.getNickname() << " " << address << " " << phone.getNumber() << endl;
    }

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

class Company : public Contact
{
private:
    String name;
public:
    Company(const String &name, const Address &address, const Phone &phone)
            : Contact(address, phone) {
        this->name = name;
    }

    String& getName() { return name; }
    void setName(const String& n) { name = n; }

    void print(std::ostream& os) const override {
        os << "Cég Adatok : " << name << " " << address << " " << phone.getNumber() << endl;
    }

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

#endif //PROJECT_CONTACT_H