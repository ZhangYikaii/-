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


// �����Ǵ� Dijkstra �úü����.

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

struct node {
	int v;	// �ڵ���
	int cost;	// ��Ȩֵ
	node(int _v, int _cost) : v(_v), cost(_cost) {}	// ���캯��
};

int N;	// ��������
int K;	// ��·����
int INF = 1000000000;	// ������� 
string start;	// ��ʼ���������
int happy[201];	// ��Ÿ������еĿ���ֵ
map<string, int> stringToInt;	// ��������->���
map<int, string> intToString; 	// ���->��������
vector<node> graph[201];	// ����ͼ

// ��Դ�㵽��i�����ٻ���ֵ.
int d[201];	// ��¼����ʼ���е����i�����ٻ���ֵ 
bool visited[201];	// �������
vector<int> pre[201];	// ��¼ǰһ���ڵ� 
vector<int> path;
vector<int> tempPath;
int optHappy = 0;
double optAverageHappy = 0.0;
int countt = 0;	// ��¼���·������ 

void dijkstra(int s);
void dfs(int nowVisit);

int main() {
	cin >> N >> K >> start;
	stringToInt[start] = 0;	// ��ʼ���б��Ϊ0
	intToString[0] = start;	// ת��������map
	string city;
	int happyness;
	for (int i = 1; i <= N - 1; i++) {
		cin >> city >> happyness;
		// ��һ��map�ѳ���(�ַ���)ת������.
		stringToInt[city] = i;
		intToString[i] = city;
		happy[i] = happyness;
	}
	string city1, city2;
	int cost;
	for (int i = 0; i < K; i++) {
		cin >> city1 >> city2 >> cost;
		int id1 = stringToInt[city1];
		int id2 = stringToInt[city2];
		graph[id1].push_back(node(id2, cost));
		graph[id2].push_back(node(id1, cost));
	}
	// graph�����ڽӱ��ͼ.

	int destination = stringToInt["ROM"];
	dijkstra(0);
	dfs(destination);
	cout << countt << " " << d[destination] << " " << optHappy << " " << (int)optAverageHappy << endl;
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << intToString[path[i]];
		if (i != 0) {
			cout << "->";
		}
	}
	return 0;
}
// ��һ�뷢���ⲻ�Ƕ��Ż���, ����Ҫ���׼�Ķ��Ż�
//
//// Dijkstra �Լ���һ��, ������.
//void dijkstraMy(int s) {
//	for (int i = 0; i < N; ++i) {
//		d[i] = INF;
//	}
//	d[s] = 0;	// ��ʼ�� 0.
//	for (int i = 0; i < N; ++i) {
//		int u = -1, min = INF;
//		for (int j = 0; j < N; ++j) {
//			// ���û�з��ʹ� j, ���Ҿ���С�ڴ��� min. u ��¼���ǵ�ǰ��С�ǵ��ĸ���.
//			if (!visited[j] && d[j] < min) {
//				min = d[j];
//				u = j;
//			}
//		}
//
//		if (u == -1) {
//			// ˵�����е㶼���ʹ���.
//			return;
//		}
//		visited[u] = true;
//	}
//}

void dijkstra(int s) {
	for (int i = 0; i < N; i++) {
		d[i] = INF;
	}
	d[s] = 0;
	for (int i = 0; i < N; i++) {
		int u = -1, min = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && d[j] < min) {
				min = d[j];
				u = j;
			}
		}
		if (u == -1) {
			return;
		}
		visited[u] = true;
		// ������൱�ڶ��Ż��ĳ���һ��Ԫ��.

		for (int j = 0; j < graph[u].size(); j++) {
			int v = graph[u][j].v;			// �����ھ�.
			int cost = graph[u][j].cost;
			if (!visited[v]) {
				if (d[u] + cost < d[v]) {
					d[v] = d[u] + cost;

					// ע���������Dijkstra Skeleton��pre[]����.
					pre[v].clear();
					pre[v].push_back(u);
				}
				// ��ǰ�����, pre[v].clear();
				// pre[v].push_back(u);
				else if (d[u] + cost == d[v]) {
					pre[v].push_back(u);
				}
			}
		}
	}
}

void dfs(int nowVisit) {
	// ����dfs, ��� == 0 ����˵������Դ��.

	// ��ʵ���dfs��ȫ����д��ѭ��.
	if (nowVisit == 0) {
		countt++;
		tempPath.push_back(nowVisit);
		int happyValue = 0;
		for (int i = tempPath.size() - 2; i >= 0; i--) {
			happyValue += happy[tempPath[i]];
		}
		double averageHappyValue = 1.0 * happyValue / (tempPath.size() - 1);
		if (happyValue > optHappy) {
			optHappy = happyValue;
			optAverageHappy = averageHappyValue;	// Ҳ��Ҫ����optAverageHappy��ֵ 
			path = tempPath;
		}
		else if (happyValue == optHappy && averageHappyValue > optAverageHappy) {
			optAverageHappy = averageHappyValue;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(nowVisit);
	// �������·�����������һ�����. ����dfs����.
	// ̫ǿ��!
	for (int i = 0; i < pre[nowVisit].size(); i++) {
		dfs(pre[nowVisit][i]);
	}
	tempPath.pop_back();
}

/*

All Roads Lead to Rome (30)
ʱ������ 1000 ms �ڴ����� 65536 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
Indeed there are many different tourist routes from our city to Rome.  You are supposed to find your clients the route with the least cost while gaining the most happiness.

��������:
Each input file contains one test case.  For each case, the first line contains 2 positive integers N (2<=N<=200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city.  The next N-1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city.  Then K lines follow, each describes a route between two cities in the format "City1 City2 Cost".  Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.


�������:
For each test case, we are supposed to find the route with the least cost.  If such a route is not unique, the one with the maximum happiness will be recommended.  If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.
Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommended route.  Then in the next line, you are supposed to print the route in the format "City1->City2->...->ROM".

��������:
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1

�������:
3 3 195 97
HZH->PRS->ROM


*/