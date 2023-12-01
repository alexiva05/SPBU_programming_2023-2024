#include <cmath>
#include <iostream>

unsigned long int cache[100];
unsigned long int RecursionFibonacci(int num) {
    if (cache[num] == 0) {
        if (num == 1 || num == 2) {
            cache[num] = 1;
        } else {
            cache[num] = RecursionFibonacci(num - 1) + RecursionFibonacci(num - 2);
        }
    }
    
    return cache[num];
}

unsigned long int LoopFibonacci(int num) {
    cache[0] = 1;
    cache[1] = 1;

    for (int i = 2; i <= num; i++) {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[num - 1];
}

unsigned long int ThirdFibonacci(int num) {
    const double sqrt5 = sqrt(5);
    const double f = (sqrt5 + 1) / 2;

    return (unsigned long int)(pow(f, num) / sqrt5 + 0.5);
}


void PrevNums(int user_input) {
    for (int i = 0; i < user_input; ++i) {
        std::cout << i + 1 << ") " << *(cache + i) << std::endl;
        std::cout << std::endl;
    }
}


