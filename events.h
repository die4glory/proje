//
// Created by Duru Irmak Öztürk on 26.02.2024.
//
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "spaceships.h"
#include "commonship.h"
#include "speedship.h"
#include "strongship.h"
#ifndef UNTITLED_EVENTS_H
#define UNTITLED_EVENTS_H
class Events{
public:

    static void start_game(){
         int counter{0};
         int max_event{5};
        do{
            int a= (rand() %3 + 1);//random  sayı gelecek
            switch(a){
                case 1: //asteroid
                    secilen_gemi()->asteroid();
                    counter++;
                    break;
                case 2: //pirate
                    secilen_gemi()->piratesChoose();
                    counter++;
                    break;
                case 3: //abandonedPlanet
                    secilen_gemi()->abandonedPlanet();
                    counter++;
                    break;
                default:
                    break;
            }

        }while(counter<max_event&&secilen_gemi()->fuel>0);
        secilen_gemi()->puan_hesabi();
    }

    static std::shared_ptr<Spaceships> secilen_gemi() {
        static std::shared_ptr<Spaceships> secilen_gemi;
        if (!secilen_gemi) {
            int gemi{0};
            std::cout<<"      _________\n"
                       "      (=========)\n"
                       "      |=========|\n"
                       "      |====_====|\n"
                       "      |== / \\ ==|\n"
                       "      |= / _ \\ =|\n"
                       "   _  |=| ( ) |=|\n"
                       "  /=\\ |=|     |=| /=\\\n"
                       "  |=| |=| ALP |=| |=|\n"
                       "  |=| |=|  _  |=| |=|\n"
                       "  |=| |=| | | |=| |=|\n"
                       "  |=| |=| | | |=| |=|\n"
                       "  |=| |=| | | |=| |=|\n"
                       "  |=| |/  | |  \\| |=|\n"
                       "  |=|/    | |    \\|=|\n"
                       "  |=/TEKIN |_| TEKIN\\=|\n"
                       "  |(_______________)|\n"
                       "  |=| |_|__|__|_| |=|\n"
                       "  |=|   ( ) ( )   |=|\n"
                       " /===\\           /===\\\n"
                       "|||||||         |||||||\n"
                       "-------         -------\n"
                       " (~~~)           (~~~)";
            std::cout<<"\nChoose a spaceship for your journey: Common ship (1) Fast ship (2) Strong ship (3)\n";
            std::cin>>gemi;
            switch (gemi) {
                case 1:
                    secilen_gemi = std::make_shared<commonShip>();
                    break;
                case 2:
                    secilen_gemi = std::make_shared<speedShip>();
                    break;
                case 3:
                    secilen_gemi = std::make_shared<strongShip>();
                    break;
                default:
                    std::cout<<"gecersiz gemi secimi yaptiniz\n";
                    //Spaceships::secilen_gemi();
                    break;
            }
        }

        return secilen_gemi;
    }




private:
protected:



};


#endif //UNTITLED_EVENTS_H
