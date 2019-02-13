// ��һ��������һ�۾͸о�������dp��
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define in(x) x = read()

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int n, pearl[300], dp[300][300], maxn = -1;

int main() {
	in(n);
	for (int i = 1; i <= n; i++) {
		in(pearl[i]); 
		pearl[i + n] = pearl[i];
	}

	// ��סģ��: ��ȷ��len, Ȼ�����ÿһ�� beg ��ʼ��( �����е����п��ܿ�ʼ�� ), �������� beg �� len ȷ����, ����beg end ֮��ķָ��, ��ÿһ�������ķָ�������д���.
	// len: ���ֵ�����������ܳ���
	for (int len = 1; len <= n; ++len) {
		// beg: �����俪ʼ��
		for (int beg = 1; beg + len <= 2 * n; ++beg) {
			// tmpEnd: �����������, par: �ָ��
			int tmpEnd = beg + len - 1;
			for (int par = beg; par < tmpEnd; ++par) {
				// cout << beg << " " << par << " " << tmpEnd << endl;
				dp[beg][tmpEnd] = max(dp[beg][tmpEnd], dp[beg][par] + dp[par + 1][tmpEnd] + pearl[beg] * pearl[par + 1] * pearl[tmpEnd + 1]);
			}
			if (dp[beg][tmpEnd] > maxn)
				maxn = dp[beg][tmpEnd];
		}
	}

	printf("%d\n", maxn);
	return 0;
}

/*
ÿ��������ͷβ��, ֻ��ͷ����β����һ���Ĳſ��Ժϲ�, ��������1 ��(m, r) ����2 ��(r, n) �ϲ���� m * r * n

�����������
��������#1��
4
2 3 5 10
�������#1��
710
*/