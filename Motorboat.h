#pragma once
#include "Ship.h"
#include <iostream>
#include <fstream>
#include <string>

class Motorboat : public Ship {
private:
    std::string purpose;       // назначение
    std::string hullMaterial;  // материал корпуса
    std::string performance;   // ходовые качества
    double speed;              // скорость
    int capacity;              // количество людей

public:
    Motorboat();
    Motorboat(const Motorboat& other);
    ~Motorboat();

    void Input() override;
    void Display() const override;
    void SaveToFile(std::ofstream& out) const override;
    void LoadFromFile(std::ifstream& in) override;

    std::string GetType() const override { return "Motorboat"; }

    // Сеттеры и геттеры
    void SetPurpose(const std::string& p) { purpose = p; }
    std::string GetPurpose() const { return purpose; }

    void SetHullMaterial(const std::string& m) { hullMaterial = m; }
    std::string GetHullMaterial() const { return hullMaterial; }

    void SetPerformance(const std::string& perf) { performance = perf; }
    std::string GetPerformance() const { return performance; }

    void SetSpeed(double s) { speed = s; }
    double GetSpeed() const { return speed; }

    void SetCapacity(int c) { capacity = c; }
    int GetCapacity() const { return capacity; }
};
