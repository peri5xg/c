#include "Bus.h"
#include <iostream>
#include <fstream>  // Добавлено для исправления ошибки компиляции

Bus::Bus() : seats(0), totalSeats(0), destination("") {
    std::cout << "Bus: Constructor without parameters called." << std::endl;
}

Bus::Bus(const std::string& mark, const std::string& model, int seats, int totalSeats, const std::string& destination)
    : Vehicle(mark, model), seats(seats), totalSeats(totalSeats), destination(destination) {
    std::cout << "Bus: Constructor with parameters called." << std::endl;
}

Bus::Bus(const Bus& other) : Vehicle(other), seats(other.seats), totalSeats(other.totalSeats), destination(other.destination) {
    std::cout << "Bus: Copy constructor called." << std::endl;
}

Bus::~Bus() {
    std::cout << "Bus: Destructor called." << std::endl;
}

int Bus::getSeats() const { return seats; }
void Bus::setSeats(int seats) { this->seats = seats; }
int Bus::getTotalSeats() const { return totalSeats; }
void Bus::setTotalSeats(int totalSeats) { this->totalSeats = totalSeats; }
std::string Bus::getDestination() const { return destination; }
void Bus::setDestination(const std::string& destination) { this->destination = destination; }

void Bus::print() const {
    std::cout << "Bus: " << mark << " " << model << ", Seats: " << seats << ", Total: " << totalSeats << ", Destination: " << destination << std::endl;
}

void Bus::serialize(std::ofstream& out) const {
    out << "B " << mark << " " << model << " " << seats << " " << totalSeats << " " << destination << std::endl;
}

void Bus::deserialize(std::ifstream& in) {
    in >> mark >> model >> seats >> totalSeats >> destination;
}

Vehicle* Bus::clone() {
    return new Bus(*this);
}
