#include"hanshu.h"

int main(){
	int quit = 1;
	int select = 1;
	int(*p[4])(int x, int y) = { add, sub, mul, dive };//转移表
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
			printf("输入你的操作数:\n");
			scanf("%d %d", &x, &y);
			int result = p[select - 1](x, y);
			printf(" 结果是 ：%d\n", result);
		}
	}
	printf("Bye Bye!");
	system("pause");
	return 0;
}
