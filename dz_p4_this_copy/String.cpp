#include "String.h"
#include <iostream>

int String::count = 0;

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