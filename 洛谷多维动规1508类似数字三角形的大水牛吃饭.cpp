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

int eat[210][210], m, n;
int firway[3] = { -1, -1, -1 };
int secway[3] = { -1, 0, 1 };

int MaxThree(int a, int b, int c) {
	if (a >= b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}

int main() {
	m = read();
	n = read();
	for (int i = 1; i <= m; ++i) {
		for (int k = 1; k <= n; ++k) {
			eat[i][k] = read();
		}
	}

	// ע������!
	if (n == 1) {
		int sum = 0;
		for (int i = 1; i <= m; ++i)
			sum += eat[i][1];
		printf("%d\n", sum);
	}

	else {
		for (int i = 2; i <= m; ++i) {
			eat[i][1] += eat[i - 1][1] > eat[i - 1][2] ? eat[i - 1][1] : eat[i - 1][2];
			eat[i][n] += eat[i - 1][n] > eat[i - 1][n - 1] ? eat[i - 1][n] : eat[i - 1][n - 1];
			for (int k = 2; k < n; ++k) {
				eat[i][k] += MaxThree(eat[i - 1][k - 1], eat[i - 1][k], eat[i - 1][k + 1]);
			}
		}


		printf("%d\n", MaxThree(eat[m][n / 2], eat[m][n / 2 + 1], eat[m][n / 2 + 2]));
	}

	return 0;
}

/*
n*m(n and m<=200)�ľ��͵ľ��ʹ����, ���е�ʳ�ﰴ�������ṩ���������˷֣���Щ�Ǹ��ģ���Ϊ����Ҫ�����ӣ�

����������, ÿ�����ݵĳ����㶼�����һ�е��м�λ�õ��·�

[�������ݣ�]

��һ��Ϊm n.(nΪ����)�����ˮţһ��ʼ�����һ�е��м���·�

������Ϊm*n�����־���.

����m��,ÿ��n������.���ּ��ÿո����.����ø����ϵ����е�ʳ�������ṩ������.

����ȫ������.

����������

����:
6 7
16 4 3 12 6 0 3
4 -5 6 7 0 0 2
6 0 -1 -2 3 6 8
5 3 4 0 0 -2 7
-1 7 4 0 7 -5 6
0 -1 3 4 12 4 2

���:
41





*/
