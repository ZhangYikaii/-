//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//using namespace std;
//
//#define in(x) x=read()
//
//struct Data  {
//	int x, y;
//	Data() : x(-1), y(-1)  { }
//};
//
//inline int read()  {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9')  { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//int MyMin(int a, int b)  {
//	return a > b ? b : a;
//}
//
//void Swap(int arr[], int i, int j)  {
//	if (i == j)
//		return;
//
//	arr[i] = arr[i] ^ arr[j];
//	arr[j] = arr[i] ^ arr[j];
//	arr[i] = arr[i] ^ arr[j];
//}
//
//int n, m, arr[510][510];
///* �ҵ�˼·:
//dfs ��������һ��ÿһ���㽨����ˮվ �� ������һ����ɵ�Ӱ��( ������l -> r )�����, ��dfs������һ����������, ����������������һ�������Ķ����������õĸ�������.*/
//
//int main()  {
//	in(n);
//	in(m);
//	for (int i = 1; i <= n; ++i)  {
//		for (int k = 1; k <= m; ++k)  {
//			in(arr[i][k]);
//		}
//	}
//
//
//	
//	return 0;
//}
//
//
///*
//
//
//��Ŀ����
//��һ��ңԶ�Ĺ��ȣ�һ���Ƿ羰�����ĺ�������һ���������ޱ߼ʵ�ɳĮ���ù�����������ʮ�����⣬�պù���һ��NN �� \times M��M �еľ��Σ�����ͼ��ʾ������ÿ�����Ӷ�����һ�����У�ÿ�����ж���һ�����θ߶ȡ�
//
//
//
//Ϊ��ʹ�����Ƕ����������õ��峺�ĺ�ˮ������Ҫ��ĳЩ���н���ˮ����ʩ��ˮ����ʩ�����֣��ֱ�Ϊ��ˮ������ˮվ����ˮ���Ĺ���������ˮ�ý������е�ˮ��ȡ�����ڳ��е���ˮ���С�
//
//��ˣ�ֻ����������ڵĵ�11 �еĳ��п��Խ�����ˮ��������ˮվ�Ĺ�������ͨ����ˮ�������ø߶�������ˮ�Ӹߴ���ʹ����͡���һ�������ܽ�����ˮվ��ǰ�ᣬ�Ǵ��ڱ������θ�����ӵ�й����ߵ����ڳ��У��Ѿ�����ˮ����ʩ�����ڵ�NN �еĳ��п���ɳĮ���Ǹù��ĸɺ���������Ҫ�����е�ÿ�����ж�����ˮ����ʩ����ô�����Ҫ���ܷ������أ�����ܣ���������ٽ��켸����ˮ����������ܣ���ɺ����в����ܽ���ˮ����ʩ�ĳ�����Ŀ��
//
//���������ʽ
//�����ʽ��
//ÿ����������֮����һ���ո����������ĵ�һ��������������N,MN,M����ʾ���εĹ�ģ��������NN �У�ÿ��MM �������������δ���ÿ�����еĺ��θ߶ȡ�
//
//�����ʽ��
//���С����������Ҫ������ĵ�һ��������11���ڶ�����һ���������������ٽ��켸����ˮ���������������Ҫ������ĵ�һ��������00���ڶ�����һ�������������м����ɺ����еĳ��в����ܽ���ˮ����ʩ��
//
//�����������
//��������#1��
//2 5
//9 1 5 4 3
//8 7 6 1 2
//�������#1��
//1
//1
//��������#2��
//3 6
//8 4 5 6 4 4
//7 3 4 3 3 3
//3 2 2 1 1 2
//�������#2��
//1
//3
//
//
//
//*/


// �����һ�¼��仯���������! Ȼ���Լ�д
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
#define maxn 510

// ������Ǹ�
#define nx x+xx[i]
#define ny y+yy[i]

int l[maxn][maxn], r[maxn][maxn];
int high[maxn][maxn];
int n, m;
bool vis[maxn][maxn];
int xx[4] =  { -1, 0, 1, 0 };
int yy[4] =  { 0, 1, 0, -1 };
int qx[maxn*maxn], qy[maxn*maxn];

// dfs ̽�ⷽ���ú궨��ļ���!
// 
inline void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i<4; i++) {

		if (nx<1 || nx>n || ny<1 || ny>m) 
			continue;

		if (high[nx][ny] >= high[x][y])
			continue;

		if (!vis[nx][ny])
			dfs(nx, ny);

		// l[x][y]: (x, y) �����Ū, ��ײ����ˮ������Сֵ.
		// ��һ������, �ߵ��µ�λ�þ͸���?
		l[x][y] = min(l[x][y], l[nx][ny]);
		r[x][y] = max(r[x][y], r[nx][ny]);
	}
}

inline int read() {
	int ret = 0;
	char c = getchar();
	while (c<'0' || c>'9') c = getchar();
	while (c >= '0' && c <= '9') {
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}

int main() {
	n = read();
	m = read();
	// memset ֻ������������ 0.
	memset(vis, false, sizeof(vis));
	memset(l, 0x3f, sizeof(l));
	memset(r, 0, sizeof(r));
	for (int i = 1; i <= m; i++)
		l[n][i] = r[n][i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			high[i][j] = read();
	}

	// dfs ��ֻŪ��һ��.
	for (int i = 1; i <= m; i++) {
		if (!vis[1][i])
			dfs(1, i);
	}
	bool flag = false;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (!vis[n][i]) {
			flag = true;
			cnt++;
		}
	}
	if (flag) {
		puts("0");
		printf("%d", cnt);
		return 0;
	}
	int left = 1;
	while (left <= m) {
		int maxr = 0;
		for (int i = 1; i <= m; i++) {
			if (l[1][i] <= left)
				maxr = max(maxr, r[1][i]);
		}
		cnt++;
		left = maxr + 1;
	}
	puts("1");
	printf("%d", cnt);
}