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
#include <queue>

using namespace std;
#define ll long long
const int maxn = 1005;
int n, m, len;
ll a[maxn], b[maxn], c[maxn*maxn];

//ll div(ll limit) {
//	// ���ֲ���Ҫ�ᱳ, ��ȻҪ���ܾ�.
//	ll id = 0;
//	int l = 1, r = len;
//	// ������ <= 
//	while (l <= r) {
//		int mid = (l + r) / 2;
//
//		// ���ܿ��Ե�ʱ��, ֱ��id = mid ��¼��.
//		if (c[mid] <= limit)
//			id = mid, l = mid + 1;
//		else
//			r = mid + 1;
//	}
//
//	return id;
//}
ll work(ll limit)
{
	ll id = 0;
	int l = 1, r = len;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (c[mid] <= limit)
			id = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	return id;
}

// a[] �����жεĺ�
// ��ʵ��Ŀ�� ���Ǹ� a * b�����, ��ʵ��������a, b �����Ӷεĺ�Ȼ��������Ĵ�.

ll cal(ll limit)
{
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			// ��Ϊ���� x * b ��ĳһ�Ӷκ� == limit ������ʵ��Ŀ���Ǹ��������.
			ll x = a[i] - a[j - 1];
			ans += work(limit / x);
		}
	}
	return ans;
}
int main()
{
	ll L, R;
	scanf("%d%d%lld%lld", &n, &m, &L, &R);
	for (int i = 1, x; i <= n; i++)
	{
		scanf("%d", &x);
		a[i] = a[i - 1] + x;
	}
	for (int i = 1, x; i <= m; i++)
	{
		scanf("%d", &x);
		b[i] = b[i - 1] + x;
		for (int j = 1; j <= i; j++)
			c[++len] = b[i] - b[j - 1];
	}

	// c[] ����b�������Ӷεĺ�.
	sort(c + 1, c + len + 1);
	printf("%lld\n", cal(R) - cal(L - 1));
	return 0;
}