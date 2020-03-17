#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<windows.h>

//单向不带头非循环链表

typedef struct node
{
	int date;
	struct node* next;
}node;

typedef struct slist
{
	node * head;
}slist;
//初始化
void slistinit(slist* sl){
	sl->head = NULL;
}

//创建节点
node* creatnode(int date){
	node * nod = (node *)malloc(sizeof(node));
	nod->date = date;
	nod->next = NULL;
	return nod;
}
//打印
void printslist(slist *sl){
	node * s = sl->head;
	while (s){
		printf("%d ", s->date);
		s = s->next;
	}
	printf("\n");
}
//头插
void slistpushfront(slist* sl,int data){

	node* nod = creatnode(data);
	if (sl->head == NULL){//判断是否为空
		sl->head = nod;
	}
	else{
		nod->next = sl->head;
		sl->head = nod;
	}
}
//尾插
void slistpushback(slist *sl,int data){
	node* nod = creatnode(data);
	if (sl->head == NULL){//判断是否为空
		sl->head = nod;
	}
	else{
		node * s = sl->head;
		while (s->next){
			s = s->next;
		}
		s->next = nod;
	}
}
//头删
void slistpopfront(slist* sl)
{
	if (sl->head == NULL){
		return;
	}
	node * s = sl->head;
	sl->head = sl->head->next;
	free(s);
}

//尾删
void slistpopback(slist *sl){
	if (sl->head == NULL){
		return;
	}
	if (sl->head->next == NULL){
		free(sl->head);
		sl->head = NULL;
	}
	else{
		node *prev = NULL;
		node *nod = sl->head;
		while (nod->next){
			prev = nod;
			nod = nod->next;
		}
		prev->next = NULL;
		free(nod);

	}
}
//任意位置(节点后插入，时间复杂度为O(1))
void slistinsert(node* nod, int date){
	if (nod != NULL){
		node* next = nod->next;
		node* newnode = creatnode(date);
		nod->next = newnode;
		newnode->next = next;
	}
}

//任意位置（节点后删除）
void slisterase(node *nod){
	if (nod != NULL){
		if (nod->next != NULL){
			node*next = nod->next;
			nod->next = next->next;
			free(next);
		}
	}
}
//查找
node* slistfind(slist *sl, int date){
	node *cur = sl->head;
	while (cur){{
		if (cur->date == date)
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//销毁单链表
void slistfree(slist*sl){
	if (sl->head){
		node*cur = sl->head;
		while (cur){
			node *next = cur->next;
			free(cur);
			cur = next;
		}
		sl->head = NULL;//链表置空
	}
}
void test(){
	slist sl;
	slistinit(&sl);
	slistpushfront(&sl, 1);
	slistpushfront(&sl, 2);
	slistpushfront(&sl, 3);
	slistpushfront(&sl, 4);
	slistpushfront(&sl, 5);
	slistpopfront(&sl);
	slistpushback(&sl, 0);
	slistpopback(&sl);
	printslist(&sl);

}
int main(){
	test();
	system("pause");
	return 0;
}