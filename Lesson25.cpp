#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
const int SIZE = 5;

//������� 1 
//�������� ��������� ������� ��������� �� ����� ������ � ��������� ����
// - �������� ������
// - ���� ������
// - ���������� ������
//�������� � ����� ���� ������ � ������� ���� > 500
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
        cout << "�� ������� ������� ����";
        return nullptr;
    }
    count = 0;
    Product temp;
   // while(!file.eof())
    //while(file.good())
    while (file >> temp.name >> temp.price >> temp.count) {
        count++;
    }
    file.clear();//���������� eof ����� ����� ������ �������
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
        cout << "�� ������� ������� ����";
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

//�������� ��������� ������� ���������� � �������� ���� ������������������ ����� �����
//��������� �� �� ����� �����������
//� ������ ����

//ofstream file(fileName, ios::binary);

//fileName.bin //fileName.dat
//file.write();
//file.read();

//�����
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