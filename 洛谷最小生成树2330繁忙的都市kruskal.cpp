#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ���鼯ģ�廹Ҫ�ٱ���
int m, n, u, v, c, maxn, k;
int fa[301];

int find(int x) {
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}

void unionn(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) fa[fx] = fy;
}

struct Node {
	int from, to, v;
	bool operator < (const Node &b) const {
		return v < b.v;
	}
}a[51000];

// ������Ŀ, ��С������ + ���Ȩֵ.
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> c;
		a[i] = Node{ u, v, c };
	}

	// init
	for (int i = 1; i <= n; i++) 
		fa[i] = i;

	sort(a + 1, a + m + 1);
	// ֱ��sort

	for (int i = 1; i <= m; i++) {
		// kruskal����: �����, �������ͬһ������, union����, �����ͬһ��������, ����.
		if (find(fa[a[i].from]) != find(fa[a[i].to])) {
			unionn(a[i].from, a[i].to);
			maxn = a[i].v;					// ��С������������Ȩֵ
			k++;
		}
		if (k == n - 1) break;
	}

	cout << n - 1 << " " << maxn;

	return 0;
}