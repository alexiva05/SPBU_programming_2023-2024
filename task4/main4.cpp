#include <iostream>
#include "fibonacci.h"
#include <vector>
#include <algorithm>

bool if_num(std::string str) {
    int num = 0;
    try {
        num = std::stoi(str);
    }
    catch (...) {
        return false;
    }
    return true;
}

int main() {
    std::string user_input = "";
    std::vector<std::string> strings;
    for (int i = 1; i < 94; ++i) {
        strings.push_back(std::to_string(i));
    }

    std::cout << "Введите натуральное число меньшее, чем 94." << std::endl;
    std::cin >> user_input;
    int dec_num{0};
    while (true) {
        if (std::find(strings.begin(), strings.end(), user_input) == strings.end() && "93" != user_input && !if_num(user_input)) {
            std::cout << "Введены некорректные символы!!!" << std::endl;
            std::cin >> user_input;
        } else {
            dec_num = std::stoi(user_input);
            break;
        }
    }
    std::cout << std::endl;

    while (dec_num <= 0 || dec_num > 93) {
        if (dec_num > 93) {
            std::cout << "Введено слишком большое число!!!" << std::endl;
        } else {
            std::cout << "Введено слишком маленькое число!!!" << std::endl;
        }

        std::cin >> user_input;
        while (true) {
            if (std::find(strings.begin(), strings.end(), user_input) == strings.end()) {
                std::cout << "Введены некорректные символы!!!" << std::endl;
                std::cin >> user_input;
            } else {
                dec_num = std::stoi(user_input);
                break;
            }
        }     
    }

    std::cout << "Число под номером " << user_input << ":" << std::endl;
    std::cout << "   * Посчитанное рекурсивно - " << RecursionFibonacci(dec_num) << ";" << std::endl;
    std::cout << "   * Посчитанное через цикл - " << LoopFibonacci(dec_num) << ";" << std::endl;
    std::cout << "   * Посчитанное по формуле - " << ThirdFibonacci(dec_num) << "." << std::endl;
    std::cout << std::endl;
    PrevNums(dec_num);

}


// int main() {
//     int user_input = 0;

//     std::cout << "Введите натуральное число меньшее, чем 94." << std::endl;
//     std::cin >> user_input;
//     std::cout << std::endl;

//     while (user_input <= 0 || user_input > 93) {
//         if (user_input > 93) {
//             std::cout << "Введено слишком большое число!!!" << std::endl;
//         } else {
//             std::cout << "Введено слишком маленькое число!!!" << std::endl;
//         }
//         std::cin >> user_input;
//     }

//     std::cout << "Число под номером " << user_input << ":" << std::endl;
//     std::cout << "   * Посчитанное рекурсивно - " << RecursionFibonacci(user_input) << ";" << std::endl;
//     std::cout << "   * Посчитанное через цикл - " << LoopFibonacci(user_input) << ";" << std::endl;
//     std::cout << "   * Посчитанное по формуле - " << ThirdFibonacci(user_input) << "." << std::endl;
//     std::cout << std::endl;
//     PrevNums(user_input);

// }