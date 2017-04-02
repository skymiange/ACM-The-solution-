/**********************************************************
 * Author        : skymiange
 * Email         : wbx747635916@gmail.com
 * Last modified : 2017-04-02 20:23
 * Filename      : 射击游戏.cpp
 * Description   : 
 * *******************************************************/
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
int n;
int a[6];
double dp[7][7][7][7][7][7];
double  dfs(int *a){
    if(dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]]!=-1)
        return dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]];
    dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]]=0.0;
    for(int i=1;i<=6;i++){
        int num=0;
        double res=0;
        for(int j=0;j<6;j++){
            if(a[j]>=i)
                num++;
        }
        if(!num)
            break;
        for(int j=1;j<=3;j++){
            int x[6];
            for(int ii=0;ii<6;ii++)
                x[ii]=a[ii];
            int ans=0;
            for(int k=0;k<6;k++){
                if(x[k]>=i) {
                    x[k]--;
                    ans++;
                }
                if(ans==j)
                    break;
            }
            res+=1-dfs(x);
        }
        dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]]=max(dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]],res/3.0);
        res=0;
        for(int j=1;j<=3;j++){
            int x[6];
            for(int ii=0;ii<6;ii++)
                x[ii]=a[ii];
            int ans=0;
            for(int k=5;k>=0;k--){
                if(x[k]>=i) {
                    x[k]--;
                    ans++;
                }
                if(ans==j)
                    break;
            }
            res+=1-dfs(x);
        }
        dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]]=max(dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]],res/3.0);
    }
    return  dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]];
}
int main(){
    while(cin>>n,n){
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<7;i++)
            for(int j=0;j<7;j++)
                for(int k=0;k<7;k++)
                    for(int l=0;l<7;l++)
                        for(int p=0;p<7;p++)
                            for(int q=0;q<7;q++)
                                dp[i][j][k][l][p][q]=-1;
        printf("%.6lf\n",dfs(a));
    }
    return 0;
}
