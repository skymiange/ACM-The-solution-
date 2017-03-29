#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include <cmath>
using namespace std;
#define maxn 100007
int tree1[maxn];
int tree2[maxn];
int lowbit(int i)
{
    return i&(-i);
}
void add1(int i,int ans)
{
    while(i<maxn)
    {
        tree1[i]=max(tree1[i],ans);
        i+=lowbit(i);
    }
}
void add2(int i,int ans)
{
    while(i<maxn)
    {
        tree2[i]=min(tree2[i],ans);
        i+=lowbit(i);
    }
}
int add3(int i)
{
    int res=1000000007;
    while(i>0)
    {
        res=min(tree2[i],res);
        i-=lowbit(i);
    }
    return res;
}
int add4(int i)
{
    int res=0;
    while(i>0)
    {
        res=max(tree1[i],res);
        i-=lowbit(i);
    }
    return res;
}
int main()
{
    int t,k,n;
    cin>>t;
    int a[maxn];
    while(t--)
    {
        cin>>n>>k;
        memset(tree1,0,sizeof(tree1));
        memset(tree2,0x7f7f7f,sizeof(tree2));
        for(int j=1; j<=n; j++)
            cin>>a[j];
        long long ans=0;
        for(int j=n; j>=1; j--)
        {
            add1(j,a[j]);
            add2(j,a[j]);
            int low=j;
            int high=n;
            while(low<=high)
            {
                int mid=(low+high)/2;
                int max1=add4(mid);
                int min1=add3(mid);
                if(max1-min1<k)
                    low=mid+1;
                else
                    high=mid-1;
            }
            ans+=low-j;
        }
        cout<<ans<<endl;
    }
    return 0;
}


