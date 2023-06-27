#include "player.h"

// void player :: draw(cards NewCard)
// {
//     inHand.emplace_back(NewCard);
// }

// void player :: move(cards &Top,int idx)
// {
//     Top=inHand[idx];
//     inHand.erase(inHand.begin() + idx);
// }

void player :: showHand()
{
    cout<<endl;

    for (int i =0, n=inHand.size();i<n;i++)
    {
        inHand[i].show();
        cout<<"\t"<<i;
    }
}