#pragma once

#include <iostream>
#include <strings.h>
#include <vector>
using namespace std;

// bool stringComp(string,string);

class cards
{
    string color; // This is the suite of the card
    char face;    // The Value of the card is teh face of the card

public:
    cards(string clr, char num)
    {
        this->color = clr;
        this->face = num;
    }
    string getColor()
    {
        return color;
    }
    char getNum()
    {
        return face;
    }
    void show()
    {
        // This Function is temporary
        cout << "\n"
             << color << "\t-> ";
        if (face == 'T')
            cout << "+2";
        else if (face == 'F')
            cout << "+4";
        else
            cout << face;
    }
    bool isValidMove(cards Top)
    {
        // if (!strcmp("Black", color))
        if (!this->color.compare("Black"))
            return true;
        // else if (!strcmp(Top.getColor(), color))
        else if (!this->color.compare(Top.getColor()))
            return true;
        else if (Top.getNum() == this->face)
            return true;

        return false;
    }
    void changeColor(string c)
    {
        this->color = c;
    }
};

// bool cards :: isValidMove(cards Top)

// These functions are now in main file

// vector<cards> CreateDeck();
// void suffleDeck(vector<cards> &deck);