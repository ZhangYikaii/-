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

// ����ؼ�����·��ѹ��

int f[10005], far[10005], a[10005], flag[10005], p, s, t, n;

int main()
{
	scanf("%d", &p);
	scanf("%d%d%d", &s, &t, &n);
	if (s == t) //��������ж�
	{
		int cont = 0, qaq;
		for (int i = 1; i <= n; ++i)scanf("%d", &qaq), cont += ((qaq%s) == 0);
		printf("%d\n", cont); return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1); 
	
	a[0] = 0; f[0] = 0;

	far[n + 1] = min(p - a[n], 100); 
	p = 0; //�����յ������һ����ľ���
	for (int i = 1; i <= n; i++)
		far[i] = min(a[i] - a[i - 1], 90), p += far[i], flag[p] = 1; // ����·�����洢���̺���յ���벢���ʯͷλ��
	p += far[n + 1];
	for (int i = 1; i <= p + 9; i++) {
		f[i] = INT_MAX - 1;
		for (int j = s; j <= t; j++)
		if (i >= j)
			f[i] = min(f[i], f[i - j] + flag[i]);
	}
	int minn = INT_MAX - 1;
	for (int i = p; i <= p + 9; i++) // ��Ϊ���ܿ��������߽���t<=10������յ��p~p+9��ȡ��Сֵ
		minn = min(minn, f[i]);
	printf("%d", minn);
}

/*
��������, ������Ծ��������������������, ���������ϵ�һЩ�ض���, �����ٲȵ�������Щ�ض���.

<h2>���������ʽ</h2>
<strong>�����ʽ��</strong><br>
<p><p>��һ����$1$��������$L(1 \le L \le 10^9)$����ʾ��ľ�ŵĳ��ȡ�</p>
<p>�ڶ�����$3$��������$S,T,M$���ֱ��ʾ����һ����Ծ����С���룬�����뼰����ʯ�ӵĸ���������$1 \le S \le T \le 10$,$1 \le M \le 100$��</p>
<p>��������$M$����ͬ���������ֱ��ʾ��$M$��ʯ���������ϵ�λ�ã����ݱ�֤�ŵ������յ㴦û��ʯ�ӣ����������ڵ�����֮����һ���ո������</p></p>
<strong>�����ʽ��</strong><br>
<p><p>һ����������ʾ���ܹ���������Ҫ�ȵ���ʯ������</p></p>

�����������
��������#1��
10
2 3 5
2 3 5 6 7

�������#1��
2

*/