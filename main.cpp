#include <iostream>
#include "events.h"
#include "spaceships.h"
#include <cstdlib>

int main() {

    srand(time(0));
    std::shared_ptr<Spaceships>secilen_gemi;
    Events::start_game();

    return 0;
}
