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

// ע�� -1 % 5 = -1

// ����Ҫdp����������
// ������, �����Ǹ�������Ĵ���������, ���ǱȽϺ�д�߽�������
/*
��Ŵ� 0 ��ʼ��, һֱ�浽 n - 1;
f[i][j] ��ʾ������� j , �������Ϊ i ���˵������ʱ��;
f[i][j] = �����������ߴ������ķ����ܺ� = f[(i + n - 1) % n][j - 1] + f[(i + 1) % n][j - 1];

ע��߽�����!!!!!
*/
int n, m;

int main() {
	int f[50][50];
	n = read(), m = read();

	// �߽�����: ��Ҫ������ 0 �� �� ���� 1 ��
	f[0][1] = 0;
	f[1][1] = 1; 
	f[n - 1][1] = 1;

	for (int i = 2; i < n - 1; ++i)
		f[i][1] = 0;

	// ���� 0 ��Ҫ��ô����??? ����ʵ�����!!!
	f[0][0] = 1;
	for (int i = 1; i < n; ++i) {
		f[i][0] = 0;
	}

	// ��θ���??? ��״̬ת�Ʒ���, ���� ���� j - 1 ˵��Ҫ��j��������ǰ�ƽ�
	for (int j = 2; j <= m; ++j) {
		for (int i = 0; i < n; ++i) {
			f[i][j] = f[(i + n - 1) % n][j - 1] + f[(i + 1) % n][j - 1];
		}
	}

	cout << f[0][m] << endl;


	return 0;
}

// dfs�ֲ���֦��ֱ��ը!
/*
int n, m, ans = 0;

void dfs(int cur, int level) {
	if (level == m && cur == 1) {
		++ans;
	}

	else if (level < m) {
		dfs((cur + 1) % m + 1, level + 1);
		dfs((cur - 1) % m + 1, level + 1);		
	}
}


int main() {
	n = read(), m = read();
	dfs(1, 0);

	cout << ans << endl;

	return 0;
}

*/

/*

ÿ��ͬѧ���԰��򴫸��Լ����ҵ�����ͬѧ�е�һ�����������⣩ ע�����Ҷ�����
n ��ͬѧ, ���� m ��

���м��ִ��򷽷�:

���:
3 3

���:
2

����:
1->2->3->1

1->3->2->1

*/
