#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
const int SIZE = 5;

//Задание 1 
//Написать программу которая считывает из файла товары в структуру вида
// - Название товара
// - Цена товара
// - Количество товара
//Записать в новый файл товары у которых цена > 500
//apple 200 10
//orange 300 10
struct Product {
    char name[30];
    double price;
    int count;
};
Product* loadProducts(const char* fileName, int& count) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл";
        return nullptr;
    }
    count = 0;
    Product temp;
   // while(!file.eof())
    //while(file.good())
    while (file >> temp.name >> temp.price >> temp.count) {
        count++;
    }
    file.clear();//сбрасывает eof чтобы снова читать сначала
    file.seekg(0, ios::beg);
    Product* products = new Product[count];
    for (int i = 0; i < count; i++) {
        file >> products[i].name
            >> products[i].price
            >> products[i].count;
    }
    file.close();
    return products;

}
void PrintProducts(Product* products, int count) {
    for (int i = 0; i < count; i++) {
        cout << products[i].name << " " << products[i].price
            <<" " << products[i].count << endl;
    }
}
void saveFileteredProduct(Product* products, int count, const char* fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл";
        return;
        }
    for (int i = 0; i < count; i++) {
        if (products[i].price > 500) {
            file << products[i].name << " " << products[i].price
                << " " << products[i].count << endl;
        }
    }
    file.close();
}

//Написать программу которая записывает в бинарный файл последовательность целых чисел
//считывает их из файла инвертирует
//в другой файл

//ofstream file(fileName, ios::binary);

//fileName.bin //fileName.dat
//file.write();
//file.read();

//порор
//rbvbn
int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    /*int count;
    Product* product = loadProducts("file.txt", count);
    if (product != nullptr) {
        saveFileteredProduct(product, count, "filter.txt");
    }
    delete[] product;*/
    //Write("number.bin");
    //Read("number.bin");

}