//////// ������Ŀ��������ʵʵdfs + ��֦��, dp�ı߽����
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

/*
// ����ⷨ!!!!!!
��n��С��ŵ�k�������е�������� =

a. ������һ������ֻ��һ��С�������� + b. û��һ������ֻ��һ��С��������

����
a. ��Ϊ���Ӳ������֣���ô a ��������� "��n-1��С��ŵ�k-1��������" �������һ��

b.û��һ������ֻ��һ��С����ô��ÿ���������ó���һ��С�� ÿ���������ó���һ��С��!!! ���е�˼·!!!����Ӧ���� "��(n-k)��С��ŵ�k�������е������"

д��״̬ת�Ʒ���:
f[i][j] ���ǰ� i �� С����� j ����������ķ�����
f[i][j] = f[i - 1][j - 1] + f[i - j][j];           j �Ǻ�������
*/

int n, k;

int main() {
	int f[210][7];
	n = read(), k = read();
	// �߽�������̫��Ҫ��/xk /xk
	// �����for����߽��Ǵ��!!!
	/*for (int i = 0; i <= n; ++i) {
		for (int k = 0; k <= i; ++k) {
			if (k != i)
				f[i][k] = 0;
			else
				f[i][k] = 1;
		}
	}*/
	for (int i = 0; i <= n; ++i) {
		f[i][1] = 1;
		f[i][0] = 1;
	}
	for (int i = 0; i <= k; ++i) {
		f[0][i] = 0;
		f[1][i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (i < j) {
				// cout << "1: " << f[i - 1][j - 1] << endl;
				f[i][j] = f[i - 1][j - 1];
			}
			else {
				// cout << "2: " << f[i - 1][j - 1] << " " << f[i - j][j] << endl;
				f[i][j] = f[i - 1][j - 1] + f[i - j][j];
			}
		}
	}

	cout << f[n][k] << endl;

	return 0;
}


/*
// dfs�ⷨ!!!!!!!!!!
int n, k;
int ans = 0;

// dfs ���������ڲ�ͬλ�ó��Ի��߲����Ե�����:
// ����һ��base, ������ÿ�εݹ�֮����λ���ǲ�������
// ע����Ϊÿһλ���ǲ���������, ע�������Ԥ�����������ֵ�˼·ȥ�Ŷ���, ֻ��������֦�ع�
void dfs(int base, int curSum, int level) {
	if (level == k && curSum == n) {
		++ans;
		return;
	}

	if (level < k) {
		// curSum + i * (k - level) <= n �����ڱ�֤���涼�������ļ�֦
		for (int i = base; curSum + i * (k - level) <= n; ++i) {
			dfs(i, curSum + i, level + 1);
		}
	}
}

int main() {
	n = read(), k = read();
	dfs(1, 0, 0);

	printf("%d\n", ans);

	return 0;
}

*/

/*

��n��С��ŵ�k�������У�С��֮�������֮��û�����𣬲������Ľ��������պ�

����:
7 3

���:
4


4 �ַ������:
1 1 5
1 2 4
1 3 3
2 2 3
*/
