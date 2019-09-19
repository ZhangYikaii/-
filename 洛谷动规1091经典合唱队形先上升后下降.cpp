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

int n, a[110];
int f[110] = { 0 }, f1[110] = { 0 };
int maxx = -1;
// f[i] ��ʾ���� i ��ʱ ����������еĳ���

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}

	for (int i = 1; i <= n; ++i) {
		f[i] = 1;
		for (int k = 1; k < i; ++k) {
			if (a[k] < a[i])
				f[i] = max(f[i], f[k] + 1);
		}
	}

	// ��½������з�����.
	for (int i = n; i >= 1; --i) {
		f1[i] = 1;
		for (int k = n; k > i; --k) {
			if (a[k] < a[i])
				f1[i] = max(f1[i], f1[k] + 1);
		}
	}

	// ע�� i Ҫ�䵽ͬһ��, Ȼ�� - 1.
	for (int i = 0; i <= n; ++i) {
		// ע��!!! �ϳ�������Ҫ��ϳɵ��м����һ��, Ȼ���ٿ۳�
		// ���ݾ��� f[] �Ķ���: ��a[i]��β�������������!
		if (maxx < f[i] + f1[i] - 1)
			maxx = f[i] + f1[i] - 1;
	}

	/*for (int i = 1; i <= n; ++i) {
		cout << f[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; ++i) {
		cout << f1[i] << " ";
	}
	cout << endl;*/

	printf("%d\n", n - maxx);            // �����/xk ������ǳ��ӵ�����!!! ����Ŀѽ

	return 0;
}

/*
�ϳ����ξ������������½��Ķ���, Ҳ������һֱ��������һֱ�½�

����������ĺϳ�����

����:
8
186 186 150 200 160 130 197 220

���:
4

*/
