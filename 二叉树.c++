#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1005];
int b[1005];
void printf(int begin,int end,int mid)
{
    int i;
    if(begin>end)
        return;
    for(i=begin; i<=end; i++)
        if(b[i]==a[mid])
            break;
    printf(begin,i-1,mid+1);  //中序，先左，后跟，再右。此时i为跟节点，左子树必定在begin到i-1里面。  mid+1是因为前序的左子树为mid+1,此时作为根，
    printf(i+1,end,mid-begin+i+1);//中序，先左，后跟，再右。此时i为跟节点，右子树必定在i+1到end里面。 同理
    cout<<a[mid];
    if(mid==1)
        cout<<endl;
    else
        cout<<" ";
}
int main()
{
    int n;
    while(cin>>n)
    {
        int i;
        for(i=1; i<=n; i++)
            cin>>a[i];
        for(i=1; i<=n; i++)
            cin>>b[i];
        printf(1,n,1);
    }
    return 0;
}
