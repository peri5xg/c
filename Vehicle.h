#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>

class Vehicle {
protected:
    std::string mark;
    std::string model;
public:
    Vehicle();
    Vehicle(const std::string& mark, const std::string& model);
    Vehicle(const Vehicle& other);
    virtual ~Vehicle();
    std::string getMark() const;
    void setMark(const std::string& mark);
    std::string getModel() const;
    void setModel(const std::string& model);
    virtual void print() const = 0;
    virtual void serialize(std::ofstream& out) const = 0;
    virtual void deserialize(std::ifstream& in) = 0;
    virtual Vehicle* clone() = 0;
};

#endif
#pragma once
