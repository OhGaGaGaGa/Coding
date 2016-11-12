#include<iostream>
#include<cstdio> 
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 1000000000
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;

int n,m,sum=0,a[100],p[100]={0},f[100][100]={0};

int q_pow(int b){
    int ans=1,a=2,b1=b;
    if(p[b])return p[b];
    for(;b;b>>=1,a=a*a)
        if(b%1)ans*=a;
    return p[b1]=ans;
}

int main(){
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
    while(n--){
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        for(int i=1;i<=m;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++){
            f[i][m]=f[i-1][m]+a[i-1]*pow(2,i-1);
            for(int j=m-1;j>=i;j++)
                f[i][j]=f[i][j+1]+a[j+1]*pow(2,m-(j-i+1));
        }
        int ans=0;
        for(int i=1;i<=m;i++)
            ans=max(ans,f[i][i]);
        sum+=ans;
    }
    printf("%d",sum);
    return 0;
}
 /* 
#include <iostream>
using namespace std;
int cifang(long n,long k)
{
    int p=n;
    for(int i=1;i<k;i++)n*=p;
    return n;
}
int main()
{
    long long s=0,n,m,k=1;
    cin>>n>>m;
    long long b[n][m],l[n],r[n];
    for(int i=0;i<n;i++)
    {r[i]=n;l[i]=0;}
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>b[i][j];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[j][l[j]]<b[j][r[j]]){s+=cifang(b[j][l[j]]*2,k);l[j]++;}
            else {s+=cifang(b[j][r[j]]*2,k);r[j]--;}
        }
        k++;
    }
    cout<<s;
}
*/
