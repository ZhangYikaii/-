#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

#define MAX 100010

bool isPrime[MAX] = { 0 };
int prime[MAX] = { 0 };

// isPrime �±���ĳ���� = true��ʾ������ false��ʾ����
// prime ��˳�������


int cnt = 0;

void Init() {
	isPrime[0] = isPrime[1] = 1;   // 0 �� 1 ��������.

	for (int i = 2; i < MAX; ++i) {
		if (!isPrime[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt && prime[j] * i < MAX; ++j)
			isPrime[prime[j] * i] = 1;
	}
}

int arr[10010], acnt = 0;

// ע������û��Ҫ��������, ��������ɸ + �����ӷֽ�֮��һ��������ɱȽϺ�������.
// ע��n��������ʱ��ֱ�����n, n����һ�������ӵ�ʱ����������Ǹ�������.

int main() {
	Init();
	int n, tmpn = 0;
	in(n);

	//if (!isPrime[n]) {
	//	cout << "1" << endl << n << endl;
	//}

	tmpn = n;

	for (int i = 0; i < cnt; ++i) {
		while (n % prime[i] == 0) {
			n /= prime[i];
			arr[acnt++] = prime[i];
		}
		if (n == 1)
			break;
	}

	int maxLen = 1, curBeg = arr[0];
	for (int i = 0; i < acnt; ++i) {
		int len = 1, tmpDiv = tmpn / arr[i];
		while (tmpDiv % (arr[i] + len) == 0) {
			tmpDiv /= (arr[i] + len);
			++len;
		}
		if (maxLen < len) {
			curBeg = arr[i];
			maxLen = len;
		}
	}

	cout << maxLen << endl;

	for (int i = 0; i < maxLen; ++i) {
		if (i == 0) {
			if (curBeg == 0)
				cout << tmpn;
			else
				cout << curBeg;
		}
		else {
			cout << "*" << curBeg + i;
		}
	}
	cout << endl;


	return 0;
}
//
//int arr[10010], acnt = 0;
//int main() {
//	Init();
//	int n;
//	in(n);
//
//	for (int i = 0; i < cnt; ++i) {
//		while (n % prime[i] == 0) {
//			n /= prime[i];
//			arr[acnt++] = prime[i];
//		}
//		if (n == 1)
//			break;
//	}
//
//
//	int beg = 0, len = 1;
//	for (int i = 0; i < acnt;) {
//		int curBeg = i, curLen = 1;
//		while (i < acnt && arr[i] == arr[i + 1]) {
//			++i;
//			++curLen;
//		}
//		if (curLen > len) {
//			beg = curBeg;
//			len = curLen;
//		}
//	}
//
//	for (int i = 0; i < acnt; ++i) {
//		cout << arr[i] << " ";
//	}
//
//	return 0;
//}
/*




*/