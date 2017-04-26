#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string str;
string ss;
string sss;
int max1;
string ans;
int vis[10];
int l;
void change() {
    if(ss==str)
        return;
    int l1=ss.size();
    if(l1==1) {
        if(l1>max1) {
            max1=1;
            ans=ss;
        }
    } else {
        int x;
        int flag=0;
        for(int i=0; i<l1; i++)
            if(ss[i]!='0') {
                flag=1;
                x=i;
                break;
            }
        if(flag) {
            ss="";
            for(int i=x; i<l1; i++)
                ss+=sss[i];
            l1=ss.size();
        }
        if(l1>max1) {
            max1=l1;
            ans=ss;
        }
    }
}
void work(int m,int k,int kk,int kkk,int kkkk,int kkkkk,int kkkkkk) {
    int op=k*1+kk*2+kkk*7+kkkk*4+kkkkk*5+kkkkkk*8;
    if(vis[1]>=k&&vis[2]>=kk&&vis[7]>=kkk&&vis[4]>=kkkk&&vis[5]>=kkkkk&&vis[8]>=kkkkkk&&(op%3==m)) {
        int qq=0;
        int qqq=0;
        int qqqq=0;
        int qqqqq=0;
        int qqqqqq=0;
        int qqqqqqq=0;
        ss=sss="";
        for(int i=0; i<l; i++) {
            if(str[i]=='1'&&qq<k) {
                qq++;
                continue;
            }
            if(str[i]=='2'&&qqq<kk) {
                qqq++;
                continue;
            }
            if(str[i]=='7'&&qqqq<kkk) {
                qqqq++;
                continue;
            }
            if(str[i]=='4'&&qqqqq<kkkk) {
                qqqqq++;
                continue;
            }
            if(str[i]=='5'&&qqqqqq<kkkkk) {
                qqqqqq++;
                continue;
            }
            if(str[i]=='8'&&qqqqqqq<kkkkkk) {
                qqqqqqq++;
                continue;
            }
            ss+=str[i];
            sss+=str[i];
        }
        change();
        string a;
        ss=sss="";
        qq=qqq=qqqq=qqqqq=qqqqqq=qqqqqqq=0;
        for(int i=l-1; i>=0; i--) {
            if(str[i]=='1'&&qq<k) {
                qq++;
                continue;
            }
            if(str[i]=='2'&&qqq<kk) {
                qqq++;
                continue;
            }
            if(str[i]=='7'&&qqqq<kkk) {
                qqqq++;
                continue;
            }
            if(str[i]=='4'&&qqqqq<kkkk) {
                qqqqq++;
                continue;
            }
            if(str[i]=='5'&&qqqqqq<kkkkk) {
                qqqqqq++;
                continue;
            }
            if(str[i]=='8'&&qqqqqqq<kkkkkk) {
                qqqqqqq++;
                continue;
            }
            a+=str[i];
        }
        int op=a.size();
        for(int i=op-1; i>=0; i--) {
            ss+=a[i];
            sss+=a[i];
        }
        change();
    }
}
int main() {
    while(cin>>str) {
        l=str.size();
        int sum=0;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<l; i++) {
            sum+=str[i]-'0';
            vis[str[i]-'0']++;
        }
        if(sum%3==0) {
            string qqqq="";
            int qer=-1;
            int ans1=0;
            for(int i=0; i<l; i++)
                if(str[i]!='0') {
                    qer=i;
                    break;
                } else {
                    ans1++;
                }
            if(ans1==l) {
                cout<<0<<endl;
                continue;
            }
            for(int i=qer; i<l; i++)
                qqqq+=str[i];
            cout<<qqqq<<endl;
        } else {
            max1=-9999999;
            ans="";
            if(l==1) {
                cout<<-1<<endl;
            } else {
                if(sum%3==1) {  //1 4 7    22  16  25 115 112 2221 1111 1114 11122 111112 1111111
                    for(int k=0; k<=1; k++)  //1
                        for(int kk=0; kk<=2; kk++) //2
                            for(int kkk=0; kkk<=1; kkk++) //7
                                for(int kkkk=0; kkkk<=1; kkkk++)  //4
                                    for(int kkkkk=0; kkkkk<=2; kkkkk++)  //5
                                        for(int kkkkkk=0; kkkkkk<=2; kkkkkk++) { //8
                                            work(1,k,kk,kkk,kkkk,kkkkk,kkkkkk);
                                        }
                } else if(sum%3==2) {   // 2 5 8   11
                    for(int k=0; k<=2; k++)  //1
                        for(int kk=0; kk<=1; kk++) //2
                            for(int kkk=0; kkk<=2; kkk++) //7
                                for(int kkkk=0; kkkk<=2; kkkk++)  //4
                                    for(int kkkkk=0; kkkkk<=1; kkkkk++)  //5
                                        for(int kkkkkk=0; kkkkkk<=1; kkkkkk++) { //8
                                            work(2,k,kk,kkk,kkkk,kkkkk,kkkkkk);
                                        }
                }
                int op1=ans.size();
                int res=0;
                for(int i=0; i<op1; i++)
                    if(ans[i]>='0'&&ans[i]<='9')
                        res+=ans[i]-'0';
                if(res%3==0&&ans!="") {
                    if(res==0)
                        cout<<0<<endl;
                    else
                        cout<<ans<<endl;
                } else
                    cout<<-1<<endl;
            }
        }
    }
    return 0;
}

