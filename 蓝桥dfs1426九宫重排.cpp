#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;

#define in(x) x=read()

struct String
{
	int step;
	int bef;
	string str;
	String() {}
	String(int a, string &b, int beff = -1) : step(a), str(b), bef(beff) { }
};


inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

string beg, endd;

int way[10][4] = {
	{ 1, 3, -1, -1 },
	{ 0, 4, 2, -1 },
	{ 1, 5, -1, -1 },
	{ 0, 4, 6, -1 },
	{ 1, 3, 5, 7 },
	{ 2, 4, 8, -1 },
	{ 3, 7, -1, -1 },
	{ 4, 6, 8, -1 },
	{ 5, 7, -1, -1 }
};

int FindEmpty(string &t) {
	int n = t.length();
	for (int i = 0; i < n; ++i) {
		if (t[i] == '.')
			return i;
	}
	return -1;
}

int main() {
	std::ios::sync_with_stdio(0);
	while (cin >> beg && cin >> endd) {
		map<string, bool> m;
		string tmp;
		char ch;
		int pos, stepTmp, befTmp;

		queue<String> q;

		q.push(String(0, beg));
		while (!q.empty()) {
			tmp = q.front().str;
			if (m[tmp] == true) {
				q.pop();
				continue;
			}
			else
				m[tmp] = true;
			stepTmp = q.front().step;
			befTmp = q.front().bef;
			if (tmp == endd)
				break;
			q.pop();
			pos = FindEmpty(tmp);

			// cout << befTmp << endl;
			// cout << q.size() << endl;
			for (int k = 0; way[pos][k] != -1; ++k) {
				if (way[pos][k] == befTmp)
					continue;
				string inQue = tmp;
				ch = inQue[pos];
				inQue[pos] = inQue[way[pos][k]];
				inQue[way[pos][k]] = ch;
				// cout << inQue << endl;
				q.push(String(stepTmp + 1, inQue, pos));
			}
			// cout << endl;
		}

		if (q.empty())
			printf("-1\n");
		else
			printf("%d\n", stepTmp);
	}


	return 0;
}

/*
���ǰѵ�һ��ͼ�ľ����Ϊ��12345678.
�ѵڶ���ͼ�ľ����Ϊ��123.46758
��Ȼ�ǰ����ϵ��£������ҵ�˳���¼���֣��ո��Ϊ��㡣
����Ŀ����������֪�Ź��ĳ�̬����̬�������پ������ٲ����ƶ����Ե��������۶��ٲ����޷���������-1��

������˳������, �ո��� .  ���һͼת���ڶ�ͼ�Ĳ���.
*/