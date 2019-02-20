#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <functional>
#include <cstdlib>
using namespace std;

const int inf = 1000000010;// Ҫ��blood��
// e[] ���, Ȩֵw��ʾ����ʧ��Ѫ��.

struct node {
	int from, to, w, next;
}e[100010];// �����鿪˫��

int n, m, blood, tot = 0;
int cityCost[10010], cost[10010];
int head[10010], d[10010];
bool vis[10010];

struct cmp {
	bool operator()(int a, int b) {
		return d[a] > d[b];
	}
};
// ע�����cmp�Ĵ���
priority_queue<int, vector<int>, cmp> q;
// priority_queue<int, vector<int>, greater<int> >q;	// С����

void addedge(int x, int y, int t) {
	tot++;
	e[tot].from = x;
	e[tot].to = y;
	e[tot].w = t;
	e[tot].next = head[x];
	head[x] = tot;
	return;
}

bool check(int x) {
	if (x < cityCost[1] || x < cityCost[n])
		return false;
	int i;
	for (i = 1; i <= n; i++)
		d[i] = inf;
	for (i = 1; i <= n; i++) {
		if (cityCost[i] > x)
			vis[i] = true;
		else
			vis[i] = false;
	}

	// ���һ��dijkstral��д��, ���Ż�!!!
	d[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int now = q.top();
		q.pop();
		if (vis[now])
			continue;
		vis[now] = true;
		for (i = head[now]; i; i = e[i].next) {
			// d[] һֱ��ѡС��Ȩֵ ( ʧѪֵ ), ����жϿɲ�������
			// �����ǹؼ�:
			if (d[e[i].to] > e[i].w + d[now]) {
				d[e[i].to] = e[i].w + d[now];
				q.push(e[i].to);
			}
		}
	}
	if (d[n] <= blood)
		return true;
	else
		return false;
}

int main() {
	int i, j, k, t, ans, maxcost = 0;
	scanf("%d%d%d", &n, &m, &blood);
	for (i = 1; i <= n; i++){
		scanf("%d", &cityCost[i]);
		cost[i] = cityCost[i];
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &j, &k, &t);
		if (j == k)
			continue;
		addedge(j, k, t);
		addedge(k, j, t);
	}
	sort(cost + 1, cost + n + 1);		// ����cost������� �����Tһ����
	int l = 1, r = n, mid;

	// �����
	if (!check(cost[n])) {
		printf("AFK\n");
		return 0;
	}
	ans = cost[n];
	while (l <= r){
		mid = (l + r) >> 1;			// ����..
		if (check(cost[mid])) {
			ans = cost[mid];
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}
/*
ÿ������(���)��һ����·��, ÿһ��·��һ��Ѫ��, 

���������ʽ
�����ʽ��
��һ��3����������n��m��cityCost���ֱ��ʾ��n�����У�m����·������Ŷ��Ѫ��ΪcityCost��

��������n�У�ÿ��1����������fi����ʾ��������i����Ҫ����fiԪ��

�ٽ�������m�У�ÿ��3����������ai��bi��ci(1<=ai��bi<=n)����ʾ����ai�ͳ���bi֮����һ����·������ӳ���ai������bi�����ߴӳ���bi������ai������ʧci��Ѫ����

�����ʽ��
��һ����������ʾ����Ŷ��������һ�ε���Сֵ��ע���ǽ�������һ�η��õ���Сֵ.

������޷�����¸����꣬���AFK��

�����������
��������#1��
4 4 8
8
5
6
10
2 1 2
2 4 1
1 3 4
3 4 3

�������#1��
10

//��Ŀ��"�������������г���������һ����ȡ�ķ��õ���Сֵ�Ƕ��٣�"
//��仰����˼ʵ������ָ��
//         ����һ��·�� a �� ���庯��f(a)��
//         ����·���ϵ����е�Ȩ���ɵļ���s�� ����f(a)=max(s)
//         ������һ��ͼ������㵽�յ���ڶ���·��a1,a2,a3...
//         �������п��ܵ�·��a1,a2,a3...�������ڶ�Ӧ��f(a1),f(a2),f(a3)...
//         ��f(a1),f(a2),f(a3)...�е���Сֵ

*/