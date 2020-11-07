/* -----------------------------------------------------------------------------
 *
 * File Name:  board.h
 * Author: Tristan Gant 
 * Assignment:   EECS-448 Project 3
 * Description:  cpp file for the board class
 * Date: 10/29/2020
 *
 ---------------------------------------------------------------------------- */
#include "board.h"

board::board() //good
{
    m_cols = 8; 
    m_rows = 8; 

    m_board = new char*[8]; 
    for(int i = 0; i < 8; i++)
    {
        m_board[i] = new char[8]; 
    }

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            m_board[i][j] = '-'; 
        }
    }

    //initializes a board of chessPiece pointers and sets them to nullptr
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            chessPieceInterface* temp = nullptr; 
            m_PiecesBoard[i][j] = temp;
        }
    }
}

void board::addToPieceBoard(chessPieceInterface* piecePtr, int row, int col) //good
{
    if(row < 0 || col < 0 || piecePtr == nullptr)
    {
        throw(std::runtime_error("Does not exist"));
    }
    else 
    {
        m_PiecesBoard[row][col] = piecePtr;
    }
}

board::~board() 
{
    for(int i = 0; i < m_rows; i++)
    {
        delete m_board[i];
    }
    delete[] m_board;
}

void board::printBoard() //good
{
    //sets up the column labels for the board
    cout << " " << '\t'; 
    for(char i = 'A'; i <= 'H'; i++) cout << i << "\t";
    cout << "\n\n";


    //prints out the board with the row labels
    for(int i = 0; i < m_rows; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(j == 0) 
            {
                cout << i+1 << '\t';
            }
            cout << m_board[i][j]  << '\t';
        }
        cout << endl; 
    }
}

void board::printPieceBoard() //good
{
    //sets up the column labels for the board
    cout << " " << '\t'; 
    for(char i = 'A'; i <= 'H'; i++) cout << i << "\t";
    cout << "\n\n";

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(j == 0) 
            {
                cout << i+1 << '\t';
            }
            if(m_PiecesBoard[i][j] == nullptr) cout << "-" <<'\t';
            else cout << m_PiecesBoard[i][j]->getSymbol() << '\t';   
        }
        cout << endl;
    }
}

