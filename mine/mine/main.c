#include"game.h"

void Meue(){
	printf("##############################\n");
	printf("####   ��ӭ����ɨ����Ϸ   ####\n");
	printf("####   1��Play    2:exit  ####\n");
	printf("##############################\n");
	printf("���������ѡ��;\n");

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
			printf("���������������룺\n");
			break;
		}
	}
	system("pause");
	return 0;
}