/**
* Author: Tristan Gant 
* File: main.cpp
* Description: This file is the main, and is empty right now
* Date: Last changed on 10/7/20 by Tristan Gant 
*/
#include <iostream> 
#include "board.h"

int main()
{

    board test; 

    test.setInitialLocation();
    test.printBoard();
    cout << "\n\n\n\n";
    test.printPieceBoard();

    system("clear");
    test.move(6,0,3,0,1); 
    test.printPieceBoard();


    return(0); 
}