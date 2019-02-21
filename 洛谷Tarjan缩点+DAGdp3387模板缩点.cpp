#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

const int maxn = 10000 + 15;
int n, m, sum, tim, top, s;
int p[maxn], head[maxn], sd[maxn], dfn[maxn], low[maxn]; //  DFN(u)Ϊ�ڵ�u������������ʱ�Ĵ�����(ʱ���)��Low(u)Ϊu��u�������ܹ�׷�ݵ��������ջ�нڵ�Ĵ���� 
int stac[maxn], vis[maxn]; // ջֻΪ�˱�ʾ��ʱ�Ƿ��и��ӹ�ϵ 
int h[maxn], in[maxn], dist[maxn];

// from ��Դ�Ե�, to ��ָ���
struct EDGE {
	int to; 
	int next; 
	int from;
}edge[maxn * 10], ed[maxn * 10];

void add(int x, int y) {
	edge[++sum].next = head[x];
	edge[sum].from = x;
	edge[sum].to = y;
	head[x] = sum;
}
void tarjan(int x) {
	low[x] = dfn[x] = ++tim;
	stac[++top] = x;			// ����ջ
	vis[x] = 1;
	// ������ǰ����Χ�ĵ�
	for (int i = head[x]; i; i = edge[i].next) {
		int v = edge[i].to;
		// ���û�о���
		if (!dfn[v]) {
			// cout << v << " ";
			tarjan(v);			// dfs
			low[x] = min(low[x], low[v]);	// low[x]ʼ��ȡ�Լ�����low[v]�Ľ�Сֵ����ôʲô�����ʹ��dfn[u]��"����"��low[u]����أ�������u����������һ����
		}
		// ���������, �͸���low[], ������ǹ��ɻ���!!!
		else if (vis[v]) {
			// cout << v << "d ";
			low[x] = min(low[x], low[v]);
		}
		//else {
		//	// printf("okkkk\n");
		//	// �����֧����, dfs������һ���Ѿ��߹��Ľ��, ���ǻ����Ѿ�������ջ��, ������������֮��������һ����, ������Ȼ�����ɻ�
		//}
	}
	// cout << endl;

	// ����, ��x�Ļ�����Ȩֵ���� p[x]
	if (dfn[x] == low[x]) {
		int y;
		// ��ջ����, ջ����������, ����֪����xΪ����һ·����dfs��ʲôԪ��
		while (y = stac[top--]) {
			sd[y] = x;			// Ϊ�������������� if (sd[i] == i... ���ҵ�ÿ��������ͷ���Ǹ���(Ҳ��Ϊ���ҵ��Ե�p[]), ��ʾ��������»���
			vis[y] = 0;			// Ϊ��һ����׼��, ��һ���� x ��ʼ��ȫ���������Ϊ��
			if (x == y)
				break;
			p[x] += p[y];
		}
	}
}
int topo() {
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		// ���Ϊ0�������
		if (sd[i] == i && !in[i]) {
			q.push(i);
			dist[i] = p[i];
		}
	}
	// k �Ӷ��ﲻ���ó���, k �����о�����������!!!
	while (!q.empty()) {
		int k = q.front();
		q.pop();

		for (int i = h[k]; i; i = ed[i].next) {
			int v = ed[i].to;
			dist[v] = max(dist[v], dist[k] + p[v]);		// ��ͼ��dp!!! k�ǵ�ǰ��(��), v���ڽӵĵ�(��), ��������ѡ��������һ����(��) // ע�������dpΪ���޺�Ч��, һ��Ҫ��������, ���ǴӶ��ﲻ���ó���!!!
			in[v]--;			// ��Χ����ȼ�һ
			// ������Ϊ0��, ���
			if (in[v] == 0) 
				q.push(v);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dist[i]);
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++) {
		// ��������û�о���
		if (!dfn[i])
			tarjan(i);
	}

	for (int k = 1; k <= m; k++) {
		int x = sd[edge[k].from], y = sd[edge[k].to];
		// ����ͼ, ��� x == y ����tarjan֮������һ�����������
		if (x != y) {
			// ������С��add()
			ed[++s].next = h[x];
			ed[s].to = y;
			ed[s].from = x;
			h[x] = s;			// ��ͼ head[]
			in[y]++;			// Ϊ���������õ�, �������, ���˳����
		}
	}

	printf("%d", topo());
	return 0;
}

/*
��Ŀ����
����+DP

��Ŀ����
����һ��n����m��������ͼ��ÿ������һ��Ȩֵ����һ��·����ʹ·�������ĵ�Ȩֵ֮�������ֻ��Ҫ������Ȩֵ�͡�

�����ξ���һ���߻���һ���㣬���ǣ��ظ������ĵ㣬Ȩֵֻ����һ�Ρ�

���������ʽ
�����ʽ��
��һ�У�n,m

�ڶ��У�n�����������δ����Ȩ

������m+2�У�ÿ����������u,v����ʾu->v��һ�������

�����ʽ��
��һ�У����ĵ�Ȩ֮�͡�

�����������
��������#1��
2 2
1 1
1 2
2 1
�������#1��
2



����:
10 20
970 369 910 889 470 106 658 659 916 964
3 2
3 6
3 4
9 5
8 3
5 8
9 1
9 7
9 8
7 5
3 7
7 8
1 7
10 2
1 10
4 8
2 6
3 1
3 5
8 5

���:
6911

// md�ʼ������ͼ:
6 8
1 1 1 1 1 1
1 2
1 3
4 1
3 4
2 4
3 5
4 6
5 6
*/