#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define in(x) x = read()

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int p, kk, n;
string all, dic[10];
int dp[1000][50], sum[1000][1000];

// �ж��Ƿ��е����� l Ϊ��ͷ
int Check(int l, int r) {
	string tmp = all.substr(l, r - l + 1);
	for (int i = 0; i < n; ++i) {
		if (tmp.find(dic[i]) == 0)
			return true;
	}
	return false;
}

int main() {
	in(p);
	in(kk);
	string inputTmp;
	for (int i = 0; i < p; ++i) {
		cin >> inputTmp;
		all += inputTmp;
	}
	in(n);
	for (int i = 0; i < n; ++i)
		cin >> dic[i];

	// Ԥ���� sum
	// ���Ԥ��������ľ���!!! ��Ϊ��Ŀ��˵:"(ÿ���а����ĵ��ʿ��Բ����ص�����ѡ��һ������֮�����һ����ĸ�������á������ַ���this�пɰ���this��is��ѡ��this֮��Ͳ��ܰ���th)", ����ѡ��Ӻ���ǰ����, �� sum[k][i] = sum[k + 1][i], (k�����ַ���ǰ���i�Ǻ����), �������ֵ�õĺܺ�! k ��Check()������ ++.
	// ��ʵ��仰 �� ��Ϊ: �����ַ�����ĳ��λ��ͷ�ĵ�������ֻ��һ��
	int allLength = all.length();
	// k ��ǰ����Ǹ�, i �Ǻ�����Ǹ�
	for (int i = 0; i < 1000; ++i) {
		for (int k = 0; k < 1000; ++k)
			sum[i][k] = 0;
	}

	for (int i = allLength; i >= 0; --i) {
		for (int k = i; k >= 0; --k) {
			sum[k][i] = sum[k + 1][i];
			if (Check(k, i))
				++sum[k][i];
		}
	}

	// dp Ԥ����
	for (int i = 0; i <= 40; ++i)
		dp[0][i] = 0;
	for (int i = 0; i <= allLength; ++i)
		dp[i][0] = sum[0][i];
	for (int i = 1; i <= allLength; ++i)
		dp[i][i] = dp[i - 1][i - 1] + sum[i - 1][i - 1];

	for (int i = 0; i <= allLength; ++i) {
		// ע�� k < i ��Ϊ ���ִ��� �϶��� <= (���� - 1) ��
		for (int k = 0; k <= kk && k < i; ++k) {
			// dp �ؼ�! ö��֮ǰ���еĻ���!
			for (int j = 0; j < i; ++j)
				dp[i][k] = max(dp[i][k], dp[j][k - 1] + sum[j + 1][i]);
		}
	}

	printf("%d\n", dp[allLength][kk]);
	
	return 0;
}

/*
��Ŀ����
����һ�����Ȳ�����200����СдӢ����ĸ��ɵ���ĸ��(Լ��;���ִ���ÿ��20����ĸ�ķ�ʽ���룬�ұ�֤ÿ��һ��Ϊ20��)��Ҫ�󽫴���ĸ���ֳ�k�ݣ���ÿ���а����ĵ��ʸ����������������(ÿ���а����ĵ��ʿ��Բ����ص�����ѡ��һ������֮�����һ����ĸ�������á������ַ���this�пɰ���this��is��ѡ��this֮��Ͳ��ܰ���th)��

�����ڸ�����һ��������6�����ʵ��ֵ��С�

Ҫ��������ĸ�����

���������ʽ
�����ʽ��
ÿ��ĵ�һ����2��������(p,k)

pp��ʾ�ִ�������,kk��ʾ��Ϊkk�����֡�

��������pp�У�ÿ�о���2020���ַ���

�ٽ�������11��������ss����ʾ�ֵ��е��ʸ�����

��������ss�У�ÿ�о���11�����ʡ�

�����ʽ��
11���������ֱ��Ӧÿ��������ݵ���Ӧ�����

�����������
��������#1��
1 3
thisisabookyouareaoh
4
is
a
ok
sab
�������#1��
7

1 1
aaaaaa
1
aaa

*/