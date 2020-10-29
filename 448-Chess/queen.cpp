/* -----------------------------------------------------------------------------
 *
 * File Name:  queen.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the queen class
 * Date: 10/22/2020
 *
 ---------------------------------------------------------------------------- */
 #include "queen.h"
 #include <iostream>
 using namespace std;

 queen::queen(int row, int col, int player)
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'Q';
    else symbol = 'q';
 } 

 queen::~queen(){}

 void queen::move(int row, int col, char **b)
 {
    if(!validMove(row, col, b))
    {
        throw(std::runtime_error("invalid move for KING"));
    }
    else 
    {
        currentColPos = col; 
        currentRowPos = row; 
    }
 }

void queen::attack(int row, int col, char **b)
{
    //needs to be defined
}

bool queen::validMove(int row, int col, char **b)
{
   if((row - location[0] == col - location[1] || row - location[0] == location[1] - col) && row - location[0] != 0)
    {
        int rowpace = row -location[0];
        int colpace = col -location[1];
        if (rowpace > 0)
            rowpace = 1;
        else
            rowpace = -1;
        if (colpace > 0)
            colpace = 1;
        else
            colpace = -1;
        int i = location[0]+rowpace;
        int j = location[1]+colpace;
        for (; i!=row; i +=rowpace)
        {
            if (this->getCurrentBox()->getboard()->getbox(i,j)->hasPiece())
                return false;
            else
                j += colpace;
        }
        return true;
    }
    if (row == location[0] && col != location[1])
    {
        int pace = col - location[1];
        if (pace > 0)
            pace = 1;
        else
            pace = -1;
        for (int i =location[1]+pace; i != col; i+=pace)
            if (this->getCurrentBox()->getboard()->getbox(x,i)->hasPiece())
                return false;
        return true;
    }
    else if (col == location[1] && row != location[0] )
    {
        int pace = row - location[0];
        if (pace > 0)
            pace = 1;
        else
            pace = -1;
        for (int i =location[0]+pace; i != row; i+=pace)
            if (this->getCurrentBox()->getboard()->getbox(i,col)->hasPiece())
                return false;
        return true;
    }
    else
        return false;
}
}

char queen::getSymbol()const
{
    return(symbol);
}

int queen::getCurrentRowPos()const
{
    return(currentRowPos);
}

int queen::getCurrentColPos()const
{
    return(currentColPos);
}

bool queen::emptySpace(char space)
{
  if(space == '-') 
    return true; 
  else 
    return false; 
}

void queen::isDead()
{
    symbol = '-';
}

bool queen::isOpposingPlayer(char s)
{
    if(symbol == 'Q') //if player1 
    {
        if(s == 'p' || s == 'r' || s == 'n' || s == 'b' || s == 'q' || s == 'k') 
            return true; 
        else 
            return false; 
    }
    else 
    {
        if(s == 'P' || s == 'R' || s == 'N' || s == 'B' || s == 'Q' || s == 'K') 
            return true; 
        else 
            return false;       
    }
}

bool queen::validAttack(int row, int col, char **b)
{
    //needs to be defined 
}
