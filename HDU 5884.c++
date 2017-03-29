#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define inf (-((LL)1<<40))
#define lson k<<1, L, (L + R)>>1
#define rson k<<1|1,  ((L + R)>>1) + 1, R
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
#define FIN freopen("in.txt", "r", stdin)
#define FOUT freopen("out.txt", "w", stdout)
#define rep(i, a, b) for(int i = a; i <= b; i ++)
#define dec(i, a, b) for(int i = a; i >= b; i --)
typedef long long ll;
ll a[100005];
int n,m;
int work(int x)
{
    queue<ll>q,d;
    int yy=(n-1)%(x-1);
    if(yy!=0)
    {
        for(int i=0; i<x-1-yy; i++)
            q.push(0);
    }
    for(int i=1; i<=n; i++)
        q.push(a[i]);
    ll ans=0;
    while(!q.empty()|| !d.empty())
    {
        ll sum=0;
        for(int i=0; i<x; i++)
        {
            if(q.empty() &&d.empty())
                break;
            if(q.empty())
            {
                sum+=d.front();
                d.pop();
            }
            else if(d.empty())
            {
                sum+=q.front();
                q.pop();
            }
            else
            {
                int u=q.front();
                int v=d.front();
                if(u<v)
                {
                    sum+=u;
                    q.pop();
                }
                else
                {
                    sum+=v;
                    d.pop();
                }
            }
        }
        ans+=sum;
        if(q.empty()&&d.empty())
            break;
        d.push(sum);
    }
    if(ans>m)
        return 0;
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        int l=2,r=n;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(!work(mid))
                l=mid+1;
            else
                r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}