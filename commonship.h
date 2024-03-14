//
// Created by Duru Irmak Öztürk on 21.02.2024.
//

#ifndef UNTITLED_COMMONSHIP_H
#define UNTITLED_COMMONSHIP_H
#include "spaceships.h"

class commonShip:public Spaceships{
public:
    commonShip(): Spaceships(1){}

    int updateHealthDamage10(int& _health) override{
       if (health>=0) {
           health -= damage * katsayi;
           return health;
       }
       else {
           health= 0;
           return health;
       }
    }
    int updateHealthDamage30(int& _health) override{
        if (health>=0) {
            health -= damage_ * katsayi;
            return health;
        }
        else {
            health= 0;
            return health;
        }
    }

    void asteroid(){
        int hasar = (rand() % 4) == 0&&1 ? 10 : 0;
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
            std::cout<<"gemi meteor yagmurundan kacamadı\n";
            std::cout<<"gemi 10 hasar aldi\n";
        }
        else{
            std::cout<<"gemi astreoit yagmurundan kacabildi\n";
            updateFuel(fuel);
        }
    }
    void run() {
        updateFuel(fuel);
        int kacma_olasilik = (rand() % 4) == 0 && 1 ? 10 : 0;
        if (kacma_olasilik > 0) {
            updateFuel(fuel);// hocam kacamasa bile yakit harcanir seklinde yaptik
            std::cout << "kacamadın. uzay korsanlarıyla tekrar karsılastın\n";
            piratesChoose();
        } else {
            updateFuel(fuel);
            std::cout << "kactın\n";

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




};

#endif //UNTITLED_COMMONSHIP_H
