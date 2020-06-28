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

int m, n;

int arr[60][60], dp[60][60][60][60];

// ��׿һ����һ������:
// ������ (i, j), (k, l).
int dfs(int i, int j, int k, int l) {
	if (i + j != k + l || (i == k && j == l))
		return 0;

	if (dp[i][j][k][l] != 0)
		return dp[i][j][k][l];
	
	// �߽��ʼ��һ��, Խ��Ӧ�ò��ᷢ��, ���Ǳ������.
	if (i >= 0 && i < m && j >= 0 && j < n
		&& k >= 0 && k < m && l >= 0 && l < n) {
		//if (abs(i - k) == 1) {
		//	// ��������, ����������:
		//	return max(max(dp[i][j][k][l], dfs(i - 1, j, k - 1, l)),
		//		max(dfs(i, j - 1, k, l - 1), dfs(i, j - 1, k - 1, l)))
		//		+ arr[i][j] + arr[k][l];
		//}
		//else {
		//	// ������, ���ĸ�����
		//	// �ϲ������������չ����.
		//	int tmpMax = max(max(dp[i][j][k][l], dfs(i - 1, j, k - 1, l)),
		//		max(dfs(i, j - 1, k, l - 1), dfs(i, j - 1, k - 1, l)));
		//	return max(tmpMax, dfs(i - 1, j, k, l - 1)) + arr[i][j] + arr[k][l];
		//}

		// �����һ���ظ����ж�
		int tmpMax = max(max(dp[i][j][k][l], dfs(i - 1, j, k - 1, l)),
			max(dfs(i, j - 1, k, l - 1), dfs(i, j - 1, k - 1, l)));
		return max(tmpMax, dfs(i - 1, j, k, l - 1)) + arr[i][j] + arr[k][l];
	}

	return 0;
}

int main() {
	in(m), in(n);

	For(i, 0, m) {
		For(j, 0, n) {
			in(arr[i][j]);
		}
	}

	int minMN = min(m, n);
	For(i, 1, minMN) {
		dp[i][0][0][i] = dp[i - 1][0][0][i - 1] + arr[i][0] + arr[0][i];
	}
	printf("%d\n", dfs(m - 1, n - 2, m - 2, n - 1) + arr[m - 1][n - 1]);

	return 0;
}