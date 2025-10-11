#include <iostream>
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

	std::bitset<8> bitsA(A);
	std::cout << A << " = " << bitsA << std::endl;

	int bitValue = bitsA[i]; 
	std::cout << "�������� " << i << "-�� ���� � " << bitValue << std::endl;

	if (bitValue != 0) {
		bitsA ^= std::bitset<8>(1 << i); 
		A = static_cast<int>(bitsA.to_ulong()); 

		std::cout << "��������� ����� �������� " << i << "-�� ����: "
			<< A << " = " << bitsA << std::endl;
	}
	else { 
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