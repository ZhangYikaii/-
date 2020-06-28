#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

// P1002 ������
int m, n;
int hx, hy;
ll dp[100][100];
int hous[40][40];
int ways[6][2] = {
	1, 1,
	1, -1,
	-1, 1,
	-1, -1
};

int main() {
	// ע�������ⲻҪ�ȳ�ʼ��һ���߽�, �����ʼ���ʼ�Ǹ����OK��.

	// ��Ϊ���־��ǲ������ĵ�(����Ƶ�)Ϊ0���, �����������ʼ��Ҳ��Ϊ0.
	// ��ô��ô�жϲ��ֿ�����? ���ǰ���Ŀ��Ƶ�������. ����һ�����ж��ǲ���.
	// ���ݺ�С�Ϳ���������hash�ķ�ʽ.
	in(m), in(n), in(hx), in(hy);
	++m;
	++n;
	++hx;
	++hy;

	For(i, 0, 4) {
		// ϸ�´��������±�.
		if (hx + 2 * ways[i][0] >= 0 && hy + 1 * ways[i][1] >= 0)
			hous[hx + 2 * ways[i][0]][hy + 1 * ways[i][1]] = 1;
		if (hx + 1 * ways[i][0] >= 0 && hy + 2 * ways[i][1] >= 0)
			hous[hx + 1 * ways[i][0]][hy + 2 * ways[i][1]] = 1;
	}
	hous[hx][hy] = 1;

	dp[1][1] = 1;
	//For(i, 0, m + 1) {
	//	dp[i][0] = 1;
	//}
	//For(i, 0, n + 1) {
	//	dp[0][i] = 1;
	//}

	For(i, 1, m + 1) {
		For(j, 1, n + 1) {
			if (hous[i][j] == 0) {
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + dp[i - 1][j]);
			}
		}
	}

	/*For(i, 1, m + 1) {
		For(j, 1, n + 1) {
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}*/
	
	printf("%lld\n", dp[m][n]);
	return 0;
}