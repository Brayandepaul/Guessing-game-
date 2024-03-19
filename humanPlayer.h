#include <iostream>
using namespace std;

#include "player.h"

#pragma once


class HumanPlayer: public Player {


public:
    HumanPlayer();

    HumanPlayer(string nameSetter);

    virtual int getGuess();

};