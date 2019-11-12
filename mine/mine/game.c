#include"game.h"


void setboard(char Mine[][col], int ROW, int COL,int *x_p,int *y_p){
	int count = NUM;
	while (count > 0){
		int x = rand() % (ROW-2) + 1;
		int y = rand() % (COL-2) + 1;
		if (Mine[x][y] == '0'){
			Mine[x][y] = '1';
			count--;
		}
	}
	int i = 1;
	for (; i <= 10; i++){
		int j = 1;
		for (; j <= 10; j++){
			if (Mine[i][j] == '0'){
				*x_p = i;
				*y_p = j;
			}
		}
	}
}

void showboard(char Player[][col], int ROW, int COL){
	printf("   ");
	int i = 1;
	for (; i <= 10; i++){
		printf(" %d  ", i);
	}
    printf("\n");
	for (i = 1; i <= 10; i++){
		printf("----");
	}
	printf("---\n");
	for (i = 1; i <= 10; i++){
		int j = 1;
		printf("%2d |", i);
		for (; j <= 10; j++){
			printf(" %c |", Player[i][j]);
		}
		printf("\n");
		int k = 1;
		for (k = 1; k<= 10; k++){
			printf("----");
		}
		printf("---\n");

	}
}
int getcount(char Mine[][col], int x, int y){
	return Mine[x - 1][y - 1] + Mine[x - 1][y] + Mine[x - 1][y + 1] + \
		Mine[x][y - 1] + Mine[x][y + 1] + Mine[x + 1][y - 1] + Mine[x - 1][y] + Mine[x - 1][y + 1] - 8 * '0';
}
void game()
{
	
	srand((unsigned)time(NULL));
	char Player[row][col];
	char Mine[row][col];
	memset(Player, '*', sizeof(Player));
	memset(Mine, '0', sizeof(Mine));
	int nx, ny;
	setboard(Mine, row, col,&nx,&ny);
	int x = 0;
	int y = 0;
	int temes = 100 - NUM;
	do{
		system("cls");
		showboard(Player, row, col);
		printf("请输入坐标:\n");
		scanf("%d %d", &x, &y);
		if (x<1 || x>10 || y<1 || y>10){
			printf("输入有误，请重新输入:\n");
			continue;
		}
		if (Player[x][y] != '*'){
			printf("该位置已被排除,请重新输入:\n");
			continue;
		}
		if (Mine[x][y] == '1'){
			if (temes == 80){
				Mine[x][y] = '0';
				Mine[nx][ny] = '1';
			}
			else{
				printf("你被炸死了，Over!\n");
				showboard(Mine, row, col);
				break;
			}
		}
		int count = getcount(Mine, x, y);
		Player[x][y] = count + '0';
		temes--;
	} while (temes > 0);
	if (temes == 0){
		printf("你赢了,Over\n");
	}
}