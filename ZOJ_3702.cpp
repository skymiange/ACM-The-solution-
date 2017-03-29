/**********************************************************
 * Author        : skymiange
 * Email         : wbx747635916@gmail.com
 * Last modified : 2017-03-29 20:38
 * Filename      : ZOJ_3702.cpp
 * Description   : 
 * *******************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    ll f[33];
    //g[i]=g[0]*f[i-2]+g[1]*f[i-1];
    f[0]=1;
    f[1]=1;
    for(int i=2;i<22;i++){
        f[i]=f[i-2]+f[i-1];
    }

    while(n--){
        ll i,gi,j;
        cin>>i>>gi>>j;
        if(i==1){
            if(j==1){
                cout<<gi<<endl;
            } 
            else{
                cout<<f[j-2]+gi*f[j-1]<<endl;
            }
        }
        else{
            ll ans;
            ans=gi-f[i-2];
            ll p=ans%f[i-1];
            if(p!=0||ans<=0){
                cout<<-1<<endl;
                continue;
            }
            else{
                ll xi=ans/f[i-1];
                if(j==1){
                    cout<<xi<<endl;
                }
                else{
                    cout<<f[j-2]+f[j-1]*xi<<endl;
                }
            }
        }
    }
    return 0;
}
