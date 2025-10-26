#include "Submarine.h"
#include <iostream>
#include <cstring>
#include <stdexcept>

Submarine::Submarine() : length(0), width(0), crew(0),
                         underwaterTime(0), maxUnderwaterSpeed(0), armament(nullptr) {
    std::cout << "[Submarine] Вызван конструктор без параметров." << std::endl;
}

Submarine::Submarine(double len, double wid, int crewCount, double time, double speed, const char* weapon)
    : length(len), width(wid), crew(crewCount),
      underwaterTime(time), maxUnderwaterSpeed(speed) {
    armament = new char[strlen(weapon) + 1];
    strcpy(armament, weapon);
    std::cout << "[Submarine] Вызван конструктор с параметрами." << std::endl;
}

Submarine::Submarine(const Submarine& other)
    : length(other.length), width(other.width), crew(other.crew),
      underwaterTime(other.underwaterTime), maxUnderwaterSpeed(other.maxUnderwaterSpeed) {
    if (other.armament) {
        armament = new char[strlen(other.armament) + 1];
        strcpy(armament, other.armament);
    } else armament = nullptr;
    std::cout << "[Submarine] Вызван конструктор копирования." << std::endl;
}

Submarine::~Submarine() {
    delete[] armament;
    std::cout << "[Submarine] Вызван деструктор." << std::endl;
}

void Submarine::Input() {
    try {
        std::cout << "Введите длину: ";
        std::cin >> length;
        if (length <= 0) throw std::invalid_argument("Длина должна быть положительной.");

        std::cout << "Введите ширину: ";
        std::cin >> width;
        if (width <= 0) throw std::invalid_argument("Ширина должна быть положительной.");

        std::cout << "Введите экипаж: ";
        std::cin >> crew;
        if (crew < 0) throw std::invalid_argument("Экипаж не может быть отрицательным.");

        std::cout << "Введите время под водой (часы): ";
        std::cin >> underwaterTime;

        std::cout << "Введите максимальную подводную скорость: ";
        std::cin >> maxUnderwaterSpeed;

        char buffer[100];
        std::cout << "Введите вооружение: ";
        std::cin.ignore();
        std::cin.getline(buffer, 100);
        SetArmament(buffer);
    }
    catch (std::exception& e) {
        std::cerr << "Ошибка ввода: " << e.what() << std::endl;
    }
}

void Submarine::Display() const {
    std::cout << "\n=== Подводная лодка ===" << std::endl;
    std::cout << "Длина: " << length << std::endl;
    std::cout << "Ширина: " << width << std::endl;
    std::cout << "Экипаж: " << crew << std::endl;
    std::cout << "Время под водой: " << underwaterTime << " ч" << std::endl;
    std::cout << "Макс. подводная скорость: " << maxUnderwaterSpeed << " узлов" << std::endl;
    std::cout << "Вооружение: " << (armament ? armament : "нет") << std::endl;
}

void Submarine::SaveToFile(std::ofstream& out) const {
    out << GetType() << '\n'
        << length << '\n'
        << width << '\n'
        << crew << '\n'
        << underwaterTime << '\n'
        << maxUnderwaterSpeed << '\n'
        << (armament ? armament : "нет") << '\n';
}

void Submarine::LoadFromFile(std::ifstream& in) {
    char buffer[256];
    in >> length >> width >> crew >> underwaterTime >> maxUnderwaterSpeed;
    in.ignore();
    in.getline(buffer, 256);
    SetArmament(buffer);
}


void Submarine::SetLength(double l) { length = l; }
double Submarine::GetLength() const { return length; }

void Submarine::SetWidth(double w) { width = w; }
double Submarine::GetWidth() const { return width; }

void Submarine::SetCrew(int c) { crew = c; }
int Submarine::GetCrew() const { return crew; }

void Submarine::SetUnderwaterTime(double t) { underwaterTime = t; }
double Submarine::GetUnderwaterTime() const { return underwaterTime; }

void Submarine::SetSpeed(double s) { maxUnderwaterSpeed = s; }
double Submarine::GetSpeed() const { return maxUnderwaterSpeed; }

void Submarine::SetArmament(const char* weapon) {
    delete[] armament;
    armament = new char[strlen(weapon) + 1];
    strcpy(armament, weapon);
}
const char* Submarine::GetArmament() const { return armament; }
