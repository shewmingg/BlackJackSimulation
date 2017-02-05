//
//  main.cpp
//  BlackJackGZM
//
//  Created by  高志鸣 on 16/01/2017.
//  Copyright © 2017  高志鸣. All rights reserved.
//

#include "dealer.hpp"
#include "player.hpp"
#include "util.hpp"

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    Player player = Player(100,1);
    Dealer dealer = Dealer(16);
    srand((unsigned int)time(NULL));
    for(int i=0;i<10000000;i++){
        dealer.Init();
        player.Init();
        // cout<<dealer.GetDealerHand().GetHand()[0];
        while(player.FollowSheet(0, dealer.GetHand().GetHand()[0]));
        for(int i =0;i<player.GetHands().size();i++){
            cout<<i<<":";
            player.GetHands()[i].Print();
        }
        dealer.DealerDraw();
        cout<<"Dealer:";
        dealer.GetHand().Print();
        for(int i=0;i<player.GetHands().size();i++){
            player.Match(i, dealer.GetHand());
        }
        player.Reset();
        dealer.Reset();
        cout<<"money:"<<player.GetMoney()<<endl;
    }
    dealer.Init();
    return 0;
}

