#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	int table[3][4];

	std::cout << "Введите 12 чисел для таблицы" << std::endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			std::cin >> table[i][j];
		}
	}
	int max_summa = 0;
	int max_col = 0;

	for (int j = 0; j < 4; j++) {
		int summa = 0;
		for (int i = 0; i < 3; i++) {
			summa += table[i][j];
		}
		
		if (summa > max_summa) {
			max_summa = summa;
			max_col = j;
		}
	}

	std::cout << "Максимальная сумма " << max_col + 1 << " столбца  — " << max_summa << std::endl;

	for (int i = 0; i < 3; i++) {
		table[i][max_col] = 0;
	}

	std::cout << "Таблица после изменений: " << std::endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
