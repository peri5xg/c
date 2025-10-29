#pragma once
#include "Ship.h"
#include "Submarine.h"
#include "Sailboat.h"
#include "Motorboat.h"
#include <iostream>
#include <fstream>

class Keeper {
private:
    Ship** ships;   // массив указателей на корабли
    int count;      // текущее количество
    int capacity;   // ёмкость

    void Expand();  // увеличение массива при нехватке места

public:
    Keeper();
    ~Keeper();

    void Add(Ship* ship);
    void RemoveByName(const std::string& name);
    void DisplayAll() const;

    void SaveToFile(const char* filename) const;
    void LoadFromFile(const char* filename);
};
