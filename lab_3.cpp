﻿// lab_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINES

#include <iostream>

bool static stream_with_error(std::istream* input) {
    if (input->fail()) {
        input->clear();
        input->ignore(INT_MAX, '\n');
        return true;
    }

    return false;
}

double round_to(double x, int n = 2) {
    return round(x * pow(10.0, n)) / pow(10.0, n);
}

/*
* Вывести на экран таблицу значений функции синус в диапазоне от − 2π до 2π с
* шагом π/8.
*/
void task_1() {
    float step = M_PI / 8;
    float range_start = -2 * M_PI;
    float range_end = 2 * M_PI;
    int precision = 4;

    std::cout << "Таблица значений с использованием цикла for:" << std::endl;

    for (double i = range_start; i <= range_end; i += step) {
        std::cout << round_to(i, precision) << " " << round_to(sin(i), precision) << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Таблица значений с использованием цикла while:" << std::endl;

    double j = range_start;
    while (j <= range_end)
    {
        std::cout << round_to(j, precision) << " " << round_to(sin(j), precision) << std::endl;
        j += step;
    }

    std::cout << std::endl;

    std::cout << "Таблица значений с использованием цикла do while:" << std::endl;

    double k = range_start;
    do {
        std::cout << round_to(k, precision) << " " << round_to(sin(k), precision) << std::endl;
        k += step;
    } while (k <= range_end);

    std::cout << std::endl;
}

/*
* Дано целое положительное число N. Вычислить сумму натуральных нечётных
* чисел не превышающих это число.
*/
void static task_2() {
    int sum = 0;
    int N;
    bool hasError = false;

    do {

        std::cout << "Введите N: ";
        std::cin >> N;

        hasError = stream_with_error(&std::cin) || N <= 0;

        if (hasError) {
            std::cout << "Значение N должно быть положительным числом!" << std::endl;
        }

    } while (hasError);

    for (int i = 1; i <= N; i += 2)
    {
        sum += i;
    }

    std::cout << "Сумма натуральных нечетных чисел равна: " << sum;
}

/*
* Вводится последовательность ненулевых чисел, 0 — конец последовательности.
* Определить сумму положительных элементов последовательности.
*/
void static task_3() {
    float sum = 0.0;

    std::cout << "Введите последовательность чисел:" << std::endl;

    float input;

    do {

        bool hasError = false;

        do {

            std::cin >> input;

            hasError = stream_with_error(&std::cin);

            if (hasError) {
                std::cout << "Ошибка ввода!" << std::endl;
            }
            else if (input > 0) {
                sum += input;
            }

        } while (hasError);

    } while (input != 0.0);

    std::cout << "Сумма положительных чисел: " << sum << std::endl;
}

/**
* Определить, является ли целое положительное число совершённым.
* Совершённое число равно сумме всех своих делителей, не превосходящих это число.
* Например, 6=1+2+3 или 28=1+2+4+7+14.
*/

void static task_4() {
    int sum = 0;
    int N;
    bool hasError = false;

    do {

        std::cout << "Введите N: ";
        std::cin >> N;

        hasError = stream_with_error(&std::cin) || N <= 0;

        if (hasError) {
            std::cout << "Значение N должно быть положительным числом!" << std::endl;
        }

    } while (hasError);

    for (int i = 1; i <= N / 2; i++)
    {
        if (N % i == 0) {
            sum += i;
        }
    }

    if (sum == N) {
        std::cout << "Число " << N << " совершенное!";
    }
    else {
        std::cout << "Число " << N << " не совершенное!";
    }

}

/**
* Дано натуральное число P.
* Вывести все простые числа не превосходящие P.
*/
void static task_5() {
    int P;
    bool hasError = false;

    do {

        std::cout << "Введите P: ";
        std::cin >> P;

        hasError = stream_with_error(&std::cin) || P <= 0;

        if (hasError) {
            std::cout << "Значение P должно быть положительным числом!" << std::endl;
        }

    } while (hasError);

    for (int i = 2; i <= P; i++)
    {
        bool isPrime = true;
        for (int j = 2; j <= std::sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            std::cout << i << std::endl;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "");

    //task_1();
    //task_2();
    //task_3();
    //task_4();
    task_5();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
