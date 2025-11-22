#include <iostream>

void iHopeAtLeastItsOkay() {
    float a, b;
    std::cout << "Введите A: ";
    std::cin >> a;
    std::cout << "Введите B: ";
    std::cin >> b;

    float* newA = new float(a);
    float* newB = new float(b);

    std::cout << "До преобразований: A = " << a << ", B = " << b << std::endl;

    *newA *= 3; 

    std::cout << "После увеличения A в 3 раза: " << *newA << std::endl;

    float temp = *newA;
    *newA = *newB;
    *newB = temp;

    a = *newA;
    b = *newB;

    std::cout << "После обмена: A = " << a << ", B = " << b << std::endl;

    delete newA;
    delete newB;
}

int main() {
    setlocale(LC_ALL, "RU");
    iHopeAtLeastItsOkay();
}
