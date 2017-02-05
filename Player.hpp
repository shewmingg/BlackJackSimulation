//
//  Player.hpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//

#ifndef Player_hpp
#define Player_hpp
#include <vector>
#include "hand.hpp"
//#include <stdio.h>
//using namespace std;
class Player{
    std::vector<Hand> _hands;
    std::vector<float> _chips;
    float _defChip;
    float _money;
public:
    Player(float money, float defChip);
    int Init();
    int Reset();
    int AddHand();
    int DrawCard(int handIndex, int num);//draw num cards in hand
    int FollowSheet(int handIndex, CARD dealerCard);
    int SheetAction(int handIndex, char action, CARD dealerCard);
    
    int SetDefaultChip(float chip);
    int SetMoney(float money);
    int GetMoney();
    
    int Match(int handIndex, Hand dealerHand);
    
    int DoubleChip(int index);
    
    std::vector<Hand> GetHands();
    
};
#endif /* Player_hpp */
