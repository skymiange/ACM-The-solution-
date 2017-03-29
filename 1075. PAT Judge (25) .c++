#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;
const int COMPARE=-2;
struct  node {
    int personRank;
    int personNumberId;
    int personTotalScore;
    int getScore[6];
    int titlePerfectSubmit;
    int personIsOutput;
    int titleIsSubmitFlag[6];
} f[N];
bool cmp(node a,node b) {
    if(a.personTotalScore!=b.personTotalScore)
        return a.personTotalScore>b.personTotalScore;
    else {
        if(a.titlePerfectSubmit!=b.titlePerfectSubmit)
            return a.titlePerfectSubmit>b.titlePerfectSubmit;
        else {
            return a.personNumberId<b.personNumberId;
        }
    }
}
int main() {
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)) {
        int everySubjectScore[6];
        for(int i=1; i<=m; i++)
            scanf("%d",&everySubjectScore[i]);
        memset(f,0,sizeof(f));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                f[i].getScore[j]=-1;
        for(int i=1; i<=k; i++) {
            int getScore;
            int personId;
            int titleId;
            scanf("%d%d%d",&personId,&titleId,&getScore);
            if(getScore!=-1)
                f[personId].getScore[titleId]=max(getScore,f[personId].getScore[titleId]);
            f[personId].titleIsSubmitFlag[titleId]=1;
        }
        for(int i=1; i<=n; i++) {
            f[i].personNumberId=i;
            for(int j=1; j<=m; j++) {
                if(f[i].getScore[j]>=0 &&f[i].titleIsSubmitFlag[j]==1) {
                    {
                        f[i].personTotalScore+=f[i].getScore[j];
                        f[i].personIsOutput=1;
                        if(f[i].getScore[j]==everySubjectScore[j])
                            f[i].titlePerfectSubmit++;
                    }
                }
            }
        }
        sort(f+1,f+1+n,cmp);
        int personRank=0;
        f[0].personTotalScore=COMPARE;
        for(int i=1; i<=n; i++) {
            if(f[i].personIsOutput==0 ) {
                continue;
            }
            if(f[i].personTotalScore!=f[i-1].personTotalScore) {
                f[i].personRank=i;
                printf("%d %05d %d",f[i].personRank,f[i].personNumberId,f[i].personTotalScore);
                personRank=i;
            } else if(f[i].personTotalScore==f[i-1].personTotalScore) {
                f[i].personRank=personRank;
                printf("%d %05d %d",f[i].personRank,f[i].personNumberId,f[i].personTotalScore);
            }
            for(int j=1; j<=m; j++) {
                if(f[i].getScore[j]>=0) {
                    printf(" %d",f[i].getScore[j]);
                } else if(f[i].titleIsSubmitFlag[j]!=1)
                    printf(" -");
                else
                    printf(" 0");
            }
            printf("\n");
        }
    }
    return 0;
}
