#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;


// �ﵽ��������� ��ѧ �ؼ�����ѧ�� ����ö�ٶ��ǳ�ʱ��.
inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
ll a, b, tmp;

// ���� oj2.md

int main() {
	in(a);
	in(b);

	for (ll x = 1; x <= b; ++x) {
		tmp = a * x;
		if (tmp - b * (tmp / b) == 1) {
			printf("%d\n", x);
			return 0;
		}
	}

	return 0;
}


/*


*/