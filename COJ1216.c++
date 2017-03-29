#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
const int Maxn=1e5*32+10;
const int Size=1e5+10;
struct node
{
    int number;
    int bit[2];
} tire[Maxn];
int cnt,ans;
void init()
{
    memset(tire,-1,sizeof(tire));
    cnt=0;
    ans=0;
}
void insert(int x,int num,int u)
{
    bool k;
    for(int i=num; i>=0; i--)
    {
        k=(1<<i)&x;
        if(tire[u].bit[k]==-1)
            tire[u].bit[k]=++cnt;
        u=tire[u].bit[k];
    }
    tire[u].number=x;
}
int query(int x,int num,int u)
{
    bool k;
    for(int i=num; i>=0; i--)
    {
        k=(1<<i)&x;
        if(tire[u].bit[!k]!=-1)
            u=tire[u].bit[!k];
        else
            u=tire[u].bit[k];
    }
    return (x^tire[u].number);
}
int main()
{
    int n;
    while(cin>>n)
    {
        init();
        int a[Size];
        for(int  i=0; i<n; i++)
        {
            cin>>a[i];
            insert(a[i],31,0);
        }
        for(int i=0; i<n; i++)ans=max(ans,query(a[i],31,0));
        cout<<ans<<endl;
    }
    return 0;
}

