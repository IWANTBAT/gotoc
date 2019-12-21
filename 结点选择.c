#include <stdio.h>
#include <string.h>
#define _Max 100010
#define max(a, b) a > b ? a : b

struct point
{
    int v, next;   //vָ�������ߵ���һ����㣨����㣩��nextָ���ӽ��
} edge[_Max * 2];  //һ���߼�¼���Σ��ֱ���һ��������¼

int head[_Max];
int M;
int dp[_Max][2];

//���һ����
void addEdge(int from, int to)
{
    //from���
    edge[M].v = to;
    edge[M].next = head[from];    //Ϊ-1��λҶ��㣬����ָ������һ����
    head[from] = M++;             //ָ������һ���ߣ����ӽ��
    //to���
    edge[M].v = from;
    edge[M].next = head[to];      //Ϊ-1��λҶ��㣬����ָ������һ����
    head[to] = M++;               //ָ������һ���ߣ����ӽ��
    return ;
}

//��ȱ����������뵽Ҷ�ӽ�㣬Ȼ��һ��һ�����ϻ�����һֱ������㣬����һ����㣨��ʼpreΪ��1����Ϊ�����û�и���㣬�ã�1��ʾ��
void dfs(int x, int pre)
{
    int i = head[x], v;
    for (; i != -1; i = edge[i].next)  //i != -1˵�����ӽ�㣬������ӽ�㣬����ΪҶ�ӽ��
    {
        v = edge[i].v;
        if (pre == v)  //���ָ����ӽ��͸�����غϣ���˵����������Ҷ�ӽ�㣬����Ҫ��һ��dp
        {
            continue;
        }
        dfs(v, x);     //x�������Ϊ�����
        //��ȱ������������Ҷ�ӽ��ĸ����   ��������ѡ�����ӽ�㲻ѡ�񣬷����ӽ�����ѡ����߲�ѡ�񣬵���Ҫ�Ƚ������ĸ���ѡ���ĸ�
        dp[x][1] += dp[v][0];                 //   ����㣨ѡ�� ���� �ӽ�㣨��ѡ��
        dp[x][0] += max(dp[v][0], dp[v][1]);   // ����㣨��ѡ������ max���ӽ�㣨��ѡ�����ӽ�㣨ѡ����
    }
    return ;
}
int main(int argc, const char * argv[])
{
    int i, n, s, t, tmp;
    scanf("%d", &n);
    M = 0;
    memset(head, -1, sizeof(head));   //��ʼ��ÿ����㶼�Ƕ�����û���ӽ��
    memset(dp, 0, sizeof(dp));
    //����Ȩֵ�����Ҽ�¼��dp[i][1]�ϣ�i��ʾ��i����㣬1����ȡ��������
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &dp[i][1]);
    }
    //����ߣ��������edge��һ�����������edge
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &s, &t);
        addEdge(s, t);
    }
    dfs(1, -1);   //������ȱ������ӵ�һ����㿪ʼ����
    tmp = max(dp[1][0], dp[1][1]);    //�������Ȩֵ��
    printf("%d\n", tmp);
    return 0;
}

