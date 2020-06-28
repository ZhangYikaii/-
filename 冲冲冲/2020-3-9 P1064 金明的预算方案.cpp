#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define INF 0x7fffff
#define MAX 70

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}


// �˰�, ֻ����0, 1, 2������.
// �ɴ಻��01������, ֱ�������+���鱳��.

int N, m;
int v[MAX], p[MAX], q[MAX];
int f[MAX][32010];				// ǰ i ����Ʒ ���� j Ԫ
int major[MAX], sumMajor = 1;   // sumMajor ��1��ʼ�� ʵ������������ sumMajor - 1


int main() {
	N = read();
	m = read();

	for (int i = 0; i < MAX; ++i) {
		for (int k = 0; k < 32010; ++k) {
			f[i][k] = 0;
		}
	}

	for (int i = 1; i <= m; ++i) {
		in(v[i]);
		in(p[i]);
		in(q[i]);
		if (q[i] == 0) {
			major[sumMajor++] = i;     // ��¼�������
		}
	}

	int iMajor = 1;

	for (int i = 0; i <= N; ++i)
		f[0][i] = 0;

	// �൱�ڹ��������ı���  ֻ�Ǽ�һ��������ѭ�� �����Ÿ���ѡ�����ȥ��
	for (int i = major[iMajor]; iMajor < sumMajor; ++iMajor) {

		i = major[iMajor];       // i: ������Ӧ������������, ��ԭӳ��.

		// ���￼�� ��ѡ���� & ѡ��ֻѡ�������
		// ��һ�� 0 1.
		for (int k = N; k >= 0; --k) {
			if (k >= v[i])
				f[iMajor][k] = max(f[iMajor - 1][k], f[iMajor - 1][k - v[i]] + v[i] * p[i]);
			else
				f[iMajor][k] = f[iMajor - 1][k];
		}

		// k: ����
		// �򵥽�: ���￼�� ѡ������ѡ����
		for (int j = 1; j <= m; ++j) {
			// �жϣ��������������ĸ���
			if (q[j] == i) {
				for (int k = N; k >= v[i] + v[j]; --k)
					f[iMajor][k] = max(f[iMajor][k], f[iMajor][k - (v[i] + v[j])] + v[i] * p[i] + v[j] * p[j]);
			}
		}
	}

	cout << f[sumMajor - 1][N] << endl;

	return 0;
}

