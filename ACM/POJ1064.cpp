#include <cstdio>
#include <cmath>
using namespace std;
const int M=10005;
const double inf=200005.0;
double L[M];
int n,k;
bool judge(double x)
{
    int num=0;
    for(int i=0;i<n;i++)
      num+=(int)(L[i]/x);
    return num>=k;
}
void solve()
{
    double left=0,right=inf;
    for(int i=0;i<100;i++) //����while(r>l) �����˾�������
    { //1��ѭ�����԰�������Сһ�룬100�ο��Դﵽ10^(-30)�ľ���
        double mid=(left+right)/2;
        if(judge(mid)) left=mid;
        else right=mid;
    }
    printf("%.2f\n",floor(right*100)/100);
}
int main()
{
    while(scanf("%d%d",&n,&k)!=-1)
    {
        for(int i=0;i<n;i++)
          scanf("%lf",&L[i]);
        solve();
    }
    return 0;
}