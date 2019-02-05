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

int m, n, ans;

// ��ס�������������ĺ���

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);      // ��λ��, �����ϵĵ���
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= sqrt(m * n); i++) {
		if ((n * m) % i == 0 && gcd(i, (n * m) / i) == n)	// �������Ĺ������� n, �������� m.
			ans++;
	}
	cout << ans * 2;		// �����Զ�����Ϊֻ������һ��
	return 0;
}

/*
P,Q��������

Ҫ�� P,Q �� x_0 Ϊ���Լ��,�� y_0 Ϊ��С������.

����:�������������п��ܵ�2���������ĸ���.


����:
3 60

���:
4

����:
1��3,60
2��15,12
3��12,15
4��60,3
*/


/*

Updates were rejected because the remote contains work that you do
not have locally. This is usually caused by another repository pushing
to the same ref. You may want to first integrate the remote changes
(e.g., 'git pull ...') before pushing again.
See the 'Note about fast-forwards' in 'git push --help' for details.

*/