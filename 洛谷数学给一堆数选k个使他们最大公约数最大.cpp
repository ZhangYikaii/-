#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
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

int n, k;

// ��ѧ���/xk ��������ô���ͺܼ���/xk
int main() {
	n = read();
	k = read();

	printf("%d\n", n / k);


	return 0;
}

/*
1~n ȡk��, ʹ��k�������Լ�����

�����ʽ��
�����ո�ֿ���������n��k����n>=k>=1��

�����ʽ��
һ��������Ϊ����Ĭ��ֵ��
*/
