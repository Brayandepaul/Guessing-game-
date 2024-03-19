#include <iostream>
using namespace std;
#include "humanPlayer.h"

HumanPlayer::HumanPlayer(): Player() {}


HumanPlayer::HumanPlayer(string nameSetter): Player(){
    setName(nameSetter);
}



int HumanPlayer::getGuess() {
    int guess;

    while (true) {

        cin >> guess;

        if (cin.fail() || guess < 0 || guess > 99) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Invalid input. Please enter a valid integer between 0 and 99." << std::endl;
        } else {
            break; 
        }
    }

    return guess;
    
    
}