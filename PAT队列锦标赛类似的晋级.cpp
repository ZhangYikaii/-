#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int weight, inda, rank, indb;
};


// �������ע�������ӷ��������, ��һ��һ�������Ŀ����ö�����.

// ������Ŀ������˳�����.
bool cmp1(node a, node b) {
	return a.indb < b.indb;
}
int main() {
	int n, g, num;
	scanf("%d%d", &n, &g);

	// ������һ������vector.
	vector<int> v(n);
	vector<node> w(n);

	// v[i] �ǳ�ʼweight
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	// inda ������˳���µ�, indb �ǳ�ʼ�����˳��.
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		w[i].weight = v[num];		// tmd ˭֪��ԭ�������Ȩ�ز��Ƕ�Ӧ˳���Ȩ��........
		w[i].inda = i;
		w[i].indb = num;
	}

	// �������
	queue<node> q;
	for (int i = 0; i < n; i++)
		q.push(w[i]);

	// ��ջ����ʱ
	while (!q.empty()) {
		int sz = q.size();
		// ����Ҫ��Ҫ�˳�
		if (sz == 1) {
			node temp = q.front();
			w[temp.inda].rank = 1;
			break;
		}
		int group = sz / g;
		if (sz % g != 0)
			group += 1;
		node maxnode;
		int maxn = -1, cnt = 0;
		// ������������.
		for (int i = 0; i < sz; i++) {
			node temp = q.front();
			// ��Ϊ���в��Ǵ�������, ����Ҫ��¼һ��indaҲ����ԭ�����������index����ԭ������Ϣ.
			w[temp.inda].rank = group + 1;
			q.pop();
			cnt++;
			if (temp.weight > maxn) {
				maxn = temp.weight;
				maxnode = temp;
			}

			// ������ȡһ�������������Ǹ���. ע�� || i = sz - 1.
			// �ͰѴ˴ν����ķ������.
			if (cnt == g || i == sz - 1) {
				cnt = 0;
				maxn = -1;
				q.push(maxnode);
			}
		}
	}

	sort(w.begin(), w.end(), cmp1);
	for (int i = 0; i < n; i++) {
		if (i != 0)
			printf(" ");
		printf("%d", w[i].rank);
	}
	return 0;
}

/*



*/