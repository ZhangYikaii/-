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
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//struct point
//{
//	int x, y, data;//��¼ÿ�����λ�ú���ֵ
//}p[100];
//int n, m, map[11][11], f[11][11];
//int main()
//{
//	int i, ii, j, jj, l;
//	scanf("%d", &n);
//	while (1)
//	{
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		if (!a&&!b&&!c)
//			break;
//		p[++m].x = a;
//		p[m].y = b;
//		p[m].data = c;
//	}
//	for (i = 1; i <= m; i++)
//		map[p[i].x][p[i].y] = p[i].data;
//	for (l = 2; l <= n * 2; l++) {
//		//ÿ�������ٺ������Ŷ���һ����඼��n��͵��յ�
//		for (i = l - 1; i >= 1; i--) {
//			//��ǰ��˵��һ����������
//			for (ii = l - 1; ii >= 1; ii--) {
//				j = l - i; jj = l - ii;//i+j=ii+jj=l
//				f[i][ii] = max(max(f[i][ii], f[i - 1][ii - 1]), max(f[i - 1][ii], f[i][ii - 1])) + map[i][j];
//				//�ص�˵��һ�°ɣ�����ʡ���˺ܶࡣ���i����1����˼����j-1����Ϊ��һ���׶ξ���l-1����ii-1����˼����˵jj����1��
//				f[i][ii] += map[ii][jj] * (i != ii);
//				//���i==ii����ʵ����(i==ii&&j==jj)����Ϊ�Ͷ���l�����߹�һ�飬�ڶ����ߵõ���ֵ����0����Ŀ��˵�ģ���
//			}
//		}
//	}
//	printf("%d\n", f[n][n]);
//	//�����˼����·������Ϊ2*n�Ľ׶Σ����鶼�ߵ�(n,n)������ֵ����Ϊ������(j=2*n-i=n,jj=2*n-ii=n),�����ߵ��ľ���(n,n)��λ��
//	return 0;
//}
//
//
////
////int arr[110][110];
////int res[110][110];
////int way[110][110];
////
////int main() {
////	int n;
////	in(n);
////
////	FOR(i, 0, n + 1) {
////		FOR(j, 0, n + 1) {
////			arr[i][j] = 0;
////			res[i][j] = 0;
////			way[i][j] = 0;
////		}
////	}
////
////	int a, b, c;
////	while (true) {
////		in(a), in(b), in(c);
////		if (a == 0 && b == 0 && c == 0)
////			break;
////		arr[a][b] = c;
////	}
////
////	for (int i = 1; i <= n; ++i) {
////		for (int j = 1; j <= n; ++j) {
////			res[i][j] = arr[i][j] + max(res[i - 1][j], res[i][j - 1]);
////			if (arr[i - 1][j] > arr[i][j - 1]) {
////				way[i][j] = -1;
////			}
////			else
////				way[i][j] = -2;
////		}
////	}
////
////	cout << res[n][n] << endl;
////	
////	return 0;
////}


#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[12][12][12][12], a[12][12], n, x, y, z;
int main() {
	cin >> n >> x >> y >> z;
	while (x != 0 || y != 0 || z != 0){
		a[x][y] = z;
		cin >> x >> y >> z;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= n; k++){
				for (int l = 1; l <= n; l++){
					f[i][j][k][l] = max(max(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1]), max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1])) + a[i][j] + a[k][l];
					// ע��ע������, ��Ϊ����ͬһ��λ��ֻ��ȡһ��, ����Ҫ�ӻ�ȥ.
					if (i == k&&l == j)f[i][j][k][l] -= a[i][j];
				}
			}
		}
	}
	cout << f[n][n][n][n];
	return 0;
}