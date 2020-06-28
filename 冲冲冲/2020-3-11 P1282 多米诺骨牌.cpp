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

int n;
int dp[1010][6010];
int arr[1010], brr[1010];
int sum;

int main() {
	in(n);
	For(i, 1, n + 1) {
		in(arr[i]), in(brr[i]);
		sum += (arr[i] + brr[i]);
	}

	// �� min ��dp��ʼ��:
	For(i, 0, 1010) {
		For(j, 0, 6010)
			dp[i][j] = INF;
	}

	dp[1][arr[1]] = 0, dp[1][brr[1]] = 1;
	For(i, 2, n + 1) {
		// �������for�кܶ�����, ���ǰ�2^n�ֿ��ܵĺͶ�������Ȼ����Ծ�ر���Ҳ�ǲ���ʵ��.
		For(j, 0, 6010) {
			if (j >= arr[i])
				dp[i][j] = min(dp[i - 1][j - arr[i]], dp[i][j]); // û�л�
			if (j >= brr[i])
				dp[i][j] = min(dp[i - 1][j - brr[i]] + 1, dp[i][j]); // ����
		}
	}

	int res = INF, curSub = INF;
	For(i, 1, 6010) {
		if (dp[n][i] != INF) {
			if (abs(i - (sum - i)) <= curSub) {
				curSub = abs(i - (sum - i));
				res = min(res, dp[n][i]);
			}
		}
	}

	printf("%d\n", res);

	return 0;
}