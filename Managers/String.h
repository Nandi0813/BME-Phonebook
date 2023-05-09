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
    String(const std::string&);

    size_t getLength() const { return length; }

    const char* getData() const { return data; }
    char* getData() { return data; };

    String& operator=(const String&);
    String& operator=(const char*);

    bool operator==(const String&) const;
    bool operator!=(const String&) const;

    String operator+(const String&) const;
    String operator+(char) const;

    char& operator[](size_t);
    const char& operator[](size_t) const;

    bool contains(char&) const;

    ~String();
};

std::ostream& operator<<(std::ostream& os, String const& rhs);
std::istream& operator>>(std::istream& is, String& s0);

#endif