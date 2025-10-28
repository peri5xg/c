#include "Motorboat.h"
#include <stdexcept>

Motorboat::Motorboat()
    : purpose(""), hullMaterial(""), performance(""),
      speed(0), capacity(0) {
    std::cout << "[Motorboat] Вызван конструктор без параметров.\n";
}

Motorboat::Motorboat(const Motorboat& other)
    : purpose(other.purpose), hullMaterial(other.hullMaterial),
      performance(other.performance), speed(other.speed),
      capacity(other.capacity) {
    std::cout << "[Motorboat] Вызван конструктор копирования.\n";
}

Motorboat::~Motorboat() {
    std::cout << "[Motorboat] Вызван деструктор.\n";
}

void Motorboat::Input() {
    //Ship::Input();

    try {
        std::cout << "Введите назначение катера: ";
        std::getline(std::cin, purpose);

        std::cout << "Введите материал корпуса: ";
        std::getline(std::cin, hullMaterial);

        std::cout << "Введите ходовые качества: ";
        std::getline(std::cin, performance);

        std::cout << "Введите скорость (узлы): ";
        std::cin >> speed;
        if (speed <= 0) throw std::invalid_argument("Скорость должна быть положительной.");

        std::cout << "Введите количество людей на борту: ";
        std::cin >> capacity;
        if (capacity < 0) throw std::invalid_argument("Количество людей не может быть отрицательным.");
    }
    catch (std::exception& e) {
        std::cerr << "Ошибка ввода: " << e.what() << std::endl;
    }
}

void Motorboat::Display() const {
    std::cout << "\n=== Катер ===\n";
    Ship::Display();
    std::cout << "Назначение: " << (purpose.empty() ? "не указано" : purpose) << std::endl;
    std::cout << "Материал корпуса: " << (hullMaterial.empty() ? "не указан" : hullMaterial) << std::endl;
    std::cout << "Ходовые качества: " << (performance.empty() ? "не указаны" : performance) << std::endl;
    std::cout << "Скорость: " << speed << " узлов" << std::endl;
    std::cout << "Вместимость: " << capacity << " человек\n";
}

void Motorboat::SaveToFile(std::ofstream& out) const {
    out << GetType() << '\n';
    Ship::SaveToFile(out);
    out << purpose << '\n'
        << hullMaterial << '\n'
        << performance << '\n'
        << speed << '\n'
        << capacity << '\n';
}

void Motorboat::LoadFromFile(std::ifstream& in) {
    Ship::LoadFromFile(in);
    std::getline(in, purpose);
    std::getline(in, hullMaterial);
    std::getline(in, performance);
    in >> speed;
    in >> capacity;
    in.ignore();
}
