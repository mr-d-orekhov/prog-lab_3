// lab_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINES

#include <iostream>

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



int main()
{
	setlocale(LC_ALL, "");

	task_1();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
