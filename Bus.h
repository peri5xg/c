#ifndef BUS_H
#define BUS_H
#include "Vehicle.h"

class Bus : public Vehicle {
private:
    int seats;
    int totalSeats;
    std::string destination;
public:
    Bus();
    Bus(const std::string& mark, const std::string& model, int seats, int totalSeats, const std::string& destination);
    Bus(const Bus& other);
    ~Bus();
    int getSeats() const;
    void setSeats(int seats);
    int getTotalSeats() const;
    void setTotalSeats(int totalSeats);
    std::string getDestination() const;
    void setDestination(const std::string& destination);
    void print() const override;
    void serialize(std::ofstream& out) const override;
    void deserialize(std::ifstream& in) override;
    Vehicle* clone() override;
};

#endif
#pragma once
