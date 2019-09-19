#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7ffffff;
//int gra[2600][2600];

struct Data {
	int id, wei;
	Data() { }
	Data(int i, int w) : id(i), wei(w) { }
	bool operator <(Data a) {
		return this->wei < a.wei;
	}
};

struct Node {
	int id, dis;
	Node(int i, int d) : id(i), dis(d) { }
	bool operator <(const Node a) const {
		return this->dis > a.dis;
	}
};
vector<Data> gra[2600];
int used[2600] = { 0 };
// ע�Ⱑ, ����һ��dis�𰸾�������, ����Ҫ��ʼ��ΪINF!
int dis[2600];

int main() {
	freopen("testdata.in", "r", stdin);
	//for (int i = 0; i < 2600; ++i) {
	//	for (int k = 0; k < 2600; ++k) {
	//		gra[i][k] = INF;
	//	}
	//}

	for (int i = 0; i < 2600; ++i) {
		dis[i] = INF;
	}
	int t, c, ts, te;
	cin >> t >> c >> ts >> te;

	for (int i = 1; i <= c; ++i) {
		int a, b, w;
		cin >> a >> b >> w;

		gra[a].push_back(Data(b, w));
		gra[b].push_back(Data(a, w));
	}


	// ��ס��, �տ�ʼһ��Ҫ:
	dis[ts] = 0;
	priority_queue<Node> q;
	q.push(Node(ts, 0));
	// used[ts] = 1;

	while (!q.empty()) {
		Node tmp = q.top();
		q.pop();


		/////// woc!!! ԭ���ⶼ������! �ж�used[] �����ó�����֮��, �ó�������Ѿ����ʹ�, ��continue, û���ʹ������ϼ�¼����.
		// ��Ҳ��Ψһ��һ���ط�.
		if (used[tmp.id] == 1)
			continue;
		used[tmp.id] = 1;


		for (int i = 0; i < gra[tmp.id].size(); ++i) {
			Data& nei = gra[tmp.id][i];
			if (dis[nei.id] > dis[tmp.id] + nei.wei) {
				dis[nei.id] = dis[tmp.id] + nei.wei;
				if (!used[nei.id]) {
					// cout << "����: " << nei.id << "juli: " << dis[nei.id] << endl;
					q.push(Node(nei.id, dis[nei.id]));
					// used[nei.id] = 1;
				}
			}
		}
	}

	cout << dis[te] << endl;



	// Floyd ����Ȼ��T��һЩ���.

	//for (int i = 1; i <= c; ++i) {
	//	int a, b, w;
	//	cin >> a >> b >> w;
	//	
	//	gra[a][b] = w;
	//	gra[b][a] = w;
	//}

	//for (int k = 1; k <= t; ++k) {
	//	for (int i = 1; i <= t; ++i) {
	//		for (int j = 1; j <= t; ++j) {
	//			if (i != j && i != k && j != k && gra[i][j] > gra[i][k] + gra[k][j])
	//				gra[i][j] = gra[i][k] + gra[k][j];
	//		}
	//	}
	//}

	//cout << gra[ts][te] << endl;


	return 0;
}