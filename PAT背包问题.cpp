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


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define MAXTOTAL	10001
#define MAXAMOUNT	101

int f[MAXTOTAL][MAXAMOUNT];			//f[n][m]��ʾǰ n ����(ǰn��Ӳ��)�еó�����ӽ� m ��ֵ ע����������ӽ�m��ֵ, �����������Ŀ��ֵ��˵����OK��.
bool has[MAXTOTAL][MAXAMOUNT];		//has[n][m]��ʾǰ n �����еó���ӽ� m ��ֵʱ�Ƿ��õ�c[n]
int* c = NULL;						// ����Ӳ����ֵ������.

int calcClosestSum(int n, int m) {
	memset(f, 0, sizeof(int) * MAXTOTAL * MAXAMOUNT);
	memset(has, false, sizeof(bool) * MAXTOTAL * MAXAMOUNT);
	int i, j;
	int sec; // ��ʾ����c[i]���ֵ
	for (i = 1; i < n + 1; i++) {
		for (j = 1; j <= m; j++) {
			if (j - c[i] < 0)
				sec = 0; // ���������С�ڵ���j����˵��������ǷǷ�ֵ����������Ϊ0����ʾ��ֵ��Ч��
			else
				sec = f[i - 1][j - c[i]] + c[i]; // ��������¼������c[i]��ֵ��
			if (f[i - 1][j] > sec) {
				f[i][j] = f[i - 1][j];
			}
			else {
				f[i][j] = sec;
				has[i][j] = true;		//�õ�c[i]�� ��has[i][j]Ϊtrue ��ǰ ǰi��, ��������ֵj��������i��û��ѡ��.
			}
		}
	}
	return f[n][m];
}

// has[][] �����ж�����ʲôԪ�ص�����
bool cmp(const int& A, const int& B) {
	return A > B;
}

int main() {
	int n, m;
	cin >> n >> m;

	c = new int[n + 1];
	memset(c, 0, sizeof(int) * (n + 1));

	int i;
	for (i = 0; i < n; i++) {
		cin >> c[i + 1];
	}
	sort(&c[1], &c[n + 1], cmp);		//�Ӵ�С����

	int res = calcClosestSum(n, m);

	// ���������¼ѡ������ĸ��������ַ���: has[] ·�ɱ�.
	if (res == m) {		// �н�
		vector<int> v;
		while (m) {
			while (!has[n][m])
				n--;
			v.push_back(c[n]);
			m = m - c[n];
			// �е���·�ɱ�, ��ǰ�������, ����ĺ����Ҫ��һ�� c[��ǰ] ȥѰ����һ��
			n--;
		}
		for (i = 0; i < v.size() - 1; i++)
			cout << v[i] << ' ';
		cout << v[i] << endl;
	}
	else						//�޽�
		cout << "No Solution" << endl;

	return 0;
}

//int n, des;
//
//int arr[100010], dp[100010];
//
//// ��������, ���������С����!
//
//int main() {
//	in(n);
//	in(des);
//
//	for (int i = 1; i <= n; ++i) {
//		in(arr[i]);
//	}
//
//	sort(arr + 1, arr + 1 + n);
//
//
//	return 0;
//}

/*

Find More Coins (30)
ʱ������ 1000 ms �ڴ����� 65536 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
Eva loves to collect coins from all over the universe, including some other planets like Mars.  One day she visited a universal shopping mall which could accept all kinds of coins as payments.  However, there was a special requirement of the payment: for each bill, she must pay the exact amount.  Since she has as many as 104 coins with her, she definitely needs your help.  You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

��������:
Each input file contains one test case.  For each case, the first line contains 2 positive numbers: N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay).  The second line contains N face values of the coins, which are all positive numbers.  All the numbers in a line are separated by a space.


�������:
For each test case, print in one line the face values V1 <= V2 <= ... <= Vk such that V1 + V2 + ... + Vk = M.  All the numbers must be separated by a space, and there must be no extra space at the end of the line.  If such a solution is not unique, output the smallest sequence.  If there is no solution, output "No Solution" instead.
Note: sequence {A[1], A[2], ...} is said to be "smaller" than sequence  {B[1], B[2], ...} if there exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].

��������:
8 9
5 9 8 7 2 3 4 1

�������:
1 3 5




*/