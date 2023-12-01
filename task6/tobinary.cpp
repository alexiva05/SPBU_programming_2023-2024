#include <string>
#include <cmath>

//Перевод числа в двоичную систему счисления.
std::string Convert_To_Binary(int a) {

    bool flag = false;
    int num = abs(a);
    std::string str = "";
    
    if (a == 0) {
        return "0";
    } else if (a < 0) {
        flag = true;
    }

    while (num > 0) {
        str += std::to_string(num % 2);
        num /= 2;
    }

    if (flag) {
        str = str + "-";
        return str;
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


int Convert_to_Decimal(std::string str) {
    int result1 = 0;
    int result2 = 0;
    int counter = str.size() - 1;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '1') {
            result1 += std::pow(2, counter);
        }
        --counter;
    }

    if (str[0] == '-') {
        return result2 - result1;
    }
    return result1;
}