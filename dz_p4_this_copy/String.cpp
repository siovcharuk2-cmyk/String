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

String String::operator*(const String& s2)
{
    int temp_size = 0;
    char* temp_str = new char[size > s2.size ? s2.size : size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < s2.size; j++)
        {
            bool is_free = true;
            if (string[i] == s2.string[j]) 
            {
                for (int k = 0; k < temp_size; k++)
                {
                    if (string[i] == temp_str[k])
                    {
                        is_free = false;
                        break;
                    }
                }

                if (is_free)
                    temp_str[temp_size++] = string[i];
            }
        }
    }
    temp_str[temp_size] = '\0';

    String temp{ temp_str };
    delete[] temp_str;
    return temp;
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