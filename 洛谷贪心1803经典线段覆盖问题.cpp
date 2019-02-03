#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

struct Data {
	int beg, end;
	bool operator >(Data a) {
		if (a.end == this->end) {
			return this->beg > a.beg;
		}
		return this->end > a.end;
	}

	bool operator <(Data a) {
		if (a.end == this->end) {
			return this->beg < a.beg;
		}
		return this->end < a.end;
	}
};

inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}

Data arr[1000010];

// �߶θ���̰������!!!
// ���ս���ʱ���С��������!!! ���һ��, ��ʵ����, ������Ϊ��ʼʱ��
int main() {
	int n = read();
	For(i, 0, n) {
		arr[i].beg = read();
		arr[i].end = read();
	}

	sort(arr, arr + n);

	int curBef = 0, res = 1;
	For(i, 1, n) {
		if (arr[i].beg >= arr[curBef].end) {
			++res;
			curBef = i;
		}
	}

	cout << res << endl;

	return 0;
}

/*
�����ʽ��
��һ����һ������n ��������n��ÿ����2������ai,bi(ai<bi)����ʾ������ʼ��������ʱ�䡣

�����ʽ��
һ���������μӵı�����Ŀ��

3
0 2
2 4
1 3
2
*/