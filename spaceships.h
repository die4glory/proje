//
// Created by Duru Irmak Öztürk on 19.02.2024.
//

#ifndef COSMIC_VOYAGER_CAPTAIN_H
#define COSMIC_VOYAGER_CAPTAIN_H
#include "spaceships.h"

class Spaceships {
public:
    explicit Spaceships(double _damageCoef) : damageCoef{_damageCoef} {}

    virtual int updateHealthDamage10(int& _health)=0;
    virtual int updateHealthDamage30(int&  _health)=0;

    int Spaceships::earnMoney(int _money);
    int Spaceships::loseMoney(int _money);
    int Spaceships::updateFuel(int& _fuel);

    virtual void asteroid()=0;
    void Spaceships::abandonedPlanet();
    void Spaceships::pirates();

    virtual void run()=0;
    virtual void fight()=0;

    void Spaceships::debate();

    void Spaceships::displayStatus() const;

    void Spaceships::puan_hesabi();

};

#endif //COSMIC_VOYAGER_CAPTAIN_H
