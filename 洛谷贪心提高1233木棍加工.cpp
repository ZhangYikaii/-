#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

struct Data
{
	int a, b;
};

bool cmp(Data x, Data y) {
	return x.a > y.a;
}

inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k * base;
}

int n, maxx = -1;
int dp[5010];
Data arr[5010];

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		arr[i].a = read();
		arr[i].b = read();
	}

	sort(arr + 1, arr + n + 1, cmp);

	for (int i = 1; i <= n; ++i) {
		dp[i] = 1;
		for (int k = 1; k < i; ++k) {
			if (arr[k].b < arr[i].b)
				dp[i] = max(dp[i], dp[k] + 1);
		}
		if (maxx < dp[i])
			maxx = dp[i];
	}

	printf("%d\n", maxx);


	return 0;
}

/*
��һ�����ӵ�׼��ʱ��Ϊ1���ӣ�

����մ����곤��ΪL�����ΪW�Ĺ��ӣ���ô�����һ�����ӳ���ΪLi�����ΪWi����������L>��Li��W>��Wi��������ӾͲ���Ҫ׼��ʱ�䣬������Ҫ1���ӵ�׼��ʱ�䣻

���㴦����n����������Ҫ�����׼��ʱ�䡣���磬����5�����ӣ����ȺͿ�ȷֱ�Ϊ(4, 9)��(5, 2)��(2, 1)��(3, 5)��(1, 4)�����׼��ʱ��Ϊ2����(4, 9)��(3, 5)��(1, 4)��(5, 2)��(2, 1)�Ĵ�����мӹ�����

�����ʽ��
��һ����һ������n(n<��5000)����2����2n���������ֱ���L1��W1��L2��w2������Ln��Wn��L��W��ֵ��������10000����������֮���ÿո�ֿ���

�����ʽ��
��һ�У�һ������������Ҫ�����׼��ʱ�䡣

����:
5
4 9 5 2 2 1 3 5 1 4


���:
2


*/
