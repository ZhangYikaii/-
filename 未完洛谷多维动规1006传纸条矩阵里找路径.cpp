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

int mapp[60][60], m, n;
int firway[3] = { -1, -1, -1 };
int secway[3] = { -1, 0, 1 };

int main() {
	m = read();
	n = read();
	for (int i = 1; i <= m; ++i) {
		for (int k = 1; k <= n; ++k) {
			mapp[i][k] = read();
		}
	}


	return 0;
}

/*
СԨ��С���Ǻ�����Ҳ��ͬ��ͬѧ��������һ������̸����Ļ��⡣һ��������չ��У�����ͬѧ��������һ��m��n�еľ��󣬶�СԨ��С���������ھ���Խ��ߵ�����

���ҵ�������������·����ʹ����2��·����ͬѧ�ĺ��ĳ̶�֮��������ڣ��������СԨ��С���ҵ�������2��·����

����:
3 3
0 3 9
2 8 5
5 7 0


���:
34
*/