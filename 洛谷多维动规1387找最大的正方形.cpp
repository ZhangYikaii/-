#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
#define in(x) x = read()
inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}
int n, m, ans = 0;
int matrix[110][110], dp[110][110];

int MyMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	in(n);
	in(m);

	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= m; ++k) {
			in(matrix[i][k]);
			if (matrix[i][k] == 1) {
				dp[i][k] = MyMin(MyMin(dp[i][k - 1], dp[i - 1][k]), dp[i - 1][k - 1]) + 1;
			}
			if (ans < dp[i][k])
				ans = dp[i][k];
		}
	}

	printf("%d\n", ans);

	return 0;
}

/*

��Ŀ����
˧˧������ͬѧ��һ������ȡ����Ϸ������һ��������n �� m�ľ��󣬾����е�ÿ��Ԫ��a_{i,j}��Ϊ�Ǹ���������Ϸ�������£�

ÿ��ȡ��ʱ���ÿ�и�ȡ��һ��Ԫ�أ���n��������m�κ�ȡ�����������Ԫ�أ�
ÿ��ȡ�ߵĸ���Ԫ��ֻ���Ǹ�Ԫ�������е����׻���β��
ÿ��ȡ������һ���÷�ֵ��Ϊÿ��ȡ���ĵ÷�֮�ͣ�ÿ��ȡ���ĵ÷� = ��ȡ�ߵ�Ԫ��ֵ * 2^i������i��ʾ��i��ȡ������1��ʼ��ţ���
��Ϸ�����ܵ÷�Ϊm��ȡ���÷�֮�͡�
˧˧�������æдһ�����򣬶���������󣬿������ȡ��������÷֡�

��������:
4 4
0 0 0 1
1 1 1 1
0 1 1 1
1 1 1 1

���:
3

*/