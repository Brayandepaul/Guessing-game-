#include <iostream>
using namespace std;
#include "player.h"


Player::Player():numWins(0) {}


string Player::getName() {
     return name;
}

void Player::setName (string n) {
    name = n;
}

int Player::getGuess() {
    return 0;
}

void Player::wrongGuess(int guess, int answer) {
    if (guess > answer)
    {
        cout << "Your guess is too high."  << endl;
    }

    else {
        cout << "Your guess is too low." << endl;
    }

}


void Player::endRound(bool condition) {
    if (condition) {
        numWins += 1;
    }

}

bool operator >(const Player &p1, const Player &p2){
    return (p1.numWins> p2.numWins);
}


ostream& operator <<(ostream& out, const Player& p1) {
    out << p1.name << '\n';
    out <<"Number of Wins: " << p1.numWins << '\n';
    
    return out;

}
