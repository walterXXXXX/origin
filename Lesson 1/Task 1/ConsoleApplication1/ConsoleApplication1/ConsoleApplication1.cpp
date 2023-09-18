#include <iostream>
#include <fstream>
#include <string>

void crashedFile() {
    std::cout << "Файл входных данных <in.txt> поврежден. Завершение программы" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // открываем для чтения файл входных данных "in.txt"
    std::ifstream fin("in.txt");
    if (!fin.is_open()) {
        std::cout << "Ошибка открытия файла входных данных <in.txt>" << std::endl;
        return -1;
    }

    // открываем для записи файл выходных данных "out.txt"
    std::ofstream fout("out.txt");
    if (!fout.is_open()) {
        std::cout << "Ошибка открытия файла выходных данных <out.txt>" << std::endl;
        fin.close();
        return -1;
    }

    std::string str;

    // считываем из файла "in.txt" кол-во n элементов первого массива и создаем массив
    int n;

    if (!fin.eof()) {
        fin >> str;
        n = std::stoi(str);
    } 
    else { crashedFile(); fin.close(); fout.close(); return -1; }

    int* arr1 = new int[n]; // создаем динамический массив из n элементов

    // заполняем массив arr1 из файла "in.txt"
    for (int i = 0; i < n; i++) {
        if (!fin.eof()) { fin >> str; arr1[i] = std::stoi(str); }
        else { crashedFile(); fin.close(); fout.close(); delete[] arr1;  return -1; }
        //std::cout << arr1[i] << " ";
    }

    // считываем из файла кол-во m элементов второго массива
    int m;

    if (!fin.eof()) {
        fin >> str;
        m = std::stoi(str);
    }
    else { crashedFile(); fin.close(); fout.close(); delete[] arr1;  return -1; }

    int* arr2 = new int[m]; // создаем динамический массив из m элементов

    // заполняем массив arr2 из файла "in.txt"
    for (int i = 0; i < m; i++) {
        if (!fin.eof()) { fin >> str; arr2[i] = std::stoi(str); }
        else { crashedFile(); fin.close(); fout.close(); delete[] arr1; delete[] arr2; return -1; }
        //std::cout << arr2[i] << " ";
    }

    // выводим кол-во элементов и содержимое массива arr2 в файл "out.txt" со сдвигом вправо
    fout << m << std::endl;
    fout << arr2[m-1] << " ";
    for (int i = 0; i < m-1; i++) {
        fout << arr2[i] << " ";
    }
    fout << std::endl;

    // выводим кол-во элементов и содержимое массива arr1 в файл "out.txt" со сдвигом влево
    fout << n << std::endl;  
    for (int i = 1; i < n; i++) {
        fout << arr1[i] << " ";
    }
    fout << arr1[0];
    fout << std::endl;

    // закрываем файлы "in.txt" и "out.txt"
    fin.close(); fout.close();
  
    // освобождаем память от arr1, arr2
    delete[] arr1; delete[] arr2;
}
