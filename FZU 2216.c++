#include<cstdio>
#include<cstring>
#include<algorithm>
#include <iostream>
using namespace std;
const int MAXN=100005;
int a[MAXN],vis[MAXN],dp[MAXN];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        memset(a,0,sizeof(a));
        int n,m;
        int joke=0;
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            if(a[i])
                vis[a[i]]=1;
            else      //0充当任何数，可以放在任何的区间
                joke++;
        }
        for(int i=1; i<=m; i++) {
            if(vis[i])
                dp[i]=dp[i-1];
            else
                dp[i]=dp[i-1]+1;   //没有的话，则需要的joke+1
        }
//        for(int i=0;i<=m;i++)
//        {
//            cout<<dp[i]<<endl;
//        }
        int res=0;
        for(int i=0; i<=m; i++) {  //枚举左区间，二分右边
            int l=i,r=m,mid;
            while(l<=r) {
                mid=(l+r)/2;
                if(dp[mid]-dp[i]>joke)
                    r=mid-1;
                else
                    l=mid+1;
            }
            res=max(res,r-i);
        }
        printf("%d\n",res);
    }
}