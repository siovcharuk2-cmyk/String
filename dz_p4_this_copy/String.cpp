#include "String.h"
#include <iostream>

int String::count = 0;


char String::operator[](int index)
{
    if (index >= 0 && index <= strlen(string))
        return string[index];
    return '\0';
}

int String::operator()(char symbol)
{
    for (int i = 0; i < size; i++)
    {
        if (string[i] == symbol)
            return i;
    }
    return -1;
}

String::operator int()
{
    return (int)strlen(string);
}


int String::getCount()
{
    return count;
}

void String::input()
{
    char* buffer = new char[size];
	std::cin.getline(buffer, size);

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Трішки підглянув
    }

    strcpy_s(string, size, buffer);
}

void String::print()
{
    std::cout << string;
}