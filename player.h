#include <iostream>
using namespace std;

#pragma once

class Player {
    
    public:

        Player ();

        void setName (string n);

        string getName();

        virtual int getGuess();

        virtual void wrongGuess(int guess, int answer);

        virtual void endRound(bool condition);

        friend bool operator >(const Player &p1, const Player &p2);

        friend ostream& operator <<(ostream& out, const Player& p1) ;

        int numWins;
    
    private:
    
        string name;
        
        
     

        
};