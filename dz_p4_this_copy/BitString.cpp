#include "BitString.h"
#include <algorithm>

BitString& BitString::operator=(const BitString& other)
{
	String::operator=(other);
	return *this;
}

BitString& BitString::operator+=(const BitString& other)
{
	if (size == 0) { *this = other; return *this; }
	if (other.size == 0) { return *this; }

	int maxSize = std::max(size, other.size);

	char signA = string[0];
	char signB = other.string[0];

	char* alignedA = new char[maxSize + 1];
	char* alignedB = new char[maxSize + 1];
	char* resultStr = new char[maxSize + 1];

	alignedA[maxSize] = '\0';
	alignedB[maxSize] = '\0';
	resultStr[maxSize] = '\0';

    int diffA = maxSize - size;
    for (int i = 0; i < diffA; i++)
        alignedA[i] = signA;
    strcpy_s(alignedA + diffA, size + 1, string);

    int diffB = maxSize - other.size;
    for (int i = 0; i < diffB; i++)
        alignedB[i] = signB;
    strcpy_s(alignedB + diffB, other.size + 1, other.string);

    int carry = 0;
    for (int i = maxSize - 1; i >= 0; i--)
    {
        int bitA = alignedA[i] - '0';
        int bitB = alignedB[i] - '0';

        int sum = bitA + bitB + carry;

        resultStr[i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    *this = BitString(resultStr);

    delete[] alignedA;
    delete[] alignedB;
    delete[] resultStr;

    return *this;
}

BitString BitString::operator+(const BitString& other) const
{
    BitString temp{ *this };
    temp += other;
    return temp;
}

bool BitString::operator==(const BitString& other) const
{
	return String::operator==(other);
}

bool BitString::operator!=(const BitString& other) const
{
	return String::operator!=(other);
}


void BitString::changeSign()
{
    if (size == 0) return;

    char* invertedStr = new char[size + 1];
    invertedStr[size] = '\0';

    for (int i = 0; i < size; i++)
    {
        if (string[i] == '0')
            invertedStr[i] = '1';
        else
            invertedStr[i] = '0';
    }

    *this = BitString(invertedStr);

    delete[] invertedStr;

    BitString plusOne("01");

    *this += plusOne;
}

void BitString::show() const
{
    String::print();
}