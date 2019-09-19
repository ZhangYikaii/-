#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <assert.h>
#include <istream>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(ll i = s; i < n; ++i)

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
ll n;

ll biao[5] = { 0, 2, 6, 20 };
ll mod = 1000000007;

ll c[1010][1010];
void Init() {
	c[0][0] = 1;
	c[1][0] = 1;
	c[1][1] = 1;
	c[0][1] = 1;
	for (int i = 2; i < 1008; ++i) {
		c[i][0] = 1;
		for (int k = 1; k <= i; ++k) {
			c[i][k] = (c[i - 1][k] + c[i - 1][k - 1]) % mod;
		}
	}
}

ll QuickPower(ll a, ll b)  {
	ll ans = 1, base = a;		// ansΪ�𰸣�baseΪa^(2^n)
	while (b > 0) {
		// ��һλ�� 1 => �˵� ans ��
		if (b & 1)				// &��λ���㣬b&1��ʾb�ڶ����������һλ�ǲ���1������ǣ�
			ans = (ans * base) % mod;		// ��ans���϶�Ӧ��a^(2^n)

		base = (base * base) % mod;			// base�Գˣ���a^(2^n)���a^(2^(n+1)), ��סbase = a^(�����Ʊ�ʾ��ÿһλֵ) ʱ��׼���˵�ans��, ֻҪ��һλ�� 1 ����
		b >>= 1;				// λ���㣬b����һλ����101���10�������ұߵ�1�Ƶ��ˣ���10010���1001������b�ڶ����������һλ�Ǹոյĵ����ڶ�λ���������b & 1ʳ�ø���
	}
	return ans;
}

int main() {
	Init();
	while (true) {
		in(n);
		if (n == 0)
			break;

		if (n <= 3) {
			printf("%lld\n", biao[n]);
			continue;
		}

		ll base = QuickPower(4, n);
		ll sub = 0;
		for (int i = 1; i < n; i += 2) {
			sub = (((sub + c[n][i]) % mod) * (0x1 << (n - i))) % mod;
		}

		sub = (2 * sub) % mod;



		// printf("%lld\n", (base + mod - 2 * sub) % mod);
	}
	
	return 0;
}