#ifndef KEEPER_H
#define KEEPER_H
#include "Vehicle.h"

class IndexOutOfRangeException : public std::exception {
public:
    const char* what() const noexcept override { return "Index is out of range."; }
};

class FileException : public std::exception {
public:
    FileException(const char* msg) : message(msg) {}
    const char* what() const noexcept override { return message; }
private:
    const char* message;
};

class Keeper {
private:
    Vehicle** vehicles;
    int size;
public:
    Keeper();
    ~Keeper();
    void add(Vehicle* v);
    void remove(int index);
    void show() const;
    void edit(int index);
    void save(const std::string& filename);
    void load(const std::string& filename);
    int getSize() const;
};

#endif
#pragma once
