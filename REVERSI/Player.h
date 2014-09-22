//
//  Player.h
//  REVERSI
//
//  Created by Sakura on 2014/08/10.
//  Copyright (c) 2014年 Sakura. All rights reserved.
//

#ifndef __REVERSI__Player__
#define __REVERSI__Player__

#include <iostream>
#include "board.h"

class Player
{
public:
    Player(board& idata);
    virtual void put(){};
    
    board* boardData;
};
class Human :public Player
{
public:
    Human(board& idata):Player(idata){};
    virtual void put();
    
};
class Com :public Player
{
public:
    Com(board& idata):Player(idata){};
    virtual void put();
    
};
class Com1 :public Player
{
public:
    Com1(board& idata):Player(idata){};
    virtual void put();
    
};

#endif /* defined(__REVERSI__Player__) */
