#include "Keeper.h"

Keeper::Keeper() : ships(nullptr), count(0), capacity(0) {}

Keeper::~Keeper() {
    for (int i = 0; i < count; ++i)
        delete ships[i];
    delete[] ships;
}

void Keeper::Expand() {
    int newCapacity = (capacity == 0) ? 2 : capacity * 2;
    Ship** newArr = new Ship*[newCapacity];
    for (int i = 0; i < count; ++i)
        newArr[i] = ships[i];
    delete[] ships;
    ships = newArr;
    capacity = newCapacity;
}

void Keeper::Add(Ship* ship) {
    if (count >= capacity)
        Expand();
    ships[count++] = ship;
}

void Keeper::RemoveByName(const std::string& name) {
    for (int i = 0; i < count; ++i) {
        if (ships[i]->GetName() == name) {
            delete ships[i];
            for (int j = i; j < count - 1; ++j)
                ships[j] = ships[j + 1];
            --count;
            std::cout << "Корабль \"" << name << "\" удалён.\n";
            return;
        }
    }
    std::cout << "Корабль с именем \"" << name << "\" не найден.\n";
}

void Keeper::DisplayAll() const {
    if (count == 0) {
        std::cout << "Нет сохранённых кораблей.\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        std::cout << "\n--- Корабль " << (i + 1) << " ---\n";
        ships[i]->Display();
    }
}

void Keeper::SaveToFile(const char* filename) const {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Ошибка открытия файла для записи!\n";
        return;
    }

    out << count << '\n';
    for (int i = 0; i < count; ++i) {
        out << ships[i]->GetType() << '\n';
        ships[i]->SaveToFile(out);
    }

    out.close();
    std::cout << "Данные успешно сохранены.\n";
}

void Keeper::LoadFromFile(const char* filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Ошибка открытия файла для чтения!\n";
        return;
    }

    for (int i = 0; i < count; ++i)
        delete ships[i];
    delete[] ships;
    ships = nullptr;
    count = 0;
    capacity = 0;

    int num;
    in >> num;
    in.ignore();

    for (int i = 0; i < num; ++i) {
        std::string type;
        std::getline(in, type);

        Ship* ship = nullptr;
        if (type == "Submarine")
            ship = new Submarine();
        else if (type == "Sailboat")
            ship = new Sailboat();
        else if (type == "Motorboat")
            ship = new Motorboat();
        else {
            std::cerr << "Неизвестный тип корабля: " << type << "\n";
            continue;
        }

        ship->LoadFromFile(in);
        Add(ship);
    }

    in.close();
    std::cout << "Данные успешно загружены.\n";
}
