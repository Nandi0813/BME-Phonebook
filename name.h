//
// Created by Dukát Nándor on 2023. 04. 24..
//

#ifndef PROJECT_NAME_H
#define PROJECT_NAME_H

#include "string.h"
#include "memtrace.h"

class Name
{
private:
    String last_name; // Vezetéknév
    String first_name; // Keresztnév
    String nickname; // Becenév
public:
    /*
     * Konstruktor
     * Beállítja az attribútomokat
     *
     * @param last_name - vezetéknév
     * @param first_name - keresztnév
     * @param nickname - becenév
     */
    Name(const String& last_name, const String& first_name, const String& nickname)
    {
        this->last_name = last_name;
        this->first_name = first_name;
        this->nickname = nickname;
    }

    /*
     * Vezetéknév getter
     * @return last_name
     */
    String getLastname() const { return last_name; }
    /*
     * Vezetéknév setter
     * @param s - új vezetéknév
     */
    void setLastname(const String& s) { this->last_name = s; }

    /*
     * Keresztnév getter
     * @return first_name
     */
    String getFirstname() const { return first_name; }
    /*
     * Keresztnév setter
     * @param s - új keresztnév
     */
    void setFirstname(const String& s) { this->first_name = s; }

    /*
     * Becenév getter
     * @return nickname
     */
    String getNickname() const { return nickname; }
    /*
     * Becenév setter
     * @param s - új becenév
     */
    void setNickname(const String& s) { this->nickname = s; }

    /*
     * @return - A személy teljes nevét.
     */
    String getFullname() const { return first_name + " " + last_name; }

    /*
     * Default destruktor
     */
    ~Name() = default;
};

#endif //PROJECT_NAME_H
