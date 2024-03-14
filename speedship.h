//
// Created by Duru Irmak Öztürk on 21.02.2024.
//

#ifndef UNTITLED_SPEEDSHIP_H
#define UNTITLED_SPEEDSHIP_H
#include "spaceships.h"

class speedShip:public Spaceships {
public:
    speedShip(): Spaceships( 1.5){}


    int updateHealthDamage10(int& _health) override {
        health -= damage*damageCoef;
        return health;
    }

    int updateHealthDamage30(int& _health) override {
        if (health>=0) {
            health -= damage_*damageCoef;
            return health;
        }
        else {
            health= 0;
            return health;
        }
    }

    void asteroid() override {
        int asteroidDamage = (rand() % 4) == 0 ? 10 : 0;
        std::cout<<"Asteroid kuşağından geçiyorsun!\n\n";
        std::cout<<"                      .:'\n"
                   "         ....     _.::'\n"
                   "       .:-\"\"-:.  (_.'\n"
                   "     .:/      \\:.\n"
                   "     :|        |:\n"
                   "     ':\\      /:'\n"
                   "      '::-..-::'\n"
                   "        `''''`";
        if (asteroidDamage > 0) {
            updateHealthDamage10(health);
            std::cout<<"\nAsteroidlerden birine çarpıp 15 hasar aldın.\n\n";
        }
        else {
            std::cout<<"\nAsteroid kuşağından hasar almadan geçtin. Yakıtın azaldı.\n\n";
            updateFuel(fuel);
        }
    }
    void run() override {
        int oddsOfFlee = (rand() % 4) == 0 ? 10 : 0;
        if (oddsOfFlee > 0) {
            updateFuel(fuel);// hocam kacamasa bile yakit harcanir seklinde yaptik
            std::cout<<"Yakıtın azaldı. Tam kaçabildiğini sandığın anda...\n\n";
            pirates();
        }
        else {
            updateFuel(fuel);
            std::cout<<"Korsanlara izini kaybettirdin! Yakıtın azaldı.\n\n";
        }
    }
    void fight() override {
        int oddsOfWin = (rand() % 4) == 0&&1 ? 10 : 0;
        if (oddsOfWin>0) {
            std::cout<<"Savaşın galibi sensin!\n\n";
        }
        else {
            std::cout<<"Savaşı kaybettin. 45 hasar aldın.\n\n";
            updateHealthDamage30(health);
        }
    }

private:
protected:

};

#endif //UNTITLED_SPEEDSHIP_H
