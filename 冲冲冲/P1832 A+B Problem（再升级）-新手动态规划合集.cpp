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

// ɸ��������ϰ:
bool isNotPrime[10010];
void initPrime() {
	isNotPrime[0] = 1, isNotPrime[1] = 1;
	For(i, 2, 10010) {
		if (isNotPrime[i] == 0) {
			// ��������������, ��ô���Կ�ʼɸ��:
			// i �ı�������������.
			for (int j = 2; i * j < 10010; ++j) {
				isNotPrime[i * j] = 1;
			}
		}
	}
}

int n;
ll dp[1010];
int main() {
	initPrime();
	
	cin >> n; // ����
	// ��ȫ����: ÿ��������������������ȡ.
	dp[0] = 1; // �߽�ֵ����ȡ����Ϊ0ʱֵΪ1
	Fee(i, 2, n) {
		// ÿ����������ȡ��ȡ:
		if (isNotPrime[i] == 0) {
			Fee(j, i, n) {
				// ע�������Ƿ�����, ������ +=
				dp[j] += dp[j - i];
			}
		}
	}
	cout << dp[n] << endl;

	return 0;
}