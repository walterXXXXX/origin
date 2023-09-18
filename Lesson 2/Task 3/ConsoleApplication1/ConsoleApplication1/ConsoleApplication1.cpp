#include <iostream>

struct Adress {
    std::string city;
    std::string street;
    std::string home;
    std::string flat;
    std::string index;
};

void showAdress(const Adress& aAdress) {
    std::cout << "Город: " << aAdress.city << std::endl;
    std::cout << "Улица: " << aAdress.street << std::endl;
    std::cout << "Номер дома: " << aAdress.home << std::endl;
    std::cout << "Номер квартиры: " << aAdress.flat << std::endl;
    std::cout << "Индекс: " << aAdress.index << std::endl << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Adress addr1 = { "Москва", "Арбат", "12", "8", "123456" };
    Adress addr2 = { "Ижевск", "Пушкина", "59", "143", "953769" };

    showAdress(addr1);

    showAdress(addr2);

}

