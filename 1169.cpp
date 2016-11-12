#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

int f[51][51][51][51],n,a[51][51],m;
int main(){
    scanf("%d%d",&n,&m);
    int i,j,k,l;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            for (k=1;k<=n;k++)
                for (l=j+1;l<=m;l++) f[i][j][k][l]=max(max(f[i][j-1][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k][l-1],f[i-1][j][k-1][l]))+a[i][j]+a[k][l];
    printf("%d\n",f[n][m-1][n-1][m]);
    return 0;
}
