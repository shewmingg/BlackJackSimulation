//
//  Player.cpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//
#include "util.hpp"
#include "player.hpp"
#include <iostream>
#include <vector>
#include <iostream>
using namespace std;
Player::Player(float money, float defChip){
    _money = money;
    _defChip = defChip;
}

// ret index of new hand
int Player::AddHand(){
    _hands.push_back(Hand());
    _chips.push_back(_defChip);
    return (int)_hands.size()-1;
}

int Player::Init(){
    int index = AddHand();
    _hands[index].GetHand().push_back(GetRandTen());
     _hands[index].GetHand().push_back(GetRandTen());
    return 0;
}

int Player::Reset(){
    _hands.clear();
    _chips.clear();
    return 0;
}
int Player::DrawCard(int handIndex, int num){
    for(int i=0;i<num;i++){
        _hands[handIndex].GetHand().push_back(GetRandTen());
    }
    return 0;
}
int Player::FollowSheet(int handIndex, CARD dealerCard){
    int count=0;
    bool AF = false;
    for(int i=0;i<_hands[handIndex].GetHand().size();i++){
        count += _hands[handIndex].GetHand()[i];
        if(_hands[handIndex].GetHand()[i] == 1) {
            AF = true;
        }
    }
    if(AF && count-1<=10){
        return SheetAction(handIndex, cs[21+count-1][dealerCard-1], dealerCard);
    }
    else if(_hands[handIndex].GetHand().size() == 2 && _hands[handIndex].GetHand()[0] == _hands[handIndex].GetHand()[1]){
        return SheetAction(handIndex, cs[30+_hands[handIndex].GetHand()[0]][dealerCard-1], dealerCard);
    }
    else if(count<=21){
        return SheetAction(handIndex, cs[count][dealerCard-1], dealerCard);
    }
    else{
        return 0;
    }
}
// ret 1: keep on checking.
int Player::SheetAction(int handIndex, char action, CARD dealerCard){
    cout<<action<<" ";
    switch (action) {
        case 'H':
            _hands[handIndex].GetHand().push_back(GetRandTen());
            return 1;
        case 'S':
            return 0;
        case 'D':
             _hands[handIndex].GetHand().push_back(GetRandTen());
            if(_hands[handIndex].GetHand().size() == 3){
                DoubleChip(handIndex);
                return 0;
            }
            else{
                return 1;
            }
        case 'P':
             _hands[handIndex].GetHand().pop_back();
            int newIndex = AddHand();
            _hands[newIndex].GetHand().push_back( _hands[handIndex].GetHand()[0]);
            DrawCard(handIndex, 1);
            DrawCard(newIndex, 1);
            if(_hands[handIndex].GetHand()[0]==1){
                return 0;
            }
            else{
                while(FollowSheet(newIndex, dealerCard));
                return 1;
            }
    }
    return -1;
}

int Player::Match(int handIndex, Hand dealerHand){
    if(_hands[handIndex].isBust() || (!dealerHand.isBust() && _hands[handIndex].CardCount()<dealerHand.CardCount())){
        _money-= _chips[handIndex];
    }
    else if (_hands[handIndex].CardCount() == 21 && _hands[handIndex].GetHand().size() == 2){
        _money+=1.5*_chips[handIndex];
    }
    else if (dealerHand.isBust() || (_hands[handIndex].CardCount()>dealerHand.CardCount() && !_hands[handIndex].isBust())){
        _money +=_chips[handIndex];
    }
    return 0;
}
int Player::SetDefaultChip(float chip){
    _defChip = chip;
    return 0;
}

int Player::SetMoney(float money){
    _money = money;
    return 0;
}
int Player::DoubleChip(int index){
    _chips[index]*=2;
    return 0;
}

std::vector<Hand> Player::GetHands(){
    return _hands;
}
int Player::GetMoney(){
    return _money;
}
