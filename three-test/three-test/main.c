#include"game.h"

void Meue(){
	printf("#####################\n");
	printf("###欢迎来到三子棋 ###\n");
	printf("###1;play   2:exit###\n");
	printf("#####################\n");
	printf("请输入你的选择\n");
}

int main()
{
	int qute = 0;
	while (!qute){
		Meue();
		int select = 0;
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			game();
			break;
		case 2:
			printf("Bye bye\n");
			qute = 1;
			break;
		default:
			printf("输入有误，请重新输入\n");
			continue;
		}
	}
	system("pause");
	return 0;
}