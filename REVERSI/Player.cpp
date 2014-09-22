//
//  Player.cpp
//  REVERSI
//
//  Created by Sakura on 2014/08/10.
//  Copyright (c) 2014年 Sakura. All rights reserved.
//

#include "Player.h"
using namespace std;

Player::Player(board& idata)
{
    boardData = &idata;
}

void Human::put()
{
    int x;
    int y;
    char cx[100],cy[100];
    
    cin >> cx;
    x = cx[0]-48;
    if(x < 0 || x >= 8) cout << "error input x is not number" << endl;
    cin >> cy;
    y = cy[0]-48;
    if(y < 0 || y >= 8) cout << "error input y is not number" << endl;
    boardData->PutStone(x, y);
}
void Com::put()
{
    int randx;
    int randy;
    while (true)
    {
        randx = rand()%8;
        randy = rand()%8;
        if (boardData->CanPutStone(randx, randy))
        {
            boardData->PutStone(randx, randy);
            break;
        }
    }
}
void Com1::put()
{
            int max = 0;
            int tx = 0;
            int ty = 0;
            board Demoview;
            Demoview = *boardData;
            for (int x =0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++) {
                    if (boardData->CanPutStone(x, y))
                    {
                        Demoview.PutStone(x, y);
                        if (Demoview.Count[boardData->TurnPlayer] - boardData->Count[boardData->TurnPlayer] < max)
                        {
                            max = Demoview.Count[boardData->TurnPlayer] - boardData->Count[boardData->TurnPlayer];
                            tx = x;
                            ty = y;
                        }
                    }
                }
            }
            boardData->PutStone(tx, ty);
}

