//
// Created by Dukát Nándor on 2023. 04. 23..
//

#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
private:
    char *data;
    size_t length;
public:
    String(const char *s = "");
    String(char c);
    String(const String&);

    size_t getLength() const { return length; }

    const char* getData() const { return data; }
    char* getData() { return data; };

    String& operator=(const String&);
    String& operator=(const char*);

    bool operator==(const String&) const;
    bool operator!=(const String&) const;

    String operator+(String const &s) const;
    String operator+(char c) const;

    char& operator[](size_t idx);
    const char& operator[](size_t idx) const;

    bool contains(char &c) const;

    ~String();
};

std::ostream& operator<<(std::ostream& os, String const& rhs);
std::istream& operator>>(std::istream& is, String& s0);

#endif