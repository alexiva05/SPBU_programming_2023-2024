#include <iostream>
#include <stdlib.h> //Для функции std::max.
#include <cstring> //Для функции std::to_string(), которая переводит число в строку.

//Перевод числа в двоичную систему счисления.
std::string Convert_To_Binary(unsigned long int a) {

    std::string str = "";
    
    if (a == 0) {
        return "0";
    }

    while (a > 0) {
        str += std::to_string(a % 2);
        a /= 2;
    }

    return str;
}

//Reverse строки.
std::string rev_string(std::string str) {

    std::string result = "";

    for (int i = str.size() - 1; i >= 0; --i) {
        result += str[i];
    }

    return result;
}




int main() {
    //Declaration and initialization of two variables.
    unsigned long int a = 0, b = 0;

    //Declaration and initialization of two variables that indicate the sum and difference.
    unsigned long int sum = 0, diff = 0;

    //Ввод двух чисел с клавиатуры.
    std::cout << "Введите два целых числа с клавиатуры:" << std::endl;
    std::cin >> a >> b;
    sum = a + b;
    std::cout << std::endl;
    std::cout << std::endl;

    //Вывод числа a.
    std::cout << "1) Число a в двоичной системе счисления: ";

    std::string res = rev_string(Convert_To_Binary(a));

    std::cout << "a = " << res << ". Количество символов: " << res.size() << ";" << std::endl;
    std::cout << std::endl;

    //Вывод числа b.
    std::cout << "2) Число b в двоичной системе счисления: ";

    res = rev_string(Convert_To_Binary(b));

    std::cout << "b = " << res << ". Количество символов: " << res.size() << ";" << std::endl;
    std::cout << std::endl;
    
    //Сумма.
    if (sum < std::max(a, b)) { //Если получаем переполнение, то добавляем разряд слева и необходимое количество нулей.
        std::cout << "3) Сумма чисел a и b в двоичной системе счисления: ";

        res = rev_string(Convert_To_Binary(sum));
        int strsize = res.size();

        while (strsize < 64) {
            res = "0" + res;
            strsize += 1;
        }

        std::cout << "a + b = 1" << res << ". Количество символов: " << res.size() + 1 << ";" << std::endl;
        std::cout << std::endl;
    } else { //Иначу просто складываем два числа.
        std::cout << "3) Сумма чисел a и b в двоичной системе счисления: ";

        res = rev_string(Convert_To_Binary(sum));

        std::cout << "a + b = " << res << ". Количество символов: " << res.size() << ";" << std::endl;
        std::cout << std::endl;
    }

    //Разность.
    if (a < b) { //В случае, если второе введенное число больше, чем первое введенное число.
        std::cout << "4) Разность чисел a и b в двоичной системе счисления: ";

        diff = b - a;
        res = rev_string(Convert_To_Binary(diff));

        std::cout << "a - b = -" << res << ". Количество символов: " << res.size() + 1 << ";" << std::endl;
        std::cout << std::endl;
    } else { //В остальных случаях.
        std::cout << "4) Разность чисел a и b в двоичной системе счисления: ";
        
        diff = a - b;
        res = rev_string(Convert_To_Binary(diff));

        std::cout << "a - b = " << res << ". Количество символов: " << res.size() << ";" << std::endl;
        std::cout << std::endl;
    }
}
