#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

class Ship {
protected:
    std::string name;  // имя корабля
public:
    Ship();
    Ship(const Ship& other);
    virtual ~Ship();

    void SetName(const std::string& n) { name = n; }
    std::string GetName() const { return name; }

    // Полиморфные методы
    virtual void Input();
    virtual void Display() const;
    virtual void SaveToFile(std::ofstream& out) const;
    virtual void LoadFromFile(std::ifstream& in);

    virtual std::string GetType() const = 0; // чисто виртуальная для типа корабля
};

#endif
