#include"game.h"

void Meue(){
	printf("##############################\n");
	printf("####   欢迎来到扫雷游戏   ####\n");
	printf("####   1：Play    2:exit  ####\n");
	printf("##############################\n");
	printf("请输入你的选择;\n");

}
int main()
{
	
	int select = 0;
	int quit = 0;
	while (!quit){
		Meue();
		scanf("%d", &select);
		switch (select){
		case 1:
			game();
			break;
		case 2:
			quit = 1;
			printf("Bye bye!\n");
			break;
		default:
			printf("输入有误，重新输入：\n");
			break;
		}
	}
	system("pause");
	return 0;
}