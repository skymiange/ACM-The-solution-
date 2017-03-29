#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const int N=1e5+100;
int dp[N][20];
int mm[N];
int n;
map<int,LL>mp;
void initrmq()
{
    mm[0]=-1;
    for(int i=1; i<=n; i++)
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(int j=1; j<=mm[n]; j++)
        for(int i=1; i+(1<<j)-1<=n; i++)
            dp[i][j]=__gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq(int x,int y)
{
    int k=mm[y-x+1];
    return __gcd(dp[x][k],dp[y-(1<<k)+1][k]);
}
int main()
{
    int t;
    scanf("%d",&t);
    int Case=0;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)scanf("%d",&dp[i][0]);
        initrmq();
        mp.clear();
        for(int i=1; i<=n; i++)
        {
            int l=i;
            int r=n;
            int v,tmp,mid;
            while(1)
            {
                v=rmq(i,l);
                tmp=l;
                while(l<=r)
                {
                    mid=(l+r)>>1;
                    if(rmq(i,mid)<v)
                        r=mid-1;
                    else
                        l=mid+1;
                }
                mp[v]+=1LL*(r-tmp+1);
                r=n;
                if(l>r)
                    break;
            }
        }
        int a,b;
        int m;
        printf("Case #%d:\n",++Case);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            int vv=rmq(a,b);
            printf("%d %lld\n",vv,mp[vv]);
        }
    }
    return 0;
}
