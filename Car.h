#pragma once
#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : public Vehicle {
private:
    double engineVolume;
    std::string color;
    std::string transmissionType;
public:
    Car();
    Car(const std::string& mark, const std::string& model, double engineVolume, const std::string& color, const std::string& transmissionType);
    Car(const Car& other);
    ~Car();
    double getEngineVolume() const;
    void setEngineVolume(double volume);
    std::string getColor() const;
    void setColor(const std::string& color);
    std::string getTransmissionType() const;
    void setTransmissionType(const std::string& type);
    void print() const override;
    void serialize(std::ofstream& out) const override;
    void deserialize(std::ifstream& in) override;
    Vehicle* clone() override;
};

#endif
