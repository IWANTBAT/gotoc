#include"game.h"

void Meue(){
	printf("#####################\n");
	printf("###��ӭ���������� ###\n");
	printf("###1;play   2:exit###\n");
	printf("#####################\n");
	printf("���������ѡ��\n");
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
			printf("������������������\n");
			continue;
		}
	}
	system("pause");
	return 0;
}