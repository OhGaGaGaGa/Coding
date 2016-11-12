/*
妈蛋这道普及组水（神）题搞了我很久。 
一、 
首先一个非常显然的事情就是每个火车告诉了站与站之间的等级关系，所以拓扑求最长路。 
但是发现暴力建边的话最坏可以达到500*500，所以时间复杂度有
O(MN^2)≈2.5*10^8
，常数相当小。。数据水成狗，所以绝对可以过的。 
二、 
所以我就想到了bitset，把每辆火车做成一个长N的布尔向量，经过为1，不经过为0，第一个车站的左边和最后一个车站的右边补1,。然后对于每个车站，把所有它所在的位为1的向量都&起来，然后扫一遍向量连边。 
这样做的时间复杂度可以用long long模拟bitset的时间复杂度来估计，就是
O（(MN^2)/64）≈10^7
，常数更小了，实际跑起来其实跟10^6差不多。 
三、 
然后我看了一个大神的代码，发现原来是有正儿八经的O(NM)的做法的。 
我们发现车站之间是比较麻烦的，所以考虑对偶转换！！
我们这样来考虑，比如说我们设火车经过的最低等级的车站为火车的等级，那么火车的等级数=车站的等级数？ 
按照上面的定义，火车的等级数自然是小于等于车站的等级数的，而如果一个车站不是任何一辆火车的等级，那么就意味着它可以下降或上升它自己的等级直到它是任何一辆火车的等级呢？ 
但是这样的前提是每一辆车站都至少有一辆火车经过，所以自然我们只要加一辆经过所有车站的火车就可以了。 
这样的话，我们只需要求出火车的等级即可了！
但是火车的等级怎么求呢？如果不存在一个车站使得两辆火车都经过它，那么显然这两辆火车之间是没有直接的等级关系的；而如果它们有交的话，那么显然在交集部分经过更多车站的火车的等级应该是更低的，因为低等级的车站会经过所有高等级的车站经过的车站！
一定要注意的地方： 
①拓扑求最长路的时候是要求Max！！ 
②一定要对拍！
*/
#include<iostream>//noip 2013 车站分级//codevs3294 
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1010;
int n,m,k,e[maxn][maxn],tmp[maxn],a[maxn];
int ans,in[maxn],q[maxn],merge[maxn];
bool flag[maxn];
int main() {
	cin>>n>>m;//n个火车站，m个车次 
	for(int l=1; l<=m; l++) {
		k=init();//停k站 
		memset(a,0,sizeof(a));
		for(int i=1; i<=k; i++) {
			tmp[i]=init();
			a[tmp[i]]=1;
		}
		for(int j=tmp[1]; j<tmp[k]; j++) {
			if(!a[j])
				for(int i=1; i<=k; i++)
					if(!e[j][tmp[i]])
						e[j][tmp[i]]=1,in[tmp[i]]++;
		}
	}
	while(1) {
		int top=0;
		for(int i=1; i<=n; i++)
			if(!in[i]&&!flag[i]) {
				flag[i]=1;
				q[++top]=i;
			}
		if(!top) break;
		for(int i=1; i<=top; i++)
			for(int j=1; j<=n; j++)
				if(e[q[i]][j]) 
					e[q[i]][j]=0,in[j]--;
		ans++;
	}
	cout<<ans;
	return 0;
}


#include<cstring>//hzw
#include<cstdio>
bool a[1001],f[1001];
int r[1001],b[1001];
bool e[1001][1001];
int main() {
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++) {//n个火车站，m个车次 
		memset(a,0,sizeof(a));//停q站 
		scanf("%d",&q);
		for(int j=1; j<=q; j++) {//j：第j个车站 
			scanf("%d",&b[j]);//b[i]:停靠的车站 
			a[b[j]]=1;
		}
		for(int j=b[1]; j<=b[q]; j++)//j：一个不停的车站 
			if(!a[j])
				for(int k=1; k<=q; k++)
					if(!e[j][b[k]]) {
						e[j][b[k]]=1;//k：停的每一个车站，j到b[k]连边 ，j的等级<b[k]等级 
						r[b[k]]++;//b[k]入度++ 
					}
	}
	int ans=0,top;
	while(1) {
		int sk[1001];//存删掉了哪一个 
		memset(sk,0,sieof(sk));
		top=0;
		for(int i=1; i<=n; i++)
			if(!r[i]&&!f[i]) {//入度是0 
				sk[++top]=i;
				f[i]=1;
			}
		if(top==0)break;
		for(int k=1; k<=top; k++) {
			for(int i=1; i<=n; i++)
				if(e[sk[k]][i]) {
					e[sk[k]][i]=0;
					r[i]--;
				}
		}
		ans++;
	}
	printf("%d",ans);
	return 0;
}
