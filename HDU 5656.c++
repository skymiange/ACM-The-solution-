#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;
typedef  long long LL;
int f[1001][1001];
int dp[1001][1001];
int a[1001];
const int mod=100000007;
inline void add(int b,int &a)
{
    if((a+=b)>=mod)a-=mod;
}
int main()
{
    int t;
    int i,j;
    for(i=0; i<=1000; i++)
        for(j=0; j<=1000; j++)
            f[i][j]=__gcd(i,j);
    scanf("%d",&t);
    while(t--)
    {
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        for(i=1; i<=n; i++)
            cin>>a[i];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(i=0; i<n; i++)
            for(j=0; j<=1000; j++)
            {
                if(dp[i][j])
                    add(dp[i][j],dp[i+1][j]);
                add(dp[i][j],dp[i+1][f[j][a[i+1]]]);
            }
        LL ans=0;
        for(i=1; i<=1000; i++)
            ans+=LL (i)*dp[n][i];
        printf("%lld\n",ans%mod);
    }
    return 0;
}
