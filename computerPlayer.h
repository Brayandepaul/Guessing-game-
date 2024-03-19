#include <iostream>
#include <cstdlib>
using namespace std;

#include "player.h"

#pragma once


class ComputerPlayer: public Player {

    public:

        ComputerPlayer();

        ComputerPlayer(string nameSetter);

        void resetRNG();

        virtual void endRound(bool condition);

        virtual void wrongGuess(int guess, int answer);

        void tooLow(int guess);

        virtual int getGuess();

        void tooHigh(int guess);





    private:
        int rngRange;

        int rngStart;



};