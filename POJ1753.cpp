/**********************************************************
 * Author        : skymiange
 * Email         : wbx747635916@gmail.com
 * Last modified : 2017-03-29 22:37
 * Filename      : POJ1753.cpp
 * Description   : 
 * *******************************************************/


#include <iostream>
using namespace std;
int a[20][20];
int ans;
bool panduan(){
    int x=a[0][0];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(x!=a[i][j])
                return false;
        }
    }
    return true;
}
void fan(int x,int y){
    if(x-1>=0)
        a[x-1][y]=!a[x-1][y];
    if(y-1>=0)
        a[x][y-1]=!a[x][y-1];
    if(x+1<4)
        a[x+1][y]=!a[x+1][y];
    if(y+1<4)
        a[x][y+1]=!a[x][y+1];
    a[x][y]=!a[x][y];
}
void dfs(int x,int y,int t){
    if ( panduan())
    {
        if (ans > t)
            ans = t ;
        return;
    }
    if (x >= 4 || y >= 4)
        return;
    int nx,ny;
    nx = (x + 1)%4;
    ny = y + ( x + 1 ) / 4;

    dfs (nx,ny,t);
    fan (x,y);

    dfs (nx,ny,t+1);
    fan (x,y);

}
int main(){
    char s[20][20];
    for(int i=0;i<4;i++){
        cin>>s[i];
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(s[i][j]=='b')
                a[i][j]=0;
            else
                a[i][j]=1;
        }
    }
    ans=0x7f7f7f;
    dfs(0,0,0);
    if(ans!=0x7f7f7f){
        cout<<ans<<endl;
    }
    else{
        cout<<"Impossible"<<endl;
    }
}
