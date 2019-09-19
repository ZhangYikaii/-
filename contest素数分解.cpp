#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

struct Data {
	int a, b, c;
	Data(int aa, int bb, int cc) : a(aa), b(bb), c(cc) { }
};

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}


const int MAXN = 1000010;
bool isPrime[MAXN];
int prime[MAXN];
int cnt = 0;
void Init()
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= MAXN; i++) {
		if (isPrime[i]) {
			prime[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * prime[j] < MAXN; j++) {
			isPrime[i * prime[j]] = false;
			if (!(i % prime[j]))
				break;
		}
	}
	return;
}
//bool IsPrime(int n) {
//	if (n == 1)
//		return false;
//	if (n == 2 || n == 3)
//		return true;
//	if (n % 6 != 1 && n % 6 != 5)
//		return false;
//	for (register int i = 5; i * i <= n; i += 6) {
//		if (n % i == 0 || n % (i + 2) == 0)
//			return false;
//	}
//	return true;
//}

int ress[10000] = { 0 };

int main() {
	/*time_t a = time(0);*/
	Init();
	int l, r;
	vector<Data> v;
	in(l), in(r);

	FOR(i, l, r + 1) {
		// a = time(0);
		// cout << i << endl;
		if (i < cnt && isPrime[i] == true)
			continue;
		int t = i, countt = 0, k;
		do {
			for (k = 0; k < cnt && prime[k] * prime[k] <= t; ++k) {
				while (t % prime[k] == 0) {
					t /= prime[k];
					ress[countt++] = prime[k];
				}
				if (countt >= 1)
					break;
				if (t < MAXN && isPrime[t] == true)
					break;
			}
			/*time_t tt = time(0) - a;
			if (tt > 1)
				cout << i << "   kkk" << endl;*/
			if (prime[k] * prime[k] > t || countt >= 1 || t < cnt && isPrime[t] == true)
				break;
		} while (t != 1);
		if (countt == 2 && t == 1) {
			v.push_back(Data(i, ress[0], ress[1]));
			// cout << i << endl;
		}
		else if (countt == 1 && (t < cnt && isPrime[t] == true) || prime[k] * prime[k] > t) {
			v.push_back(Data(i, ress[0], t));
			// cout << i << endl;
		}
	}

	cout << v.size() << endl;
	for (auto i : v) {
		cout << i.a << " " << i.b << " " << i.c << endl;
	}
	return 0;
}


/*

���ӣ�https://ac.nowcoder.com/acm/contest/637/C
��Դ��ţ����

��Ŀ����
�������ʦ�԰���������Ȥ��������(semi-prime)�ǿ��Ա�ʾ�����������˻�����������4��10�ǰ���������Ϊ4=2��2��10=2��5����8���ǰ���������Ϊ8=2��2��2������֪��ĳһ��l��r�ı��������ж��ٸ����������������������̫�����ˣ�����������������
��������:
����һ�У�����������l,r(1<=l<=r<=1010��r-l<=105)����ʾ���������
�������:
��һ��һ����n����ʾһ���ж��ٸ���������
�����n�У�ÿ����������pi ai bi����ʾpi�ǰ�����������������ai��bi�ĳ˻�
�����n�����������յ�����˳�򡣶���ÿһ�У�ai<=bi
ʾ��1
����
����
1 10
���
����
4
4 2 2
6 2 3
9 3 3
10 2 5

*/