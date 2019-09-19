#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;

#define in(x) x=read()

#define FOR(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

// beg: 2019��4��28��19:09:46
// end: 2019��4��28��19:40:18

int n, k, arr[100010] = { 0 }, mapp[100010] = { 0 };
ll res = 0;

int main() {
	in(n);
	in(k);
	FOR(i, n) {
		in(arr[i]);
	}

	FOR(i, n) {
		mapp[arr[i]]++;
	}

	FOR(i, n) {
		if (mapp[arr[i]] != 0) {
			if (arr[i] == k - arr[i]) {
				res += mapp[arr[i]] * (mapp[arr[i]] - 1) / 2;
			}
			else {
				res += mapp[arr[i]] * mapp[k - arr[i]];
			}
			mapp[arr[i]] = 0;
		}
	}

	cout << res << endl;

	return 0;
}


/*

���ӣ�https://ac.nowcoder.com/acm/contest/637/B
��Դ��ţ����

��Ŀ����
������ʦ��ѧ���У�ÿһ��ͬѧ����һ������ֵ����������ʦ����ѡһ������С�飬���и���ֵ�Ҫ��
��Ҫ������ͬѧ������ֵ������������ʦһ��������ֵһ�������������æ�������ж�������ѡѧ�����С��ķ�ʽ��ע�ⲻͬѧ������ֵ������ͬ��
��������:
��һ��һ������n(2<=n<=100000)��һ������t(1<=t<=100000), ��ʾ����ʦѧ���ĸ�������������ֵ��
������һ����n���Ǹ���������i���Ǹ�������ʾ��i��ѧ��������ֵ������ÿ��ѧ��������ֵ�����ᳬ��t��
�������:
���һ�У���ʾ����ʦ����ѡ����С��ķ�����
ʾ��1
����
����
4 5
2 3 3 2
���
����
4
˵��
����ѡ��ķ�ʽ��(1,2),(1,3),(2,4),(3,4)��4��
ʾ��2
����
����
5 4
2 2 2 2 2
���
����
10

*/