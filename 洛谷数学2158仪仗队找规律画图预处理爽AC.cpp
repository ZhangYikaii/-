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
/*****/
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

#define MAX 40000

int n, arr[40010];		// arr[i] ���п���ȥ�ĵ� i ��������ÿ���ܿ����ĸ���


// ҮҮҮ����ˬˬ��AC��һ����
int main() {
	// Ԥ����, ����arr[]
	for (int i = 3; i <= MAX; ++i) {
		arr[i] = i - 2;
	}
	for (int i = 3; i <= MAX; ++i) {
		int tmp = i - 1;
		for (int k = i + tmp; k <= MAX; k += tmp)
			arr[k] -= arr[i];			// ��ǰ����arr[i]��, �͵�ס�˺���� ÿ +(i - 1) �е�arr[i]��
	}

	n = read();

	if (n == 2)
		printf("3\n");
	else if (n < 2)
		printf("0\n");
	else {
		int sum = 0;
		for (int i = 3; i <= n; ++i)
			sum += arr[i];
		printf("%d\n", 2 * sum + 3);
	}


	return 0;
}

/*
��Ϊ����ίԱ��C����������˶������̶ӵ�ѵ�������̶�����ѧ����ɵ�N * N�ķ���Ϊ�˱�֤�������н������뻮һ��C����������̶ӵ���󷽣�����������������ѧ���������ж϶����Ƿ�����(����ͼ)��  ���ڣ�C��ϣ�����������������ʱ�ܿ�����ѧ��������

����:
4

���:
9
*/