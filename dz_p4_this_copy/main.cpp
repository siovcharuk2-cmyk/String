#include <iostream>
#include "BitString.h"
#include "String.h"
#include <windows.h>

void printResult(const char* testName, const BitString& str)
{
    std::cout << testName << ": \""; 
    str.show();
    std::cout << "\"" << std::endl;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    //std::cout << "===== Default =====\n";
    //String str1;
    //str1.input();
    //str1.print();

    //std::cout << "\n===== Selected size =====\n";
    //String str2{ 100 };
    //str2.input();
    //str2.print();

    //std::cout << "\n===== Init =====\n";
    //String str3{ "Hello world!!!" };
    //str3.print(); 

    //std::cout << "\n===== [4] =====\n";
    //std::cout << str3[4] << std::endl;

    //std::cout << "\n===== (r) =====\n";
    //std::cout << str3('r') << std::endl;

    //std::cout << "\n===== (int) =====\n";
    //std::cout << (int)str3 << std::endl;

    //std::cout << "\n===== str1 * str2 =====\n";
    //(str1 * str2).print();
    //std::cout << std::endl;

    //std::cout << "\nNumber of strings: " << String::getCount() << std::endl;

    std::cout << "=== Тест 1: Конструктори та Валідація ===" << std::endl;

    BitString bEmpty;
    printResult("Конструктор за замовчуванням (має бути порожнім)", bEmpty);

    BitString bValid("0101");
    printResult("Правильний рядок '0101'", bValid);

    BitString bInvalid("01a01");
    printResult("Неправильний рядок '01a01' (має стати порожнім)", bInvalid);

    std::cout << "\n=== Тест 2: Конструктор копіювання та Оператор присвоювання ===" << std::endl;

    BitString bCopy(bValid);
    printResult("Конструктор копіювання (копія '0101')", bCopy);

    BitString bAssign;
    bAssign = bValid;
    printResult("Оператор присвоювання (присвоєно '0101')", bAssign);

    std::cout << "\n=== Тест 3: Перевірка на рівність (==) та нерівність (!=) ===" << std::endl;

    std::cout << "bValid == bCopy: " << (bValid == bCopy ? "TRUE (Правильно)" : "FALSE") << std::endl;
    std::cout << "bValid != bInvalid: " << (bValid != bInvalid ? "TRUE (Правильно)" : "FALSE") << std::endl;

    std::cout << "\n=== Тест 4: Зміна знака числа (Додатковий код) ===" << std::endl;

    BitString bFour("0100");
    printResult("Початкове число (+4)", bFour);

    bFour.changeSign();
    printResult("Після changeSign() (має бути 1100, тобто -4)", bFour);

    bFour.changeSign();
    printResult("Повторний changeSign() (має повернутися до 0100, тобто +4)", bFour);

    std::cout << "\n=== Тест 5: Додавання бітових рядків (+ та +=) ===" << std::endl;

    BitString bThree("011");
    BitString bTwo("010");

    BitString bSum = bThree + bTwo;
    std::cout << "Оператор + (011 + 010):" << std::endl;
    printResult("Результат (має бути 0101)", bSum);

    BitString bMinusOne("11");

    std::cout << "Оператор += (0101 + 11) [тобто 5 + (-1)]:" << std::endl;
    bSum += bMinusOne;
    printResult("Результат (має бути 0100, тобто +4)", bSum);
}