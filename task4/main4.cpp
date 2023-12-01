#include <iostream>
#include "fibonacci.h"

int main() {
    int user_input = 0;

    std::cout << "Введите натуральное число меньшее, чем 94." << std::endl;
    std::cin >> user_input;
    std::cout << std::endl;

    while (user_input <= 0 || user_input > 93) {
        if (user_input > 93) {
            std::cout << "Введено слишком большое число!!!" << std::endl;
        } else {
            std::cout << "Введено слишком маленькое число!!!" << std::endl;
        }
        std::cin >> user_input;
    }

    std::cout << "Число под номером " << user_input << ":" << std::endl;
    std::cout << "   * Посчитанное рекурсивно - " << RecursionFibonacci(user_input) << ";" << std::endl;
    std::cout << "   * Посчитанное через цикл - " << LoopFibonacci(user_input) << ";" << std::endl;
    std::cout << "   * Посчитанное по формуле - " << ThirdFibonacci(user_input) << "." << std::endl;
    std::cout << std::endl;
    PrevNums(user_input);

}