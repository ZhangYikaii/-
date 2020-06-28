// �������, �����Ǵ���:

#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

typedef long long LL;
const int maxn = 1e5 + 145;
const int mod = 998244353;
LL dp[maxn], sum, val;
char s[maxn];


int main() {
	int n; scanf("%d %s", &n, s + 1);
	val = 1;
	dp[0] = 1;
	
	for (int i = 1; i <= n; ++i) {
		sum = (sum + s[i] - '0') % 3;	// sum �ǵ�ǰǰ׺��.

		// ��� == 0 ���ǵ�ǰλ����ǰ���Ա�3����.
		if (sum == 0) {
			dp[i] = val % mod;
			val += dp[i];
			val %= mod;
			if (s[i] == '0') 
				val = ((val - dp[i - 1]) % mod + mod) % mod;
		}
	}
	cout << dp[n] << '\n';

	return 0;
}


