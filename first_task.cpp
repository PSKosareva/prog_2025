#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	int N;
	std::cout << "������� ���������� ����� (����� ������������������): " << std::endl;
	std::cin >> N;

	if (N <= 0) {
		std::cout << "���� ������������������ ������." << std::endl;
		return 0;
	}

	int first;
	int sum = 0;
	int minNum = 100000000;
	int minIndex = -1;
	bool found = 0;

	std::cout << "������� ������������������: " << std::endl;

	for (int i = 1; i <= N; i++) {
		int current;
		std::cout << "����� " << i << ": " << std::endl;
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
		std::cout << "��� ����� ������ �������" << std::endl;
	}
	else {
		std::cout << "����� ����� ������ �������: " << sum << std::endl;
		std::cout << "���������� �� ������������������ �����: " << minNum << std::endl;
		std::cout << "��� ����� � ������������������: " << minIndex << std::endl;
	}
	return 0;
}