//
//  board.h
//  REVERSI
//
//  Created by Sakura on 2014/08/10.
//  Copyright (c) 2014年 Sakura. All rights reserved.
//

#ifndef __REVERSI__board__
#define __REVERSI__board__

#include <iostream>
class board
{
public:
    
    board();
    void output();
    bool CanPutStone(int x, int y);
    bool CanPutStoneAll();
    bool Gameover();
    void PutStone(int x, int y);
    
    int stone[8][8];
    int TurnPlayer;
    
    int TurnCount;
    int Count[2];
    
};

class vector
{
public:
    vector(){}
    vector(int ix, int iy){x = ix; y = iy;}
    int x;
    int y;
    
    vector operator + ( const vector obj ){return vector(x+obj.x,y+obj.y);};
    vector operator - ( const vector obj ){return vector(x-obj.x,y-obj.y);};
    
};

#endif /* defined(__REVERSI__board__) */
