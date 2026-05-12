#pragma once
#include <cstring>

class String
{
private:
	char* string;
	int size;
	static int count;

public:
	// constructors and destructors
	String() : String(80) {}

	String(int size)
		: string{ new char[size + 1] },
		size{ size + 1 }
	{
		count++;
	}

	String(const char* string)
		: String{ (int)(strlen(string) + 1)}
	{
		if (this->string) strcpy_s(this->string, strlen(string) + 1, string);
	}

	String(const String& obj)
		: String(obj.size - 1)
	{
		strcpy_s(this->string, size, obj.string);
	}

	~String()
	{
		delete[] string;
		count--;
	}

	// operator overloading
	char operator[](int index);
	int operator()(char symbol);
	operator int();

	// methods
	static int getCount();
	void input();
	void print();
};