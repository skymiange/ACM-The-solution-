#include <bits/stdc++.h>
using namespace std;
vector<int>g[10005];
map<int,map<int,int> >mp; //记录一条路线的编号 二维map不会爆内存
int min1,min2;//路线最少,换乘最少.
int vis[10005]; //回溯标记
int pre[10005];  //记录前驱
stack<int>q;   //将长度最小的路径压入
int road[10005];  // 最后的路径
int road1[10005];  //相同站数不同换乘的数组.
int flag;  //是否可以到达
int len;  //路径的长度
int check(int road[]) {
    int x=mp[road[0]][road[1]];
    int cnt=1;
    for(int i=0; i<len; i++) {
        if(mp[road[i]][road[i+1]]!=x&&i+1<len) {
            x=mp[road[i]][road[i+1]];
            cnt++;
        }
    }
    return cnt;
}
void dfs(int st,int ed,int cnt) {
    if(((st==ed &&cnt<min1 )||(st==ed&&cnt==min1))) {
        flag=1;
        min1=cnt;
        q.push(ed);
        while(pre[ed]!=-1) {
            q.push(pre[ed]);
            ed=pre[ed];
        }
        if(q.size()<len) {
            len=0;
            while(!q.empty()) {
                road[len++]=q.top();
                q.pop();
            }
        } else if(q.size()==len) {
            int len1=0;
            while(!q.empty()) {
                road1[len1++]=q.top();
                q.pop();
            }
            if(check(road1)<check(road)) {
                for(int i=0; i<len1; i++)
                    road[i]=road1[i];
            }
        }
        return;
    }
    int sz=g[st].size();
    for(int i=0; i<sz; i++) {
        int v=g[st][i];
        if(!vis[v]) {
            vis[v]=1;
            pre[v]=st;
            dfs(v,ed,cnt+1);
            vis[v]=0;
            pre[v]=-1;
        }
    }
}
int main() {
    int n;
    while(cin>>n) {
        for(int i=0; i<10005; i++)
            g[i].clear();
        mp.clear();
        for(int i=1; i<=n; i++) {
            int m;
            cin>>m;
            int num[105];
            for(int j=0; j<m; j++) {
                cin>>num[j];
            }
            for(int j=0; j<m-1; j++) {
                g[num[j]].push_back(num[j+1]);
                g[num[j+1]].push_back(num[j]);
                mp[num[j]][num[j+1]]=i;
                mp[num[j+1]][num[j]]=i;
            }
        }
        int k;
        cin>>k;
        while(k--) {
            int a,b;
            cin>>a>>b;
            min1=99999;
            min2=99999;
            while(!q.empty())
                q.pop();
            memset(pre,-1,sizeof(pre));
            memset(vis,0,sizeof(vis));
            len=99999999;
            vis[a]=1;
            flag=0;
            dfs(a,b,0);
            if(!flag) {
                cout<<"Sorry, no line is available."<<endl;
                continue;
            }
            cout<<len-1<<endl;
            int x=mp[road[0]][road[1]];
            int st=0;
            for(int i=0; i<len; i++) {
                if(mp[road[i]][road[i+1]]!=x&&i+1<len) {
                    printf("Go by the line of company #%d from %04d to %04d.\n",x,road[st],road[i]);
                    x=mp[road[i]][road[i+1]];
                    st=i;
                }
            }
            printf("Go by the line of company #%d from %04d to %04d.\n",x,road[st],road[len-1]);
        }
    }
    return 0;
}

