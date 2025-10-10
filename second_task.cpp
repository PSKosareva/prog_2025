#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	int N, M;
	std::cout << "Введите первую цифру (1-9): ";
	std::cin >> N;
	std::cout << "Введите вторую цифру (1-9): ";
	std::cin >> M;
	std::cout << std::endl;

	//проверка
	if (N < 1 || N > 9 || M < 1 || M > 9) {
		std::cout << "Ошибка! Цифры должны быть от 1 до 9" << std::endl;
		return 1;
	}

	int number = N * 10 + M;

	if (N == M && number <= 90) {
		switch (number) {
		case 11:
			std::cout << "Барабанные палочки" << std::endl;
			break;
		case 22:
			std::cout << "Утята" << std::endl;
			break;
		case 33:
			std::cout << "Тридцать три" << std::endl;
			break;
		case 44:
			std::cout << "Стульчики" << std::endl;
			break;
		case 55:
			std::cout << "Перчатки" << std::endl;
			break;
		case 66:
			std::cout << "Валенки" << std::endl;
			break;
		case 77:
			std::cout << "Топорики" << std::endl;
			break;
		case 88:
			std::cout << "Бабушка" << std::endl;
			break;
		default:
			std::cout << "Не дубль" << std::endl;
		}
	}
	else {
		std::cout << "Номер не дубль :(" << std::endl;
		std::cout << "Причина: ";
		if (N != M) {
			std::cout << "цифры N и M разные" << std::endl;
		}
		if (number > 90) {
			std::cout << "число больше 90 - такого в лото не существует" << std::endl;
		}
	}
	return 0;
}