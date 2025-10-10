#include <iostream>
#include <cmath>
#include <bitset>

int main() {
	setlocale(LC_ALL, "RU");
	short A;
	int i;

	std::cout << "������� ����� �: " << std::endl;
	std::cin >> A;

	std::cout << "������� ����� ���� (0-7): " << std::endl;
	std::cin >> i;

	//��������

	if (i < 0 || i > 7) {
		std::cout << "������! ����� ���� ������ ���� �� 0 �� 7." << std::endl;
		return 1;
	}

	std::cout << A << " = ";
	for (int j = 7; j >= 0; j--) {
		std::cout << ((A >> j) & 1);
	}
	std::cout << std::endl;

	int bitValue = (A >> i) & 1;
	std::cout << "�������� " << i << "-�� ���� � " << bitValue << std::endl;

	if (bitValue != 0) {
		// i-� ��� �� ����� 0 - ������ �� ���������������
		A = A ^ (1 << i);
		std::cout << "��������� ����� �������� " << i << "-�� ����: " << A << " = ";
		for (int j = 7; j >= 0; j--) {
			std::cout << ((A >> j) & 1);
		}
		std::cout << std::endl;
	}
	else { // i-�� ��� ����� ����.
		int num1, num2;
		std::cout << "������� ��� �����: " << std::endl;
		std::cin >> num1 >> num2;
		int abs1, abs2;
		if (num1 <= 0) {
			abs1 = -num1;
		}
		else {
			abs1 = num1;
		}

		if (num2 <= 0) {
			abs2 = -num2;
		}
		else {
			abs2 = num2;
		}

		int maxAbs;

		if (abs1 > abs2) {
			maxAbs = num1;
		}
		else if (abs2 > abs1) {
			maxAbs = num2;
		}
		else {
			maxAbs = num1;
		}

		std::cout << "���������: " << maxAbs << maxAbs << std::endl;
	}
	return 0;
}