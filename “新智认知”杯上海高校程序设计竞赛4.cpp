#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;
string s, res = "";
int del[10010] = { 0 };
bool isDel[10010] = { false };
map<char, int> mm;

// �ؼ�����ÿ����ͬ�Ƚ�, �������ѡ����ǰ���, ��ô�͹̶��Ǳ�����һ����.

int main() {
	ios::sync_with_stdio(false);

	cin >> s;
	n = s.length();

	for (int i = 0; i < n; ++i) {
		if (mm[s[i]] == 0) {
			mm[s[i]] = i + 1;
		}
		else {
			if (isDel[mm[s[i]] - 1] == true) {
				del[i] = 1;
				continue;
			}
			// ����ǰ��
			if (s[mm[s[i]]] > s[mm[s[i]] - 1]) {
				del[mm[s[i]] - 1] = 0;				// ԭ���趨�Ĳ���ɾ��.
				isDel[mm[s[i]] - 1] = true;
				del[i] = 1;
			}
			// ��������.
			else {
				del[mm[s[i]] - 1] = 1;
				mm[s[i]] = i + 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		// cout << del[i];
		if (del[i] == 0)
			res += s[i];
	}
	// cout << endl;

	cout << res << endl;

	return 0;
}
/*


*/