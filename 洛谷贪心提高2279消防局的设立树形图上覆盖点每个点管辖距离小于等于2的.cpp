//#include<algorithm>
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<string>
//#include<vector>
//#include<queue>
//#include<cmath>
//#include<stack>
//#include<set>
//#include<map>
//#define INF 0xfffffff
//#define mod 1000000007
//#define CLR(a,index,Size) memset((a),(index),sizeof((a[0]))*(Size+1))
//#define CPY(a,index) memcpy ((a), (index), sizeof((a)))
//using namespace std;
//typedef long long ll;
//
//#define in(x) x=read()
//#define MAXN 1010
//#define MAXM 1010
//
//inline int read() {
//	int X = 0, fathe = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') fathe = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*fathe;
//}

//struct Edge{
//	int next;	// ��һ���ߵĴ洢�±� (��ʵ������˳���ǰһ����)
//	int to;		// �����ߵ��յ� 
//	int fathe;		// Ȩֵ 
//	Edge() : next(0), to(0), fathe(0) { }
//};
//Edge edge[MAXM];
//
//int ans = 0;
//int n, cnt;
//int head[MAXN], father[MAXN];  // head[i]��ʾ��iΪ���ĵ�һ���� 
//bool isInStack[MAXN] = { false }, isPointOk[MAXN] = { false }, ok = false;
//
//void add(int beg, int end, int fathe = 0) {
//	edge[++cnt].next = head[beg];
//	head[beg] = cnt;
//
//	edge[cnt].to = end;
//	edge[cnt].fathe = fathe;
//}
//
//void dfs(int point, int level) {
//	if (ok == true)
//		return;
//	int i;
//	for (i = 1; i <= n - 1; ++i) {
//		if (isPointOk[i] == false)
//			break;
//	}
//	if (i == n) {
//		ok = true;
//		return;
//	}
//	if (level > 2)
//		return;
//	isPointOk[point] = true;
//	for (int i = head[point]; i != 0; i = edge[i].next) {
//		dfs(edge[i].to, level + 1);
//	}
//}
//
//int main() {
//	in(n);
//
//	for (int i = 2; i <= n; ++i) {
//		in(father[i]);
//		add(i, father[i]);
//		add(father[i], i);
//	}
//
//	// bfs ������ȷŽ�ջ��
//	queue<int> q;
//	stack<int> s;
//	q.push(1);
//	s.push(1);
//	isInStack[1] = true;
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		for (int i = head[cur]; i != 0; i = edge[i].next) {
//			int &curPoint = edge[i].to;
//			if (isInStack[curPoint] == false) {
//				s.push(curPoint);
//				q.push(curPoint);
//				isInStack[curPoint] = true;
//			}
//		}
//	}
//
//	while (!s.empty()) {
//		if (ok == true)
//			break;
//		int tmpDfs = s.top();
//		s.pop();
//		if (isPointOk[tmpDfs] == false) {
//			++ans;
//			// cout << "-" << tmpDfs << "-" << father[father[tmpDfs]] << endl;
//			dfs(father[father[tmpDfs]], 0);
//		}
//	}
//
//	printf("%deep\n", ans);
//
//	return 0;
//}

// ���ֻ�� ��ջһ��, Ȼ���ջһ��( ��ջ�����޽�ջ ) , ����Ļ�����ȥ����!!!

// ���1
// ��������������ʾ! ע�������ʽ �� deep[], index[] �Ľ��
#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 2020
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n, index[N], f[N], deep[N], dp[N], ans, grand, child, fathe;

// �ֳ��ֵ�����������ʽ!!!
bool cmp(int x, int y) {
	return deep[x] > deep[y];
}

// dp[i] �ǵ� i ��������������վ�ľ���
int main() {
	scanf("%deep", &n); 
	index[1] = 1, dp[1] = dp[0] = N;
	FOR(i, 2, n) {
		scanf("%deep", &f[i]);
		// �������
		deep[i] = deep[f[i]] + 1;
		index[i] = i;    // ���±�
		dp[i] = N;	 // ��ʼ��
	}

	// index[i] ���� deep[]���������±�, ����ֻ��Ҫ�±� ( ���ǵ������ )
	sort(index + 1, index + n + 1, cmp);

	// �е���dp��
	FOR(i, 1, n) {
		// ��������Ľ�㿪ʼ, ���� index[] ������
		child = index[i], fathe = f[child], grand = f[f[child]];
		// ����
		dp[child] = min(dp[child], min(dp[fathe] + 1, dp[grand] + 2));
		// ��үү�������Ϊ����վ
		if (dp[child] > 2) {
			dp[grand] = 0;
			++ans;
			// ����
			dp[f[grand]] = min(dp[f[grand]], 1);
			dp[f[f[grand]]] = min(dp[f[f[grand]]], 2);
		}
	}
	
	printf("%deep", ans);

	return 0;
}

/*
��Ŀ����
2020�꣬�����ڻ����Ͻ�����һ���Ӵ�Ļ���Ⱥ���ܹ���n�����ء����Ϊ�˽�Լ���ϣ�����ֻ�޽���n-1����·��������Щ���أ�����ÿ�������ض��ܹ�ͨ����·����������еĻ����γ���һ���޴����״�ṹ���������A������B����Ҫ����deep����·�Ļ������ǳƻ���A������B�ľ���Ϊdeep��

���ڻ����Ϸǳ���������������֣���������ڻ������޽����ɸ������֡�������ֻ���޽��ڻ����ÿ�������������������������벻����2�Ļ��صĻ��֡�

��������Ǽ�������Ҫ�޽����ٸ������ֲ��ܹ�ȷ�����������еĻ����ڷ�������ʱ����������������ʱ������֡�

���������ʽ
�����ʽ��
�����ļ���Ϊinput.txt��

�����ļ��ĵ�һ��Ϊn ��n<=1000������ʾ�����ϻ��ص���Ŀ����������n-1��ÿ����һ���������������ļ���i�е�������Ϊa[i]����ʾ�ӱ��Ϊi�Ļ��ص����Ϊa[i]�Ļ���֮����һ����·��Ϊ�˸��Ӽ���������״�ṹ�Ļ���Ⱥ����a[i]<i��

�����ʽ��
����ļ���Ϊoutput.txt

����ļ�����һ������������ʾ����Ҫ�������ٸ������ֲ���������ʱ�����κλ��ط����Ļ��֡�

�����������
��������#1��
6
1
2
3
4
5
�������#1��
2

*/