// Написать программу «справочник».Создать два одномерных
// массива.Один массив хранит номера мобильных телефонов,
// второй — домашние телефонные номера.
// Реализовать меню для пользователя :
// ■ Отсортировать по номерам мобильных
// ■ Отсортировать по домашним номерам телефонов;
// ■ Вывести пользовательский данные;
// ■ Выход.

#include <iostream>
#include <windows.h>
#include <random>
using namespace std;

enum  PhoneType
{
    MobilePhone,
    HomePhone
};

void FillPhonesNumbers(long long int* arr, int size, PhoneType type);
void PrintArray(long long int* arr, int size, PhoneType type);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 10;        
    long long int MobilePhones[size];
    long long int HomePhones[size];

    FillPhonesNumbers(MobilePhones, size, MobilePhone);
    FillPhonesNumbers(HomePhones, size, HomePhone);
    PrintArray(MobilePhones, size, MobilePhone);
    PrintArray(HomePhones, size, HomePhone);
    cout << "Hello World!\n";
}

void FillPhonesNumbers(long long int* arr, int size, PhoneType type) {
    random_device random;
    int operators[] = { 955, 921, 988, 923 };
    int sizePhoneNumber = (type == MobilePhone) ? 11 : 7;

    for (long long int* i = arr; i < arr + size; i++) {
        *i = (type == MobilePhone) ? 7 : 7812;

        for (int j = (type == MobilePhone) ? 1 : 0; j < sizePhoneNumber; j++) {
            int digit = random() % 10;  
            *i = *i * 10 + digit;       
        }
    }
}

// В этом случае не обязательно использовать указатель, но для закрепления.
void PrintArray(long long int* arr, int size, PhoneType type) {

    cout << (type == MobilePhone ? "Список мобильных номеров" : "Список городских номеров") << endl;
    for (long long int* i = arr; i < arr + size; i++)
    {
        cout << "[ " << *i << " ]" << endl;
    }
}

