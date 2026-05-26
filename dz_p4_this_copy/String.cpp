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
    char* temp_str = new char[(size > s2.size ? s2.size : size) + 1];
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

String& String::operator=(const String& other)
{
    if (*this == other)
        return *this;

    if (other.string == nullptr)
    {
        delete[] string;
        string = nullptr;
        size = 0;
        return *this;
    }

    delete[] string;
    string = new char[strlen(other.string) + 1];

    strcpy_s(string, strlen(other.string) + 1, other.string);
    size = other.size;

    return *this;
}

String& String::operator+=(const String& other)
{
    if (other.string == nullptr) return *this;

    int newLen = strlen(string) + strlen(other.string) + 1;
    char* temp = new char[newLen];

    strcpy_s(temp, newLen, string);
    strcat_s(temp, newLen, other.string);

    delete[] string;
    string = temp;
    size = newLen;
    return *this;
}

String String::operator+(const String& other) const
{
    String temp = *this;
    temp += other;
    return temp;
}

bool String::operator==(const String& other) const
{
    if (size == other.size && strcmp(string, other.string) == 0)
        return true;
    return false;
}

bool String::operator!=(const String& other) const
{
    if (*this == other) return false;
    return true;
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    strcpy_s(string, size, buffer);
    delete[] buffer;
}

void String::print() const
{
    std::cout << string;
}

void String::clear()
{
    delete[] string;
    string = nullptr;
    size = 0;
}