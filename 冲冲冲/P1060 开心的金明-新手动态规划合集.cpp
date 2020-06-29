#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

#define MAX 50000

// ����ע������±��ʾ����ʲô
// dp���鲻Ҫ���˳�ʼ��Ϊ 0

int MyMax(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int N, m;
	scanf("%d%d", &N, &m);
	int v[50], w[50];
	int dp[MAX] = { 0 };
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &v[i], &w[i]);
	}

	// ״̬ת�Ʒ��̣� f[i][v] = max{f[i-1][v](�� i ����Ʒ��ѡ) , f[i-1][v-g[k].weight] + g[k].cost}
	// dp[i] �����õ���i����� ���Դﵽ�����ֵ
	// ����ÿһ����Ʒ �������Ʒ��˵��dp������Ǵ����������ʼ�����Ų��������Ʒ
	for (int i = 1; i <= m; ++i) {
		for (int k = N; k >= v[i]; --k) {
			dp[k] = MyMax(dp[k], dp[k - v[i]] + w[i] * v[i]);    // �ǿ������Ʒ�Ų��� �����±���i��
		}
	}

	cout << dp[N] << endl;


	return 0;
}
