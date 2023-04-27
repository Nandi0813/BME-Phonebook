//
// Created by Dukát Nándor on 2023. 04. 23..
//

#include <iostream>

#include "String.h"

String::String(const char *s)
{
    data = new char[(length = std::strlen(s)) + 1];

    for (size_t i = 0; i < length; i++)
        data[i] = s[i];

    data[length] = '\0';
}

String::String(const char c)
{
    data = new char[2];

    length = 1;
    data[0] = c;

    data[length] = '\0';
}

String::String(const String &s)
{
    data = new char[(length = s.length) + 1];

    for (size_t i = 0; i < length; i++)
        data[i] = s.data[i];

    data[length] = '\0';
}

String::String(const std::string &s)
{
    data = new char[(length = s.length()) + 1];

    for (size_t i = 0; i < length; i++)
        data[i] = s[i];

    data[length] = '\0';
}

String& String::operator=(const String &s)
{
    if (this != &s)
    {
        delete[] data;
        data = new char[(length = s.length) + 1];

        for (size_t i = 0; i < length; i++)
            data[i] = s.data[i];

        data[length] = '\0';
    }

    return *this;
}

String& String::operator=(const char* s)
{
    return *this = String(s);
}

bool String::operator==(const String &s) const
{
    if (length != s.length) return false;

    for (size_t i = 0; i < length; i++)
        if (data[i] != s.data[i])
            return false;

    return true;
}

bool String::operator!=(const String &s) const
{
    if (length != s.length) return true;

    for (size_t i = 0; i < length; i++)
        if (data[i] != s.data[i])
            return true;

    return false;
}

String String::operator+(char c) const
{
    return *this + String(c);
}

String String::operator+(const String &s) const
{
    String string;

    delete[] string.data;
    string.length = std::strlen(data) + std::strlen(s.data);
    string.data = new char[string.length + 1];

    int count = 0;

    for (size_t i = 0; i < length; i++)
        string.data[count++] = data[i];
    for (size_t i = 0; i < s.length; i++)
        string.data[count++] = s.data[i];

    string.data[count] = '\0';

    return string;
}

char& String::operator[](size_t idx)
{
    if (idx >= length)
        throw "String: indexelesi hiba";

    return data[idx];
}

const char& String::operator[](size_t idx) const
{
    if (idx >= length)
        throw "String: indexelesi hiba";

    return data[idx];
}

bool String::contains(char &c) const
{
    for (size_t i = 0; i < length; i++)
        if (data[i] == c) return true;
    return false;
}

String::~String()
{
    delete[] data;
}

std::ostream& operator<<(std::ostream& os, String const& rhs)
{
    return os << std::string(rhs.getData());
}

std::istream& operator>>(std::istream& is, String& s0)
{
    unsigned char ch;
    s0 = String("");
    std::ios_base::fmtflags fl = is.flags();
    is.setf(std::ios_base::skipws);
    while (is >> ch) {
        is.unsetf(std::ios_base::skipws);
        if (ch == '\n') {
            break;
        } else {
            s0 = s0 + ch;
        }
    }
    is.flags(fl);
    return is;
}