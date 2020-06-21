#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long 
const ll mxn = 200005;
const ll INF = 0x3f3f3f3f;
ll ar[mxn];
ll n,m;

bool Judge(ll mid)
{
    ll cnt = 0;
    ll sum = 0;
    for(ll i = 1; i <= n; i ++)
    {
        sum += ar[i];
        if(sum == mid)
        {
            sum = 0;
            cnt ++;
        }
        else if(sum > mid)
        {
            sum = ar[i];
            cnt ++;
        }
    }

    if(sum)
        cnt ++;
    return cnt > m;	
}

int main()
{
    while(scanf("%lld %lld", &n, &m)!= EOF)
    {
        ll l = 0;
        ll r = 0;
        for(ll i = 1; i <= n; i ++)
        {
            scanf("%lld", &ar[i]); 
            l = max(l, ar[i]);
            r += ar[i];
        }
        ll ans = l; 
        while(l <= r) 
        {
            ll mid = (l + r) >> 1;
            if(Judge(mid))
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}