void board::setInitialLocation() //good
{
    //creates a king object and sets it at 1,1
    king* king1 = new king(7,4,1); 
    m_board[7][4] = king1->getSymbol();
    addToPieceBoard(king1, 7, 4); 

    queen* queen1 = new queen(7,3,1);
    m_board[7][3] = queen1->getSymbol(); 
    addToPieceBoard(queen1, 7, 3);

    rook* player1rook0 = new rook(7,0,1);
    rook* player1rook1 = new rook(7,7,1); 
    m_board[7][0] = player1rook0->getSymbol();
    m_board[7][7] = player1rook1->getSymbol();
    addToPieceBoard(player1rook0,7,0);
    addToPieceBoard(player1rook1, 7,7); 

    knight* player1knight0 = new knight(7,1,1);
    knight* player1knight1 = new knight(7,6,1); 
    m_board[7][1] = player1knight0->getSymbol();
    m_board[7][6] = player1knight1->getSymbol();
    addToPieceBoard(player1knight0, 7,1); 
    addToPieceBoard(player1knight1,7,6); 

    bishop* player1bishop0 = new bishop(7,2,1);
    bishop* player1bishop1 = new bishop(7,5,1); 
    m_board[7][2] = player1bishop0->getSymbol(); 
    m_board[7][5] = player1bishop1->getSymbol();
    addToPieceBoard(player1bishop0,7,2);
    addToPieceBoard(player1bishop1,7,5); 

    pawn* player1pawn0 = new pawn(6,0,1); 
    pawn* player1pawn1 = new pawn(6,1,1); 
    pawn* player1pawn2 = new pawn(6,2,1); 
    pawn* player1pawn3 = new pawn(6,3,1); 
    pawn* player1pawn4 = new pawn(6,4,1); 
    pawn* player1pawn5 = new pawn(6,5,1); 
    pawn* player1pawn6 = new pawn(6,6,1); 
    pawn* player1pawn7 = new pawn(6,7,1); 
    m_board[6][0] = player1pawn0->getSymbol(); 
    m_board[6][1] = player1pawn1->getSymbol(); 
    m_board[6][2] = player1pawn2->getSymbol(); 
    m_board[6][3] = player1pawn3->getSymbol(); 
    m_board[6][4] = player1pawn4->getSymbol(); 
    m_board[6][5] = player1pawn5->getSymbol(); 
    m_board[6][6] = player1pawn6->getSymbol(); 
    m_board[6][7] = player1pawn7->getSymbol(); 
    addToPieceBoard(player1pawn0,6,0);
    addToPieceBoard(player1pawn1,6,1);
    addToPieceBoard(player1pawn2,6,2);
    addToPieceBoard(player1pawn3,6,3);
    addToPieceBoard(player1pawn4,6,4);
    addToPieceBoard(player1pawn5,6,5);
    addToPieceBoard(player1pawn6,6,6);
    addToPieceBoard(player1pawn7,6,7);




    //player 2 pieces being placed //

    king* king2 = new king(0,4,2);
    m_board[0][4] = king2->getSymbol(); 
    addToPieceBoard(king2,0,4); 

    queen* queen2 = new queen(0,3,2);
    m_board[0][3] = queen2->getSymbol();
    addToPieceBoard(queen2,0,3); 

    rook* player2rook0 = new rook(0,0,2);
    rook* player2rook1 = new rook(0,7,2); 
    m_board[0][0] = player2rook0->getSymbol();
    m_board[0][7] = player2rook1->getSymbol();
    addToPieceBoard(player2rook0,0,0); 
    addToPieceBoard(player2rook1,0,7); 

    knight* player2knight0 = new knight(0,1,2);
    knight* player2knight1 = new knight(0,6,2); 
    m_board[0][1] = player2knight0->getSymbol();
    m_board[0][6] = player2knight1->getSymbol();
    addToPieceBoard(player2knight0,0,1); 
    addToPieceBoard(player2knight1,0,6); 

    
    bishop* player2bishop0 = new bishop(0,2,2);
    bishop* player2bishop1 = new bishop(0,5,2); 
    m_board[0][2] = player2bishop0->getSymbol(); 
    m_board[0][5] = player2bishop1->getSymbol();
    addToPieceBoard(player2bishop0,0,2); 
    addToPieceBoard(player2bishop1,0,5); 

    pawn* player2pawn0 = new pawn(1,0,2); 
    pawn* player2pawn1 = new pawn(1,1,2); 
    pawn* player2pawn2 = new pawn(1,2,2); 
    pawn* player2pawn3 = new pawn(1,3,2); 
    pawn* player2pawn4 = new pawn(1,4,2); 
    pawn* player2pawn5 = new pawn(1,5,2); 
    pawn* player2pawn6 = new pawn(1,6,2); 
    pawn* player2pawn7 = new pawn(1,7,2); 
    m_board[1][0] = player2pawn0->getSymbol(); 
    m_board[1][1] = player2pawn1->getSymbol(); 
    m_board[1][2] = player2pawn2->getSymbol(); 
    m_board[1][3] = player2pawn3->getSymbol(); 
    m_board[1][4] = player2pawn4->getSymbol(); 
    m_board[1][5] = player2pawn5->getSymbol(); 
    m_board[1][6] = player2pawn6->getSymbol(); 
    m_board[1][7] = player2pawn7->getSymbol(); 
    addToPieceBoard(player2pawn0,1,0);
    addToPieceBoard(player2pawn1,1,1);
    addToPieceBoard(player2pawn2,1,2);
    addToPieceBoard(player2pawn3,1,3);
    addToPieceBoard(player2pawn4,1,4);
    addToPieceBoard(player2pawn5,1,5);
    addToPieceBoard(player2pawn6,1,6);
    addToPieceBoard(player2pawn7,1,7);


}

bool board::checkForPiece(int row, int col)
{
    if(m_board[row][col] == '-') return false; 
    else return true;
}


void board::move(int pickRow, int pickCol, int moveToRow, int moveToCol, int player, bool &x)
{
    if(!checkForPiece(pickRow,pickCol))
    {
        x = false;
        throw(std::runtime_error("there is no piece at this location to move"));
    }
    else //if there is a piece on this spot 
    {
        //if the piece does not belong to the correct player
        if(getPlayerByPiece(m_board[pickRow][pickCol]) != player)
        {
            x = false;
            throw(std::runtime_error("This piece is not yours to move"));
        }
        else 
        {
            try
            {
                m_PiecesBoard[pickRow][pickCol]->move(moveToRow,moveToCol, m_board); //calls the piece move function
                chessPieceInterface* temp = m_PiecesBoard[pickRow][pickCol]; //creates a ptr to its position before the move
                m_PiecesBoard[pickRow][pickCol] = nullptr; //sets its initial position to null
                m_PiecesBoard[moveToRow][moveToCol] = temp; //sets the new index to be the chess piece

                //update the char board -- because it is passed to the pieces classes when move is called
                m_board[pickRow][pickCol] = '-'; 
                m_board[moveToRow][moveToCol] = m_PiecesBoard[moveToRow][moveToCol]->getSymbol();
                // x = true;
            }
            catch(const runtime_error& rte)
            {
                cout << rte.what() << endl;
                x = false;
                return;
            }
            x = true;
        }

    }
}

