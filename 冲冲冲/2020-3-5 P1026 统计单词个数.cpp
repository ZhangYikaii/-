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

int p, n, s;
string tmp, str;
//map<string, int> m;
vector<string> m;

int wordNum[210][210], dp[210][210];

int main() {
	in(p), in(n);
	For(i, 0, p) {
		cin >> tmp;
		str += tmp;
	}
	in(s);
	For(i, 0, s) {
		cin >> tmp;
		m.push_back(tmp);

		// ������ĸ�Ĵ����.
		if (tmp.length() == 1) {
			For(i, 0, str.length()) {
				if (str[i] == tmp[0])
					wordNum[i][i] = 1;
			}
		}
	}


	//// ��str i, j֮��ĵ��ʸ���:
	//int strLen = str.length();
	//For(i, 0, strLen) {
	//	int isBeginUsed[210] = { 0 };
	//	For(j, i + 1, strLen) {
	//		// ������һ����ĸ֮��֮ǰ�����п��ܿ�ͷ.
	//		for (int k = i; k < j; ++k) {
	//			if (m[str.substr(k, j - k)] == 1)
	//				++wordNum[]
	//		}
	//	}
	//}


	int strLen = str.length();
	// ��str i, j֮��ĵ��ʸ���: ��Ҫ���Ŵ���.
	for (int j = strLen - 1; j > 0; --j) {
		for (int i = j - 1; i >= 0; --i) {
			string sub = str.substr(i, j + 1 - i);	// ǰ�պ������.
			wordNum[i][j] = wordNum[i + 1][j];
			For(k, 0, m.size()) {
				if (sub.find(m[k]) == 0) {
					wordNum[i][j]++;
					break;		// ÿ������ĸֻ���ܹ��׸�һ��word.
				}
			}
		}
	}

	//For(i, 0, strLen) {
	//	For(j, 0, strLen) {
	//		cout << wordNum[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	// ��ʼ��, û�л��ֵ�ʱ�����ԭ����wordNum.
	For(j, 0, strLen) {
		dp[j][0] = wordNum[0][j];
	}

	For(j, 0, strLen) {
		For(i, 0, j) {
			For(k, 1, n + 1) {
				dp[j][k] = max(dp[j][k], dp[i][k - 1] + wordNum[i + 1][j]);
			}
		}
	}

	printf("%d\n", dp[strLen - 1][n]);


	return 0;
}