#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[10][10];     //��¼����λ��
int book[10];        //��¼һ���Ƿ��Ѿ��Ź�����
int n,k;
int total,m;    //total �Ƿ����ӵķ����� ��m���ѷ������̵�������Ŀ

void DFS(int cur)
{
    if(k==m)
    {
        total++;
        return ;
    }
    if(cur>=n)    //�߽�
        return ;
    for(int j=0; j<n; j++)
        if(book[j]==0 && a[cur][j]=='#')  //�ж�����
        {
            book[j]=1;           //���
            m++;                 
            DFS(cur+1);
            book[j]=0;           //�Ļ���������һ�е��ж�
            m--;
        }
    DFS(cur+1);                //����һ��
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)&&n!=-1&&k!=-1) //��������
    {
        total=0;
        m=0;
        for(i=0; i<n; i++)
            scanf("%s",&a[i]);
        memset(book,0,sizeof(book));
        DFS(0);
        printf("%d\n",total);
    }
    return 0;
}