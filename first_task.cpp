#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	int arr[10];

	std::cout << "������� 10 �����" << std::endl;
	for(int i = 0; i < 10; i++) {
		std::cout << "����� " << int(i + 1) << ": " << std::endl;
		std::cin >> arr[i];
	}

	if (arr[0] > arr[9]) {
		for (int i = 0; i < 10; i++) {
			for (int j = i + 1; j < 10; j++) {
				if (arr[i] > arr[j]) {
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		std::cout << "������ ������������!" << std::endl;
	}
	else {
		std::cout << "���������� �� �����" << std::endl;
	}
	std::cout << "���������: ";
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << ", ";
	}

	return 0;
}