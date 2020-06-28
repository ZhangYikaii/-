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
//#include <queue>
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
//int arr[3000][3000], res[3000][3000];
//int ans = 0;
//
//int main() {
//	FOR(i, 0, 3000) {
//		FOR(k, 0, 3000)
//			res[i][k] = -1;
//	}
//	int n, m;
//	in(n), in(m);
//	FOR(i, 0, n) {
//		FOR(k, 0, m) {
//			in(arr[i][k]);
//		}
//	}
//
//	FOR(i, 0, m) {
//		if (arr[0][i] == 1)
//			res[0][i] = i;
//	}
//
//	FOR(i, 1, n) {
//		FOR(k, 0, m) {
//			if (k == 0) {
//				if (arr[i][k] == 1)
//					res[i][k] = 0;
//				continue;
//			}
//			if (arr[i - 1][k] == 0 && arr[i][k - 1] == 0 && arr[i][k] == 1) {
//				if (res[i - 1][k - 1] == -1)
//					res[i][k] = k;
//				else {
//					res[i][k] = res[i - 1][k - 1];
//					ans = max(ans, k - res[i - 1][k - 1] + 1);
//				}
//			}
//			else if (arr[i][k] == 1 && !(arr[i - 1][k] == 0 && arr[i][k - 1] == 0)) {
//				res[i][k] = k;
//			}
//		}
//	}
//
//	/*cout << endl;
//
//	FOR(i, 0, n) {
//		FOR(k, 0, m)
//			cout << res[i][k] << " ";
//		cout << endl;
//	}*/
//
//	cout << ans << endl;
//	
//	return 0;
//}
//
//


// �����Ǵ�
// ע��Խ������Ҷ�����ѽ..
//
//#include<iostream>
//#include<algorithm>
//#include<cstdio>
//#include<cstring>
//using namespace std;
//#define N 2510
//int dp[N][N], sum[N][N];  //sum��ʾ��(1,1)��(i,j)��Ԫ�غ�
//bool map[N][N];
//int maxx = 0;
//
//// ��άǰ׺��.
//int getsum(int i, int j, int x, int y) {
//	return sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1];  //��άǰ׺�͵ľ�����������ʾ�Խ��ߴ�(i,j)��(x,y)���Ӿ����Ԫ�غ�
//}
//int read() {
//	int ans = 0, f = 1;
//	char ch = getchar();
//	while (!isdigit(ch)) {
//		if (ch == '-') f = -1;
//		ch = getchar();
//	}
//	while (isdigit(ch)) {
//		ans = ans * 10 + ch - '0';
//		ch = getchar();
//	}
//	return f*ans;
//}
//
//// ��άǰ׺�� => �����1 ��ʼ��!!!
//int main() {
//	int i, j, n = read(), m = read();
//	for (i = 1; i <= n; i++) {
//		int num = 0;
//		for (j = 1; j <= m; j++) {
//			map[i][j] = read();
//			num += map[i][j];
//			sum[i][j] = sum[i - 1][j] + num;  //��ʼ����άǰ׺�� ע��������ʼ������, ��һ��num��¼��ǰ��ǰ�������.
//		}
//	}
//	//��Խ��߲���
//	// ��άǰ׺�� + ���� ����Ѿ�����·��..
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= m; j++) {
//			// ������λ�� == 1.
//			if (map[i][j]) {
//				dp[i][j] = 1; // ��ʼ��Ϊ1��������ûʲô���壬�����������ҶԽ���ʱ�Ǳ�Ҫ��
//				if (dp[i - 1][j - 1]) {
//					int num = dp[i - 1][j - 1];
//					int l = 0, r = num, ans = 0;
//					//���¼�Ϊ���ֲ��ң����ܾ����ҳ�������������Խ��߳���
//					while (l <= r) {
//						int mid = l + r >> 1;
//						if (getsum(i - mid, j - mid, i, j) == mid + 1) ans = mid, l = mid + 1;
//						else r = mid - 1;
//					}
//					dp[i][j] = max(dp[i][j], ans + 1);
//				}
//				maxx = max(maxx, dp[i][j]);
//			}
//		}
//	}
//	// �ҶԽ��߳���
//	for (i = 1; i <= n; i++)
//	for (j = 1; j <= m; j++)
//	if (map[i][j]) {
//		dp[i][j] = 1;
//		if (dp[i - 1][j + 1]) {
//			int num = dp[i - 1][j + 1];
//			int l = 0, r = num, ans = 0;
//			while (l <= r) {
//				int mid = l + r >> 1;
//				if (getsum(i - mid, j, i, j + mid) == mid + 1) ans = mid, l = mid + 1; //ע��getsum()�������˳����һ��ʼ�ͱ�����
//				else r = mid - 1;
//			}
//			dp[i][j] = max(dp[i][j], ans + 1);
//		}
//		maxx = max(maxx, dp[i][j]);
//	}
//	printf("%d\n", maxx);
//	return 0;
//}


// ���һ��dp��˼·, �ǳ�����, ��ͺ����ҵ�˼·, ����Ϊʲô�Ҳ�����.. ������Ϊû��s1[]��s2[] ����������, ʹÿ��
// 100
// 010
// 101
// ������Ӿͻ����


#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
typedef long long ll;
using namespace std;
int n, m, ans;
int a[2509][2509], f[2509][2509], s1[2509][2509], s2[2509][2509];//s1Ϊ����s2Ϊ���� 
int main()
{
	cin >> n >> m;
	//��һ�����ϡ������� 
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		scanf("%d", &a[i][j]);
		if (!a[i][j])
		{
			s1[i][j] = s1[i][j - 1] + 1;
			s2[i][j] = s2[i - 1][j] + 1;
		}
		if (a[i][j])
			f[i][j] = min(f[i - 1][j - 1], min(s1[i][j - 1], s2[i - 1][j])) + 1;
		ans = max(ans, f[i][j]);
	}
	//�ڶ������ϡ������� 
	memset(f, 0, sizeof(f));
	memset(s1, 0, sizeof(s1));//������0 
	memset(s2, 0, sizeof(s2));
	for (int i = 1; i <= n; i++)
	for (int j = m; j >= 1; j--)
	{
		if (!a[i][j])
		{
			s1[i][j] = s1[i][j + 1] + 1;
			s2[i][j] = s2[i - 1][j] + 1;
		}
		if (a[i][j])
			f[i][j] = min(f[i - 1][j + 1], min(s1[i][j + 1], s2[i - 1][j])) + 1;
		ans = max(ans, f[i][j]);
	}
	cout << ans << endl;
	return 0;
}