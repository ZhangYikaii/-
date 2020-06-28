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

// ˼·: ������ɢ����, �˶�������ʵ����ÿ��ѡ�� 17m/s �� ���� 60m/s ��.
int tr = 0;
int m, s, t;
int dp[300010] = { 0 };

int main() {
	in(m);
	in(s);
	in(t);
	// ע����·��ʱ��Ҳ�ɻ���.

	// �𰸵ķ���: ���ֵĺ���Ҫ���ܲ�һͬ����ʮ���鷳, ���ǰ����Ƿֿ��㣺
	// �ȴ���ȫ��ʹ��һ�ֲ��Ե�, �������ֵ�
	// ����ȫ��ʹ��һ�ֲ��Ե�dp������, ��dpһ�鿴������Щ�ڵ�ʹ��17m/s�ĸ���.
	// �ֲ������ȫ�ֿ�

	// dp[i]��ʾʱ��i���߶�Զ

	for (int i = 1; i <= t; ++i) {
		if (m >= 10) {
			m -= 10;
			dp[i] = dp[i - 1] + 60;
		}
		else {
			m += 4;
			dp[i] = dp[i - 1];
		}
	}

	for (int i = 1; i <= t; ++i) {
		dp[i] = max(dp[i], dp[i - 1] + 17);
		if (dp[i] >= s) {
			printf("Yes\n%d\n", i);
			return 0;
		}
	}

	printf("No\n%d\n", dp[t]);

	return 0;
}

/*

#include <cstdio>
#include <algorithm>
using namespace std;
int dp[300001];
int main(){
	int m,s,t;
	scanf("%d%d%d",&m,&s,&t);
	for(int i=1;i<=t;i++){//������˸����
		if(m>=10)dp[i]=dp[i-1]+60,m-=10;//������ã�����
		else dp[i]=dp[i-1],m+=4;//������Ϣ
	}
	for(int i=1;i<=t;i++){dp[i]=max(dp[i],dp[i-1]+17);//�����ܲ���dp[i]Ϊʹ�÷������ܲ������ֵ�����ţ�
	if(dp[i]>=s){printf("Yes\n%d",i);return 0;}//��������˾���s���ͳɹ��ˣ����yes
	}printf("No\n%d",dp[t]);//û�ɹ������no
	return 0;
}
*/

/*


*/