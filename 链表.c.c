#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<windows.h>

//���򲻴�ͷ��ѭ������

typedef struct node
{
	int date;
	struct node* next;
}node;

typedef struct slist
{
	node * head;
}slist;
//��ʼ��
void slistinit(slist* sl){
	sl->head = NULL;
}

//�����ڵ�
node* creatnode(int date){
	node * nod = (node *)malloc(sizeof(node));
	nod->date = date;
	nod->next = NULL;
	return nod;
}
//��ӡ
void printslist(slist *sl){
	node * s = sl->head;
	while (s){
		printf("%d ", s->date);
		s = s->next;
	}
	printf("\n");
}
//ͷ��
void slistpushfront(slist* sl,int data){

	node* nod = creatnode(data);
	if (sl->head == NULL){//�ж��Ƿ�Ϊ��
		sl->head = nod;
	}
	else{
		nod->next = sl->head;
		sl->head = nod;
	}
}
//β��
void slistpushback(slist *sl,int data){
	node* nod = creatnode(data);
	if (sl->head == NULL){//�ж��Ƿ�Ϊ��
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
//ͷɾ
void slistpopfront(slist* sl)
{
	if (sl->head == NULL){
		return;
	}
	node * s = sl->head;
	sl->head = sl->head->next;
	free(s);
}

//βɾ
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
//����λ��(�ڵ����룬ʱ�临�Ӷ�ΪO(1))
void slistinsert(node* nod, int date){
	if (nod != NULL){
		node* next = nod->next;
		node* newnode = creatnode(date);
		nod->next = newnode;
		newnode->next = next;
	}
}

//����λ�ã��ڵ��ɾ����
void slisterase(node *nod){
	if (nod != NULL){
		if (nod->next != NULL){
			node*next = nod->next;
			nod->next = next->next;
			free(next);
		}
	}
}
//����
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
//���ٵ�����
void slistfree(slist*sl){
	if (sl->head){
		node*cur = sl->head;
		while (cur){
			node *next = cur->next;
			free(cur);
			cur = next;
		}
		sl->head = NULL;//�����ÿ�
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