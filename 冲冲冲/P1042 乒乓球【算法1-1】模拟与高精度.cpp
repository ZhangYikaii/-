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

int s[100010], len;

void solve(int points) {
	int w = 0, l = 0;
	For(i, 0, len) {
		if (s[i] == 1)
			++w;
		else if (s[i] == 2)
			++l;
		if ((w >= points || l >= points) && abs(w - l) >= 2) {
			cout << w << ":" << l << endl;
			w = 0, l = 0;
		}
	}

	// ��һ��WA����Ϊ0:0Ҳ��Ҫ�����, ��̫�뵱Ȼ.
	//if (w != 0 || l != 0)
	//	cout << w << ":" << l << endl;
	cout << w << ":" << l << endl;
}

int main() {
	// ����ĿҪ��������. �����������.
	char ch;
	for (; cin >> ch && ch != 'E'; ++len) {
		// ѭ������, �������ַ�E���� 
		if (ch == 'W')
			s[len] = 1;
		else if (ch == 'L')
			s[len] = 2;
	}

	solve(11);
	cout << endl;
	solve(21);

	return 0;
}