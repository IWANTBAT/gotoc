#include"hanshu.h"

int add(int x, int y){
	return x + y;
}
int sub(int x, int y){
	return x - y;
}
int mul(int x, int y){
	return x*y;
}
int dive(int x, int y){
	if (y == 0){
		printf("ÊäÈëÓÐÎó\n");
		return -1;
	}
	else{
		return x / y;
	}
}
void Mene(){
	printf("###################################\n");
	printf("###1:add                   2:sub###\n");
	printf("###3:mul                  4:dive###\n");
	printf("###0:quit                      ####\n");
	printf("###################################\n");
	printf("Enter your number ->");

}