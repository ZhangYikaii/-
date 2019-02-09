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
/***/
#define For(i, n, m) for(long long i = n;i < m; ++i)

inline long long read() {
	char s;
	long long k = 0, base = 1;
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

// �������Խ���ֵ���Խ��, ���ȿ������ֵ���С�ķŷ�, ����Ե���Ŀ����ͨ�����ü������
// ��ס������ǿ��Ե�������, �����!
// ע���С������ʼ��, ��Ϊ���Լ�������ǰ���ж����� �� ����Ϊ�����������

int main() {
	long long n = read(), needRev = read();
	long long ans[50010] = { 0 }, iAnsHead = 1, iAnsTail = n;

	// ��С�����ÿһ������ ��һ��1~5������ȥ���
	for (long long i = 1; i <= n; ++i) {
		long long maxRevNum = (n - i) * (n - 1 - i) / 2;
		// ������֧, ���ʼ�
		if (maxRevNum >= needRev)	// �ŵ�һ��
			ans[iAnsHead++] = i;
		else {						// �ŵ�ǰ���һ��
			ans[iAnsTail--] = i;
			needRev -= (iAnsTail - iAnsHead + 1);
		}
	}

	printf("%d", ans[1]);
	for (long long i = 2; i <= n; ++i)
		printf(" %d", ans[i]);
	printf("\n");


	return 0;
}

/*
������1-N����ʾ������Ԫ�أ���һ����������

1, 2, 3, �� N

�ڶ��죬�����Զ���Ϊ

1, 2, 3, �� N, N-1

����ÿ����������һ����ǰδ���ֹ��ġ���С�������С�������תΪN+1���ƺ�������ֵ��С��
Ҳ����N�������ı����ֵ�˳��, Ȼ���Сһ��, ��һ�㾡����С



����Ŀ����:
�������Ϊ M ���ֵ�����С��, �������� 1~N ����.

����:
5 4

���:
1 3 5 4 2



// ����1 2 3 4 5һ��һ����С, ֱ������Ը����� 4 ����ʱ��: 1 3 5 4 2 �����

*/