//
// Created by Duru Irmak Öztürk on 21.02.2024.
//

#ifndef UNTITLED_STRONGSHIP_H
#define UNTITLED_STRONGSHIP_H
#include "spaceships.h"

class strongShip:public Spaceships {
public:
    strongShip(): Spaceships(0.5){}

    //UPDATES
    int updateHealthDamage10(int& _health) override {
        health -= damage*damageCoef;
        return health;
    }

    int updateHealthDamage30(int& _health) override {
        if (health >= 0) {
            health -= damage_*damageCoef;
            return health;
        }
        else {
            health = 0;
            return health;
        }
    }

    //EVENTS
    void asteroid() override {
        int asteroidDamage = (rand() % 4) == 0&1&2 ? 10: 0;
        std::cout<<"\nAsteroid kuşağından geçiyorsun!\n\n";
        std::cout<<"                      .:'\n"
                   "         ....     _.::'\n"
                   "       .:-\"\"-:.  (_.'\n"
                   "     .:/      \\:.\n"
                   "     :|        |:\n"
                   "     ':\\      /:'\n"
                   "      '::-..-::'\n"
                   "        `''''`";
        if(asteroidDamage>0) {
            updateHealthDamage10(health);
            std::cout<<"\nAsteroidlerden birine çarpıp 5 hasar aldın.\n\n";
            displayStatus();
        }
        else {
            std::cout<<"\nAsteroid kuşağından hasar almadan geçtin. Yakıtın azaldı.\n";
            updateFuel(fuel);
            displayStatus();
        }
    }

    //ACTIONS
    void run() override {
        int oddsOfFlee =  (rand() % 4) == 0&1&2 ? 10: 0;
        if(oddsOfFlee>0) {
            updateFuel(fuel);// hocam kacamasa bile yakit harcanir seklinde yaptik
            std::cout<<"Yakıtın azaldı. Tam kaçabildiğini sandığın anda...\n\n";
            pirates();
            displayStatus();
        }
        else {
            updateFuel(fuel);
            std::cout<<"Korsanlara izini kaybettirdin! Yakıtın azaldı.\n\n";
            displayStatus();
        }
    }

    void fight() override {
        int oddsOfWin = (rand() % 4) == 0&&1 ? 10 : 0;
        if (oddsOfWin>0) {
            std::cout<<"Savaşın galibi sensin!\n\n";
        }
        else {
            std::cout<<"Savaşı kaybettin. 15 hasar aldın.\n\n";
            updateHealthDamage30(health);
            displayStatus();
        }
    }

private:
protected:

};

#endif //UNTITLED_STRONGSHIP_H
