//
//  board.cpp
//  REVERSI
//
//  Created by Sakura on 2014/08/10.
//  Copyright (c) 2014年 Sakura. All rights reserved.
//

#include "board.h"
using namespace std;
board::board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            stone[i][j] = 0;
        }
    }

    stone[3][3] = 1;
    stone[3][4] = 2;
    stone[4][3] = 2;
    stone[4][4] = 1;
    
    TurnPlayer = 1;
    
    TurnCount = 1;
    Count[0] = 2;
    Count[1] = 2;
    
}
void board::output()
{
    cout << (TurnPlayer == 1 ? "◯" : "☓") << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << " " <<  i;
    }
    cout << endl;
    for (int j = 0; j < 8; j++)
    {
        cout << j;
        for (int i = 0; i < 8; i++)
        {
            if (stone[i][j] == 0)
            {
                cout << "-" << " ";
            }
            if (stone[i][j] == 1)
            {
                cout << "◯" << " ";
            }
            if (stone[i][j] == 2)
            {
                cout << "☓" << " ";
            }
        }
        cout << endl;
    }
    cout << "黒:" << Count[0] << endl;
    cout << "白:" << Count[1] << endl;
    cout << "Turn:" << TurnCount << endl;
    
    cout << endl;
}
bool board::CanPutStone(int x, int y)
{
    vector vec[] =
    {
        vector(-1,-1),
        vector( 0,-1),
        vector( 1,-1),
        vector( 1, 0),
        vector( 1, 1),
        vector( 0, 1),
        vector(-1, 1),
        vector(-1, 0)
    };
    
    int MyColor = TurnPlayer;
    int RivalColor = (TurnPlayer == 1 ? 2 : 1);
    
    if (x > 7 || y > 7 ||x < 0 || y < 0) return false;
    if (stone[x][y] != 0) return false;
    
    for (int i = 0 ; i < 8; i++)
    {
        int tx = x;
        int ty = y;
        int step = 0;
        
        while (true)
        {
            
            tx += vec[i].x;
            ty += vec[i].y;
            
            if (stone[tx][ty] == RivalColor)
            {
                step = 1;
            }
            else if (stone[tx][ty] == MyColor)
            {
                if (step == 1)
                {
                    return true;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }

    return false;
}
bool board::CanPutStoneAll()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(CanPutStone(i, j))
            {
                return true;
            }
        }
    }
    return false;
}
bool board::Gameover()
{
    if(!CanPutStoneAll())
    {
        TurnPlayer = (TurnPlayer == 1 ? 2 : 1);
        if (!CanPutStoneAll())
        {
            return true;
        }
        TurnPlayer = (TurnPlayer == 1 ? 2 : 1);
    }
    return false;
}
void board::PutStone(int x , int y)
{
    vector vec[] =
    {
        vector(-1,-1),
        vector( 0,-1),
        vector( 1,-1),
        vector( 1, 0),
        vector( 1, 1),
        vector( 0, 1),
        vector(-1, 1),
        vector(-1, 0)
    };
    
    int MyColor = TurnPlayer;
    int RivalColor = (TurnPlayer == 1 ? 2 : 1);
    if (!CanPutStone(x,y)) return ;
    
    for (int i = 0 ; i < 8; i++)
    {
        int tx = x;
        int ty = y;
        int step = 0;
        
        
        while (true)
        {
            
            tx += vec[i].x;
            ty += vec[i].y;
            
            if (stone[tx][ty] == RivalColor)
            {
                step = 1;
            }
            else if (stone[tx][ty] == MyColor)
            {
                if (step == 1)
                {
                    step = 2;
                }
                break;
            }
            else
            {
                break;
            }
        }
        
        tx = x;
        ty = y;
        
        if (step == 2)
        {
            while (true)
            {
                
                tx += vec[i].x;
                ty += vec[i].y;
                
                if (stone[tx][ty] == RivalColor)
                {
                    stone[tx][ty] = MyColor;
       
                    Count[MyColor -1]++;
                    Count[RivalColor -1]--;
                }
                else
                {
                    break;
                }
            }
            
            Count[MyColor -1]++;
            stone[x][y] = MyColor;
        }
        
    }
    TurnPlayer = (TurnPlayer == 1 ? 2 : 1);
}