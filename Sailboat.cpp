#include "Sailboat.h"
#include <stdexcept>

Sailboat::Sailboat() : type(""), isMilitary(false), length(0), speed(0), crew(0) {
    std::cout << "[Sailboat] Вызван конструктор без параметров.\n";
}

Sailboat::Sailboat(const Sailboat& other)
    : type(other.type), isMilitary(other.isMilitary),
      length(other.length), speed(other.speed), crew(other.crew) {
    std::cout << "[Sailboat] Вызван конструктор копирования.\n";
}

Sailboat::~Sailboat() {
    std::cout << "[Sailboat] Вызван деструктор.\n";
}

void Sailboat::Input() {
    //Ship::Input();

    try {
        std::cout << "Введите тип парусника: ";
        std::getline(std::cin, type);

        std::cout << "Это военный парусник? (1 - да, 0 - нет): ";
        int flag;
        std::cin >> flag;
        isMilitary = (flag == 1);

        std::cout << "Введите длину корпуса: ";
        std::cin >> length;
        if (length <= 0) throw std::invalid_argument("Длина должна быть положительной.");

        std::cout << "Введите скорость (узлы): ";
        std::cin >> speed;
        if (speed <= 0) throw std::invalid_argument("Скорость должна быть положительной.");

        std::cout << "Введите экипаж: ";
        std::cin >> crew;
        if (crew < 0) throw std::invalid_argument("Экипаж не может быть отрицательным.");
    }
    catch (std::exception& e) {
        std::cerr << "Ошибка ввода: " << e.what() << std::endl;
    }
}

void Sailboat::Display() const {
    std::cout << "\n=== Парусник ===\n";
    Ship::Display();
    std::cout << "Тип: " << (type.empty() ? "неизвестен" : type) << std::endl;
    std::cout << "Назначение: " << (isMilitary ? "Военный" : "Мирный") << std::endl;
    std::cout << "Длина корпуса: " << length << " м" << std::endl;
    std::cout << "Скорость: " << speed << " узлов" << std::endl;
    std::cout << "Экипаж: " << crew << std::endl;
}

void Sailboat::SaveToFile(std::ofstream& out) const {
    out << GetType() << '\n';
    Ship::SaveToFile(out);
    out << type << '\n'
        << isMilitary << '\n'
        << length << '\n'
        << speed << '\n'
        << crew << '\n';
}

void Sailboat::LoadFromFile(std::ifstream& in) {
    Ship::LoadFromFile(in);
    std::getline(in, type);
    in >> isMilitary;
    in >> length;
    in >> speed;
    in >> crew;
    in.ignore();
}
