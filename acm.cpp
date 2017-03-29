/**********************************************************
 * Author        : skymiange
 * Email         : wbx747635916@gmail.com
 * Last modified : 2017-03-29 15:12
 * Filename      : lalala.cpp
 * Description   : 
 * *******************************************************/
#include <bits/stdc++.h>
using namespace std;
struct node {
    int x,y;
    int id;
    int hurt;
    bool friend operator<(node a,node b) {
        {
            if(a.hurt!=b.hurt)
                return a.hurt>b.hurt;
            else
                return a.id>b.id;
        }
    }
};
int dir[4][2]= {-1,0,1,0,0,-1,0,1};
int a[505][505];
int v[505][505];
int vis[500005];
int main() {
    int n,m;
    while(cin>>n>>m) {
        node st;
        int num=0;
        memset(vis,0,sizeof(vis));
        memset(v,0,sizeof(v));
        int ans=0;
        priority_queue<node>q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>a[i][j];
                if(a[i][j]>0) {
                    st.x=i;
                    ans++;
                    st.y=j;
                    st.hurt=1;
                    st.id=a[i][j];
                    q.push(st);
                    v[i][j]=1;
                    continue;
                }
                v[i][j]=-1;
            }
        }
        node ss;
        while(!q.empty()) {
            node ed=q.top();
            q.pop();
            int tt=-99999999;
            for(int i=0; i<4; i++) {
                ss.x=ed.x+dir[i][0];
                ss.y=ed.y+dir[i][1];
                if(ss.x>=0&&ss.x<n &&ss.y>=0 &&ss.y<m &&v[ss.x][ss.y]==-1 &&abs(a[ss.x][ss.y])<=ed.hurt) {
                    ss.id=ed.id;
                    ss.hurt=ed.hurt;
                    v[ss.x][ss.y]=1;
                    vis[ed.id]++;
                    num++;
                    q.push(ss);
                } else {
                    if(tt<a[ss.x][ss.y]&&ss.x>=0&&ss.x<n &&ss.y>=0 &&ss.y<m&&v[ss.x][ss.y]==-1 )
                        tt=a[ss.x][ss.y];
                }
            }
            if(tt!=-99999999){
                ed.hurt=tt*-1;
                q.push(ed);
            }
            if(num>=n*m-ans)
                break;
        }
        int k;
        cin>>k;
        while(k--) {
            int num1;
            cin>>num1;
            cout<<vis[num1]+1<<endl;
        }

    }
    return 0;
}
