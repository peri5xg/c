#include "Keeper.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
#include <fstream>
#include <iostream>

Keeper::Keeper() : vehicles(nullptr), size(0) {
    std::cout << "Keeper: Constructor called." << std::endl;
}

Keeper::~Keeper() {
    std::cout << "Keeper: Destructor called. Cleaning up..." << std::endl;
    for (int i = 0; i < size; ++i) {
        delete vehicles[i];
    }
    delete[] vehicles;
}

void Keeper::add(Vehicle* v) {
    Vehicle** newVehicles = new Vehicle * [size + 1];
    for (int i = 0; i < size; ++i) {
        newVehicles[i] = vehicles[i];
    }
    newVehicles[size] = v;
    delete[] vehicles;
    vehicles = newVehicles;
    ++size;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size) {
        throw IndexOutOfRangeException();
    }
    delete vehicles[index];
    for (int i = index; i < size - 1; ++i) {
        vehicles[i] = vehicles[i + 1];
    }
    --size;
    Vehicle** newVehicles = new Vehicle * [size];
    for (int i = 0; i < size; ++i) {
        newVehicles[i] = vehicles[i];
    }
    delete[] vehicles;
    vehicles = newVehicles;
}

void Keeper::show() const {
    for (int i = 0; i < size; ++i) {
        std::cout << i << ": ";
        vehicles[i]->print();
    }
}

void Keeper::edit(int index) {
    if (index < 0 || index >= size) {
        throw IndexOutOfRangeException();
    }
    std::string param;
    std::cout << "Editing object at index " << index << ". Type: ";
    vehicles[index]->print();
    // Здесь можно добавить меню редактирования, но для простоты пропустим (или расширить по типу объекта)
    std::cout << "Edit not fully implemented in demo; use getters/setters directly." << std::endl;
}

void Keeper::save(const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        throw FileException("Error opening file for writing.");
    }
    out << size << std::endl;
    for (int i = 0; i < size; ++i) {
        vehicles[i]->serialize(out);
    }
    out.close();
}

void Keeper::load(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        throw FileException("Error opening file for reading.");
    }
    int newSize;
    in >> newSize;
    for (int i = 0; i < size; ++i) {
        delete vehicles[i];
    }
    delete[] vehicles;
    size = newSize;
    vehicles = new Vehicle * [size];
    char type;
    for (int i = 0; i < size; ++i) {
        in >> type;
        if (type == 'C') {
            vehicles[i] = new Car();
        }
        else if (type == 'M') {
            vehicles[i] = new Motorcycle();
        }
        else if (type == 'B') {
            vehicles[i] = new Bus();
        }
        vehicles[i]->deserialize(in);
    }
    in.close();
}

int Keeper::getSize() const {
    return size;
}
