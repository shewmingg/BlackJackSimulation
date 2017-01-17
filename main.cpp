//
//  main.cpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//  Copyright © 2017  高志鸣. All rights reserved.
//
#include "Dealer.hpp"
#include "Player.hpp"
#include "util.hpp"

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    Player player = Player();
    for(int i=0;i<100000;i++){
        player.init();
        while(player.PlayerMove()){}
    }
    cout<<player.getMoney();
   // cout<<"sadf";
    return 0;
}

