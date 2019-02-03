#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

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

int a[30010], used[30010] = { false };

// ��ɢ�ķ��� Ҫ���������! �ٶȱȽϿ�, ����ÿ�ζ���һ��! ����������������! ��Ҳ��̰�ĵ�ϰ��! �����������ɨһ���ȥ����
int main() {
	int w = read(), n = read(), maxIndext = -1, maxW = -1, res = 0;
	For(i, 0, n) {
		a[i] = read();
	}

	For(i, 0, n) {
		if (used[i] == false) {
			maxIndext = -1, maxW = -1;
			For(k, 0, n) {
				if (used[k] == false && i != k && a[i] + a[k] <= w && a[i] + a[k] >= maxW) {
					maxIndext = k;
					maxW = a[i] + a[k];
				}
			}
			used[i] = true;
			if (maxIndext != -1)
				used[maxIndext] = true;
			++res;
		}
	}

	cout << res << endl;
	return 0;
}

/*
Ԫ���쵽�ˣ�Уѧ���������ָ����������ļ���Ʒ���Ź�����Ϊʹ�òμ�����ͬѧ����� �ļ���Ʒ��ֵ��Ծ��⣬��Ҫ�ѹ����ļ���Ʒ���ݼ۸���з��飬��ÿ�����ֻ�ܰ�����������Ʒ�� ����ÿ�����Ʒ�ļ۸�֮�Ͳ��ܳ���һ��������������Ϊ�˱�֤�ھ����̵�ʱ���ڷ������м���Ʒ������ϣ���������Ŀ���١�

�ҳ����з��鷽���з��������ٵ�һ�֣�������ٵķ�����Ŀ��

// �����һ����ÿ������, �ڶ���������
����:
100
9
90
20
20
30
50
60
70
80
90

���:
6

*/