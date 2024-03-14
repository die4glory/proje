//
// Created by Duru Irmak Öztürk on 19.02.2024.
//

#ifndef COSMIC_VOYAGER_CAPTAIN_H
#define COSMIC_VOYAGER_CAPTAIN_H
#include "cstdlib"
#include <iostream>


//çözülecek sorunlar:
//destructorlar yapılacak
//const olanları const yapıcaz
//single responsibility bakılabilir
//shipfleetmanager??
//altın 0 ise pazarlık çıkmayacak
//ifadeleri düzenlicez
//declaration ve definitionları ayırcaz
//display fonksiyonu yazıcaz

class Spaceships{
public:
    Spaceships(double _katsayi) :katsayi{_katsayi}{}

    virtual int updateHealthDamage10(int& _health) = 0;
    virtual int updateHealthDamage30(int&  _health)=0;

    int getMoney(int _money) {
        money += prize;
        return money;
    }
    int loseMoney(int _money) {
        int kayipMiktari = (rand() % 3 + 1);
        kayipMiktari=kayipMiktari*10;
        return money-=kayipMiktari;

    }

    virtual void asteroid()=0;
    void piratesChoose(){ //3 secenek kac savas pazarlık
        std::cout<<"     _                      _______                      _\n"
                   "  _dMMMb._              .adOOOOOOOOOba.              _,dMMMb_\n"
                   " dP'  ~YMMb            dOOOOOOOOOOOOOOOb            aMMP~  `Yb\n"
                   " V      ~\"Mb          dOOOOOOOOOOOOOOOOOb          dM\"~      V\n"
                   "          `Mb.       dOOOOOOOOOOOOOOOOOOOb       ,dM'\n"
                   "           `YMb._   |OOOOOOOOOOOOOOOOOOOOO|   _,dMP'\n"
                   "      __     `YMMM| OP'~\"YOOOOOOOOOOOP\"~`YO |MMMP'     __\n"
                   "    ,dMMMb.     ~~' OO     `YOOOOOP'     OO `~~     ,dMMMb.\n"
                   " _,dP~  `YMba_      OOb      `OOO'      dOO      _aMMP'  ~Yb._\n"
                   "\n"
                   "             `YMMMM\\`OOOo     OOO     oOOO'/MMMMP'\n"
                   "     ,aa.     `~YMMb `OOOb._,dOOOb._,dOOO'dMMP~'       ,aa.\n"
                   "   ,dMYYMba._         `OOOOOOOOOOOOOOOOO'          _,adMYYMb.\n"
                   "  ,MP'   `YMMba._      OOOOOOOOOOOOOOOOO       _,adMMP'   `YM.\n"
                   "  MP'        ~YMMMba._ YOOOOPVVVVVYOOOOP  _,adMMMMP~       `YM\n"
                   "  YMb           ~YMMMM\\`OOOOI`````IOOOOO'/MMMMP~           dMP\n"
                   "   `Mb.           `YMMMb`OOOI,,,,,IOOOO'dMMMP'           ,dM'\n"
                   "     `'                  `OObNNNNNdOO'                   `'\n"
                   "                           `~OOOOO~'         ";
        if (fuel>=33) {
            std::cout << "Space pirates attack! Flee (0), fight (1) or negotiate (2)!\n";
            int choice{0};
            std::cin >> choice;
            switch(choice){
                case 0: //kac
                run();
                break;
                case 1: //savas
                fight();
                break;
                case 2: //pazarlik et
                    debate();
                break;
                default:
                    std::cout<<"gecersiz secenek\n";
                    piratesChoose();
                    break;

            }
        }
        else if(fuel<33) {
            std::cout << "yakıt yetersiz kac(0) ,savas(1) ya da pazarlık et(2)!\n";
            int choice{1};
            std::cin >> choice;
            switch (choice) {
                case 0://kac
                    run();
                    break;
                case 1: //savas
                    fight();
                    break;
                case 2: //pazarlik et
                    debate();
                    break;
                default:
                    std::cout << "gecersiz secenek\n";
                    piratesChoose();
                    break;
            }
        }
    }
    virtual void run()=0;
    virtual void fight()=0;

    void debate(){
        int ucret = rand() % 3 + 1;
        money-=10*ucret;
        if (money<0){
           std::cout<<"yeterli altın yok";
           piratesChoose();
        }
    }
    void abandonedPlanet(){
        int oran = (rand() % 2) == 0 ? 10: 0;
        if(oran>0){
            std::cout<<"10 altın kazandın\n";
            getMoney(money); //!!!!!!!
        }
        else {
            std::cout<<"uzay korsanları cıkacak\n";
            piratesChoose();
        }
    }

    int updateFuel(int& _fuel){
        if(fuel>=34) {
            fuel -= spentFuel;
            return fuel;
        }
        else{
            fuel=0;
        }
    }

    void puan_hesabi(){
        std::cout<<"oyun bitti puanınız :" << ((fuel*5)+(health*10)+(money*10));
    }

    int fuel{100};
private:
protected:
    const int prize{10};
    int health{100};
    const double katsayi;
    int money{0};

    const int spentFuel{33};
    const int damage{10};
    const int damage_{30};
};

#endif //COSMIC_VOYAGER_CAPTAIN_H
