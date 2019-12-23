#include <cstdio>
 
inline int min(int a, int b){ return a > b ? b : a; }
 
struct ListNode{
Int value;
ListNode *next;
 
ListNode(int v) : value(v), next(NULL){}
};
//free list memory
void deleteList(ListNode* head)
{
if(head == NULL) return;
 
ListNode* p;
    while(head->next != NULL){
        p = head->next;
        head->next = p->next;
        delete p;
    }
    delete head;
}
//merge two lists and figure out the minimum reverse pair
int mergeList(ListNode*& head, ListNode* a, ListNode* b)
{
    if(a == NULL){
        head = b;
        return 0;
    }
    if(b == NULL){
        head = a;
        return 0;
    }
     
    //figure out merged head
    ListNode* p;
    int lena = 1, lenb = 1;
    int revPair = 0, equalPair = a->value == b->value;
    if(a->value > b->value){
        p = b;
        b = b->next;
        ++revPair;
    }
    else{
        p = a;
        a = a->next;
    }
    head = p;
     
    //merge and record equalPair, reversePair, lena and lenb
    for(; a != NULL && b != NULL; p = p->next){
        if(a->value == b->value) ++equalPair;
        if(a->value > b->value){
            p->next = b;
            b = b->next;
            ++revPair;
            ++lenb;
        }
        else{
            p->next = a;
            a = a->next;
            ++lena;
        }
    }
    p->next = a != NULL ? a : b; 
     
    return min(revPair, lena * lenb - equalPair - revPair);
}
//dp at the same time with input
int getMinRevPair(ListNode*& head)
{
    int num;
    scanf("%d", &num);
    if(num != 0){
        head = new ListNode(num);
        return 0;
    }
     
    ListNode *leftList, *rightList;
    int minRevPair = 0;
     
    minRevPair += getMinRevPair(leftList);
    minRevPair += getMinRevPair(rightList);
    minRevPair += mergeList(head, leftList, rightList);
     
    return minRevPair;
}
 
int main()
{
    int n;
    ListNode* head;
     
    scanf("%d", &n);
    n = getMinRevPair(head);
    printf("%d", n);
    deleteList(head);
 
    return 0;
}

