#include <iostream>

enum class Monthes {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OKTOBER,
    NOVEMBER,
    DECEMBER
};

int main()
{
    setlocale(LC_ALL, "Russian");

    int num;
    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> num;
        if (num < 0 || num > 12) {
            std::cout << "Неправильный номер!" << std::endl;
            continue;
        }
        switch (static_cast<Monthes>(num)) {
            case Monthes::JANUARY:
                std::cout << "Январь" << std::endl; break;
            case Monthes::FEBRUARY:
                std::cout << "Февраль" << std::endl; break;
            case Monthes::MARCH:
                std::cout << "Март" << std::endl; break;
            case Monthes::APRIL:
                std::cout << "Апрель" << std::endl; break;
            case Monthes::MAY:
                std::cout << "Май" << std::endl; break;
            case Monthes::JUNE:
                std::cout << "Июнь" << std::endl; break;
            case Monthes::JULY:
                std::cout << "Июль" << std::endl; break;
            case Monthes::AUGUST:
                std::cout << "Август" << std::endl; break;
            case Monthes::SEPTEMBER:
                std::cout << "Сентябрь" << std::endl; break;
            case Monthes::OKTOBER:
                std::cout << "Октябрь" << std::endl; break;
            case Monthes::NOVEMBER:
                std::cout << "Ноябрь" << std::endl; break;
            case Monthes::DECEMBER:
                std::cout << "Декабрь" << std::endl; break;
        }
    } while (num);
    
    std::cout << "До свидания\n";
}

