//
//  hand.cpp
//  BlackJackGZM
//
//  Created by  高志鸣 on 2017-01-31.
//  Copyright © 2017  高志鸣. All rights reserved.
//

#include "hand.hpp"
#include <iostream>
std::vector<CARD>& Hand::GetHand(){
    return _cards;
}
int Hand::SetHand(std::vector<CARD> a){
    _cards = a;
    return 0;
}
//return 1: bust
int Hand::isBust(){
    if(CardCount()>21){
        return 1;
    }
    else{
        return 0;
    }
}
int Hand::CardCount(){
    int AF = 0;
    int total = 0;
    for(auto const& value: _cards) {
        if(value == 1 && total <=10){
            AF ++;
            total +=11;
        }
        else{
            total += value;
            if(total >21 && AF){
                AF--;
                total-=10;
            }
        }
    }
    return total;
}
void Hand::Print(){
    for(int i=0;i<_cards.size();i++){
        std::cout<<_cards[i]<<" ";
    }
    std::cout<<std::endl;
}

