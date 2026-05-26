#pragma once
#include <cstring>

class String
{
protected:
	char* string;
	int size;
	static int count;

public:
	// constructors and destructors
	String() : String(80) {}

	String(int size)
		: string{ new char[size + 1] },
		size{ size }
	{
		count++;
		string[0] = '\0';
	}

	String(const char* string)
		: String{ (int)(strlen(string))}
	{
		if (this->string) strcpy_s(this->string, size + 1, string);
	}

	String(const String& obj)
		: String(obj.size)
	{
		strcpy_s(this->string, size + 1, obj.string);
	}

	~String()
	{
		if (string != nullptr)
			delete[] string;
		count--;
	}

	// operator overloading
	char operator[](int index);
	int operator()(char symbol);
	operator int();
	String operator*(const String& s2);
	String& operator=(const String& other);
	String& operator+=(const String& other);
	String operator+(const String& other) const;
	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;

	// methods
	static int getCount();
	void input();
	void print() const;
	void clear();
};