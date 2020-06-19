#include <iostream>
#include <cstring>
using namespace std;
int n, k;
char a[10][10]; //��������cstring
int book[10];
int total; //��������
int m;     //�ѷ���������
void DFS(int s);
int main()
{

    while (scanf("%d%d", &n, &k) && n != -1 && k != -1)
    {
        total = 0;
        m = 0;
        memset(book, 0, sizeof(book));

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        DFS(0);

        cout << total;
    }
    system("pause");
    return 0;
}

void DFS(int s)
{
    if (m == k)
    {
        total++;
        return;
    }
    if (s >= n)
    {
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (book[j] == 0 && a[s][j] == '#')
        {

            book[j] = 1;
            m++;
            DFS(s + 1);

            book[j] = 0;
            m--;
        }
        
    }
    DFS(s + 1);
}
