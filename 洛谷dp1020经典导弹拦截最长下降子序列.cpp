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

int n, a[100010];
int f[100010], f1[100010];
int maxx = -1, maxx1 = -1;
// f[i] ��ʾ���� i ��ʱ �������/���������еĳ���

int main() {
	// û�н�β��ʶ��������scanf��д��:
	int input = 1;
	while (scanf("%d", &a[input]) != EOF) {
		++input;
	}

	// �ʼ����������Ĺ���
	for (int i = 1; i < input; ++i) {
		f[i] = 1;
		f1[i] = 1;
		for (int k = 1; k < i; ++k) {
			// �������������:
			if (a[k] >= a[i])
				f[i] = max(f[i], f[k] + 1);
			// �����������:
			else {
				f1[i] = max(f1[i], f1[k] + 1);
			}
		}
		if (maxx < f[i])
			maxx = f[i];
		if (maxx1 < f1[i])
			maxx1 = f1[i];
	}


	/*for (int i = 1; i < input; ++i)
		cout << f1[i] << " ";
	cout << endl;*/
	printf("%d\n%d\n", maxx, maxx1);

	
	return 0;
}

/*
������ ������������г���, �� ���ٵĲ����������е���Ŀ, �ʼ�������ϸ���

��Ŀ���� Description
ĳ��Ϊ�˷����й��ĵ���Ϯ������չ��һ�ֵ�������ϵͳ���������ֵ�������ϵͳ��һ��ȱ�ݣ���Ȼ���ĵ�һ���ڵ��ܹ���������ĸ߶ȣ������Ժ�ÿһ���ڵ������ܸ���ǰһ���ĸ߶ȡ�ĳ�죬�״ﲶ׽���й��ĵ�����Ϯ�����ڸ�ϵͳ�������ý׶Σ�����ֻ��һ��ϵͳ������п��ܲ����������еĵ�����

�������� Input Description
���뵼�����η����ĸ߶ȣ��״�����ĸ߶������ǲ�����30000����������

������� Output Description

�������ϵͳ��������ض��ٵ��������Ҫ�������е�������Ҫ�䱸���������ֵ�������ϵͳ��

�������� Sample Input
389 207 155 300 299 170 158 65

(����������������е�dp����ͻ���:
1   2   3   2   3   4   5   6 )

������� Sample Output
6

2
*/
