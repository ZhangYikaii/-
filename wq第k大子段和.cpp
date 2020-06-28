#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
// ��״����Ҫ��������!

const double pi = acos(-1.0);
double eps = 0.00000001;
vector<int> dis;
int tm[100010];
int sum[100010];
int tree[100010];
int n, k;
int lowbit(int x) {
	return x&-x;
}
void add(int x, int value) {
	for (int i = x; i <= n; i = i + lowbit(i)) {
		tree[i] += value;
	}
}
int get(int x) {
	int sum = 0;
	for (int i = x; i; i -= lowbit(i)) {
		sum += tree[i];
	}
	return sum;
}

// ����ٸ������еĺ��ϸ����mid
// ����״�����Ż�, �е�������Ե�, ������������˳���! ԭ��һ��, �Ǹ��ڼ��������ĳɵڼ�С�ľͿ�����
int check(int mid) {
	int i, ret = 0;
	memset(tree, 0, sizeof(tree));
	for (i = 1; i <= n; i++) {
		int x = sum[i] - mid;  // sum[i]-sum[j]>mid, => sum[i]-mid>sum[j],��Ӧs[j+1]...s[i]
		int it = lower_bound(dis.begin(), dis.end(), x) - dis.begin();	// �ҵ���ɢ�������ж�Ӧ>=x���±�, �������x�ڵڼ�С: �� �� it С.

		ret += get(it);		// ��� j �ĸ���, ���� x ǰ��� x С�ĸ���
		if (x > 0)			// ǰ׺�� = �Ӷκ͵����
			ret++;
		it = lower_bound(dis.begin(), dis.end(), sum[i]) - dis.begin();
		cout << it << "   -----" << endl;
		add(it + 1, 1);		// ����ڼ�С����״����
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);

	int i, j;
	cin >> n >> k;

	for (i = 1; i <= n; i++)
		cin >> tm[i];

	dis.clear();
	for (i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + tm[i];
		dis.push_back(sum[i]);
	}

	sort(dis.begin(), dis.end());

	dis.erase(unique(dis.begin(), dis.end()), dis.end());		//ȥ��

	int maxx = 100010;
	int minn = -100010;
	int l = minn, r = maxx;

	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid) >= k)
			l = mid + 1;
		else
			r = mid - 1, ans = mid;
	}

	/*sum[0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int k = i + 1; k <= n; ++k) {
			int tmp = sum[k] - sum[i];
			if (ans == tmp) {
				cout << i + 1 << " " << k << endl;
				return 0;
			}
		}
	}*/

	return 0;

}