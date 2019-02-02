#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <functional>
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



int main() {
	int n = read(), tmp = 0, a, b, sum = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	For(i, 0, n) {
		tmp = read();
		q.push(tmp);
	}
	if (n == 1) {
		cout << tmp << endl;
		return 0;
	}

	while (true) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		sum += a + b;
		if (q.empty())
			break;
		q.push(a + b);
	}

	cout << sum << endl;

	return 0;
}

/*
������ 3 �ֹ��ӣ���Ŀ����Ϊ 1 �� 2 �� 9 �������Ƚ� 1 �� 2 �Ѻϲ����¶���ĿΪ 3 ���ķ�����Ϊ 3 �����ţ����¶���ԭ�ȵĵ����Ѻϲ����ֵõ��µĶѣ���ĿΪ 12 ���ķ�����Ϊ 12 �����Զ���ܹ��ķ����� = 3+12=15 ������֤�� 15 Ϊ��С�������ķ�ֵ��

��ʵ�Ƕ������һ����, ע��ע��ÿʱÿ�̶���ȡ��С����������, ֻȡ��С/�������������, ���ö���!!!
*/

// 1 2 3 4
// (1 + 2) + (1 + 2 + 3) + (1234)
