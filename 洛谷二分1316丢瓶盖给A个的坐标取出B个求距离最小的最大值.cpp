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

// ���ֵľ������ڱʼǱ���

int a[100010], n, b;
int lef, rig, mid;

// �ж��� b ��ƿ������, �� b ��������������ֵ�ǲ��ǿ��Դﵽ dis
bool judge(int dis) {
	
}

int main() {
	n = read();
	b = read();

	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}

	sort(a + 1, a + n + 1);

	lef = a[2] - a[1];
	rig = a[n] - a[1];

	while (lef <= rig) {
		mid = (lef + rig) >> 1;

	}

	return 0;
}

/*
���ڵ��϶���A��ƿ�ǣ�Ϊ�˼����⣬���ǿ��Ե�����A��ƿ�Ƕ���һ��ֱ���ϣ������������Щƿ�����ҳ�B����ʹ�þ��������2�������������֪���������Ե������أ�

���������ʽ
�����ʽ��
��һ�У�����������A,B����B<=A<=100000��

�ڶ��У�A���������ֱ�Ϊ��A��ƿ�����ꡣ

�����ʽ��
��һ��������Ϊ����𰸡�
*/
