//
// Created by Duru Irmak Öztürk on 21.02.2024.
//

#ifndef UNTITLED_STRONGSHIP_H
#define UNTITLED_STRONGSHIP_H
#include "spaceships.h"

class strongShip:public Spaceships{
public:
    strongShip(): Spaceships(0.5){}


    int updateHealthDamage10(int& _health) {
        health -= damage*katsayi;
        return health;
    }

    int updateHealthDamage30(int& _health) override {
        if (health >= 0) {
            health -= damage_ * katsayi;
            return health;
        } else {
            health = 0;
            return health;
        }
    }

    void asteroid() override {
        int hasar = (rand() % 4) == 0&1&2 ? 10: 0;
        std::cout<<"                      .:'\n"
                   "         ....     _.::'\n"
                   "       .:-\"\"-:.  (_.'\n"
                   "     .:/      \\:.\n"
                   "     :|        |:\n"
                   "     ':\\      /:'\n"
                   " jgs  '::-..-::'\n"
                   "        `''''`";
        if(hasar>0){
            updateHealthDamage10(health);
            std::cout<<"gemi 5 hasar aldi\n";
        }
        else{
            std::cout<<"gemi astreoit yagmurundan kacabildi\n";
            updateFuel(fuel);
        }
    }
    void run() override {
        int kacma_olasılık =  (rand() % 4) == 0&1&2 ? 10: 0;
        if(kacma_olasılık>0){
            updateFuel(fuel);// hocam kacamasa bile yakit harcanir seklinde yaptik
            std::cout<<"kacamadın. uzay korsanlarıyla tekrar karsılastın\n";
            piratesChoose();
        }
        else {
            updateFuel(fuel);
            std::cout<<"kactın\n";
        }
    }

    void fight() override{
        int zaferOlasilik = (rand() % 4) == 0&&1 ? 10 : 0;
        if (zaferOlasilik>0){ //kazandin
            std::cout<<"savası kazandın\n";
        }
        else { //kaybettin
            std::cout<<"savası kaybettin\n";
            updateHealthDamage30(health);
        }


    }



private:
protected:

};

#endif //UNTITLED_STRONGSHIP_H
