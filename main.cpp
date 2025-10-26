#include <iostream>
#include <windows.h>
#include <fstream>
#include "Submarine.h"
// #include "Sailboat.h"
// #include "Motorboat.h"

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Ship** fleet = nullptr;  // массив указателей на корабли
    int fleetSize = 0;       // текущее количество кораблей
    int choice;

    do {
        std::cout << "\n==== Меню ====\n";
        std::cout << "1. Создать корабль\n";
        std::cout << "2. Показать все корабли\n";
        std::cout << "3. Сохранить все в файл\n";
        std::cout << "4. Загрузить все из файла\n";
        std::cout << "5. Удалить корабль по имени\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::string shipName, type;
                std::cout << "Введите имя корабля: ";
                std::getline(std::cin, shipName);
                std::cout << "Выберите тип корабля (submarine - 1 /sailboat- 2/ motorboat- 3): ";
                std::getline(std::cin, type);

                Ship* newShip = nullptr;
                if (type == "1") newShip = new Submarine();
                // else if (type == "sailboat") newShip = new Sailboat();
                // else if (type == "motorboat") newShip = new Motorboat();
                else {
                    std::cout << "Неизвестный тип корабля!\n";
                    break;
                }

                newShip->SetName(shipName);
                newShip->Input();

                // Расширяем массив на 1 элемент
                Ship** temp = new Ship*[fleetSize + 1];
                for (int i = 0; i < fleetSize; ++i) temp[i] = fleet[i];
                temp[fleetSize] = newShip;
                delete[] fleet;
                fleet = temp;
                fleetSize++;

                break;
            }

            case 2:
                if (fleetSize == 0) std::cout << "Нет данных!\n";
                else {
                    for (int i = 0; i < fleetSize; ++i) {
                        std::cout << "\n=== Корабль: " << fleet[i]->GetName() << " ===\n";
                        fleet[i]->Display();
                    }
                }
                break;

            case 3: {
                std::ofstream fout("ships.txt");
                if (!fout) { std::cerr << "Ошибка открытия файла!\n"; break; }
                fout << fleetSize << '\n';
                for (int i = 0; i < fleetSize; ++i)
                    fleet[i]->SaveToFile(fout);
                fout.close();
                std::cout << "Данные сохранены.\n";
                break;
            }

            case 4: {
                std::ifstream fin("ships.txt");
                if (!fin) { std::cerr << "Ошибка открытия файла!\n"; break; }

                for (int i = 0; i < fleetSize; ++i) delete fleet[i];
                delete[] fleet;
                fleet = nullptr;
                fleetSize = 0;

                fin >> fleetSize;
                fin.ignore();
                fleet = new Ship*[fleetSize];
                for (int i = 0; i < fleetSize; ++i) {
                    std::string type;
                    std::getline(fin, type);
                    Ship* ship = nullptr;
                    if (type == "Submarine") ship = new Submarine();
                    // else if (type == "Sailboat") ship = new Sailboat();
                    // else if (type == "Motorboat") ship = new Motorboat();
                    else {
                        std::cout << "Неизвестный тип корабля в файле!\n";
                        continue;
                    }
                    ship->LoadFromFile(fin);
                    fleet[i] = ship;
                }
                std::cout << "Данные загружены.\n";
                fin.close();
                break;
            }

            case 5: {
                if (fleetSize == 0) { std::cout << "Нет кораблей для удаления!\n"; break; }
                std::cin.ignore();
                std::string delName;
                std::cout << "Введите имя корабля для удаления: ";
                std::getline(std::cin, delName);

                int index = -1;
                for (int i = 0; i < fleetSize; ++i) {
                    if (fleet[i]->GetName() == delName) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) { std::cout << "Корабль с таким именем не найден.\n"; break; }

                delete fleet[index]; // удаляем объект

                // сдвигаем элементы массива
                for (int i = index; i < fleetSize - 1; ++i)
                    fleet[i] = fleet[i + 1];
                fleetSize--;

                Ship** temp = nullptr;
                if (fleetSize > 0) {
                    temp = new Ship*[fleetSize];
                    for (int i = 0; i < fleetSize; ++i) temp[i] = fleet[i];
                }
                delete[] fleet;
                fleet = temp;

                std::cout << "Корабль удалён.\n";
                break;
            }

            case 0:
                std::cout << "Выход из программы.\n";
                break;

            default:
                std::cout << "Неверный ввод!\n";
        }

    } while (choice != 0);

    for (int i = 0; i < fleetSize; ++i) delete fleet[i];
    delete[] fleet;

    return 0;
}
