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

// ���� ����ˮ��� 2 ֮��, ����ϲ�֮��Ͷ��� 2 ���ݴ���, ȥ�������
// ������ 1015808 �� 11111000000000000000

// ����ʮ������ת������֮���ж��ٸ� 1
int popcnt(int u) {
	int ret = 0;
	while (u)
	{
		u = (u & (u - 1));    // �� u ���ұߵ� 1 ���
		ret++;
	}
	return ret;
}

int n, k, ans = 0;
// ���ϼ��� lowbit() ����
int main() {
	scanf("%d%d", &n, &k);
	while (popcnt(n) > k) 
		ans += n & -n, n += n & -n;
	printf("%d\n", ans);

	return 0;
}
/*

һ�죬CC����N������������Ϊ�����޴��ƿ�ӣ���ʼʱÿ��ƿ������1��ˮ������~~CC����ƿ��ʵ��̫���ˣ���������������������K��ƿ�ӡ�ÿ����ѡ��������ǰ��ˮ����ͬ��ƿ�ӣ���һ��ƿ�ӵ�ˮȫ��������һ���Ȼ��ѿ�ƿ������(���ܶ�����ˮ��ƿ��)

��Ȼ��ĳЩ�����CC�޷��ﵽĿ�꣬����N=3,K=1����ʱCC��������һЩ�µ�ƿ��(��ƿ���������ޣ���ʼʱ��1��ˮ)���Ե���Ŀ�ꡣ

����CC��֪����������Ҫ�������ƿ�Ӳ��ܴﵽĿ���أ�

����:
3 1

���:
1

����:
13 2

���:
3

����:
1000000 5

���:
15808


���� N, K  �����Ҫ��ӵı���
*/