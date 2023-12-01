#include <stdio.h>

int main() {
    double a,b, result;

    printf("Введите два числа через пробел: ");
    scanf("%lf %lf", &a, &b);

    result = a + b;

    printf("Сумма ваших чисел равна: %.16lg\n", result);

    result = a - b;

    printf("Разность ваших чисел равна: %.16lg\n", result);

    result = a * b;

    printf("Произведение ваших чисел равно: %.16lg\n", result);

    result = a / b;

    printf("Частное ваших чисел равно: %.16lg\n", result);
}




