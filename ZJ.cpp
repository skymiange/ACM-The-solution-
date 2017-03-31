/**********************************************************
 * Author        : skymiange
 * Email         : wbx747635916@gmail.com
 * Last modified : 2017-03-31 16:00
 * Filename      : ZJ.cpp
 * Description   : 
 * *******************************************************/
#include <bits/stdc++.h>
using namespace std;
const double eps=1e-9;
struct node{
    double x,y,left;
}f[5005];
int cmp(node a,node b){
    if(a.x!=b.x){
        return a.x<b.x;
    }
    else{
        return a.y<b.y;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>f[i].x>>f[i].y;            
        }
        sort(f+1,f+1+n,cmp);
        node q[5005];
        int len=0;
        for(int i=1;i<n;i++){
            if(f[i].x==f[i+1].x)
                continue;
            q[++len]=f[i];
        }
        q[++len]=f[n];
        stack<node>que;
        while(!que.empty()){
            que.pop();
        }
        q[1].left=-999999999;
        que.push(q[1]);
        int cnt=2;
        while(!que.empty()){
            node op=que.top();
            if(cnt>len)
                break;
            double line=(q[cnt].y-op.y)/(op.x-q[cnt].x);
            if(op.left+eps>=line){
                que.pop();
                continue;
            }
            else{
                q[cnt].left=line;
                que.push(q[cnt]);
                cnt++;
            }
        }
        cout<<que.size()<<endl;
    }
    return 0;
}
