#include "Motorcycle.h"
#include <iostream>
#include <fstream>  // Добавлено для исправления ошибки компиляции

Motorcycle::Motorcycle() : engineVolume(0.0), power(0.0), terrain("") {
    std::cout << "Motorcycle: Constructor without parameters called." << std::endl;
}

Motorcycle::Motorcycle(const std::string& mark, const std::string& model, double engineVolume, double power, const std::string& terrain)
    : Vehicle(mark, model), engineVolume(engineVolume), power(power), terrain(terrain) {
    std::cout << "Motorcycle: Constructor with parameters called." << std::endl;
}

Motorcycle::Motorcycle(const Motorcycle& other) : Vehicle(other), engineVolume(other.engineVolume), power(other.power), terrain(other.terrain) {
    std::cout << "Motorcycle: Copy constructor called." << std::endl;
}

Motorcycle::~Motorcycle() {
    std::cout << "Motorcycle: Destructor called." << std::endl;
}

double Motorcycle::getEngineVolume() const { return engineVolume; }
void Motorcycle::setEngineVolume(double volume) { engineVolume = volume; }
double Motorcycle::getPower() const { return power; }
void Motorcycle::setPower(double power) { this->power = power; }
std::string Motorcycle::getTerrain() const { return terrain; }
void Motorcycle::setTerrain(const std::string& terrain) { this->terrain = terrain; }

void Motorcycle::print() const {
    std::cout << "Motorcycle: " << mark << " " << model << ", Engine: " << engineVolume << ", Power: " << power << ", Terrain: " << terrain << std::endl;
}

void Motorcycle::serialize(std::ofstream& out) const {
    out << "M " << mark << " " << model << " " << engineVolume << " " << power << " " << terrain << std::endl;
}

void Motorcycle::deserialize(std::ifstream& in) {
    in >> mark >> model >> engineVolume >> power >> terrain;
}

Vehicle* Motorcycle::clone() {
    return new Motorcycle(*this);
}
