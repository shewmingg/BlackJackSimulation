//
//  Dealer.hpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//

#ifndef Dealer_hpp
#define Dealer_hpp
//
//#include <stdio.h>
#include <vector>
//using namespace std;
class Dealer{
    std::vector<int> _cards;
    int _dealerNum;
    int _stopNum;
public:
    Dealer();
    void init();
    int GetDealerNum();
    int SetDealerNum();
    void DealerDraw();
};

#endif /* Dealer_hpp */
