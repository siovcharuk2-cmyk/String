#pragma once
#include "String.h"
#include <cstring>
#include <iostream>

class BitString :
    public String
{
private:
    bool isCorrect(const char* string)
    {
        bool correct = true;
        for (int i = 0; i < strlen(string); i++)
        {
            if (string[i] != '0' && string[i] != '1')
            {
                correct = false;
                break;
            }
        }
        return correct;
    }

public:
    BitString(const char* str)
        : String{ isCorrect(str) ? str : ""}
    {}

    BitString() :BitString{ ""}
    { }

    BitString(const BitString& other)
        : String{ other }
    { }


    // operators
    BitString& operator=(const BitString& other);
    BitString& operator+=(const BitString& other);
    BitString operator+(const BitString& other) const;
    bool operator==(const BitString& other) const;
    bool operator!=(const BitString& other) const;

    // methods
    void changeSign();
    void show() const;
};