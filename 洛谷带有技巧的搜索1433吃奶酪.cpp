#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>			// ��sqrt��Ҫ
using namespace std;

#define in(x) x=read()

#define MAXN 500

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

// �򵥵�Ԥ���� + dfs��һ�°�.
// ע����򵥵ļ�֦, if (curAns > ans) return;

int n;
double res = 0xfffffff;
double a[30][2], dis[30][30];
bool used[30] = { false };

// �������׼��dfs��...
void dfs(double curAns, int bef, int level) {
	if (curAns > res)
		return;
	if (level == n) {
		/*for (int i = 0; i <= n; ++i)
			cout << debug[i] << " ";
		cout << endl;*/
		res = res > curAns ? curAns : res;
		// cout << res << endl;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (used[i] == false) {
			used[i] = true;
			dfs(curAns + dis[bef][i], i, level + 1);
			used[i] = false;
		}
	}
}

double getDis(int x, int y) {
	if (x == y)
		return 0;

	return sqrt((a[x][0] - a[y][0]) * (a[x][0] - a[y][0]) + (a[x][1] - a[y][1]) * (a[x][1] - a[y][1]));
}


int main() {
	in(n);

	// ����ע������
	if (n == 0) {
		printf("0\n");
		return 0;
	}

	a[0][0] = a[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", &a[i][0]);				// double �� %lf !!!!!!!!!!!!!!
		scanf("%lf", &a[i][1]);
	}

	// printf("%.6f\n", a[1][0]);

	for (int i = 0; i <= n; ++i) {
		for (int k = 0; k <= n; ++k) {
			dis[i][k] = getDis(i, k);
		}
	}

	dfs(0, 0, 0);

	printf("%.2f\n", res);				// ע�����������λС������ô��!!!

	return 0;
}

/*

��Ŀ����
���������n�����ҡ�һֻС����Ҫ�����Ƕ��Ե���������Ҫ�ܶ��پ��룿����һ��ʼ��(0,0)�㴦��

���������ʽ
�����ʽ��
��һ��һ����n (n<=15)

������ÿ��2��ʵ������ʾ��i�����ҵ����ꡣ

����֮��ľ��빫ʽ=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))

�����ʽ��
һ��������ʾҪ�ܵ����پ��룬����2λС����

�����������
��������#1��
4
1 1
1 -1
-1 1
-1 -1
�������#1��
7.41

*/