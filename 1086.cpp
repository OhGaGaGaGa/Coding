#include<iostream>
#include<cstdio>
using namespace std;
long double jc[]= {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000};
long double pailie(int m,int n) {
	if(m==0)return 1;
	return (jc[n]/jc[n-m]);
}
unsigned long long A(int n,int m){
	if(n==0)return 1;
	unsigned long long ans=1;
	if(n==m)return jc[n]; 
	for(int i=n+1;i<=m;i++)
		ans*=i;
	return ans;
}
int main() {
	int n;
	unsigned long long ans=0;
	cin>>n;
	for(int i=1; i<=n; i++)
		ans+=A(i-1,n-1);
	cout<<ans<<endl;
}
/*
#include<iostream>
using namespace std;
unsigned long long f[101]= {0};
int main() {
	int n,i,j;
	cin>>n;
	f[0]=1;
	f[1]=1;
	for(i=2; i<=n; i++)
		for(j=1; j<=i; j++)
			f[i]+=f[j-1]*f[i-j];
	cout<<f[n];
	return 0;
}*/ 
/*
考虑这样一个序列。
序列初始为空，每当一个元素入栈就在序列末尾填一个1，
每当一个元素出栈就在序列末尾填一个0，
可知一个出栈顺序对应着一个长度为2n其中有n个1的序列，同时一个长度为2n,
其中有n个1且满足任意时刻序列中1的个数不少于0的个数的一个序列也对应着一个可能的出栈顺序。
因此原题目转化为求满足条件的01序列有多少个。
长度为2n其中有n个1的序列共有C(2n,n)个<从2n个里取出n个为1其它为0>，
在这些序列中显然有一部分不满足对于任意i≤2n都有前i项中1的个数多于0的个数。
那么，怎么求出不满足这个条件的01序列的个数呢？显然，
对于任意一个不满足条件的01序列，
都存在一个i(1≤i≤2n)使得该序列的前i项中0的个数恰好比1的个数多1(显然i是一个奇数，但是这并不重要)，
这里的证明请自行脑补（划掉）。因为对于序列的前0项，1的个数与0的个数相等，
序列中又存在一个位置j使得前j项中1的个数比0的个数少。
设d[i]为前i项中0的个数与1的个数之差，则显然有d[i]-d[i-1]=1或-1，d[0]=0，d[j]>0，
考虑最接近d[j]的d[x]=0（就是从d[j]开始while d[j]<>0 do dec(j)，d数列中显然也一定能找到0），
若d[x+1]=-1则在x+1~j之间必定还有d[i]=0出现与“最接近”矛盾，因此d[x+1]=1，
即对于该01序列的前x+1项0的个数恰好比1的个数多1。
由于原01序列有n个0和n个1所以第x+2~2n项中0的个数也恰好比1的个数少1。
将序列的前x+1项xor 1，即把原来的0变成1把原来的1变成0，
再接到第x+2项之前，得到的新序列中必定恰好有n-1个0和n+1个1，
而恰好有n-1个0和n+1个1的01序列q也必定对应着一个上述不满足条件的含有n个0和n个1的01序列p
（同理可证对于序列q必然存在一个位置i使得序列的前i项中1的个数恰好比0的个数多1，然后把前i项xor 1就得到p），
这样的恰好有n-1个0和n+1个1的01序列q有C(2n,n-1)个，
即在C(2n,n)个01序列中存在C(2n,n-1)个是不符合要求的，
题目所求最后答案即为ans(n)=C(2n,n)-C(2n,n-1)。
而ans（n）的这个形式恰好是Catalan数的形式，
于是代入求Catalan数的递推式中ans(n)=ans(n-1)*(4*n-2)/(n+1);，
ans(0)=ans(1)=1。就可以用O(n)的时间求出答案。
由于ans数组不用存储,只需递推计算,所以空间复杂度O(1)
<存一个n一个循环变量i一个当前答案ans（这个应该需要long long或者int64）>
就OK啦~至于代码什么的请参考之前的题解- -
相关公式请自行百度Catalan数。
*/
