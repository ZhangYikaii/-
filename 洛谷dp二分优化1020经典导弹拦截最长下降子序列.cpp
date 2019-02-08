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

int n, a[100010], B[100010], b[100010];
int f[100010], f1[100010];
int maxx = -1, maxx1 = -1;
// f[i] ��ʾ���� i ��ʱ �������/���������еĳ���

// ��arr[l...r]�ж��ֲ��Ҳ���λ��, ���ص��ǲ���󱣳������λ��, ���ظ��ľ��ǲ����ظ��������һ��
// r �ǿ��Է��ʵ��±�
int insert(int arr[], int l, int r, int key) {
	int mid;
	if (arr[r] <= key)
		return r + 1;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (arr[mid] <= key)
			l = mid + 1;
		else
			r = mid;
	}
	return l;
}

// insert1 ���С���Ǹ������ǵ�
int insert1(int arr[], int l, int r, int key) {
	int mid;
	if (arr[r] > key)
		return r + 1;
	while (l < r) {
		mid = l + (r - l) / 2;
		if (arr[mid] > key)
			l = mid + 1;
		else if (arr[mid] < key)
			r = mid;
		else
			return -1;
	}
	return l;
}

// �����������
int LISplus(int a[], int n) {
	int i, len = 1, next;
	b[1] = a[1];

	for (i = 2; i <= n; ++i) {
		int next = insert1(b, 1, len, a[i]);
		if (next != -1)
			b[next] = a[i];
		if (len < next)
			len = next;
	}

	return len;
}

// ������̽��Ϳ��ʼ�
int LIS(int A[], int n) {
	int i = 0, len = 1, next;
	B[1] = A[1];
	for (i = 2; i <= n; i++) {
		int next = insert(B, 1, len, A[i]);
		B[next] = A[i];
		if (len < next) // �����������β��, ����Ҫ���� 1
			len = next;
	}
	return len;
}

int main() {
	int a[18] = { 9, 6, 5, 3, 1, 0 };
	cout << insert1(a, 0, 5, 4);
	// û�н�β��ʶ��������scanf��д��:
	int input = 1;
	while (scanf("%d", &a[input]) != EOF) {
		++input;
	}

	printf("%d\n", LIS(a, input));

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
