#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	std::cout << "Введите количество чисел (длину последовательности): " << std::endl;
	std::cin >> N;

	if (N <= 0) {
		std::cout << "Ваша последовательность пустая." << std::endl;
		return 0;
	}

	int first;
	int sum = 0;
	int minNum = 100000000;
	int minIndex = -1;
	bool found = 0;

	std::cout << "Введите последовательность: " << std::endl;

	for (int i = 1; i <= N; i++) {
		int current;
		std::cout << "Число " << i << ": " << std::endl;
		std::cin >> current;

		if (i == 1) {
			first = current;
			continue;
		}
		if (current > first) {
			found = 1;
			sum += current;
		}

		if (current < minNum) {
			minIndex = i;
			minNum = current;
			}
		}
	if (!found) {
		std::cout << "Нет чисел больше первого" << std::endl;
	}
	else {
		std::cout << "Сумма чисел больше первого: " << sum << std::endl;
		std::cout << "Наименьшее из последовательности чисел: " << minNum << std::endl;
		std::cout << "Его номер в последовательности: " << minIndex << std::endl;
	}
	return 0;
}