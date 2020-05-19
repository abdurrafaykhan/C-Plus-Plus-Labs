//  playMove.cpp
//  TicTacTo
//
//  Updated by Tarek Abdelrahman on 2019-06-07.
//  Created by Tarek Abdelrahman on 2018-05-15.
//  Copyright © 2018-2019 Tarek Abdelrahman. All rights reserved.
//

#include "tictactoe.h"
#include "gameState.h"

void playMove(gameState& game_state) {
   
    //Checks if the clicked row and clicked column are within the domain of the 3x3 board
    if (0 <= game_state.get_clickedRow() && game_state.get_clickedRow() <= 2 && 0 <= game_state.get_clickedColumn() && game_state.get_clickedColumn() <=2) {
        
        //sets the clickedRow and clickedColumn to the corresponding clicked box on the board
        game_state.set_clickedRow(game_state.get_clickedRow());
        game_state.set_clickedColumn(game_state.get_clickedColumn());
       
        //Checks if there is no 'X' or 'O' on the clicked spot
        if (game_state.get_gameBoard(game_state.get_clickedRow(), game_state.get_clickedColumn()) == 0) {
            game_state.set_moveValid(true);
            
            //Sets the box to 'X' or 'O' depending on who's turn it is
            if (game_state.get_turn() == true) {
                game_state.set_gameBoard(game_state.get_clickedRow(),game_state.get_clickedColumn(), 1);
               
            }
            else {
                game_state.set_gameBoard(game_state.get_clickedRow(),game_state.get_clickedColumn(), -1);
            }
           
           
            //Below are all the scenarios where a player wins and when the winning scenario exists, the game is over
            if (game_state.get_gameBoard(0,0) == game_state.get_gameBoard(0,1) && game_state.get_gameBoard(0,1) == game_state.get_gameBoard(0,2) && game_state.get_gameBoard(0,2) != 0) {
                game_state.set_winCode(1);
                game_state.set_gameOver(true);
            }
           
            else if (game_state.get_gameBoard(1,0) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(1,2) && game_state.get_gameBoard(1,2) != 0) {
                game_state.set_winCode(2);
                game_state.set_gameOver(true);
            }
           
            else if (game_state.get_gameBoard(2,0) == game_state.get_gameBoard(2,1) && game_state.get_gameBoard(2,1) == game_state.get_gameBoard(2,2) && game_state.get_gameBoard(2,2) != 0) {
                game_state.set_winCode(3);
                game_state.set_gameOver(true);
            }
           
            else if (game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,0) && game_state.get_gameBoard(1,0) == game_state.get_gameBoard(2,0) && game_state.get_gameBoard(2,0) != 0) {
                game_state.set_winCode(4);
                game_state.set_gameOver(true);
            }
           
            else if (game_state.get_gameBoard(0,1) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(2,1) && game_state.get_gameBoard(2,1) != 0) {
                game_state.set_winCode(5);
                game_state.set_gameOver(true);
            }
           
            else if (game_state.get_gameBoard(0,2) == game_state.get_gameBoard(1,2) && game_state.get_gameBoard(1,2) == game_state.get_gameBoard(2,2) && game_state.get_gameBoard(2,2) != 0) {
                game_state.set_winCode(6);
                game_state.set_gameOver(true);
            }
           
            else if (game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(2,2) && game_state.get_gameBoard(2,2) != 0) {
                game_state.set_winCode(7);
                game_state.set_gameOver(true);
            }
           
            else if (game_state.get_gameBoard(0,2) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(2,0) && game_state.get_gameBoard(2,0) != 0) {
                game_state.set_winCode(8);
                game_state.set_gameOver(true);
            }  
            
            //If none of the above winning conditions were met during the turn, then the game continues as if nobody has one
            if (game_state.get_winCode() != 1 && game_state.get_winCode() !=2 && game_state.get_winCode() !=3 && game_state.get_winCode() !=4 && game_state.get_winCode() !=5 && game_state.get_winCode() !=6 && game_state.get_winCode() !=7 && game_state.get_winCode() !=8) {
                game_state.set_winCode(0);
                
                //Checks to see if the board is full of pieces to determine if the game is a draw. If the board is full, the game is over and noone has won
                if(game_state.get_gameBoard(0,0) != 0 && game_state.get_gameBoard(0,1) != 0 && game_state.get_gameBoard(0,2) != 0 && game_state.get_gameBoard(1,0) != 0 && game_state.get_gameBoard(1,1) != 0 && game_state.get_gameBoard(1,2) != 0 && game_state.get_gameBoard(2,0) != 0 && game_state.get_gameBoard(2,1) != 0 && game_state.get_gameBoard(2,2) != 0) {
                    game_state.set_gameOver(true);
                }
                
                //When nobody has won and the board is not full, the players switch turns and the game is not over
                else {
                    game_state.set_gameOver(false);
               
                    if (game_state.get_turn() == true) {
                        game_state.set_turn(false);
                    }
                    else {
                        game_state.set_turn(true);
                    }
                }
            }
           
        } 
        
        //if the selected box is occupied with an 'X' or an 'O', then the game continues with the same player's turn and nobody has won
        else {
            game_state.set_moveValid(false);
            game_state.set_gameOver(false);
            game_state.set_turn(game_state.get_turn());
            game_state.set_winCode(0);
        }
    }
}