//
//  Dealer.hpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//

#ifndef Dealer_hpp
#define Dealer_hpp
#include <vector>
#include "hand.hpp"
//using namespace std;
class Dealer{
    Hand _hand;
    int _stopNum;
public:
    Dealer(int stopNum);
    int Init();
    Hand GetHand();
    int DealerDraw();
    int Reset();
};

#endif /* Dealer_hpp */
