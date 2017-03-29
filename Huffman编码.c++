#include iostream
#include algorithm
#include cstdio
#include queue
#include cmath
#include cstring
using namespace std;
#define lson l,m,rt1
#define rson m+1,r,rt11
int a[50005];
struct cmp
{
    bool operator ()(const int &i,const int &j)
    {
        return ij;
    }
};
int main()
{
    int n;
    priority_queueint,vectorint,cmpq;
    while(scanf(%d,&n)!=EOF)
    {
        int i;
        int ans=0;
        for(i=0; in; i++)
        {
            cina[i];
            q.push(a[i]);
        }
        while(n=2)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            q.push(a+b);
            ans+=a+b;
            n--;
        }
        coutansendl;
    }
    return 0;
}
