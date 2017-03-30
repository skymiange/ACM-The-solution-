#include <bits/stdc++.h>
using namespace std;
char s[260][260];
int main(){
    int t;
scanf("%d",&t);
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>s[i];
        int a[5];
        int sum=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<m;j++){
                memset(a,0,sizeof(a));
                for(int k=0;k<m;k++){
                    if(s[i][k]=='B'&&s[j][k]==s[i][k])
                        a[0]++;
                    if(s[i][k]=='J'&&s[j][k]==s[i][k])
                        a[1]++;
                    if(s[i][k]=='H'&&s[j][k]==s[i][k])
                        a[2]++;
                    if(s[i][k]=='Y'&&s[j][k]==s[i][k])
                        a[3]++;
                    if(s[i][k]=='N'&&s[j][k]==s[i][k])
                        a[4]++;
                }
                for(int i=0;i<5;i++)
                    sum+=(a[i]*(a[i]-1))/2;
            }
        cout<<sum<<endl;
    }
    return 0;
}
