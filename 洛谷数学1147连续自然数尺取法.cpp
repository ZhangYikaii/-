#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
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

// ��ȡ��!!!
int main() {
	// goal ��һ��������������
	int m = read(), goal = m / 2, curSum = 1;
	for (int i = 0, j = 1; i <= goal;) {
		if (curSum < m) {
			++j;
			curSum += j;
		}
		else if (curSum > m) {
			curSum -= i;
			++i;
		}
		else {
			printf("%d %d\n", i, j);
			++j;
			curSum += j;
		}
	}
	return 0;
}

/*
����һ���� m , ��� a b, ��ʾ a ~ b �������͵���m, ��֤һ����һ����

����:
10000


���:
18 142
297 328
388 412
1998 2002

*/