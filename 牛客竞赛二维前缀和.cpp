#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i <= n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, m;
ll L, R;

ll a[1010], b[1010];
ll c[1010][1010];

ll q[1010][1010];


ll tmp = 0;
int res = 0;

int main() {
	for (int i = 0; i < 1010; ++i) {
		for (int k = 0; k < 1010; ++k) {
			q[i][k] = 0;
		}
	}
	ios::sync_with_stdio(false);
	cin >> n >> m >> L >> R;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	FOR(i, 1, m) {
		cin >> b[i];
	}

	FOR(i, 1, n) {
		FOR(k, 1, m) {
			c[i][k] = a[i] * b[k];
		}
	}

	q[1][1] = c[1][1];
	FOR(i, 2, n) {
		q[i][1] = c[i][1] + q[i - 1][1];
	}
	FOR(k, 2, m) {
		q[1][k] = c[1][k] + q[1][k - 1];
	}
	FOR(i, 2, n) {
		FOR(k, 2, m) {
			q[i][k] = c[i][k] + q[i - 1][k] + q[i][k - 1] - q[i - 1][k - 1];
		}
	}

	FOR(bi, 0, n - 1) {
		FOR(bk, 0, m - 1) {
			FOR(ei, bi + 1, n) {
				FOR(ek, bk + 1, m) {
					tmp = q[ei][ek] - (q[ei][bk] + q[bi][ek] - q[bi][bk]);
					cout << bi << " " << bk << " " << ei << " " << ek << "   " << tmp << endl;
					if (tmp <= R && tmp >= L) {
						// cout << bi << " " << bk << " " << ei << " " << ek << "   " << tmp << endl;
						++res;
					}
				}
			}
		}
	}

	printf("%d\n", res);
	

	return 0;
}


/*

3 3 6 10
3 2 3
2 3 1


���ӣ�https://ac.nowcoder.com/acm/contest/894/B
��Դ��ţ����

��Ŀ����
����������a������b�ϳ��˾���c������a���鳤��Ϊn��b���鳤��Ϊm��c��n��m�еľ�����c[i][j]=a[i]*b[j]����������ȨֵΪ����������Ԫ�صĺ͡�Ȼ������Ѿ����͸����ȡ�Ȼ���������Ȳ�ϲ�����������ȨֵС��L,���Ȼ�����������Ϊ���Ȳ�ϲ��̫С�����֡��������Ȩֵ����R�����Ȼ�������Ϊ���Ȳ���ʶ��R������֡���������ֻϲ��Ȩֵ���ڵ���L����С�ڵ���R�ľ��󡣻��û���ѧ��acm���������뵽����������һ���Ӿ��󣬲���������д�����c�������ҳ�����������ϲ�����Ӿ�����ֻ��Ҫ���������������Ӿ����ж��ٸ����ɡ�
��������:
��һ������n,m,L,R��
�ڶ���n������ʾa����
������m������ʾb����
1<=n,m<=1000,1<=L<=R<=1e18
1<=a[i],b[i]<=1e6
�������:
���һ������ʾ�Ӿ���ĸ���
ʾ��1
����
����
3 3 3 8
3 2 3
2 3 1
���
����
10

*/