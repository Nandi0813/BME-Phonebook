#include <iostream>

#include "Libs/gtest_lite.h"
#include "Managers/directory.h"

int main()
{
    Contact contact = Contact("Dukát", "Nándor", "Nándi", "2045 Törökbálint Meggyes utca 19.2", "+36309383747", "+36306106664");
    contact.print(std::cout);

    Contact contact2;
    contact2.setLastname("Dukát");
    contact2.setFirstname("Nándor");
    contact2.setNickname("Nándi");
    contact2.setAddress("2045 Törökbálint Meggyes utca 19.2");
    contact2.setWorkNumber("+36309383747");
    contact2.setPrivateNumber("+36306106664");
    contact2.print(std::cout);

    Directory directory;
    directory.addContact(contact);
    directory.addContact(contact2);
}