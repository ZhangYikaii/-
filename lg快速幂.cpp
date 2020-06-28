#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

#define For(i, n, m) for(ll i = n;i < m; ++i)

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
	return k*base;
}

// �����Ǵ��Ŀ����ݺ���
// �� b �ֽ�ɶ����Ʊ�ʾ, ��һλ���� 1 �ٳ˵� ans ��
ll QuickPower(ll a, ll b)    // ����a��b�η�
{
	ll ans = 1, base = a;		// ansΪ�𰸣�baseΪa^(2^n)
	while (b > 0)				// b��һ���仯�Ķ��������������û������ ��λ�ƶ���
	{
		// ��һλ�� 1 => �˵� ans ��
		if (b & 1)				// &��λ���㣬b&1��ʾb�ڶ����������һλ�ǲ���1������ǣ�
			ans *= base;		// ��ans���϶�Ӧ��a^(2^n)

		base *= base;			// base�Գˣ���a^(2^n)���a^(2^(n+1)), ��סbase = a^(�����Ʊ�ʾ��ÿһλֵ) ʱ��׼���˵�ans��, ֻҪ��һλ�� 1 ����
		b >>= 1;				// λ���㣬b����һλ����101���10�������ұߵ�1�Ƶ��ˣ���10010���1001������b�ڶ����������һλ�Ǹոյĵ����ڶ�λ���������b & 1ʳ�ø���
	}
	return ans;
}
ll c;

/*

*/

// �����Ǵ�ȡģ��
ll QuickPowerMod(ll a, ll b)
{
	if (b == 0) {
		return 1 % c;
	}
	ll ans = 1, base = a;
	while (b > 0) {
		if (b & 1) {
			ans *= base;
			ans %= c;
		}

		base *= base;
		base %= c;
		b >>= 1;
	}
	return ans;
}



int main() {
	ll a = read(), b = read();
	c = read();

	printf("%lld^%lld mod %lld=%lld\n", a, b, c, QuickPowerMod(a, b));

	return 0;
}

/*

�ü�����ܿ�����a^b

������˵Ļ�������Ҫ���� b �Ρ��ÿ����ݣ���������� log_2(b) ���𣬺�ʵ�á�

*/