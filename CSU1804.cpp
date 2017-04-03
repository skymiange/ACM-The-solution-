/**********************************************************
 * Author        : skymiange
 * Email         : wbx747635916@gmail.com
 * Last modified : 2017-04-03 19:11
 * Filename      : CSU1804.cpp
 * Description   : 
 * *******************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+5;
int n,m,vis[maxn];
ll a[maxn],b[maxn],c;
int in[maxn];
vector<int> G[maxn];
int main() {
    while(~scanf("%d%d",&n,&m)) {
        for(int i=0; i<=n; i++)
            G[i].clear();
        for(int i=1; i<=n; i++)
            scanf("%lld%lld",&a[i],&b[i]);
        memset(in,0,sizeof(in));
        for(int i=1; i<=m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            in[b]++;
        }
        queue<int>q;
        for(int i=1; i<=n; i++)
            if(in[i]==0)
                q.push(i);
        ll ans=0;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            for(int i=0; i<G[u].size(); i++) {
                int v=G[u][i];
                in[v]--;
                ans+=(a[u]*b[v])%mod;
                a[v]+=a[u];
                a[v]%=mod;
                ans%=mod;
                if(in[v]==0)
                    q.push(v);
            }
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}
