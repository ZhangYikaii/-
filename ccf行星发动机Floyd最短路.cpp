//#include <bits/stdc++.h>
//using namespace std;
//
//int wei[10010];
//int gra[10010][10010];
//
//#define For(i, s, e) for(int i = s; i <= e; ++i)
//#define INF 0x7ffffff
//
//int main() {
//	int n, m, k;
//	int a, b, w;
//	cin >> n >> m >> k;
//
//	for (int i = 1; i <= n; ++i) {
//		cin >> wei[i];
//	}
//
//	For(i, 1, n) {
//		For(t, 1, n) {
//			gra[i][t] = INF;
//		}
//	}
//
//	for (int i = 1; i <= m; ++i) {
//		cin >> a >> b >> w;
//		if (a != b) {
//			gra[a][b] = w;
//			gra[b][a] = w;
//		}
//	}
//
//	for (int t = 1; t <= n; ++t) {
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= n; ++j) {
//				if (t != i && i != j && t != j && gra[i][j] > gra[i][t] + gra[t][j]) {
//					gra[i][j] = gra[i][t] + gra[t][j];
//				}
//			}
//		}
//	}
//
//	For(i, 1, n) {
//		For(j, 1, n) {
//			if (wei[j] == 0)
//				gra[i][j] = INF;
//		}
//		sort(&gra[i][1], &gra[i][1] + n);
//		int sum = 0, endd = k;
//		if (wei[i] == 1)
//			--endd;
//		for (int j = 1; j <= endd; ++j) {
//			if (gra[i][j] == INF)
//				break;
//			
//			sum += gra[i][j];
//		}
//		cout << sum << endl;
//	}
//
//	return 0;
//}
//
///*
//
//7 6 2
//1 0 1 0 1 1 0
//1 4 1
//1 2 3
//2 4 4
//2 3 5
//2 5 7
//6 7 5
//
//
//*/


#include <bits/stdc++.h>
using namespace std;
struct E
{
	int v, w;
	E() { }
	E(int vv, int ww) : v(vv), w(ww) { }
	bool operator < (const E& b)const {
		return w > b.w;
	}
};
int n, m, k;
int ff[10000 + 10];
priority_queue<int, vector<int>, greater<int> > d[10000];
vector<E> edge[10000];


void dijkstra(int k)
{
	priority_queue<E> Q;
	int dis[10000];

	// ��ס��, disȫ��Ϊ INF, �����Ϊ 0, �������.
	// �����ȶ��в��յ�ʱ��, �ó�, ��Ϊtmp, ���used[tmp], continue;
	// ����tmp�������ھ�nei, ������ó��������ľ������һ�ߵľ��� < ֱ�ӵ�nei��dis, �͸���, ���Ѹ��µĽ��id�;���������.
	for (int i = 0; i < n; i++)
		dis[i] = 0x3f3f3f3f;
	dis[k] = 0;
	Q.push(E(k, 0));
	while (!Q.empty())
	{
		E t = Q.top();
		Q.pop();
		if (t.w != dis[t.v])
			continue;

		d[t.v].push(t.w);			// d�Լ�����һ����, ����t.v����������С����.

		// Dijkstra �����ȶ��������ó�����ʱ����Ѿ���: ��ǰ�㵽�ó�������������С������t.w
		// ������ʵ��������. ��Ϊ�㵽�ҵ����·��, Ҳһ�����ҵ�������·��, bidirectional.
		int m = edge[t.v].size();
		int u, w;
		for (int i = 0; i < m; i++)
		{
			u = edge[t.v][i].v;
			w = edge[t.v][i].w;
			if (dis[u] > dis[t.v] + w)
				dis[u] = dis[t.v] + w,
				Q.push(E(u, dis[u]));
		}
	}
}

// ��ʹ�ǲ���(�����)��֮������·, Ҳ��ҪFloyd, ��DIjkstra
// ��ĿҪ�������һ�ݵ㵽���k�����Ƿ������ݵ�����·֮�ͣ��������ǿ�����k�����Ƿ������ݵ�����·���԰�! ��k�����Ƿ����������·�����Ϳ�����.


int main()
{
	scanf("%d%d%d", &n, &m, &k);
	int num = 0, x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x)
			ff[num++] = i;
	}
	int u, v, w;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		u--; v--;
		edge[u].push_back(E(v, w));
		edge[v].push_back(E(u, w));
	}
	for (int i = 0; i < num; i++)
		dijkstra(ff[i]);
	long long ans;


	for (int i = 0; i < n; i++) {
		int cnt = k;
		ans = 0;
		while (!d[i].empty() && cnt--) {
			ans += d[i].top();
			d[i].pop();
		}
		printf("%lld\n", ans);
	}

	return 0;
}