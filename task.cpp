#include <iostream>

double average(int a, int b) {
    std::cout << "исп. функция среднего 2-х чисел" << std::endl;
    return (a + b) / 2.0; 
}

double average(int a, int b, int c) {
    std::cout << "исп. функция среднего 3х чисел" << std::endl;
    return (a + b + c) / 3.0; 
}

void calculateNumber() {
    int x;
    std::cout << "Введите целое число X (не 0): ";
    std::cin >> x;

    if (x == 0) {
        std::cout << "Ошибка: число не должно быть 0!" << std::endl;
        return;
    }

    double inv = 1.0 / x;

    int pow2 = x * x;

    int pow5 = x * x * x * x * x;

    std::cout << "Обратное число: " << inv << std::endl;
    std::cout << "2-я степень: " << pow2 << std::endl;
    std::cout << "5-я степень: " << pow5 << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    std::cout << "Выберите пункт (1 или 2): ";
    std::cin >> choice;

    if (choice == 1) {
        int a, b, c;
        std::cout << "Введите 3 числа: " << std::endl;
        std::cin >> a >> b >> c;

        int count = 0;
        if (a != 0) {
            count++;
        };
        if (b != 0) {
            count++;
        }
        if (c != 0) {
            count++;
        }

        double result;

        if (count == 2) {
            if (a == 0) {
                result = average(b, c);
            }
            else if (b == 0) {
                result = average(a, c);
            }
            else {
                result = average(a, b);
            }
        }
        else if (count == 3) {
            result = average(a, b, c);
        }
        else {
            std::cout << "Ошибка: должно быть 2 или 3 числа, отличных от нуля" << std::endl;
            return 1;
        }

        std::cout << "Результат: " << result << std::endl;
    }
    else if (choice == 2) {
        calculateNumber();
    }
    else {
        std::cout << "Такого пункта нет" << std::endl;
    }

    return 0;
}