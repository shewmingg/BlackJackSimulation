//
//  Player.hpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//

#ifndef Player_hpp
#define Player_hpp
#include "Dealer.hpp"
#include <vector>
//#include <stdio.h>
//using namespace std;
class Player{
    std::vector<int> _cards;
    std::vector<int> _op_cards;
    int _chip;
    int _money;
    Dealer _Dealer;
public:
    Player();
    void init();
    void initCards(std::vector<int> cards);
    bool PlayerMove();
    bool CardsMove(std::vector<int> cards);
    
    bool PlayerAction(std::vector<int> cards, char action);
    int CardCount(std::vector<int> cards);
    bool Split();
    bool DoubleChip(std::vector<int> cards);
    int Match();
    bool isBust(std::vector<int> cards);
    
    int getMoney();
};
#endif /* Player_hpp */
