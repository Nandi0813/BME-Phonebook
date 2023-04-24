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

    void print(std::ostream& os, bool lastLine);

    bool operator==(const Contact&) const;

    ~Contact() = default;
};