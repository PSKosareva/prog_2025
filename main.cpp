/*
7 вариант
Основы программирования (25.09.2025)
*/

#include <iostream>
#include <limits>

int main() {
	setlocale(LC_ALL, "RU");
	int x;
	/* 
	Был выбран этот тип данных, во-первых, потому что число должно быть целым, а не дробным (int это ограничивает),
	во-вторых, потому что вычисления с данным типом проводить легко (x^2 и x^5 априори будут целые числа, а 1.0/x будет
	автоматически выводиться с типом данных double 
	*/

	std::cout << "Введите целое число x (не 0): " << std::endl;
	std::cin >> x;
	if (x == 0) {
		std::cout << "Число не должно быть равно нулю!" << std::endl;
		return 1;
	} else {
		std::cout << "Тип: int" << std::endl;
		std::cout << "Размер в битах: " << sizeof(int) * 8 << std::endl;
		std::cout << "Минимальное значение: " << std::numeric_limits<int>::min() << std::endl;
		std::cout << "Максимальное значение: " << std::numeric_limits<int>::max() << std::endl;
		std::cout << "Обратное число: " << 1.0 / x << "\n";  // деление
		std::cout << "Тип: double" << std::endl;
		std::cout << "Размер в битах: " << sizeof(double) * 8 << std::endl;
		std::cout << "Минимальное значение: " << std::numeric_limits<double>::lowest() << std::endl;
		std::cout << "Максимальное значение: " << std::numeric_limits<double>::max() <<  std::endl;
		std::cout << "Квадрат числа: " << x * x << "\n";           // квадрат
		std::cout << "Пятая степень: " << x * x * x * x * x       // пятая степень
		<< std::endl;
		return 0;
	}
}
