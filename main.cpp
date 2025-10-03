/*
7 �������
������ ���������������� (25.09.2025)
*/

#include <iostream>
#include <limits>

int main() {
	setlocale(LC_ALL, "RU");
	int x;
	/* 
	��� ������ ���� ��� ������, ��-������, ������ ��� ����� ������ ���� �����, � �� ������� (int ��� ������������),
	��-������, ������ ��� ���������� � ������ ����� ��������� ����� (x^2 � x^5 ������� ����� ����� �����, � 1.0/x �����
	������������� ���������� � ����� ������ double 
	*/

	std::cout << "������� ����� ����� x (�� 0): " << std::endl;
	std::cin >> x;
	if (x == 0) {
		std::cout << "����� �� ������ ���� ����� ����!" << std::endl;
		return 1;
	} else {
		std::cout << "���: int" << std::endl;
		std::cout << "������ � �����: " << sizeof(int) * 8 << std::endl;
		std::cout << "����������� ��������: " << std::numeric_limits<int>::min() << std::endl;
		std::cout << "������������ ��������: " << std::numeric_limits<int>::max() << std::endl;
		std::cout << "�������� �����: " << 1.0 / x << "\n";  // �������
		std::cout << "���: double" << std::endl;
		std::cout << "������ � �����: " << sizeof(double) * 8 << std::endl;
		std::cout << "����������� ��������: " << std::numeric_limits<double>::lowest() << std::endl;
		std::cout << "������������ ��������: " << std::numeric_limits<double>::max() <<  std::endl;
		std::cout << "������� �����: " << x * x << "\n";           // �������
		std::cout << "����� �������: " << x * x * x * x * x       // ����� �������
		<< std::endl;
		return 0;
	}
}
