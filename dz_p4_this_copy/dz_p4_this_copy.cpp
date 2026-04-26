#include <iostream>
#include "String.h"

int main()
{
    std::cout << "===== Default =====\n";
    String str1;
    str1.input();
    str1.print();

    std::cout << "\n===== Selected size =====\n";
    String str2{ 100 };
    str2.input();
    str2.print();

    std::cout << "\n===== Init =====\n";
    String str3{ "Hello world!!!" };
    str3.print();

    std::cout << "\nNumber of strings: " << String::getCount() << std::endl;
}