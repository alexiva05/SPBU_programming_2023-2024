#include <cmath>
#include <iostream>
#include <cstdio>
#include <string>


//Вывод корней на экран.
void count_of_roots(double& root1, double& root2) {
    if (root1 != root2) {
        printf("%.16lg %.16lg\n", root1, root2);
    } else {
        printf("%.16lg\n", root1);
    }
    return;
}

//Функция, которая находит корни квадратного уравнения.
void roots(double& a, double& b, double& c, double& root1, double& root2) {

    if (a == 0 && c == 0 && b == 0) {
        std::cout << "Бесконечно много решений." << std::endl;
        return;
    }

    if (a == 0 && b != 0 && c != 0 && (std::to_string(c / b) == "-inf" || std::to_string(c / b) == "inf")) {
        std::cout << "Возникает переполнение" << std::endl;
        return;
    }

    if (std::to_string(b * b) == "inf" || std::to_string(b * b) == "-inf") {
        std::cout << "Возникает переполнение" << std::endl;
        return;
    }

    if (b != 0 && b * b == 0) {
        std::cout << "Возникает переполнение" << std::endl;
        return;
    }

    if (a != 0 && c != 0 && a * c == 0) {
        std::cout << "Возникает переполнение" << std::endl;
        return;
    }

    double d = (b * b) - (4 * a * c);

    double res1 = (- b - std::sqrt(d)) / (2 * a);
    double res2 = (- b + std::sqrt(d)) / (2 * a);
    double res3 = (- b) / (2 * a);


    if (a == 0 && b == 0 && c != 0) {
        std::cout << "Решений нет!!!" << std::endl;
        return;
    }

    if (a == 0 && c == 0) {
        std::cout << "Ответ: ";
        std::cout << "0" << std::endl;
        return;
    }

    if (b == 0 && c == 0) {
        std::cout << "Ответ: ";
        std::cout << "0" << std::endl;
        return;
    }

    /*if (0 <= abs(a) <= 10000000e-300) {
        std::cout << "Возникает переполнение" << std::endl;
        return;
    }*/

    if ((0 <= abs(a) <= 10000000e-300 && (std::to_string(res1) == "-inf" || std::to_string(res2) == "-inf" || std::to_string(res3) == "-inf"))) {
        std::cout << "Возникает переполнение" << std::endl;
        return;
    }

     if (a == 0) {
        std::cout << "Данное уравнение является линейным! Ответ: ";;
        std::cout << (-c / b) << std::endl;
        return;
    }

    if ((abs(a) <= 10000000e-300 && (std::to_string(res1) == "-inf" || std::to_string(res2) == "-inf" || std::to_string(res3) == "-inf"))) {
        std::cout << "Возникает переполнение" << std::endl;
        return;
    }


    if (a != 0 && d > 0) {
        root1 = std::min(res1, res2);
        root2 = std::max(res1, res2);
        std::cout << "Ответ: ";
        count_of_roots(root1, root2);
        return;
    } else if (a != 0 && d == 0) {
        root1 = root2 = res3;
        std::cout << "Ответ: ";
        count_of_roots(root1, root2);
        return;
    } else {
        std::cout << "Действительных корней нет." << std::endl;
        return;
    }
}


int main() {
    double a = 0.0, b = 0.0, c = 0.0, root1 = 0.0, root2 = 0.0;
    std::cout << "Введите три числа с клавиатуры: " << std::endl;
    std::cin >> a >> b >> c;
    std::cout << std::endl;
    std::cout << std::endl;

    roots(a, b, c, root1, root2);

    return 0;
}
