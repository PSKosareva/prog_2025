#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	int N, M;
	std::cout << "������� ������ ����� (1-9): ";
	std::cin >> N;
	std::cout << "������� ������ ����� (1-9): ";
	std::cin >> M;
	std::cout << std::endl;

	//��������
	if (N < 1 || N > 9 || M < 1 || M > 9) {
		std::cout << "������! ����� ������ ���� �� 1 �� 9" << std::endl;
		return 1;
	}

	int number = N * 10 + M;

	if (N == M && number <= 90) {
		switch (number) {
		case 11:
			std::cout << "���������� �������" << std::endl;
			break;
		case 22:
			std::cout << "�����" << std::endl;
			break;
		case 33:
			std::cout << "�������� ���" << std::endl;
			break;
		case 44:
			std::cout << "���������" << std::endl;
			break;
		case 55:
			std::cout << "��������" << std::endl;
			break;
		case 66:
			std::cout << "�������" << std::endl;
			break;
		case 77:
			std::cout << "��������" << std::endl;
			break;
		case 88:
			std::cout << "�������" << std::endl;
			break;
		default:
			std::cout << "�� �����" << std::endl;
		}
	}
	else {
		std::cout << "����� �� ����� :(" << std::endl;
		std::cout << "�������: ";
		if (N != M) {
			std::cout << "����� N � M ������" << std::endl;
		}
		if (number > 90) {
			std::cout << "����� ������ 90 - ������ � ���� �� ����������" << std::endl;
		}
	}
	return 0;
}