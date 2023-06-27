#include <iostream>
#include <stdlib.h>
using namespace std;

void rules();
void how_to_play();
int starting_Game();
void PowerCards();
void declareWinner(string);
void declareWDraw();

// int main()
// {
//     rules();
//     how_to_play();
//     return 0;
// }

void rules()
{
    system("cls");

    cout << "\nRules of This UNO Game\n";
    cout << "\nStarting :";
    cout << "\nYou have to select the number of players that are willing to play the game (It should be between 3 to 5)";
    cout << "\n7 UNO cards will be distributed to all the players at begning which may or may not contain the POWER CARDS";
    cout << "\nAll The Players Will get the Turn According to the order";

    cout << "\nMoving:";
    cout << "\nThe player has to play the Same color as of the deck or the same number present at the top card";
    cout << "\nIf the top card is a power card and the player has the move then same power can also be played or same color card";
    cout << "\nIf a player is unnable to play he/she gets a card form the deck and may play the card if possible";
    cout << "\nAt a time player is allowed to play atmost 1 card";

    PowerCards();

    cout << "\nGame Over:";
    cout << "\nThe Aim of the game is to finish your cards ASAP";
    cout << "\nWhen a player finishes the card then the Player is the winner and games aborts with a winner";
    cout << "\nIf the deck of Cards get empty then the game aborts with a Draw";

    cout << "\n\n";
    system("pause");
}

void how_to_play()
{
    system("cls");

    cout << "\n\nHow to Play/Move\n";
    cout << "\nThere would be index number would be present with the Cards. Enter the Index number to move that card";
    cout << "\nTo Draw a Card form Deck Press (<last index> + 1) at any time of the game";
    cout << "\nTo See the rules Press -1 at any time of the game";
    cout << "\nTo See Power Cards Press -2 at any time of the game";
    cout << "\nTo See Cards Remaining in Deck Press -3 at any time of the game";

    cout << "\n\n";
    // system("pause");
}

int starting_Game()
{
    system("cls");
    bool flag=false;
    int Player;
    do
    {
        if (flag)
            cout<<"Numbers of players can be either of 3,4,5\n";
        cout << "Enter The number of Players to Play the game\n";
        cin >> Player;
        flag = true;
    }while(Player<3 || Player >5);
    return Player;
}

void PowerCards()
{
    cout << "\nPOWER CARDS:";
    cout << "\nEach Power Card has a specific purpose which influence the order of the game. These are as follows";
    cout << "\n1. REVERSE CARD (<->) : This Reverses the order of the Move";                                                                                                                // Alt 8989
    cout << "\n2. SKIP CARD (X) : The move of next player is cancled and passed";                                                                                                           //
    cout << "\n3. DRAW 2 CARD (+2) : The Next Player Picks 2 cards form the deck and the move is skip[ed for the reciver";                                                                  //
    cout << "\n4. DRAW 4 CARD (+4) : The Next Player Picks 4 cards form the deck, move of the reciver also gets skipped and the player who played the card can call the color of the deck"; //
    cout << "\n5. WILD CARD (_) : The Player call the color of the deck and next plater has to play the color";                                                                             //
    cout << "Remember the stacking of power cards is not allowed. That means If a power card is played then the next player has to follow it";
}


void declareWinner(string str)
{
    cout<<"\nThe Winnwe is "<<str;
}

void declareDraw()
{
    cout<<"The Game ended in draw";
}