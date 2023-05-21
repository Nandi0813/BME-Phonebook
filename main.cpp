#include <iostream>

#include "directory.h"
#include "gtest_lite.h"
#include "memtrace.h"

/*
 * Iterator használata
 * C++ -osabb megoldások akármit is jelentsen
 */

void test1(Directory &directory)
{
    TEST(adatok beolvasasa, adatok felvetele)
        {
            directory.getContacts().add(new Person(Name("Kiss", "János", "Jani"),Address("1234", "Nagy város", "Kis utca", "17"), Phone("06301234567")));
            directory.getContacts().add(new Person(Name("Hajdu", "Bálint", "Bálint"),Address("5678", "Eger", "Egri Csillagok utca", "61"), Phone("06303211234")));
            directory.getContacts().add(new Company("Facebook", Address("1112", "Budapest", "Meggy utca", "1"), Phone("06301002020")));
            directory.getContacts().add(new Company("Apple", Address("2045", "Törökbálint", "Alma utca", "9"), Phone("06302509981")));

            EXPECT_EQ(5, directory.getContacts().getSize()) << "Nem sikerült felvenni az összes adatot!";
        END
    }
}

void test2(Directory &directory)
{
    TEST(adatok kilistazasa, adatok kilistazasa)
        {
            for (auto contact : directory.getContacts())
            {
                contact->print(std::cout); // Ezt kérdezd meg.
            }
        END
    }
}

void test3(Directory &directory)
{
    TEST(adat kereses, talalat)
        {
            EXPECT_TRUE(directory.searchByNumber("06301234567") != nullptr) << "Névjegy nem található";
        END
    }
}

void test4(Directory &directory)
{
    TEST(adat kereses, nincs talalat)
        {
            EXPECT_FALSE(directory.searchByNumber("06301111111") != nullptr) << "Névjegy található";
        END
    }
}
void test5(Directory &directory)
{
    TEST(adat modositas, szemely nev)
        {
            Person *p = dynamic_cast<Person *>(directory.searchByNumber("06301234567"));
            p->getName().setLastname("Nagy");
            p->getName().setFirstname("Béla");
            p->getName().setNickname("Béci");

            EXPECT_STREQ("Béla Nagy", p->getName().getFullname().getData());
            EXPECT_STREQ("Béci", p->getName().getNickname().getData());
        END
    }
}
void test6(Directory &directory)
{
    TEST(adat modositas, ceg nev)
        {
            Company *c = dynamic_cast<Company *>(directory.searchByNumber("06301002020"));
            c->setName("Twitter");

            EXPECT_STREQ("Twitter", c->getName().getData());
        END
    }
}

void test7(Directory &directory)
{
    TEST(adat modositas, lakcim)
        {
            Contact* contact = directory.searchByNumber("06301234567");
            contact->getAddress().setPostcode("4444");
            contact->getAddress().setCity("Kis város");
            contact->getAddress().setStreet("Nagy utca");
            contact->getAddress().setHouseNumber("11");

            EXPECT_STREQ("4444", contact->getAddress().getPostcode().getData());
            EXPECT_STREQ("Kis város", contact->getAddress().getCity().getData());
            EXPECT_STREQ("Nagy utca", contact->getAddress().getStreet().getData());
            EXPECT_STREQ("11", contact->getAddress().getHouseNumber().getData());
        END
    }
}

void test8(Directory &directory)
{
    TEST(adat modositas, telefonszam)
        {
            Contact* contact = directory.searchByNumber("06302509981");
            contact->getPhone().setNumber("06302509982");

            EXPECT_STREQ("06302509982", contact->getPhone().getNumber().getData());
        END
    }
}

void test9(Directory &directory)
{
    TEST(adat torles, sikertelen)
        {
            directory.getContacts().remove(directory.searchByNumber("0620111111"));
            EXPECT_TRUE(directory.searchByNumber("0620111111") == nullptr) << "Névjegy törlés sikeres";
        END
    }
}

void test10(Directory &directory)
{
    TEST(adat torles, sikeres)
        {
            directory.getContacts().remove(directory.searchByNumber("06301234567"));
            directory.getContacts().remove(directory.searchByNumber("06303211234"));
            directory.getContacts().remove(directory.searchByNumber("06301002020"));
            directory.getContacts().remove(directory.searchByNumber("06302509982"));

            EXPECT_TRUE(directory.searchByNumber("06301234567") == nullptr) << "Névjegy törlése sikertelen";
            EXPECT_TRUE(directory.searchByNumber("06303211234") == nullptr) << "Névjegy törlése sikertelen";
            EXPECT_TRUE(directory.searchByNumber("06303211234") == nullptr) << "Névjegy törlése sikertelen";
            EXPECT_TRUE(directory.searchByNumber("06302509982") == nullptr) << "Névjegy törlése sikertelen";
        END
    }
}

void test11(Directory &directory)
{
    TEST(vissza az eredeti allapotba, 1 nevjegy)
    {
        EXPECT_EQ(1, directory.getContacts().getSize()) << "Nem 1 névjegy marad a telefonkönyvben.";
        END
    }
}

void test12(Directory &directory)
{
    TEST(nevjegyek mentese, nevjegyek mentese)
    {
        directory.saveData("data.txt");
        END
    }
}

int main()
{
    Directory directory;

    test1(directory);
    test2(directory);
    test3(directory);
    test4(directory);
    test5(directory);
    test6(directory);
    test7(directory);
    test8(directory);
    test9(directory);
    test10(directory);
    test11(directory);
    test12(directory);
}