void board::attack(int pickRow, int pickCol, int moveToRow, int moveToCol, int player, bool &x)
{
    if(!checkForPiece(pickRow,pickCol))
    {
        x = false;
        throw(std::runtime_error("There is no piece in that position to move"));
    }
    else
    {
        //if the piece does not belong to the correct player
        if(getPlayerByPiece(m_board[pickRow][pickCol]) != player)
        {
            x = false;
            throw(std::runtime_error("This piece is not yours to attack with"));
        }
        else 
        {
            try
            {
                //pick the piece that is going to attack
                //attack at the index given
                m_PiecesBoard[pickRow][pickCol]->attack(moveToRow, moveToCol, m_board); 

                //call is dead function to remove the piece from the board 
                m_PiecesBoard[moveToRow][moveToCol]->isDead();
                m_PiecesBoard[moveToRow][moveToCol] = nullptr;

                chessPieceInterface* temp = m_PiecesBoard[pickRow][pickCol]; //creates a ptr to its position before the move
                m_PiecesBoard[pickRow][pickCol] = nullptr; //sets its initial position to null
                m_PiecesBoard[moveToRow][moveToCol] = temp; 

                m_board[pickRow][pickCol] = '-';
                m_board[moveToRow][moveToCol] = m_PiecesBoard[moveToRow][moveToCol]->getSymbol();
                // x = true;
            }
            catch(std::runtime_error& rte)
            {
                cout << rte.what() << endl;
                x = false; 
                return;
            }
            x = true; 
        }
    }
}

int board::convertCharToInt(char letter)
{
    switch (letter)
    {
    case 'A':
        return 0;
        break;
    case 'B':
        return 1;
        break;
    case 'C':
        return 2;
        break;
    case 'D':
        return 3;
        break;
    case 'E':
        return 4;
        break;
    case 'F':
        return 5;
        break;
    case 'G':
        return 6;
        break;
    case 'H':
        return 7;
        break;
    case 'a':
        return 0;
        break;
    case 'b':
        return 1;
        break;
    case 'c':
        return 2;
        break;
    case 'd':
        return 3;
        break;
    case 'e':
        return 4;
        break;
    case 'f':
        return 5;
        break;
    case 'g':
        return 6;
        break;
    case 'h':
        return 7;
        break;
    }
    return letter;
}

int board::getPlayerByPiece(char piece)
{
    if(piece == 'K' || piece == 'Q' || piece == 'R' || piece == 'N' || piece == 'B' || piece == 'P')
    {
        return 1; 
    }
    if(piece == 'k' || piece == 'q' || piece == 'r' || piece == 'n' || piece == 'b' || piece == 'p')   
    {
        return 2;
    }
    else return 0; 
}

bool board::inCheck(int player)
{
    //the king is not on the board 
    if(getKingRow(player) == -1 && getKingCol(player) == -1)
    {
        return(false);
    }

    //loop through the board and check the remaining pieces to see if they can 
    //attack the king at position
    if(canPieceAttackTheKing(player, getKingRow(player), getKingCol(player))) return true; 

    //should be false if it gets to this point
    else return(false);
    
}

bool board::canPieceAttackTheKing(int player, int r, int c)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            //it is an opposing player (lowercase)
            if(player != getPlayerByPiece(m_board[i][j]))
            {
                //that can attack the king 
                if(m_PiecesBoard[i][j] != nullptr)
                {
                    if(true == m_PiecesBoard[i][j]->validAttack(r,c, m_board) || m_PiecesBoard[i][j]->validMove(r,c,m_board) == true)
                    {
                        //cout is for testing
                        // cout << i+1 << j+1 << endl; 
                        return true;
                    }
                }
            }
        }
    }
    //nothing can attack the king
    return false; 
}

int board::getKingRow(int player)
{
    int kingPositionRow = -1;

    //first find the kings on the board 
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(player == 1 && m_board[i][j] == 'K')
            {
                // cout << i << j << endl;
                kingPositionRow = i; 
            }
            //SECOND KING
            if(player == 2 && m_board[i][j] == 'k')
            {
                kingPositionRow = i;
            }
        }
    }
    if(kingPositionRow == -1) return 0; 
    else return(kingPositionRow);
}

int board::getKingCol(int player)
{
    int kingPositionCol = -1;

    //first find the kings on the board 
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(player == 1 && m_board[i][j] == 'K')
            {
                // cout << i << j << endl;
                kingPositionCol = j; 
            }
            //SECOND KING
            if(player == 2 && m_board[i][j] == 'k')
            {
                kingPositionCol = j;
            }
        }
    }
    if(kingPositionCol == -1) return 0; 
    else return(kingPositionCol);
}


