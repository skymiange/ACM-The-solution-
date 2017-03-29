#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int a[1005];
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int ans=0;
        for(int i=1; i<=n-2; i++) {
            if(i==1 || i>1 &&a[i]!=a[i-1]) {
                int sum=-a[i];
                int le=i+1;
                int ri=n;
                while(le<ri) {
                    if(a[le]+a[ri]==sum) {
                        ans++;
                        while(a[le]==a[le+1] &&le<ri) le++;
                        while(a[ri]==a[ri-1] &&le<ri)ri--;
                        le++;
                        ri--;
                    } else if(a[le]+a[ri]<sum)
                        le++;
                    else
                        ri--;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
