#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

#define in(x) x=read()

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

#define maxn 10010

ll mergeResTmp[maxn] = { 0 }, iResTmp = 0;			// ��ʱ��Ź鲢���.
ll arr[maxn], brr[maxn];
void MergeSort(ll l, ll r, ll a[], ll &ans) {
	// ��ֹ����
	if (l >= r)
		return;

	ll mid = (l + r) / 2;

	// �ȵݹ�!
	MergeSort(l, mid, a, ans);
	MergeSort(mid + 1, r, a, ans);

	// ��ʼ�鲢
	//for (ll i = l; i <= r; ++i)
	//	prllf("%d ", a[i]);
	//prllf("\n");

	ll i = l, j = mid + 1;
	iResTmp = l - 1;						// ע���������м���һ���ִ���!
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) {
			mergeResTmp[++iResTmp] = a[i++];
		}
		else {
			mergeResTmp[++iResTmp] = a[j++];
			ans += mid - i + 1;				// ע������ ans �Ĵ���, �鲢�ڶ�����ʱ��, ǰ���ȫ������С, ���������
		}
	}

	// ʣ������Ū��ȥ
	while (i <= mid)
		mergeResTmp[++iResTmp] = a[i++];
	while (j <= r)
		mergeResTmp[++iResTmp] = a[j++];

	// �м���һ���ַŻ�ȥ, �����Ǵ� l ��ʼ�� r.
	for (ll t = l; t <= r; ++t)
		a[t] = mergeResTmp[t];
}

ll MyMin(ll a, ll b) {
	return a > b ? b : a;
}
ll n;
ll ans1 = 0, ans2 = 0, as1, as2;

int main() {
	ios::sync_with_stdio(false);

	int aaa[60] = { 0 };
	aaa[0] = 2;

	for (int i = 1; i < 20; ++i) {
		int sum = 0;
		for (int k = 1; k <= i / 2; ++k) {
			sum += aaa[k] * aaa[i - k];
		}
		aaa[i] = (4 - sum) / 2;
	}

	for (int i = 0; i < 20; ++i)
		cout << aaa[i] << " ";
	cout << endl;

	return 0;
}

/*


*/