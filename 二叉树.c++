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
    printf(begin,i-1,mid+1);  //�������󣬺�������ҡ���ʱiΪ���ڵ㣬�������ض���begin��i-1���档  mid+1����Ϊǰ���������Ϊmid+1,��ʱ��Ϊ����
    printf(i+1,end,mid-begin+i+1);//�������󣬺�������ҡ���ʱiΪ���ڵ㣬�������ض���i+1��end���档 ͬ��
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
