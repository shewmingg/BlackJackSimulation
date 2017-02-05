//
//  hand.hpp
//  BlackJackGZM
//
//  Created by  高志鸣 on 2017-01-31.
//  Copyright © 2017  高志鸣. All rights reserved.
//

#ifndef hand_hpp
#define hand_hpp

#include <stdio.h>
#include <vector>
#include "util.hpp"
class Hand {
    std::vector<CARD> _cards;
public:
    std::vector<CARD>& GetHand();
    int SetHand(std::vector<CARD>);
    int isBust();
    int CardCount();
    void Print();
  //  int DealerCardCount(int stopNum);
};
#endif /* hand_hpp */
