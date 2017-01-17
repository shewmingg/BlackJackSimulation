//
//  util.cpp
//  blackjack
//
//  Created by  高志鸣 on 02/01/2017.
//
//

#include "util.hpp"
#include <stdlib.h>
int GetRandTen(){
    int num = rand()%13+1;
    return num-num/10*(num%10);
}
