#include "player.h"
#include "info.cpp"
#include "math.h"
bool updateColor(cards &Top, char NewColor);

void MoveandRotation(player Players[], int NumberOfPlayers, vector<cards> &Deck, cards &TopCard)
{
    int move, rev = 0;
    for (int i = 60; Deck.size() != 0; i = i + pow(-1, rev % 2))
    {
        int defplayer = i;
        how_to_play();
    Again:
        cout << "\nTop Card is :";
        TopCard.show();

        cout << "\n\nIts Move of " << Players[i % NumberOfPlayers].PlayerName() << endl;
        Players[i % NumberOfPlayers].showHand();
        cout << "\nEnter the Index\n";
        cin >> move;
        if (move > Players[i % NumberOfPlayers].CardsCount() || move < -3)
        {
            cout << "Enter a Valid Move\n";
            goto Again;
        }
        else if (move == Players[i % NumberOfPlayers].CardsCount())
        {
            Players[i % NumberOfPlayers].draw(Deck.back());
            Deck.pop_back();
            continue;
        }
        switch (move)
        {
        case -1:
            rules();
            goto Again;
            break;
        case -2:
            PowerCards();
            goto Again;
            break;
        case -3:
            cout << "\nCards Remaining in Deck are " << Deck.size();
            goto Again;
            break;

        default:
            if (!(Players[i % NumberOfPlayers].move(TopCard, move)))
            {
                cout << "Enter a Valid Move If No Valid Move then Draw a card";
                goto Again;
            }

            // Rotating the Moves
            switch (TopCard.getNum())
            {
            case 'S':
                i += pow(-1, rev % 2);
                cout << "\nSkipping the Next Players Move\n";
                system("pause>0");
                break;

            case 'R':
                rev++;
                cout << "\nThe Order is Reversed now";
                system("pause>0");
                break;

            case 'T':
                // Draw 2 to next person
                i += pow(-1, rev % 2);
                for (int x = 0; x < 2; x++)
                {
                    Players[i % NumberOfPlayers].draw(Deck.back());
                    Deck.pop_back();
                }
                cout << "\nNext Players Draws 2 Cards";
                system("pause>0");
                break;

            case 'W':
                // For Wild Card -> Get the color and update
                bool flag;
                do
                {
                    cout << "\nYou Have Played the Wild Card -> Which Color You want to change";
                    cout << "\nR-> Red, B-> Blue, G-> Green, Y-> Yellow\n";
                    char NewColor;
                    cin >> NewColor;
                    flag = updateColor(TopCard, NewColor);
                } while (!flag);
                break;

            case 'F':
                // For Wild Card -> Get the color and update
                // bool flag;
                do
                {
                    cout << "\nYou Have Played the Draw Four Card -> Which Color You want to change";
                    cout << "\nR-> Red, B-> Blue, G-> Green, Y-> Yellow\n";
                    char NewColor;
                    cin >> NewColor;
                    flag = updateColor(TopCard, NewColor);
                } while (!flag);
                i += pow(-1, rev % 2);
                for (int x = 0; x < 4; x++)
                {
                    Players[i % NumberOfPlayers].draw(Deck.back());
                    Deck.pop_back();
                }
                cout << "\nNext Players Draws 4 Cards";
                system("pause>0");
                break;

            default:
                // For Number Cards
                break;
            }
            break;
        }
        if (Players[defplayer % NumberOfPlayers].CardsCount() == 0)
        {
            declareWinner(Players[defplayer % NumberOfPlayers].PlayerName());
            return;
        }
    }
    declareDraw();
}

bool updateColor(cards &Top, char NewColor)
{
    if (Top.getColor().compare("Black"))
    {
        return true;
    }
    string color;
    switch (NewColor)
    {
    case 'R':
    case 'r':
        color = "Red";
        break;
    case 'B':
    case 'b':
        color = "Blue";
        break;
    case 'Y':
    case 'y':
        color = "Yellow";
        break;
    case 'G':
    case 'g':
        color = "Green";
        break;
    default:
        cout << "Enter a Valid Color";
        return false;
    }
    Top.changeColor(color);
    return true;
}