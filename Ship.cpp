#include "Ship.h"

Ship::Ship() {
    std::cout << "[Ship] Вызван конструктор базового класса.\n";
}

Ship::Ship(const Ship& other) : name(other.name) {
    std::cout << "[Ship] Вызван конструктор копирования базового класса.\n";
}

Ship::~Ship() {
    std::cout << "[Ship] Вызван деструктор базового класса.\n";
}

void Ship::Input() {
    std::cout << "Введите имя корабля: ";
    std::cin.ignore(); // очистка буфера
    std::getline(std::cin, name);
}

void Ship::Display() const {
    std::cout << "Имя корабля: " << name << std::endl;
}

void Ship::SaveToFile(std::ofstream& out) const {
    out << name << '\n';
}

void Ship::LoadFromFile(std::ifstream& in) {
    std::getline(in, name);
}
