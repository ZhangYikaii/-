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
#include <queue>

/*


*/

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)
	
typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, m, k;

int arr[805][805];
int dp[805][805][20][2];
ll mod = 1000000007;
// dp[i][j][h][l] ��ʾ�ڵ� (i,j)����ֵΪh��СA����uimȡҺ��ķ�����(0-->СA 1-->uim) 
// dp[i][j][h][1]+=(dp[i-1][j][(h-arr[i][j]+k)%k][0]) // uimȡ����ֵ�ͱ�С��
// dp[i][j][h][1]+=(dp[i][j-1][(h-arr[i][j]+k)%k][0])
// dp[i][j][h][0]+=(dp[i-1][j][(h+arr[i][j])%k][1]) // СAȡ
// dp[i][j][h][0]+=(dp[i][j-1][(h+arr[i][j])%k][1]) 

// zhuyi ע��һ�³�ʼ���ĺ���.
// ��ʼ����dp[i][j][arr[i][j]][0]=1;      // һ��ʼСA���Դ�����㿪ʼ 


// dp �� �е����������Ҫ����Ϣ����¼����, ��Ȼ��Щ�ǿ����Ƶ�.

int main() {
	ios::sync_with_stdio(false);
	in(n);
	in(m);
	in(k);

	FOR(i, 1, n + 1) {
		FOR(j, 1, m + 1) {
			in(arr[i][j]);
			dp[i][j][arr[i][j] % k][0] = 1;
		}
	}

	FOR(i, 1, n + 1) {
		FOR(j, 1, m + 1) {
			FOR(h, 0, k + 1) {
				dp[i][j][h][0] = (dp[i][j][h][0] + dp[i - 1][j][(h - arr[i][j] + k) % k][1]) % mod;
				dp[i][j][h][0] = (dp[i][j][h][0] + dp[i][j - 1][(h - arr[i][j] + k) % k][1]) % mod;
				dp[i][j][h][1] = (dp[i][j][h][1] + dp[i - 1][j][(h + arr[i][j]) % k][0]) % mod;
				dp[i][j][h][1] = (dp[i][j][h][1] + dp[i][j - 1][(h + arr[i][j]) % k][0]) % mod;
			}
		}
	}

	ll res = 0;
	FOR(i, 1, n + 1) {
		FOR(j, 1, m + 1) {
			res = (res + (ll)dp[i][j][0][1]) % mod;
		}
	}

	printf("%lld\n", res);


	

	return 0;
}
