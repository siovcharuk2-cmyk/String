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

    std::cout << "\n===== [4] =====\n";
    std::cout << str3[4] << std::endl;

    std::cout << "\n===== (r) =====\n";
    std::cout << str3('r') << std::endl;

    std::cout << "\n===== (int) =====\n";
    std::cout << (int)str3 << std::endl;

    std::cout << "\n===== str1 * str2 =====\n";
    (str1 * str2).print();
    std::cout << std::endl;

    std::cout << "\nNumber of strings: " << String::getCount() << std::endl;
}