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
class Events {
public:
    //GAME STARTER
    static void start_game() {
         int counter{0};
         int max_event{5};
        do {
            int randomEvent = (rand() %3 + 1);
            switch(randomEvent){
                case 1: //asteroid
                    playersShip()->asteroid();
                    counter++;
                    break;
                case 2: //pirates
                    playersShip()->pirates();
                    counter++;
                    break;
                case 3: //abandonedPlanet
                    playersShip()->abandonedPlanet();
                    counter++;
                    break;
                default:
                    break;
            }
        } while(counter<max_event&&playersShip()->fuel>0);
        playersShip()->puan_hesabi();
    }

    //SHIP SELECTOR
    static std::shared_ptr<Spaceships> playersShip() {
        static std::shared_ptr<Spaceships> playersShip;
        if (!playersShip) {
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
                       "  |=/TEKIN_|_TEKIN\\=|\n"
                       "  |(_______________)|\n"
                       "  |=| |_|__|__|_| |=|\n"
                       "  |=|   ( ) ( )   |=|\n"
                       " /===\\           /===\\\n"
                       "|||||||         |||||||\n"
                       "-------         -------\n"
                       " (~~~)           (~~~)";
            std::cout<<"\nYolculuğuna başlamak için bir gemi seç: Normal gemi (1) Hızlı gemi (2) Güçlü gemi (3)\n";
            std::cin>>gemi;
            switch (gemi) {
                case 1:
                    playersShip = std::make_shared<commonShip>();
                    break;
                case 2:
                    playersShip = std::make_shared<speedShip>();
                    break;
                case 3:
                    playersShip = std::make_shared<strongShip>();
                    break;
                default:
                    std::cout<<"Geçersiz gemi seçimi.\n\n";
                    //Spaceships::secilen_gemi();
                    break;
            }
        }
        return playersShip;
    }

private:
protected:

};


#endif //UNTITLED_EVENTS_H
