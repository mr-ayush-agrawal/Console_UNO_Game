#include "cards.h"
#include "player.h"
#include <time.h>
#include "MovesAndRotation.cpp"
using namespace std;

vector<cards> CreateDeck();
void suffleDeck(vector<cards> &);
cards Distribute(player[],int,vector<cards>&);


int main()
{
    rules();

    how_to_play();
    system("pause");
    int NumberOfPlayers = starting_Game();
    vector<cards> Deck = CreateDeck();
    suffleDeck(Deck);

    player Players[NumberOfPlayers];

    // Collecting Names
    for(int i=0; i<NumberOfPlayers;i++)
    {
        string Name;
        cout<<"\nEnter the Name of the player "<<i+1<<endl;
        cin>>Name;
        Players[i].getName(Name);
    }

    cards TopCard = Distribute(Players,NumberOfPlayers,Deck);

    MoveandRotation(Players,NumberOfPlayers,Deck,TopCard);

    return 0;
}

vector<cards> CreateDeck()
{
    // Creating all the cards present in the Deck
    string clrs[] = {"Blue", "Green", "Red", "Yellow"};
    char nums[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'T', 'S', 'R', 'W', 'F'};
    int numsize = sizeof(nums), clrsize = 4;
    vector<cards> deck;
    for (int i = 0; i < numsize; i++)
    {
        for (int j = 0; j < clrsize; j++)
        {
            // Creating thje card and Pusding it in a Vector
            if (nums[i] == 'W' || nums[i] == 'F')
            {
                cards c("Black", nums[i]);
                deck.push_back(c);
            }
            else
            {
                cards c(clrs[j], nums[i]);
                deck.push_back(c);
            }
        }
    }
    return deck;
}

void suffleDeck(vector<cards> &deck)
{
    srand(time(0));
    for (int i = 0, sz = deck.size(); i < sz; i++)
    {
        swap(deck[i], deck[rand() % sz]);
    }
}

cards Distribute(player Players[],int No,vector<cards> &Deck)
{
    for (int i=0; i<No*7; i++)
    {
        Players[i%No].draw(Deck.back());
        Deck.pop_back();
    }
    cards Top = Deck.back();
    Deck.pop_back();

    return Top;
}

