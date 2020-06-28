#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int n, a[110];
int f[110] = { 0 }, f1[110] = { 0 };
int maxx = -1;
// f[i] ��ʾ���� i ��ʱ ����������еĳ���
// f1[i]��ʾ�ӵ�i����β����½�������.

int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(a[i]);
	}

	// �����������.
	for (int i = 1; i <= n; ++i) {
		f[i] = 1;
		for (int k = 1; k < i; ++k) {
			if (a[k] < a[i])
				// ������, ���ܿ��Խ���ȥ.
				f[i] = max(f[i], f[k] + 1);
		}
	}

	// �������, ��½�������.
	for (int i = n; i >= 1; --i) {
		f1[i] = 1;
		for (int k = n; k > i; --k) {
			if (a[k] < a[i])
				f1[i] = max(f1[i], f1[k] + 1);
		}
	}

	for (int i = 0; i <= n; ++i) {
		if (maxx < f[i] + f1[i] - 1)
			maxx = f[i] + f1[i] - 1;
	}

	/*for (int i = 1; i <= n; ++i) {
		cout << f[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; ++i) {
		cout << f1[i] << " ";
	}
	cout << endl;*/

	printf("%d\n", n - maxx);

	return 0;
}