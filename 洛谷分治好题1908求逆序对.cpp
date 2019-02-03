#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
using namespace std;
#define For(i, n, m) for(ll i = n;i < m; ++i)
#define ll long long

inline ll read() {
	char s;
	ll k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k * base;
}

ll a[500010], discre[500010], n, c[500010] = { 0 }, ans = 0, rankArr[500010] = { 0 };

bool CmpDiscretize(ll &x, ll &y) {
	return a[x] > a[y];
}

void Add(ll x)  //��״������� 
{
	for (; x <= n; x += (x&-x))
		c[x]++;  //��Ϊ����ֻ��Ҫ1�������Ҿ�д��c[x]++��
}
ll Sum(ll x)  //��״������ͣ�ͬ�����sum(x)
{
	ll s = 0;  //�����ı���
	for (; x>0; x -= (x&-x))  //�ۼ�
		s += c[x];
	return s;  //���ؽ��
}
/*
���鶼��1��ʼ��
����Ծ���������ai>aj��i<j�������, �����ʱajΪ��������, ai��ǰ������.
����ԭ����t[] = { 1, 3, 2 };
������ɢ������һ��a[] = { 3, 1, 2 }, a[]��ʾԪ���ǵڼ��������, ����a[1] = 3��ʾt[1] = 1��t[]���ǵ�3�����
Ȼ���a[]�����±����, ������״�����е�A[a[i]] = 1, ����iȫ���ӽ�ȥͬʱ��ǰi���.
������Ļ�, ���ǰ���t[]�Ĵ�����˳��, ����t[i]Ϊ����������ǰ����������.

����һ���㷨:
������ɢ����һ��a[] = { 2, 3, 1 }, a[i]��ʾ��i��Ԫ�ص��±�λ��
ͬ����a[]�����±����, ������״�����е�A[a[i]] = 1, ����iȫ���ӽ�ȥͬʱ��ǰi���.
������Ļ�, ���ǰ���t[]Ԫ�صĴӴ�С˳������Դ�Ԫ��Ϊ���������ĵ�ǰ����������. ����Ҳ�ǶԵ���Ϊ����ǰ������ֻҪ֪�������Ԫ�ش������Ԫ�ص�λ��
*/

int main() {
	// freopen("testdata.in", "r", stdin);
	n = read();
	for (ll i = 1; i <= n; ++i) {
		a[i] = read();
		discre[i] = i;
	}

	sort(discre + 1, discre + n + 1, CmpDiscretize);

	for (ll i = 1; i <= n; ++i)
		rankArr[discre[i]] = i;

	for (ll i = 1; i <= n; ++i) {
		Add(rankArr[i]);
		cout << ans << endl;
		ans += Sum(rankArr[i] - 1);
	}

	cout << ans << endl;


	return 0;
}

/*
����Ծ���������ai>aj��i<j������ԡ�֪�����������Ǿͱ���˭�����������һ������������������Ե���Ŀ��

����:
6
5 4 2 6 3 1


���:
11
*/