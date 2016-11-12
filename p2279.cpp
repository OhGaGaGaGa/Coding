#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 0x3f3f3f3f
int g[1001][1001],dp[1001][5];
int main(){
    int N,v,m,n;
    cin>>N;
    for(int i=2;i<=N;++i){
        cin>>v;
        g[v][i]=1;
    }
    for(int i=N;i>=1;i--){
        dp[i][0]=1;
        m=n=MAXN;
        for(int v=1;v<=N;v++){
            if(g[i][v]==1){
                dp[i][3]+=dp[v][2];
                dp[i][0]+=dp[v][4];
                dp[i][4]+=dp[v][3];
                m=min(m,dp[v][0]-dp[v][3]);
                n=min(n,dp[v][1]-dp[v][2]);
            }
        }
        dp[i][1]=dp[i][4]+m;
        dp[i][2]=min(min(dp[i][1],dp[i][0]),dp[i][3]+n);
        dp[i][3]=min(dp[i][3],dp[i][2]);
        dp[i][4]=min(dp[i][3],dp[i][4]);
    }
    cout<<dp[1][2]<<endl;
    return 0;
}
