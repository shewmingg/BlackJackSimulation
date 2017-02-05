//
//  util.hpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//

#ifndef util_hpp
#define util_hpp

#include <stdio.h>
#include <vector>
extern char cs[1+21+10+9][13];
extern int gi;
typedef int CARD;
//typedef std::vector<CARD> HAND;

int GetRandTen();
void printVector(std::vector<int> a);
#endif /* util_hpp */
