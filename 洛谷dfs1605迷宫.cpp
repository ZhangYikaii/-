#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
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
	return k*base;
}

int mapp[10][10], used[10][10];
int n, m, xBeg, yBeg, xEnd, yEnd, res = 0;

int xw[4] = { 0, 0, -1, 1 };
int yw[4] = { -1, 1, 0, 0 };

void dfs(int x, int y) {
	if (x == xEnd && y == yEnd) {
		++res;
		return;
	}
	For(i, 0, 4) {
		int xt = x + xw[i], yt = y + yw[i];
		if (0 <= xt && xt < n && 0 <= yt && yt < m && used[xt][yt] == 0 && mapp[xt][yt] == 0) {
			used[xt][yt] = 1;
			dfs(xt, yt);
			used[xt][yt] = 0;
		}
	}
}

int main() {
	For(i, 0, 10) {
		For(k, 0, 10)
			used[i][k] = 0;
	}
	n = read(), m = read();
	int cou = read();
	xBeg = read() - 1, yBeg = read() - 1, xEnd = read() - 1, yEnd = read() - 1;
	used[xBeg][yBeg] = 1;
	int a, b;

	For(i, 0, n) {
		For(k, 0, m)
			mapp[i][k] = 0;
	}
	For(i, 0, cou) {
		a = read() - 1;
		b = read() - 1;
		mapp[a][b] = 1;
	}

	dfs(xBeg, yBeg);

	cout << res << endl;

	return 0;
}

/*
����:
��һ��N��M��T��NΪ�У�MΪ�У�TΪ�ϰ��������ڶ����������SX,SY���յ�

����FX,FY��������T�У�ÿ��Ϊ�ϰ�������ꡣ

���:

�������������յ����꣬��ÿ��������ྭ��1�Σ���������굽�յ�����ķ�

��������

����:
2 2 1
1 1 2 2
1 2

���:
1

3 4 2
3 4 3 2
1 2
3 3

0 1 0 0
0 0 0 0
0 0 1 0

*/