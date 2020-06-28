#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <assert.h>
#include <istream>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n = 0;
// vector<vector<int> > vec;
vector<int> *nv, *p2SCC, *vec;
int *dfn, *low, *stac, *vis, *sd, *in, *tAns;
//int dfn[100010], low[100010], stac[100010], p[100010];
//int vis[100010] = { 0 }, sd[100010], in[100010];
int top = 0, tim = 0;
int idx = 0;


int MyMax(int a, int b) {
	return a > b ? b : a;
}


void tarjan(int x) {
	int v = 0;
	low[x] = dfn[x] = ++tim;

	stac[++top] = x;			// ����ջ
	vis[x] = 1;
	// ������ǰ����Χ�ĵ�
	int tn = vec[x].size();
	for (int i = 0; i < tn; ++i) {
		v = vec[x][i];
		// ���û�о���
		if (!dfn[v]) {
			// cout << v << " ";
			tarjan(v);			// dfs
			if (low[x] > low[v])
				low[x] = low[v];	// low[x]ʼ��ȡ�Լ�����low[v]�Ľ�Сֵ����ôʲô�����ʹ��dfn[u]��"����"��low[u]����أ�������u����������һ����
		}
		// ���������, �͸���low[], ������ǹ��ɻ���!!!
		else if (vis[v]) {
			// cout << v << "d ";
			if (low[x] > dfn[v])
				low[x] = dfn[v];
		}
		//else {
		//	// printf("okkkk\n");
		//	// �����֧����, dfs������һ���Ѿ��߹��Ľ��, ���ǻ����Ѿ�������ջ��, ������������֮��������һ����, ������Ȼ�����ɻ�
		//}
	}
	// cout << endl;

	// ����, ��x�Ļ�����Ȩֵ���� p[x]
	if (dfn[x] == low[x]) {
		// ��ջ����, ջ����������, ����֪����xΪ����һ·����dfs��ʲôԪ��
		do {
			if (top < 0)
				break;
			v = stac[top--];
			sd[v] = x;			// Ϊ�������������� if (sd[i] == i... ���ҵ�ÿ��������ͷ���Ǹ���(Ҳ��Ϊ���ҵ��Ե�p[]), ��ʾ��������»���
			vis[v] = 0;			// Ϊ��һ����׼��, ��һ���� x ��ʼ��ȫ���������Ϊ��
			p2SCC[x].push_back(v);
		} while (v != x);
		//while (y = stac[top--]) {
		//	sd[y] = x;			// Ϊ�������������� if (sd[i] == i... ���ҵ�ÿ��������ͷ���Ǹ���(Ҳ��Ϊ���ҵ��Ե�p[]), ��ʾ��������»���
		//	p2SCC[x].push_back(y);
		//	vis[y] = 0;			
		//	if (x == y)
		//		break;
		//}
	}
}


void dfsNew(int beg, map<int, bool> used, int &anstt) {
	int tmpn = nv[beg].size();
	FOR(i, 0, tmpn) {
		int &nei = nv[beg][i];
		if (used[nei] == false) {
			anstt += p2SCC[nei].size();

			used[nei] = true;
			dfsNew(nei, used, anstt);
		}
	}
}

/*

1
2
0
2 4
5
3


3
4
4
4


*/

