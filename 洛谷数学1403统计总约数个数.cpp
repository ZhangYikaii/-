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


int main() {
	int n = read(), ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += n / i;
	cout << ans << endl;
	// ˼·: 1-n�����Ӹ��������Կ��ɹ�����2���ӵ����ĸ���+����3���ӵ����ĸ�������+����n���ӵ����ĸ���, ������1~n�к��С�2��������ӵ�����n / 2����3��n / 3�����Դ����ƣ���ʽ�ͳ�����
	return 0;
}

/*
f(n)��ʾn��Լ�����������ڸ���n��Ҫ�����f(1)��f(n)���ܺ͡�

12 �� Լ����: 1��2��3��4��6��12  => f(12) = 6;

����:
3

���:
5
*/