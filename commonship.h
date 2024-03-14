//
// Created by Duru Irmak Öztürk on 13.03.2024.
//
#ifndef UNTITLED_COMMONSHIP_H
#define UNTITLED_COMMONSHIP_H
#include "spaceships.h"

class commonShip:public Spaceships {
public:
    //CONSTRUCTOR
    commonShip(double _damageCoef):Spaceships(1){}

    //UPDATES
    int updateHealthDamage10(int& _health) override;
    int updateHealthDamage30(int& _health) override;

    //EVENTS
    void asteroid() override;

    //ACTIONS
    void run() override;
    void fight() override;

private:
protected:

};
#endif //UNTITLED_COMMONSHIP_H