int main() {
	// freopen("out.txt", "r", stdin);
	ios::sync_with_stdio(false);

	// freopen("outt.txt", "w", stdout); 

	/*
	

5 
4 3 
5 6 
6 
6 

*/

	int bef = 0;
	char buf[100010] = "";
	int tmp;
	// vec.resize(2099);
	vec = new vector<int>[20010];
	while (cin.getline(buf, 100010)) {
		bef = 0;
		int i;
		++n;
		if (buf[0] == '\0')
			continue;

		// cout << tmp << endl;
		for (i = 0; buf[i] != '\0';) {
			if (buf[i] == ' ') {
				++i;
				continue;
			}
			tmp = atoi(buf + i);
			// cout << tmp << endl;
			vec[n].push_back(tmp + 1);
			while (buf[i] != '\0' && buf[i] != ' ')
				++i;
		}

		memset(buf, 0, sizeof(buf));
	}

	/* *dfn, *low, *stac, *p, *vis, *sd, *in;*/

	dfn = new int[n + 10];
	low = new int[n + 10];
	stac = new int[n + 1010];
	vis = new int[n + 10];
	sd = new int[n + 10];
	in = new int[n + 10];

	nv = new vector<int>[n + 10];

	// int used[1000] = { 0 };
	tAns = new int[n + 10];
	memset(tAns, 0, sizeof(int)* (n + 10));

	memset(dfn, 0, sizeof(int)* (n + 10));
	memset(low, 0, sizeof(int)* (n + 10));
	memset(stac, 0, sizeof(int)* (n + 10));
	memset(vis, 0, sizeof(int)* (n + 10));
	memset(sd, 0, sizeof(int)* (n + 10));
	memset(in, 0, sizeof(int)* (n + 10));
	p2SCC = new vector<int>[n + 10];
	/*
	FOR(i, 0, n + 10) {
	dfn[i] = 0;
	low[i] = 0;
	stac[i] = 0;
	p[i] = 0;
	vis[i] = 0;
	sd[i] = 0;
	in[i] = 0;
	used[i] = 0;
	}
	*/

	for (int i = 1; i <= n; i++) {
		// ��������û�о���
		if (!dfn[i])
			tarjan(i);
	}

	// nv.resize(n + 1);
	FOR(i, 1, n + 1) {
		int x = sd[i], ttn = vec[i].size();
		FOR(k, 0, ttn) {
			int y = sd[vec[i][k]];
			// ����ͼ:
			if (x != y) {
				nv[x].push_back(y);
				++in[y];
			}
		}
	}

	vector<int> zv;
	for (int i = 1; i <= n; i++) {
		// ���Ϊ0��
		if (sd[i] == i && !in[i]) {
			zv.push_back(i);
		}
	}

	int cmi = 0;
	int curMax = -1, realMax = 0;
	int tnn = zv.size();
	vector<int> ress;
	vector<int> outRes;
	FOR(i, 0, tnn) {
		map<int, bool> used;
		dfsNew(zv[i], used, tAns[zv[i]]);
		// cout << "dian:   " << zv[i] << "  " << tAns[zv[i]] << endl;
		if (tAns[zv[i]] > curMax) {
			ress.clear();
			cmi = i;
			ress.push_back(i);
			curMax = tAns[zv[i]];
		}
		else if (tAns[zv[i]] == curMax) {
			ress.push_back(i);
		}
	}

	FOR(i, 0, ress.size()) {
		int &k = ress[i];
		outRes.insert(outRes.end(), p2SCC[zv[k]].begin(), p2SCC[zv[k]].end());
	}

	printf("I have read the rules about plagiarism punishment\n");


	printf("%d\n", curMax + p2SCC[zv[cmi]].size() - 1);
	//sort(p2SCC[zv[cmi]].begin(), p2SCC[zv[cmi]].end());
	//tnn = p2SCC[zv[cmi]].size();
	//FOR(i, 0, tnn) {
	//	printf("%d ", p2SCC[zv[cmi]][i] - 1);
	//}
	//printf("\n");


	sort(outRes.begin(), outRes.end());
	FOR(i, 0, outRes.size()) {
		printf("%d ", outRes[i] - 1);
	}


	return 0;
}




/*
1
2 3
0

5 3
6
4 7

*/

