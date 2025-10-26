#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship {
private:
    double length;
    double width;
    int crew;
    double underwaterTime;
    double maxUnderwaterSpeed;
    char* armament;

public:
    Submarine();
    Submarine(double len, double wid, int crewCount, double time, double speed, const char* weapon);
    Submarine(const Submarine& other);
    ~Submarine();

    void Input() override;
    void Display() const override;
    void SaveToFile(std::ofstream& out) const override;
    void LoadFromFile(std::ifstream& in) override;

    std::string GetType() const override { return "Submarine"; }


    // set/get методы
    void SetLength(double l);
    double GetLength() const;

    void SetWidth(double w);
    double GetWidth() const;

    void SetCrew(int c);
    int GetCrew() const;

    void SetUnderwaterTime(double t);
    double GetUnderwaterTime() const;

    void SetSpeed(double s);
    double GetSpeed() const;

    void SetArmament(const char* weapon);
    const char* GetArmament() const;
};

#endif
