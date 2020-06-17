#include<iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int visit[20];
char mp[20][20];
int ans;
int k;
int n; 
int DFS(int x,int y)
{
    if(y==k)
    {
        ans++;
        return 0;
    }
    for(int i=x;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visit[j]&&mp[i][j]=='#')
            {
                visit[j]=true;
                DFS(i+1,y+1);
                visit[j]=false;
            }
        }
    }
    return 0;
}
int main()
{
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1)
            break;
        memset(visit,false,sizeof(visit));
        memset(mp,false,sizeof(mp));
        for(int i=0;i<n;i++)
            cin>>mp[i];
        ans=0;
        DFS(0,0);
        cout<<ans<<endl;
    }
    return 0;
}