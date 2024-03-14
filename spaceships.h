//
// Created by Duru Irmak Öztürk on 19.02.2024.
//

#ifndef COSMIC_VOYAGER_CAPTAIN_H
#define COSMIC_VOYAGER_CAPTAIN_H
#include <cstdlib>
#include <iostream>

//çözülecek sorunlar:
//destructorlar yapılacak
//const olanları const yapıcaz
//single responsibility bakılabilir
//shipfleetmanager??
//altın 0 ise pazarlık çıkmayacak
//ifadeleri düzenlicez
//declaration ve definitionları ayırcaz
//display fonksiyonu yazıcaz!!!
//gecersiz gemi seciminde secim fonksiyonunu tekrar cağır

class Spaceships {
public:
    explicit Spaceships(double _damageCoef) :damageCoef{_damageCoef}{}

    //UPDATES
    virtual int updateHealthDamage10(int& _health) = 0;
    virtual int updateHealthDamage30(int&  _health)=0;

    int earnMoney(int _money) {
        money += prize;
        return money;
    }

    int loseMoney(int _money) {
        int moneyLoss = (rand() % 3 + 1);
        moneyLoss=moneyLoss*10;
        return money-=moneyLoss;

    }

    int updateFuel(int& _fuel){
        if(fuel>=34) {
            fuel -= spentFuel;
            return fuel;
        }
        else {
            fuel=0;
        }
    }

    //EVENTS
    virtual void asteroid()=0;

    void abandonedPlanet(){
        int oran = (rand() % 2) == 0 ? 10: 0;
        if(oran>0){
            std::cout<<"Terk edilmiş bir gezegende yerde 10 altın buldun! Şanslı günündesin!\n\n";
            earnMoney(money); //!!!!!!!
        }
        else {
            std::cout<<"Terk edildiğini sandığın gezegene geldiğinde yanıldığını anladın ve...\n\n";
            pirates();
        }
    }

    void pirates() { //3 secenek kac savas pazarlık
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
            std::cout << "\nUzay korsanlarıyla karşılaştın! Kaç (0), savaş (1) ya da pazarlık et (2)!\n";
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
                    std::cout<<"Sadece 3 seçeneğin var!\n\n";
                    pirates();
                    break;

            }
        }
        else if(fuel<33) {
            std::cout << "\nUzay korsanlarıyla karşılaştın! Kaçmak için yeterli yakıtın yok. Savaş (1) ya da pazarlık et (2)!\n";
            int choice{1};
            std::cin >> choice;
            switch (choice) {
                case 1: //savas
                    fight();
                    break;
                case 2: //pazarlik et
                    debate();
                    break;
                default:
                    std::cout << "Sadece 2 seçeneğin var!\n\n";
                    pirates();
                    break;
            }
        }
    }

    //ACTIONS
    virtual void run()=0;
    virtual void fight()=0;

    void debate(){
        /*int ucret = rand() % 3 + 1;
        money-=10*ucret;*/
        loseMoney(money);
        if (money<0){
           std::cout<<"Pazarlık etmek için cebinde beş kuruş olmadığını fark ettin.\n\n";
           pirates();
        }
    }

    //GAME ENDING
    void puan_hesabi(){
        std::cout<<"Oyun sona erdi. Puanınız :" << ((fuel*5)+(health*10)+(money*10));
    }

    int fuel{100};

protected:
    //ATTRIBUTIONS
    int money{0};
    int health{100};
    double damageCoef{0};////

    //CONSTANTS
    const int prize{10};
    const int spentFuel{33};
    const int damage{10};
    const int damage_{30};
};

#endif //COSMIC_VOYAGER_CAPTAIN_H
