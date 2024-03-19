// Include a header comment here and in your other files.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "humanPlayer.h"
#include "computerPlayer.h"
// Include the other header files you write for the three classes.
using namespace std;

//Declare all three function here!
void play(Player& player1, Player& player2);
bool checkForWin(Player& player, int answer);
void DisplayStats(Player& player1, Player& player2);


int main()
{
    // Set the Random Seed!
    srand(time(0));
    int numPlayers;
    Player* p1, * p2;

    // Determine the number of players via user input and looping.
    cout << "How many human players? (0, 1, or 2): " << endl;
    cin >> numPlayers;

    while (cin && !(numPlayers>=0 && numPlayers<=2)) {
        cout << "Please re-enter the number of players. (0, 1, or 2): ";
        cin >> numPlayers;
    }

    HumanPlayer h1("Player 1"), h2("Player 2");
    ComputerPlayer c1("CPU 1"), c2("CPU 2");
    
    // Set up player pointers.

    if (numPlayers == 0) {
        p1 = &c1;
        p2 = &c2;
    }

    else if (numPlayers == 1) {
        p1 = &h1;
        p2 = &c1;
    }

    else {
        p1 = &h1;
        p2 = &h2;
        string name1, name2;
        cout << "Enter name for first player: ";
        cin.ignore(1000, '\n');
        getline(cin, name1);
        p1->setName(name1); 
        cout << "Enter name for second player: ";
        getline(cin, name2);
        p2->setName(name2); 
    }


    // Write the game loop here.
    char escape;
    do {
        play(*p1, *p2);

      

        cout << " Would you like to play again? [Y/N]: ";

        cin >> escape;

    } 
    while (escape == 'Y' || escape == 'y');


    cout << endl;
    // Call the output game stats functions you wrote!
    DisplayStats(*p1, *p2);

    return 0;
}

void play(Player& player1, Player& player2)
{
    int answer = rand() % 100;
    bool win = false;
    while (!win)
    {
        win = checkForWin(player1, answer);
        if (win)
        {
            player1.endRound(true);
            player2.endRound(false);
            return;
        }
        win = checkForWin(player2, answer);
        if (win)
        {
            player1.endRound(false);
            player2.endRound(true);
        }
    }
}

bool checkForWin(Player& player, int answer)
{
    bool win = false;
    cout << player.getName() << "'s turn to guess." << endl;
    int guess = player.getGuess();
    cout << "You guessed " << guess << ". ";
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        win = true;
    }
    else
        player.wrongGuess(guess, answer);
    return win;
}

// Write the function to output game stats!
void DisplayStats(Player& player1, Player& player2) {
    cout << "Final Results: " << endl;
    cout << player1;
    cout << player2;

    if (player1 > player2) {

        cout << "Congratulaions, " << player1.getName();

    }
    
    else if (player2 > player1) {

        cout << "Congratulaions, " << player2.getName();

    }

    else {
        cout << "We have a tie!" << endl;
    }


}

