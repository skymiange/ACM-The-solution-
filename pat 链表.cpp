#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    int next;
    int jie;
} f[1000005],f1[1000005],f2[1000005];
int main() {
    int adr,n;
    cin>>adr>>n;
    for(int i=0; i<n; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        f[a].data=b;
        f[a].next=c;
    }
    int len=0;
    for(int i=adr; i!=-1; i=f[i].next) {
        //printf("%05d %d %05d\n",i,f[i].data,f[i].next);
        f1[len].jie=i;
        f1[len].data=f[i].data;
        f1[len++].next=f[i].next;
    }
    int len1=0;
    if(len%2==0)
        for(int i=len-1,j=0; i>=(len+1)/2; i--,j++) {
            //  printf("%05d %d %05d\n",f1[i].jie,f1[i].data,f1[i].next);
            if(i!=j) {
                f2[len1].jie=f1[i].jie;
                f2[len1].data=f1[i].data;
                f2[len1++].next=f1[i].next;
                f2[len1].jie=f1[j].jie;
                f2[len1].data=f1[j].data;
                f2[len1++].next=f1[j].next;
            } else {
                f2[len1].jie=f1[i].jie;
                f2[len1].data=f1[i].data;
                f2[len1++].next=f1[i].next;
            }

        }
    else {
        for(int i=len-1,j=0; ; i--,j++) {
            //  printf("%05d %d %05d\n",f1[i].jie,f1[i].data,f1[i].next);
            if(i!=j) {
                f2[len1].jie=f1[i].jie;
                f2[len1].data=f1[i].data;
                f2[len1++].next=f1[i].next;
                f2[len1].jie=f1[j].jie;
                f2[len1].data=f1[j].data;
                f2[len1++].next=f1[j].next;
            } else {
                f2[len1].jie=f1[i].jie;
                f2[len1].data=f1[i].data;
                f2[len1++].next=f1[i].next;
            }
            if(i==j)
                break;
        }
    }
    for(int i=0; i<len1-1; i++) {
        printf("%05d %d %05d\n",f2[i].jie,f2[i].data,f2[i+1].jie);
    }
    printf("%05d %d %d\n",f2[len1-1].jie,f2[len1-1].data,-1);
}

