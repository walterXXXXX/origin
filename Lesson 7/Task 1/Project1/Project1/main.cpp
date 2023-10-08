#include <iostream>

#define MODE 1

#ifndef MODE
#error ��������� MODE �� ����������
#endif // !MODE

// #define ADD(a, b) ((a) + (b))
// �������� ������� ����� ������, �� � ������� ������� ������� ������ ����� �������

#if MODE == 1
int ADD(int num1, int num2) {
	return num1 + num2;
}
#endif

int main() {

	setlocale(LC_ALL, "Russian");

#if MODE == 0
	std::cout << "������� � ������ ����������" << std::endl;
#elif MODE == 1
	int num1, num2;
	std::cout << "������� � ������ ������" << std::endl;
	std::cout << "������� ����� 1: "; std::cin >> num1;
	std::cout << "������� ����� 2: "; std::cin >> num2;
	std::cout << "��������� ��������: " << ADD(num1, num2) << std::endl;
#else 
	std::cout << "����������� �����. ���������� ������" << std::endl;
#endif

}