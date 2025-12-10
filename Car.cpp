#include "Car.h"
#include <iostream>
#include <fstream>  // Добавлено для исправления ошибки компиляции

Car::Car() : engineVolume(0.0), color(""), transmissionType("") {
    std::cout << "Car: Constructor without parameters called." << std::endl;
}

Car::Car(const std::string& mark, const std::string& model, double engineVolume, const std::string& color, const std::string& transmissionType)
    : Vehicle(mark, model), engineVolume(engineVolume), color(color), transmissionType(transmissionType) {
    std::cout << "Car: Constructor with parameters called." << std::endl;
}

Car::Car(const Car& other) : Vehicle(other), engineVolume(other.engineVolume), color(other.color), transmissionType(other.transmissionType) {
    std::cout << "Car: Copy constructor called." << std::endl;
}

Car::~Car() {
    std::cout << "Car: Destructor called." << std::endl;
}

double Car::getEngineVolume() const { return engineVolume; }
void Car::setEngineVolume(double volume) { engineVolume = volume; }
std::string Car::getColor() const { return color; }
void Car::setColor(const std::string& color) { this->color = color; }
std::string Car::getTransmissionType() const { return transmissionType; }
void Car::setTransmissionType(const std::string& type) { transmissionType = type; }

void Car::print() const {
    std::cout << "Car: " << mark << " " << model << ", Engine: " << engineVolume << ", Color: " << color << ", Transmission: " << transmissionType << std::endl;
}

void Car::serialize(std::ofstream& out) const {
    out << "C " << mark << " " << model << " " << engineVolume << " " << color << " " << transmissionType << std::endl;
}

void Car::deserialize(std::ifstream& in) {
    in >> mark >> model >> engineVolume >> color >> transmissionType;
}

Vehicle* Car::clone() {
    return new Car(*this);
}