bool board::checkKingMoves(int player)
{
    //the king is not on the board 
    if(getKingRow(player) == -1 && getKingCol(player) == -1)
    {
        return(false);
    }

    //redefine variables
    int r = getKingRow(player);
    int c = getKingCol(player); 
    

    //check all moves for the king to see if he can move/attack out of check
    //check when the king moves if he can still be attacked
    //check down
    if(m_PiecesBoard[r][c]->validMove(r+1,c,m_board) || m_PiecesBoard[r][c]->validAttack(r+1,c,m_board))
    {
        if(canPieceAttackTheKing(player, r+1, c)) return true; 
        else return(false); 
    } 
    
    //check up
    else if(m_PiecesBoard[r][c]->validMove(r-1,c,m_board) || m_PiecesBoard[r][c]->validAttack(r-1,c,m_board))
    {
        if(canPieceAttackTheKing(player, r-1, c)) return true; 
        else return(false); 
    }
    
    //check right
    else if(m_PiecesBoard[r][c]->validMove(r,c+1,m_board) || m_PiecesBoard[r][c]->validAttack(r,c+1,m_board))
    {
        if(canPieceAttackTheKing(player, r, c+1)) return true; 
        else return(false);    
    }
    
    //check left
    else if(m_PiecesBoard[r][c]->validMove(r,c-1,m_board) || m_PiecesBoard[r][c]->validAttack(r,c-1,m_board))
    {
        if(canPieceAttackTheKing(player, r, c-1)) return true; 
        else return(false);        
    }
    
    //check down and right
    else if(m_PiecesBoard[r][c]->validMove(r+1,c+1,m_board) || m_PiecesBoard[r][c]->validAttack(r+1,c+1,m_board))
    {
        if(canPieceAttackTheKing(player, r+1, c+1)) return true; 
        else return(false); 
    }
    
    //check down and left
    else if(m_PiecesBoard[r][c]->validMove(r+1,c-1,m_board) || m_PiecesBoard[r][c]->validAttack(r+1,c-1,m_board))
    {
        if(canPieceAttackTheKing(player, r+1, c-1)) return true; 
        else return(false); 
    }
    
    //check up and left
    else if(m_PiecesBoard[r][c]->validMove(r-1,c-1,m_board) || m_PiecesBoard[r][c]->validAttack(r-1,c-1,m_board))
    {
        if(canPieceAttackTheKing(player, r-1, c-1)) return true; 
        else return(false); 
    } 

    //check up and right
    else if(m_PiecesBoard[r][c]->validMove(r-1,c+1,m_board) || m_PiecesBoard[r][c]->validAttack(r-1,c+1,m_board))
    {
        if(canPieceAttackTheKing(player, r-1, c+1)) return true; 
        else return(false); 
    }
    
    //the king has no where he can move to or attack
    else 
    {
        cout << "CHECKMATE" << endl;
        return(true);
    }

}
 








bool board::isCheckMate(int player)
{
    bool bCheckmate = false; 

    //1st case - is the king in check ?
    if(!inCheck(player)) return false; 

    //2nd case - Can the king move to other squares 
    //define variables to store the positions of the kings
    if(!checkKingMoves(player)) return false; 

    
}


//I THINK THE PROBLEM IS THST THE KING IS GETTING ATTACKED AND DELETED BEFORE GOING BACK INTO THE CHECK FUNCTION
//THIS IS CREATING A PROBLEM AS THE FOR LOOP SEARCHES THE ARRAY FOR THE KING BUT THERE IS NO KING THERE
//THE TWO VARIABLES THAT ARE STORING THE KINGS COL AND ROW GO UNDEFINED
//THE COMPILER ASSIGNS THEM RANDOM INTS BASED ON THERE PLACE IN MEMORY WHICH IS THEN BEING PLACED AS THE 
//PARAMETERS IN THE VALID ATTACK FUCNTIONS,, THIS CAN BE FIXED IN A COUPLE DIFFERENT WAYS I THINK
//ONE
//BOUND CHECK ON THE BOARD IN ALL CHESS PIECE FILES FOR VALID MOVE AND ATTACK
// THIS IS A SMART THING TO DO ANYWAY
//NOT SURE IF THIS WILL FIX THE PROBLEM THO
//TWO 
//IF THERE IS NO KING? END THE GAME 


//IN THE CAN PIECE ATTACK THEKING FUNCTION -- CREATE ANOTHER FUNCTION
//THAT TAKES IN THE POSITION OF THE PIECE THAT THE CAN ATTACK THE KING 
//AND SEE IF IT CAN BE ATTACKED BY AN OPPOSING PLAYERS PIECE

//AFTER THE ABOVE IS IMPLEMENTED THE ONLY THING LEFT FOR CHECKMATE WILL
//BE TO CHECK IF A PIECE CAN BE PUT IN THE WAY OF THE ATTACKING PIECE 
//TO STOP THE CHECK