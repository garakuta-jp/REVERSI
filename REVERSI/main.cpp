//
//  main.cpp
//  REVERSI
//
//  Created by Sakura on 2014/08/10.
//  Copyright (c) 2014年 Sakura. All rights reserved.
//

#include <iostream>
#include "board.h"
#include "Player.h"
using namespace std;


void NPC(board &base);

int main()
{
    board base;
    Player* Players[2];
    
    Players[0] = new Human(base);
    Players[1] = new Com1(base);
    
    base.output();
    
    
    
    while(!base.Gameover())
    {
        if (!base.CanPutStoneAll())
        {
            base.TurnPlayer = (base.TurnPlayer == 1 ? 2 : 1);
        }
        
        Players[base.TurnPlayer -1]->put();
        
        base.output();
    }
    return 0;
}