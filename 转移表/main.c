#include"hanshu.h"

int main(){
	int quit = 1;
	int select = 1;
	int(*p[4])(int x, int y) = { add, sub, mul, dive };//ת�Ʊ�
	while (quit){
		Mene();
		scanf("%d", &select);
		if (select == 0){
			quit = 0;
			continue;
		}
		else{
			int x = 0;
			int y = 0;
			printf("������Ĳ�����:\n");
			scanf("%d %d", &x, &y);
			int result = p[select - 1](x, y);
			printf(" ����� ��%d\n", result);
		}
	}
	printf("Bye Bye!");
	system("pause");
	return 0;
}