//
//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//#include <string.h>
//#include <vector>
//#include <set>
//#include <map>
//
//using namespace std;
//
//#define in(x) x=read()
//
//#define FOR(i, s, n) for(int i = s; i < n; ++i)
//
//typedef long long ll;
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//vector<vector<int> > vec;
//vector<vector<int> > p2SCC;
//int *dfn, *low, *vis, *stac;
////int dfn[100010], low[100010], stac[100010], p[100010];
////int vis[100010] = { 0 }, sd[100010], in[100010];
//int top = 0, tim = 0;
//
//int MyMax(int a, int b) {
//	return a > b ? b : a;
//}
//
//void tarjan(int x) {
//	low[x] = dfn[x] = ++tim;
//	stac[++top] = x;			// ����ջ
//	vis[x] = 1;
//	// ������ǰ����Χ�ĵ�
//	for (int i = 0; i < vec[x].size(); ++i) {
//		int v = vec[x][i];
//		// ���û�о���
//		if (!dfn[v]) {
//			// cout << v << " ";
//			tarjan(v);			// dfs
//			low[x] = min(low[x], low[v]);	// low[x]ʼ��ȡ�Լ�����low[v]�Ľ�Сֵ����ôʲô�����ʹ��dfn[u]��"����"��low[u]����أ�������u����������һ����
//		}
//		// ���������, �͸���low[], ������ǹ��ɻ���!!!
//		else if (vis[v]) {
//			// cout << v << "d ";
//			low[x] = min(low[x], dfn[v]);
//		}
//		//else {
//		//	// printf("okkkk\n");
//		//	// �����֧����, dfs������һ���Ѿ��߹��Ľ��, ���ǻ����Ѿ�������ջ��, ������������֮��������һ����, ������Ȼ�����ɻ�
//		//}
//	}
//	// cout << endl;
//
//	// ����, ��x�Ļ�����Ȩֵ���� p[x]
//	if (dfn[x] == low[x]) {
//		int y;
//		// ��ջ����, ջ����������, ����֪����xΪ����һ·����dfs��ʲôԪ��
//		while (y = stac[top--]) {
//			// sd[y] = x;			// Ϊ�������������� if (sd[i] == i... ���ҵ�ÿ��������ͷ���Ǹ���(Ҳ��Ϊ���ҵ��Ե�p[]), ��ʾ��������»���
//			p2SCC[x].push_back(y);
//			vis[y] = 0;			// Ϊ��һ����׼��, ��һ���� x ��ʼ��ȫ���������Ϊ��
//			if (x == y)
//				break;
//			// p[x] += p[y];
//		}
//	}
//}
//
//void dfsOld(int beg, int used[], int &tAns) {
//	FOR(i, 0, vec[beg].size()) {
//		int &nei = vec[beg][i];
//		if (used[nei] == false) {
//			++tAns;
//			// cout << nei << "   k   ";
//			used[nei] = true;
//			dfsOld(nei, used, tAns);
//			used[nei] = false;
//		}
//	}
//}
//
///*
//1
//2 3
//0
//4
//5
//3
//*/
//
//int main() {
//	freopen("out.txt", "r", stdin);
//	char buf[2048] = "";
//	vector<int> tmpp;
//	int tmp;
//	int n = 0, bef = 0;
//	vec.push_back(tmpp);
//	while (cin.getline(buf, 2048)) {
//		vec.push_back(tmpp);
//		bef = 0;
//		int i;
//		++n;
//		for (i = 0; buf[i] != '\0'; ++i) {
//			if (buf[i] == ' ') {
//				char tmpChar[11] = "";
//				strncpy(tmpChar, buf + bef, i - bef);
//				tmp = atoi(tmpChar);
//				bef = i + 1;
//				vec[n].push_back(tmp + 1);
//			}
//		}
//		char tmpChar[11] = "";
//		strncpy(tmpChar, buf + bef, i - bef);
//		tmp = atoi(tmpChar);
//		vec[n].push_back(tmp + 1);
//	}
//	/*
//	while (getline(cin, s)) {
//		++n;
//		vec.push_back(tmpp);
//
//		istringstream iss(s);
//		++beg;
//		flag = false;
//		while (iss >> tmp) {
//			flag = true;
//			vec[beg].push_back(tmp + 1);
//		}
//	}
//*/
//	/* *dfn, *low, *stac, *p, *vis, *sd, *in;*/
//
//	dfn = new int[n + 10];
//	low = new int[n + 10];
//	vis = new int[n + 10];
//	stac = new int[n + 10];
//
//	// int used[1000] = { 0 };
//	int *used;
//	used = new int[n + 10];
//
//	memset(dfn, 0, sizeof(int)* (n + 10));
//	memset(low, 0, sizeof(int)* (n + 10));
//	memset(vis, 0, sizeof(int)* (n + 10));
//	memset(used, 0, sizeof(int)* (n + 10));
//	memset(stac, 0, sizeof(int)* (n + 10));
//	/*
//	FOR(i, 0, n + 10) {
//	dfn[i] = 0;
//	low[i] = 0;
//	stac[i] = 0;
//	p[i] = 0;
//	vis[i] = 0;
//	sd[i] = 0;
//	in[i] = 0;
//	used[i] = 0;
//	}
//	*/
//
//	printf("I have read the rules about plagiarism punishment\n");
//
//
//	p2SCC.resize(n + 10);
//
//	int tres = 0, curMax = 0, curPoint = 0;
//	vector<int> resVec;
//	for (int i = 1; i <= n; i++) {
//		// ��������û�о���
//		if (!dfn[i]) {
//			tarjan(i);
//
//			tres = 0;
//			used[i] = true;
//			dfsOld(i, used, tres);
//			used[i] = false;
//			if (tres > curMax) {
//				resVec.clear();
//				curMax = tres;
//				FOR(j, 0, p2SCC[i].size())
//					resVec.push_back(p2SCC[i][j]);
//			}
//			else if (tres == curMax) {
//				FOR(j, 0, p2SCC[i].size())
//					resVec.push_back(p2SCC[i][j]);
//			}
//		}
//	}
//
//	
//
//	printf("%d\n", curMax);
//	sort(resVec.begin(), resVec.end());
//	FOR(i, 0, resVec.size()) {
//		printf("%d ", resVec[i] - 1);
//	}
//	printf("\n");
//
//	return 0;
//}
//
///*
//1
//2 3
//0
//
//5 3
//6
//4 7
//
//*/
//
///*
//1
//2
//0 3
//4
//5
//3
//*/
