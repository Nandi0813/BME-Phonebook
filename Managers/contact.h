//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include <cstring>
#include <iostream>

#include "String.h"
#include "name.h"
#include "address.h"
#include "phone.h"

enum ContactType { null, company, person };

class Contact
{
private:
    Name name;
    Address address;
    Phone phone;
protected:
    ContactType contactType;
public:
    Contact(const Name &name, const Address &address, const Phone &phone)
    : name(name), address(address), phone(phone), contactType() {}

    Name getName() const { return name; }
    Address getAddress() const { return address; }
    Phone getPhone() const { return phone; }

    virtual void print(std::ostream& os) const = 0;

    bool operator==(const Contact& c) const {
        return phone == c.getPhone();
    }

    virtual ~Contact() = default;
};

class Person : public Contact
{
public:
    Person(const Name &name, const Address &address, const Phone &phone)
    : Contact(name, address, phone) {
        this->contactType = person;
    }

    void print(std::ostream& os) const override {
        os << "Személy Adatok : " << getName().getFullname() << " " << getName().getNickname() << " " << getAddress() << " " << getPhone().getNumber() << std::endl;
    }
};

class Company : public Contact
{
public:
    Company(const Name &name, const Address &address, const Phone &phone)
            : Contact(name, address, phone) {
        this->contactType = company;
    }

    void print(std::ostream& os) const override {
        os << "Cég Adatok : " << getName().getFullname() << " " << getName().getNickname() << " " << getAddress() << " " << getPhone().getNumber() << std::endl;
    }
};