/* -----------------------------------------------------------------------------
 *
 * File Name:  king.cpp
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the king class
 * Date: 10/12/2020
 *
 ---------------------------------------------------------------------------- */
 #include "king.h"
 #include <iostream>
 using namespace std;

 king::king(int row, int col, int player)
 {
    currentRowPos = row;
    currentColPos = col; 

    if(player == 1) symbol = 'K';
    else symbol = 'k';
 } 

 king::~king(){}

 void king::move(int row, int col)
 {
    if(validMove(row, col))
    {
        throw(std::runtime_error("invalid move for KING"));
    }
    else 
    {
        currentColPos = col; 
        currentRowPos = row; 
    }
 }

// void king::attack(int row, int col)
// {

// }

bool king::validMove(int row, int col)
{
    if(row > currentRowPos+1 || col > currentColPos+1 || row < currentRowPos-1 || col < currentColPos-1)
    {
        return(false); 
    }
    else return(true);
}

char king::getSymbol()const
{
    return(symbol);
}

int king::getCurrentRowPos()const
{
    return(currentRowPos);
}

int king::getCurrentColPos()const
{
    return(currentColPos);
}