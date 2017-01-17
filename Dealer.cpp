//
//  Dealer.cpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//

#include "Dealer.hpp"
#include "util.hpp"
Dealer::Dealer(){
    _stopNum = 17;
    _cards.push_back(GetRandTen());
}
void Dealer::init(){
    _cards.clear();
    _cards.push_back(GetRandTen());
    _dealerNum = 0;
                     
}
void Dealer::DealerDraw(){
    while(GetDealerNum()<_stopNum){
        _cards.push_back(GetRandTen());
        SetDealerNum();
    }
}
int Dealer::GetDealerNum(){
    return _dealerNum;
}
int Dealer::SetDealerNum(){
    int total = 0;
    int AF = 0;
    for(int i=0;i<_cards.size();i++){
        if(_cards[i] == 1){
            total += 11;
            AF++;
        }
        else if(total>21 && AF){
            AF--;
            total -=10;
            total +=_cards[i];
        }else{
            total += _cards[i];
        }
    }
    _dealerNum = total;
    return _dealerNum;
}
