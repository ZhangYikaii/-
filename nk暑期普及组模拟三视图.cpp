#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int arr[1010][1010];
int rowMax[1010], linMax[1010];
int n;

int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		int maxx = 0;
		for (int k = 1; k <= n; ++k) {
			in(arr[i][k]);
			if (arr[i][k] > maxx)
				maxx = arr[i][k];
			rowMax[i] = maxx;
		}
	}

	for (int k = 1; k <= n; ++k) {
		int maxx = 0;
		for (int i = 1; i <= n; ++i) {
			if (arr[i][k] > maxx)
				maxx = arr[i][k];
		}
		linMax[k] = maxx;
	}

	// ����ͼ:
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			if (linMax[k] >= n + 1 - i)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}

	// ����ͼ:
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			if (rowMax[k] >= n + 1 - i)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}

	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= n; ++k) {
			if (arr[i][k] != 0)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}

	return 0;
}


/*

���ӣ�https://ac.nowcoder.com/acm/contest/928/B
��Դ��ţ����

��Ŀ����
С��Ů��С��ϲ���Ի�����������һ�����룬������ħ�������������ζ�ɿڵĻ��������������Ϳ����������ܻ���������ζ����
С��Ů��ѧϰ����ͼ���ٶ�ÿ������ͼ��������С��������ɡ�
С��Ů������һ������ͼ�����㳢�Ի���������ͼ����������ͼ��ʵ�ߺ����ߣ���
��������:
��һ�У�һ������n����ʾ����ͼ�ĳ���ߣ�����ȣ���
�������� n �У�ÿ�а����ÿո������ n �����֣���ʾ����ʱ��ÿ��λ�öѵ����ٸ������塣
�������:
������ n �У�ÿ�� n ���ַ�����ʾ����ͼ����Ϊ��*�� ���ʾ��λ���������Σ���Ϊ��.�� ���ʾ��λ��û�������Ρ�
������ n �У�ÿ�� n ���ַ�����ʾ����ͼ����Ϊ��*�� ���ʾ��λ���������Σ���Ϊ��.�� ���ʾ��λ��û�������Ρ�
������ n �У�ÿ�� n ���ַ�����ʾ����ͼ����Ϊ��*�� ���ʾ��λ���������Σ���Ϊ��.�� ���ʾ��λ��û�������Ρ�
ʾ��1
����
����
3
3 2 0
2 2 0
0 0 0
���
����
*..
**.
**.
*..
**.
**.
**.
**.
...


*/