#include <iostream>
#include <windows.h>
#include "Keeper.h"

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Keeper keeper;
    int choice;

    do {
        std::cout << "\n==== Меню ====\n";
        std::cout << "1. Добавить корабль\n";
        std::cout << "2. Показать все корабли\n";
        std::cout << "3. Удалить корабль по имени\n";
        std::cout << "4. Сохранить всё в файл\n";
        std::cout << "5. Загрузить всё из файла\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::string name;
                std::cout << "Введите имя корабля: ";
                std::getline(std::cin, name);

                std::cout << "Выберите тип:\n";
                std::cout << "1. Подводная лодка\n";
                std::cout << "2. Парусник\n";
                std::cout << "3. Катер\n";
                std::cout << "Ваш выбор: ";
                int t;
                std::cin >> t;

                Ship* newShip = nullptr;
                switch (t) {
                    case 1: newShip = new Submarine(); break;
                    case 2: newShip = new Sailboat(); break;
                    case 3: newShip = new Motorboat(); break;
                    default: std::cout << "Неверный выбор!\n"; break;
                }

                if (newShip) {
                    newShip->SetName(name);
                    newShip->Input();
                    keeper.Add(newShip);
                }
                break;
            }

            case 2:
                keeper.DisplayAll();
                break;

            case 3: {
                std::cin.ignore();
                std::string name;
                std::cout << "Введите имя корабля для удаления: ";
                std::getline(std::cin, name);
                keeper.RemoveByName(name);
                break;
            }

            case 4:
                keeper.SaveToFile("ships.txt");
                break;

            case 5:
                keeper.LoadFromFile("ships.txt");
                break;

            case 0:
                std::cout << "Выход из программы.\n";
                break;

            default:
                std::cout << "Неверный ввод!\n";
        }

    } while (choice != 0);

    return 0;
}
