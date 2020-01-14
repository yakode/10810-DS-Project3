#include <iostream>
#include <stdlib.h>
#include "../include/algorithm.h"

using namespace std;

int left_over(Board board, int x, int y){
	return board.get_capacity(x, y) - board.get_orbs_num(x, y);
}

void algorithm_A(Board board, Player player, int index[]){

	//scanf("%d%d",&index[0], &index[1]);
	//return;
	
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
				if( left_over(board, i, j) <= left_over(board, row_, col_) ){
					reaction++;
					if(left_over(board, row_, col_) == 1){
							index[0] = i;
							index[1] = j;
							return;
					}
				}
			}
			if(reaction > max_reaction){
				max_reaction = reaction;
				row = i;
				col = j;
			}else if(reaction == max_reaction && reaction != 0){
				if(left_over(board, i, j) < left_over(board, row, col)){
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

    index[0] = row;
    index[1] = col;
}
