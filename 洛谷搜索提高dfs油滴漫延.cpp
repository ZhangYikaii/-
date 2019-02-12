#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

// ������Ŀ������ double ����, ��Ҫһֱ��ס��double!!!, double�Ĳ��ử����ͼ, ���ǻ������, ע��һ��ȫ��double!!! ���Կ������б� -> ����

const double PI = 3.1415926535;

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}
// dfs ��һ�������ж�Ҫ���ͼ��

double min(double a, double b) {
	return a > b ? b : a;
}

double n, ax, ay, bx, by, minn = 0xfffffff, allArea;
double xarr[2010], yarr[2010], usedArr[2010] = { 0 }, r[2010] = { 0 };

double Distant(int a, int b) {
	return sqrt((xarr[a] - xarr[b]) * (xarr[a] - xarr[b]) + (yarr[a] - yarr[b]) * (yarr[a] - yarr[b]));
}

double GetR(int who) {
	double ans = 0xfffffff;
	// �Ȳ������������͵�
	for (int i = 1; i <= n; ++i) {
		if (i != who && r[i] != 0) {
			double dis = Distant(who, i);
			// �������͵�����
			if (dis < r[i])
				return 0;

			if (ans > dis - r[i])
				ans = dis - r[i];
		}
	}

	// �ٲ��������߽�
	double minx = min(abs(xarr[who] - ax), abs(xarr[who] - bx)), miny = min(abs(yarr[who] - ay), abs(yarr[who] - by));
	ans = min(min(minx, miny), ans);
	return ans;
}

void dfs(int num, double used) {
	if (num == n) {
		double tmp = allArea - used;
		if (minn > tmp)
			minn = tmp;
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (usedArr[i] == 0) {
			r[i] = GetR(i);
			usedArr[i] = 1;
			dfs(num + 1, used + PI * r[i] * r[i]);
			usedArr[i] = 0;
		}
	}
}


int main() {
	n = read();
	scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);

	allArea = abs((bx - ax) * (by - ay));

	for (int i = 1; i <= n; ++i) {
		scanf("%lf%lf", &xarr[i], &yarr[i]);
	}

	dfs(0, 0);
	printf("%d\n", (int)(minn + 0.5));


	return 0;
}

/*
��һ�������ο���������N��0��N��6��������ĵ㣬�������κ�һ�����Ϸ�һ����С���͵Σ���ô����͵λ�һֱ��չ��ֱ���Ӵ��������͵λ��߿��ӵı߽硣�����һ���͵���չ��ϲ��ܷ�����һ���͵Ρ���ôӦ�ð���������˳������N�����Ϸ����͵Σ�����ʹ������Ϻ������͵�ռ�ݵ����������أ�����ͬ���͵β����໥�ںϣ�

ע��Բ�������ʽV=pi*r*r������rΪԲ�İ뾶��

���������ʽ
�����ʽ��
��1��һ������N��

��2��Ϊ�����α߿�һ�����㼰��ԽǶ�������꣬x,y,x��,y����

����ȥN�У�ÿ����������xi,yi����ʾ���ӵ�N��������ꡣ

�������е����ݶ���[-1000��1000]�ڡ�

�����ʽ��
һ�У�һ�������������κ���ʣ�����С�ռ䣨����������������

�����������
��������#1��
2
20 0 10 10
13 3
17 7


�������#1��
50


*/