#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle() : mark(""), model("") {
    std::cout << "Vehicle: Constructor without parameters called." << std::endl;
}

Vehicle::Vehicle(const std::string& mark, const std::string& model) : mark(mark), model(model) {
    std::cout << "Vehicle: Constructor with parameters called: " << mark << ", " << model << std::endl;
}

Vehicle::Vehicle(const Vehicle& other) : mark(other.mark), model(other.model) {
    std::cout << "Vehicle: Copy constructor called." << std::endl;
}

Vehicle::~Vehicle() {
    std::cout << "Vehicle: Destructor called." << std::endl;
}

std::string Vehicle::getMark() const { return mark; }
void Vehicle::setMark(const std::string& mark) { this->mark = mark; }
std::string Vehicle::getModel() const { return model; }
void Vehicle::setModel(const std::string& model) { this->model = model; }
