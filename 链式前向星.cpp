#include <iostream>
using namespace std;

#define MAXM 500010
#define MAXN 10010

// ����ͼ��ʽǰ���Ǳ���ʵ��!

struct Edge{
	int next;	// ��һ���ߵĴ洢�±� (��ʵ������˳���ǰһ����)
	int to;		// �����ߵ��յ� 
	int w;		// Ȩֵ 
};
Edge edge[MAXM];

int n, m, cnt;
int head[MAXN];  // head[i]��ʾ��iΪ���ĵ�һ���� 

// head[i] ��������� i ����������ı�, Ȼ���������߿���ͨ�� edge[i].next ȥ��ǰ������ı�

void Add(int u, int v, int w) {		// ���u, �յ�v, Ȩֵw 
	// ǰ������Ϊ������������ͼ��
	edge[++cnt].next = head[u];
	head[u] = cnt;					// ��һ����Ϊ��ǰ�� 

	edge[cnt].w = w;
	edge[cnt].to = v;
}

void Print() {
	int start;
	cout << "Begin with[Please Input]: \n";
	cin >> start;
	// i��ʼΪ��һ���ߣ�ÿ��ָ����һ��(��0Ϊ������־)
	// ���±��0��ʼ��nextӦ��ʼ��-1 !!!
	for (int i = head[start]; i != 0; i = edge[i].next) {
		cout << "Start: " << start << endl;
		cout << "End: " << edge[i].to << endl;
		cout << "W: " << edge[i].w << endl << endl;
	}
}

int main() {
	int s, t, w;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s >> t >> w;
		Add(s, t, w);
	}
	Print();
	return 0;
}
