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

struct Pair {
	int first, second;
	Pair() { }
	Pair(int a, int b) : first(a), second(b) { }
};

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

// ����˼��: ��һ����ķ�Χ, �������ķ�Χ�����Ҵ�, ������
// �����ķ�Χ���� �������������� ~ �������еĺ�

int n, m, maxx = -1, sum;
int arr[100010];

// ע�����������͵ĺ���Ҫ��ôд!
bool greedyFind(int divid, int maxSum) {
	int curSum = 0;
	for (int i = 1; i <= n; ++i) {
		if (curSum + arr[i] <= maxSum) 
	}
}

int main() {
	n = read(), m = read();

	for (int i = 1; i <= n; ++i) {
		arr[i] = read();
		sum += arr[i];
		if (maxx < arr[i])
			maxx = arr[i];
	}



	return 0;
}

/*

Ҫ��ÿ����������ÿ�κ͵����ֵ��С��

����һ����4 2 4 5 1Ҫ�ֳ�33��

�������·ֶΣ�

[4 2][4 5][1]

����:
5 3
4 2 4 5 1

���:
6
*/
