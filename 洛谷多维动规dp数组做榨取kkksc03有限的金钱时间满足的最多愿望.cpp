#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
// ע���������ƶ���� ��һ��f[]��¼�� dfs���仯����!!!
using namespace std;
int n, m, t;
struct Data {
	int tim, mon;
} a[205];

int f[205][205][205];

int MyMax(int a, int b) {
	return a > b ? a : b;
}

// f[i][j][k] Ϊ ǰ i �� ��Ǯ����Ϊ j, ʱ������Ϊ k �µ���Ʒ���ֵ.

int main() {
	for (int i = 0; i <= 200; ++i) {
		for (int j = 0; j <= 200; ++j) {
			for (int k = 0; k <= 200; ++k)
				f[i][j][k] = 0;
		}
	}
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].tim, &a[i].mon);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 1; k <= t; ++k) {
				// �ܻ�����01������, ���Ǽ���һ��ά��
				if (a[i].mon <= j && a[i].tim <= k) {
					f[i][j][k] = MyMax(f[i - 1][j - a[i].mon][k - a[i].tim] + 1, f[i - 1][j][k]);
				}
				else
					f[i][j][k] = f[i - 1][j][k];
			}
		}
	}

	printf("%d\n", f[n][m][t]);

	return 0;
}


/*

������� 01 ��������, ���������������: ʱ�� + ��Ǯ, ��01�������Ȩֵ��, ��ɶ���1��(�����Ʒ����) ����.

Kkksc03��ʱ��ͽ�Ǯ�����޵ģ�������������������ͬѧ��Ը������������֪�����Լ���������Χ�ڣ���������ɶ���ͬѧ��Ը����

���������ʽ
�����ʽ��
��һ��,n M T����ʾһ����n(n<=100)��Ը����kkksc03 �����ϻ�ʣM(M<=200)Ԫ�����������T(T<=200)����ʱ�䡣

��2~n+1�� mi,ti ��ʾ��i��Ը������Ҫ�Ľ�Ǯ��ʱ�䡣

�����ʽ��
һ�У�һ��������ʾkkksc03������ʵ��Ը���ĸ�����

�����������
��������#1��
6 10 10
1 1
2 3
3 2
2 5
5 2
4 3
�������#1��
4

*/