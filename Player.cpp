//
//  Player.cpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//
#include "util.hpp"
#include "Player.hpp"
Player::Player(){
    initCards(_cards);
}
void Player::init(){
    _cards.clear();
    _op_cards.clear();
    initCards(_cards);
    _Dealer.init();
}
bool Player::PlayerMove(){
    bool flag = false;
    if(_op_cards.size()!=0 && isBust(_op_cards)){
        flag = CardsMove(_op_cards) || flag;
    }
    if(isBust(_cards)){
        flag = CardsMove(_cards) || flag;
    }
    return flag;
}

bool Player::CardsMove(std::vector<int> cards){
    int count=0;
    bool AF = false;
    for(int i=0;i<cards.size();i++){
        count += cards[i];
        if(cards[i] == 1) {
            AF = true;
        }
    }
    if(AF && count-1<=10){
        return PlayerAction(cards, cs[21+count-1][_Dealer.GetDealerNum()]);
    }
    else if(cards.size() == 2 && cards[0] == cards[1]){
        return PlayerAction(cards, cs[30+cards[0]][_Dealer.GetDealerNum()]);
    }
    else {
        return PlayerAction(cards, cs[count][_Dealer.GetDealerNum()]);
    }
}

bool Player::PlayerAction(std::vector<int> cards, char action){
    if(action == 'H'){
        cards.push_back(GetRandTen());
        return true;
    }
    if(action == 'D'){
        if(!DoubleChip(cards)){
            cards.push_back(GetRandTen());
            _Dealer.DealerDraw();
            Match();
            return false;
        }
        cards.push_back(GetRandTen());
        return true;
    }
    if(action == 'S'){
        _Dealer.DealerDraw();
        Match();
        return false;
    }
    if(action == 'P'){
        Split();
        return true;
    }
    if(action == 'W'){
        _money += 1.5 * _chip;
        return false;
    }
    
    return true;
}

int Player::CardCount(std::vector<int> cards){
    int total = 0;
    for(int i=0;i<cards.size();i++){
        total += cards[i];
    }
    return total;
}


void Player::initCards(std::vector<int> cards){
    cards.push_back(GetRandTen());
    cards.push_back(GetRandTen());
}
bool Player::Split(){
    if (_cards.size() == 2){
        //move last card in hand to another vector
        _op_cards.push_back(_cards[0]);
        _cards.pop_back();
        
        //draw two card seperately into two cards vector
        _op_cards.push_back(GetRandTen());
        _cards.push_back(GetRandTen());

        return true;
    }
    return false;
}

bool Player::DoubleChip(std::vector<int> cards){
    if(cards.size() == 2){
        _chip*=2;
        return true;
    }
    return false;
}
bool Player::isBust(std::vector<int> cards){
    if(CardCount(cards)>21){
        return true;
    }
    return false;
}

int Player::Match(){
    int total = 0;
    if(_op_cards.size()!= 0){
        if(CardCount(_op_cards)>_Dealer.GetDealerNum()){
            _money+= _chip;
            total ++;
        }
        else if(CardCount(_op_cards)<_Dealer.GetDealerNum()){
            _money-= _chip;
            total --;
        }
    }
    if(CardCount(_cards)>_Dealer.GetDealerNum()){
        _money+= _chip;
        total ++;
    }
    else if(CardCount(_cards)<_Dealer.GetDealerNum()){
        _money-= _chip;
        total --;
    }
    return total;
}

int Player::getMoney(){
    return _money;
}
