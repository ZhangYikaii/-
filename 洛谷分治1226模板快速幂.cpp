#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
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

// �����Ǵ��Ŀ����ݺ���
// �� b �ֽ�ɶ����Ʊ�ʾ, ��һλ���� 1 �ٳ˵� ans ��
int QuickPower(int a, int b)    // ����a��b�η�
{
	int ans = 1, base = a;		// ansΪ�𰸣�baseΪa^(2^n)
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
int c;

// �����Ǵ�ȡģ��
int QuickPowerMod(int a, int b)   
{
	int ans = 1, base = a;		
	while (b > 0) {
		if (b & 1) {
			ans *= base;
			ans %= c;
		}

		base *= base;	
		b >>= 1;		
	}
	return ans;
}



int main() {
	int a = read(), b = read();
	c = read();

	printf("%d^%d mod %d=%d\n", a, b, c, QuickPowerMod(a, b));

	return 0;
}

/*

�ü�����ܿ�����a^b

������˵Ļ�������Ҫ���� b �Ρ��ÿ����ݣ���������� log_2(b) ���𣬺�ʵ�á�

*/