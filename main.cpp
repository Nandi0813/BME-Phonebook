#include <iostream>

#include "Managers/directory.h"
#include "Libs/gtest_lite.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Teszt 1: Adatok beolvasása file-ból" << endl;

    Directory directory;

    cout << "Teszt 2: Adatok felvétele" << endl;


    directory.saveData("data.txt");
}