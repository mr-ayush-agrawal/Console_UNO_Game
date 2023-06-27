#pragma once

#include "cards.h"
#include <vector>

class player
{
    // string name;
    vector<cards> inHand;
    string Name;

public:
    void draw(cards newCard);         // To add the cards in hand if drawn
    bool move(cards &Top_Cards, int); // To remove the card in hand as moved
    int CardsCount();                 // Returns the Number of Cards a player is having
    void showHand();                  // Printing all the cards a player is carrying with Index
    void getName(string);             // To get the name of the player
    string PlayerName();              // To return the Player's Name
};

// Declearing the functions here but to be defined in other file

void player ::draw(cards NewCard)
{
    inHand.emplace_back(NewCard);
}

void player ::showHand()
{
    cout << endl;

    for (int i = 0, n = inHand.size(); i < n; i++)
    {
        inHand[i].show();
        cout << "\t" << i;
    }
}

bool player ::move(cards &Top, int idx)
{
    if (inHand[idx].isValidMove(Top))
    {
        Top = inHand[idx];
        inHand.erase(inHand.begin() + idx);
        return true;
    }
    return false;
}

void player ::getName(string Name)
{
    this->Name = Name;
}

string player ::PlayerName()
{
    return Name;
}

int player ::CardsCount()
{
    return this->inHand.size();
}