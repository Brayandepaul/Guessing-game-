#include <iostream>
using namespace std;

#include "computerPlayer.h"

ComputerPlayer::ComputerPlayer(): Player() {
    resetRNG();
}


ComputerPlayer::ComputerPlayer(string nameSetter): Player() {
    resetRNG();
    setName(nameSetter);
}


void ComputerPlayer::resetRNG() {
    rngStart = 0;
    rngRange = 100;
}


int ComputerPlayer::getGuess() {
    int n = (rand() % rngRange + rngStart);
    return n;
}


void ComputerPlayer::endRound(bool condition) {
    resetRNG();
    if (condition) {
        numWins += 1;
    }

}

//when then guess is too high, we set the range to guess

 void ComputerPlayer::tooHigh(int guess) {
    // Adjust the range based on the guessed number
    int new_num = guess - 1;
    
    // Calculate the difference between new_num and rngStart
    int differenceBetween = new_num - rngStart;
    
    // Update rngRange based on the calculated difference
    rngRange = differenceBetween + 1;
   
}
 
 



//when the guess is low, we go up to the guess plus one place
//and we reduce the range by the number of places we went up plus one
void ComputerPlayer::tooLow(int guess) {
    
   int oldEndpoint = rngStart + rngRange - 1;
   
   int difbtnNewNumandoldEnd = oldEndpoint - (guess + 1);
   
   rngStart = guess + 1;
    
  
   rngRange = difbtnNewNumandoldEnd + 1;
  

    


}


void ComputerPlayer::wrongGuess(int guess, int answer){
    if (guess > answer)
    {
        cout << "Your guess is too high."  << endl;
        tooHigh(guess);
     
    }

    else {
        cout << "Your guess is too low." << endl;
        tooLow(guess);
       
    }

}