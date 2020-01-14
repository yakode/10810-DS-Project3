#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions 
 * 1. ~ 4. are listed in next block)
 * 
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 * 
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/


void algorithm_A(Board board, Player player, int index[]){

    // cout << board.get_capacity(0, 0) << endl;
    // cout << board.get_orbs_num(0, 0) << endl;
    // cout << board.get_cell_color(0, 0) << endl;
    // board.print_current_board(0, 0, 0);

    //////////// Random Algorithm ////////////
    // Here is the random algorithm for your reference, you can delete or comment it.
    //srand(time(NULL));
	scanf("%d%d",&index[0], &index[1]);
	return;
	//
	
    int row = -1, col;
    int color = player.get_color();
    

	int dx[4] = {0, 0, -1, 1},
		dy[4] = {-1, 1, 0, 0};
	int max_reaction = 0;
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 6; ++j){
			if(board.get_cell_color(i, j) != color && board.get_cell_color(i, j) != 'w') continue;
			int reaction = 0;
			for(int k = 0; k < 4; ++k){
				int row_ = i + dx[k],
					col_ = j + dy[k];
				if(row_ < 0 || row_ > 4 || col_ < 0 || col_ > 5) continue;
				if(board.get_cell_color(row_, col_) == color || board.get_cell_color(row_, col_) == 'w') continue;
				if( board.get_capacity(i, j) < board.get_capacity(row_, col_) ){
					reaction++;
					if(board.get_capacity(row_, col_) == 1){
						reaction += board.get_orbs_num(row_, col_);
					}
				}
			}
			if(reaction > max_reaction){
				max_reaction = reaction;
				row = i;
				col = j;
			}else if(reaction == max_reaction){
				if(board.get_capacity(i, j) < board.get_capacity(row, col)){
					row = i;
					col = j;
				}
			}
		}
	}

	if(row == -1){
		int min_capacity = 5;
		for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 6; ++j){
				if(board.get_cell_color(i, j) != color && board.get_cell_color(i, j) != 'w') continue;
				int capa = board.get_capacity(i, j);
				if(capa < min_capacity){
					min_capacity = capa;
					row = i;
					col = j;
				}
			}
		}
	}
    /*while(1){
        row = rand() % 5;
        col = rand() % 6;
        if(board.get_cell_color(row, col) == color || board.get_cell_color(row, col) == 'w') break;
    }*/

    index[0] = row;
    index[1] = col;
}
