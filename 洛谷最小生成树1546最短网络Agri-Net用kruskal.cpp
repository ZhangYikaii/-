// ���鼯 + ���� ���鼯ģ�岻Ҫ����, kruskal ����Ҫ��ϰ!
// ���������� kruskal
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

const int MAX_NODE = 110, MAX_EDGE = 10000;

int pre[MAX_NODE], nodeNum[MAX_NODE]; // pre[a] == b��ʾa�ĸ�����b, nodeNum[i] == j��ʾ���ڵ�Ϊi��������j���ڵ�

struct Edge {
	int u; //�����ӵ�һ��������
	int v; //��������һ��������
	int w; //�ߵ�Ȩֵ

	Edge() : u(-1), v(-1), w(-1) { }
};

// ����sortҪ�õĺ��� ��д
bool cmp(const Edge &a, const Edge &b) {
	return a.w < b.w;
}

void init(int n) {
	// ����ʱ����ֹ��ʱ�� �Լ����Լ��ĸ���
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
		nodeNum[i] = 1;
	}
}

// ���Ƿǵݹ���Ҹ���
// findFather(a)�ķ���ֵ����a������ �����Ǹ�
int findFather(int x) {
	int t = x;

	// ͨ�����ϵ��Ҹ��ײ����������ҵ�x�����ȣ����������Լ����Լ�������
	while (x != pre[x])
		x = pre[x];
	// �����Ѿ��ҵ����ϵ����Ⱦ��� x ��

	// �Ż� ������̫�� ��ѹ���Ż���
	if (t != x) {
		int tFa = pre[t];  // �ݴ�t�ĸ��� 
		pre[t] = x;        // ֱ��ָ����������
		t = tFa;           // ��һ���μ���û��ָ���������ȵ� һֱ����������
	}

	return x;
}

void Union(int a, int b) {
	a = findFather(a);
	b = findFather(b);

	// a, b������һ������ô�Ͳ���Ҫ������
	if (a == b)
		return;

	// ע�����������ʱ������ѭһ������
	// a��b������b�ӵ�a����
	if (nodeNum[a] >= nodeNum[b]) {
		pre[b] = a;
		nodeNum[a] += nodeNum[b];
	}
	else {
		pre[a] = b;
		nodeNum[b] += nodeNum[a];
	}
}

void Kruskal(const Edge edges[], int n, int m) {
	int cost = 0, e1 = 0, e2 = 0;
	init(n);
	// ��Ȩֵ��С����
	for (int i = 0; i < m; i++) {
		e1 = findFather(edges[i].u);
		e2 = findFather(edges[i].v);
		// ����ǰ�����ӵ���������ڲ�ͬ�����У�ѡȡ�ñ߲��ϲ�����������
		if (e1 != e2) {
			cost += edges[i].w;				// ��С��������Ȩֵ����ȥ
			Union(edges[i].u, edges[i].v);	 // �ϲ���ǰ�����ӵ������������ڼ���
		}
	}

	cout << cost << endl;
}

// �����Ż�
int getin() {
	int x = 0;
	char ch = getchar();
	while (ch<'0' || ch>'9')
		ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x;
}

Edge edges[MAX_EDGE];

int main() {
	int n, tmp, cnt = 0;
	n = getin();

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			tmp = getin();
			if (j < i) {
				edges[++cnt].u = i;
				edges[cnt].v = j;
				edges[cnt].w = tmp;
			}
		}
	}

	sort(edges + 1, edges + cnt + 1, cmp); //����֮�󣬿����Ա�Ȩֵ��С�����˳��ѡȡ��
	Kruskal(edges, n, cnt);

	return 0;
}

/*

��Ŀ����
ũ��Լ����ѡΪ��������򳤣�������һ����ѡ��ŵ���������Ͻ����������������ӵ����е�ũ������Ȼ������Ҫ��İ�����

��Ŀ����
Լ���Ѿ�������ũ��������һ�����ٵ�������·�������������·���������ũ����Ϊ������С�����ѣ�����������̵Ĺ���ȥ�������е�ũ����

�㽫�õ�һ�ݸ�ũ��֮�����ӷ��õ��б�������ҳ�����������ũ�������ù�����̵ķ�����ÿ����ũ����ľ��벻�ᳬ��100000

���������ʽ
�����ʽ��
��һ�У� ũ���ĸ�����N��3<=N<=100����

�ڶ���..��β: �������а�����һ��N*N�ľ���,��ʾÿ��ũ��֮��ľ��롣�����ϣ�������N�У�ÿ����N���ÿո�ָ�������ɣ�ʵ���ϣ�����������80���ַ�����ˣ�ĳЩ�л��������һЩ�С���Ȼ���Խ��߽�����0����Ϊ��������·�ӵ�i��ũ����������

�����ʽ��
ֻ��һ����������а������ӵ�ÿ��ũ���Ĺ��˵���С���ȡ�

�����������
��������#1��
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
�������#1��
28

*/
