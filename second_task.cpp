#include <iostream> 

int main() {
	setlocale(LC_ALL, "Russian");

	int x;
	std::cout << "������� ����� (|x| < 1000): " << std::endl;
	std::cin >> x;

	if (x > 1000 || x < -1000) {
		std::cout << "������! ������ ����� ������ ���� ������ 1000" << std::endl;
		return 1;
	}

	int num;
	if (x < 0) {
		num = -x;
	}
	else {
		num = x;
	}

	int minDigit = 9;
	int maxDigit = 0;

	if (num == 0) {
		minDigit = 0;
		maxDigit = 0;
	}
	else {
		while (num > 0) {
			int digit = num % 10;
			if (digit < minDigit) {
				minDigit = digit;
			}
			if (digit > maxDigit) {
				maxDigit = digit;
			}

			num /= 10;
		}
	}

	int summa = minDigit + maxDigit;
	std::cout << "���������� ����� �����: " << minDigit << std::endl;
	std::cout << "���������� ����� �����: " << maxDigit << std::endl;
	std::cout << "����� ����������� � ����������� �����: " << summa << std::endl;

	return 0;
}