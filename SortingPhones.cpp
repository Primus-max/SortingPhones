﻿// Написать программу «справочник».Создать два одномерных
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

void FillPhonesNumbers(long long int* arr, int* identifiers, int size, PhoneType type);
void PrintArray(long long int* arr, int* identifires, int size, PhoneType type);
void SortByMobilePhones(long long int* mobilePhones, long long int* homePhones, int* identifiers, int size);
void SortByHomePhones(long long int* mobilePhones, long long int* homePhones, int* identifiers, int size);
void DisplayMenu();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 10;        
    long long int MobilePhones[size];
    long long int HomePhones[size];
    int Id[size];

    FillPhonesNumbers(MobilePhones, Id, size, MobilePhone);
    FillPhonesNumbers(HomePhones, Id, size, HomePhone);
   // PrintArray(MobilePhones, Id, size, MobilePhone);

    int userChoice;
    do {
        DisplayMenu();
        cout << "Выберите действие (1-4): " ;
        cin >> userChoice;
        cout << "\n";
        switch (userChoice) {
        case 1:
            SortByMobilePhones(MobilePhones, HomePhones, Id, size);            
            break;
        case 2:
            SortByHomePhones(MobilePhones, HomePhones, Id, size);
            break;
        case 3:
            PrintArray(MobilePhones, Id, size, MobilePhone);
            PrintArray(HomePhones, Id, size, HomePhone);
            break;
        case 4:
            cout << "До свидания!\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    } while (userChoice != 4);
    
}

void FillPhonesNumbers(long long int* arr, int* identifiers,  int size, PhoneType type) {
    random_device random;
    int operators[] = { 955, 921, 988, 923 };
    int sizePhoneNumber = (type == MobilePhone) ? 11 : 7;

    for (long long int* i = arr; i < arr + size; ++i) {
        // Инициализация префикса (префикса/кода)
        *i = (type == MobilePhone) ? 7 : 7812;

        // Выбор случайного оператора
        int randomOperatorIndex = random() % (sizeof(operators) / sizeof(operators[0]));
        int selectedOperator = operators[randomOperatorIndex];

        if (type == MobilePhone)
            *i = *i * 1000 + selectedOperator;

        // Генерация оставшихся цифр номера телефона
        for (int j = (type == MobilePhone) ? 4 : 0; j < sizePhoneNumber; j++) {
            int digit = random() % 10;
            *i = *i * 10 + digit;
        }
    }

    for (int i = 0; i < size; i++)
    {
        identifiers[i] = i;
    }
}


// В этом случае не обязательно использовать указатель, но для закрепления.
void PrintArray(long long int* arr, int* identifiers, int size, PhoneType type) {
    cout << (type == MobilePhone ? "Список мобильных номеров" : "Список городских номеров") << endl;
    cout << "\n";
    for (int i = 0; i < size; i++) {
        cout << identifiers[i] << ". " << "[ " << arr[i] << " ]" << endl;
    }
    cout << "-----------------------------------------------" << endl;
}


void SortByMobilePhones(long long int* mobilePhones, long long int* homePhones, int* identifiers, int size) {
    for (int i = size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (mobilePhones[j] > mobilePhones[j + 1]) {
              
                long long int tempMobile = mobilePhones[j];
                mobilePhones[j] = mobilePhones[j + 1];
                mobilePhones[j + 1] = tempMobile;

                long long int tempHome = homePhones[j];
                homePhones[j] = homePhones[j + 1];
                homePhones[j + 1] = tempHome;

                int tempId = identifiers[j];
                identifiers[j] = identifiers[j + 1];
                identifiers[j + 1] = tempId;
            }
        }
    }
}

void SortByHomePhones(long long int* mobilePhones, long long int* homePhones, int* identifiers, int size) {
   

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (homePhones[identifiers[j] - 1] > homePhones[identifiers[j + 1] - 1]) {
                
                long long int tempMobile = mobilePhones[j];
                mobilePhones[j] = mobilePhones[j + 1];
                mobilePhones[j + 1] = tempMobile;

                long long int tempHome = homePhones[j];
                homePhones[j] = homePhones[j + 1];
                homePhones[j + 1] = tempHome;

                int tempId = identifiers[j];
                identifiers[j] = identifiers[j + 1];
                identifiers[j + 1] = tempId;
            }
        }
    }
}




void DisplayMenu() {
    cout << "Меню:\n";
    cout << "1. Отсортировать по номерам мобильных телефонов\n";
    cout << "2. Отсортировать по домашним номерам телефонов\n";
    cout << "3. Вывести пользовательские данные\n";
    cout << "4. Выход\n";
}


