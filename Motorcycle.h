#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"

class Motorcycle : public Vehicle {
private:
    double engineVolume;
    double power;
    std::string terrain;
public:
    Motorcycle();
    Motorcycle(const std::string& mark, const std::string& model, double engineVolume, double power, const std::string& terrain);
    Motorcycle(const Motorcycle& other);
    ~Motorcycle();
    double getEngineVolume() const;
    void setEngineVolume(double volume);
    double getPower() const;
    void setPower(double power);
    std::string getTerrain() const;
    void setTerrain(const std::string& terrain);
    void print() const override;
    void serialize(std::ofstream& out) const override;
    void deserialize(std::ifstream& in) override;
    Vehicle* clone() override;
};

#endif
#pragma once
