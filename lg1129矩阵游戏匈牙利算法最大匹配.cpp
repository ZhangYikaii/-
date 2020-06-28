
// �����Ǵ�, ע�����ת����ƥ������.

#include<cstdio>
#include<cstring>
using namespace std;
const int maxN = 500;
int n, ans, t;

// ��һ��match����.
int matched[maxN + 1];

bool G[maxN + 1][maxN + 1], vis[maxN + 1];
// A �����, B ���ұ�, ��A��B����(ƥ��)

// Ϊ A[x] ���ĸ� B[i] ������ƥ��.
bool dfs(int x) {
	// A ȥƥ��(��B��������) B
	// ɨ�����ÿһ�� B:
	for (int i = 1; i <= n; i++) {
		// ���ܿ���.
		if (G[x][i] && !vis[i]) {
			vis[i] = true;
			// û��ƥ������߿����ڳ�λ����.
			if (!matched[i] || dfs(matched[i])) {
				matched[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(matched, 0, sizeof(matched));
		memset(G, false, sizeof(G));
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) scanf("%d", &G[i][j]);
		for (int i = 1; i <= n; i++) {
			memset(vis, false, sizeof(vis));
			ans += dfs(i);				// Ϊÿһ��i��ƥ��.
		}
		if (ans == n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}