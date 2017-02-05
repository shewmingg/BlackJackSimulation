//
//  Dealer.cpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//

#include "dealer.hpp"
#include "util.hpp"
#include <iostream>
Dealer::Dealer(int stopNum){
    _stopNum = stopNum;
}
int Dealer::DealerDraw(){
    while(_hand.CardCount()<=_stopNum){
        _hand.GetHand().push_back(GetRandTen());
    }
    return _hand.CardCount();
}

int Dealer::Init(){
    _hand.GetHand().push_back(GetRandTen());
    return 0;
}

int Dealer::Reset(){
    _hand.GetHand().clear();
    return 0;
}

Hand Dealer::GetHand(){
    return _hand;
}
