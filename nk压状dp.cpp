#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff
#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
using namespace std;
typedef long long ll;

#define in(x) x=read()

#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int main() {

	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define far(i,t,n) for(int i=t;i<n;++i)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int price[20];
const int maxm=1<<15+5;
int vis[maxm];
int dp[maxm];//dp[i]��ʾ������״̬Ϊiʱ����Żݵ�Ǯ��
int cnt[maxm];//cnt[i]��ʾ����״̬Ϊiʱ�����ı��飬��i��1�ĸ���

int main()
{
	int n,m;
	cin>>n>>m;
	int sum=0;
	far(i,1,n+1)
		scanf("%d",&price[i]),sum+=price[i];
	sort(price+1,price+n+1,greater<int>());
	far(i,0,m)
	{
		int state=0;
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			state |= 1<<(x-1);
		}
		vis[state]=1;
	}
	int es=1<<n;
	far(i,1,es)
		cnt[i]=cnt[i&(i-1)]+1;//�������ұ�1���״̬
	far(i,1,es)
	{
		if(vis[i])
			dp[i]=max(dp[i],price[cnt[i]]);//������ǰcnt[i]���飬�Żݵ�cnt[i]��
		for(int j=i;j>0;j=i&(j-1))
		{
			int x=i^j;//xΪj����i�Ĳ���
			if(vis[x])//���������Żݷ������ڣ������ͨ���ȵ���״̬j����x����i
				dp[i]=max(dp[i],dp[j]+price[cnt[i]]);
		}
		for(int j=0;j<n;++j)
			dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]);
	}
	int ans=sum-dp[es-1];
	cout<<ans<<"\n";
}

*/


/*
#include<cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int f[1<<15],c[20],m,n;
int g[1<<15],sz[1<<15];
int main()
{
	cin>>n>>m;
	for(int x=1;x<=n;x++)
	{
		cin>>c[x];
	}
	sort(c+1,c+1+n);
	for(int x=1;x<=m;x++)
	{
		int s=0,k,zhi;
		cin>>k;
		for(int y=1;y<=k;y++)
		{
			cin>>zhi;
			s|=(1<<zhi-1);
		}
		g[s]=1;
	}
	for(int x=1;x<(1<<n);x++)
	{
		sz[x]=sz[(x-1)&x]+1;
	}
	for(int x=0;x<(1<<n);x++)
	{
		int s=((1<<n)-1)^x;
		for(int y=s;y;y=(y-1)&s)
		{
		if(g[y])
		{
			f[x|y]=max(f[x|y],f[x]+c[sz[x]+1]);
			}
		}
	}
	int tot=0;
	for(int x=1;x<=n;x++)
	{
		tot+=c[x];
	}
	cout<<tot-f[(1<<n)-1]<<endl;
	return 0;
}

*/

/*
���ӣ�https://ac.nowcoder.com/acm/contest/946/B
��Դ��ţ����

��Ŀ����
������һ���Ȱ��Ķ��ĺ����꣬����ϲ�����������ȥ�����������
һ�죬������һ����nn�������꣬����ʮ�ֿ��֣���������ҵ������е���ȫ����������
���ɽ�������ڸ��������������ɸ�����������ÿ��������������ָ�������ɱ��鹹�ɵļ��ϣ���������˸÷��������е��飬��ô��������˵�һ���齫��ѡ����ǣ�ÿ����ֻ������һ������������
��Ϊ�����VIP�������õ�nn���۸��ǩ��������Ը�ÿ������ѡһ���۸��ǩ��ʹ��ÿ���۸��ǩ��ÿ����һһ��Ӧ��
������Ҫ֪�����ں����������д�������������£�������������СҪ����Ǯ��

��������:
��һ��������n,mn,m���ֱ��ʾ��ı����ʹ���������������
�ڶ���nn����������ʾÿ���۸��ǩ�ϵı�ע�ļ۸�
������mm�У�ÿ�е�һ����kk��ʾ�ô��������������������������kk��������ʾ��ı�š�
�������:
���һ��һ��������ʾ�𰸡�
ʾ��1
����
����
4 2
2 3 2 4
2 2 3
2 2 4
���
����
8

*/