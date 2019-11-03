#include"game.h"

void initboard(char board[][col],int ROW,int COL){
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++){
		for (j = 0; j < COL; j++){
			board[i][j] = K;
		}
	}
}

void showboard(char board[][col], int ROW, int COL){
	int i = 0;
	int j = 0;
	printf("  1  | 2 | 3 \n");
	printf("---------------\n");
	for (i = 0; i < ROW; i++){
		printf("%d |", i + 1);
		for (j = 0; j < COL; j++){	
			printf("%c  |", board[i][j]);
		}
		printf("\n");
		printf("------------------\n");
	}
}

void computer(char board[][col], int ROW, int COL){
	do{
		int x = rand() % ROW;
		int y = rand() % COL;
		if (board[x][y] == ' '){
			board[x][y] = 'O';
			break;
		}
	} while (1);
}

char judgeboard(char board[][col], int ROW, int COL){
	int i = 0;
	for (i = 0; i < ROW; i++){
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != K){
			return board[i][0];
		}
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != K){
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != K){
		return board[1][1];
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != K){
		return board[1][1];
	}
	for (i = 0; i < ROW; i++){
		int j = 0;
		for (j = 0; j < COL; j++){
			if (board[i][j] == ' '){
				return 'N';
			}
		}
	}
	return 'F';
}
void game(){
	srand((unsigned long)time(NULL));
	char board [row][col];
	initboard(board, row, col);
	char result;
	do{
		system("cls");
		showboard(board, row, col);
	    int x = 0;
	    int y = 0;
	    printf("请输入坐标\n");
	    scanf("%d %d", &x, &y);
		if (x<1 || x>3 || y<1 || y>3){
			printf("输入错误，请重新输入：\n");
			continue;
		}
		else if (board[x-1][y-1] != K){
			printf("输入错误，请重新输入：\n");
			continue;
		}
		else{
			board[x-1][y-1] = 'X';
		}
		computer(board, row, col);
		showboard(board, row, col);
		result = judgeboard(board, row, col);
		if (result != 'N'){
			break;
		}
	} while (1);
	if (result == 'F'){
		printf("平局\n");
	}
	else if (result == 'X'){
		printf("你赢了\n");
	}
	else if(result == 'O'){
		printf("你输了\n");
	}
}
