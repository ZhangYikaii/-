#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010, MAXM = 500010;


// ��ʽǰ����, ������!
struct edge {
	int to, w, next;
};

edge e[MAXM];
int head[MAXN], dis[MAXN], cnt;
bool vis[MAXN];
int n, m, s;

inline void add(int u, int v, int w) {
	++cnt;
	e[cnt].w = w;
	e[cnt].to = v;
	e[cnt].next = head[u]; // ע�����!
	head[u] = cnt;
}

// ��ΪҪ�ڶ�������ȽϾ����С, ����һ��Ҫ����.
// �����������±�, �е�ǰ�������ľ���.
struct node {
	int dis;
	int ind;
	node() { }
	node(int d, int p) : dis(d), ind(p) { }

	bool operator <(const node& x) const {
		return x.dis < dis;
	}
};


priority_queue<node> q;
inline void dijkstra() {
	dis[s] = 0;
	// s �㷨��ʼ�� ����ų���ȫ�ֱ���.
	q.push(node(0, s));					/////////////////

	while (!q.empty()) {
		node tmp = q.top();				//////////////////
		q.pop();

		int x = tmp.ind, d = tmp.dis;

		// ���x�Ѿ������ʹ�. ����Ѿ����ʹ�, �ͼ���
		if (vis[x])
			continue;
		vis[x] = 1;
		// ���ʵļ�¼�����ó�����׼�������ʱ��.

		// ����i���ھ�.
		for (int i = head[x]; i; i = e[i].next) {
			int nei = e[i].to;
			// ��������ǳ��ؼ�.
			// �����ڶ����ó��������֮��������ĸ���.
			
			// ͨ�� x ���� nei �ľ����С, �͸���
			// ���Ҫ�������ͬ·�������·����, ��Ҫ���� ���ʱ��ļ�¼, ���PAT���·�����·��ͨ�����·.cpp

			// if (dis[nei] > dis[x] + e[i].w)
			// ע��ֻ�и��� ����û�б����ʹ����ֽڵ�ſ������.
			if (dis[nei] > dis[x] + e[i].w) {
				dis[nei] = dis[x] + e[i].w;
				// ���neiû�б����ʹ�, �����
				// �����ÿһ�����, �ھӽڵ��d[]���
				if (!vis[nei]) {
					q.push(node(dis[nei], nei));				///////////////
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= n; ++i)dis[i] = 0x7fffffff;
	for (register int i = 0; i < m; ++i) {
		register int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		add(u, v, d); // ����ͼ, ��һ��.
	}
	dijkstra();
	for (int i = 1; i <= n; i++)
		printf("%d ", dis[i]);

	return 0;
}



