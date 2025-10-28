#pragma once
#include "Ship.h"
#include <iostream>
#include <fstream>
#include <string>

class Sailboat : public Ship {
private:
    std::string type;   // тип парусника (Бриг, Фрегат и т.д.)
    bool isMilitary;    // военный или нет
    double length;      // длина корпуса
    double speed;       // скорость
    int crew;           // экипаж

public:
    Sailboat();
    Sailboat(const Sailboat& other);
    ~Sailboat();

    void Input() override;
    void Display() const override;
    void SaveToFile(std::ofstream& out) const override;
    void LoadFromFile(std::ifstream& in) override;

    std::string GetType() const override { return "Sailboat"; }

    // Сеттеры и геттеры
    void SetType(const std::string& t) { type = t; }
    std::string GetTypeName() const { return type; }

    void SetIsMilitary(bool m) { isMilitary = m; }
    bool GetIsMilitary() const { return isMilitary; }

    void SetLength(double l) { length = l; }
    double GetLength() const { return length; }

    void SetSpeed(double s) { speed = s; }
    double GetSpeed() const { return speed; }

    void SetCrew(int c) { crew = c; }
    int GetCrew() const { return crew; }
};
