#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define in(a) a=read()

inline long long read() {
	long long X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

long long n, aLast, ans = 1;

long long getLast(long long a) {
	while (a % 10 == 0)
		a /= 10;
	return a % 10;
}

int main() {
	in(n);

	// ÿ��ȡһλ�ķ����Ǵ����!!! 
	// 14 != 87178291200�����������ǵĳ�����Ȼ��ȷ��result��������2��
	// 15 != 1307674368000��Ȼ����2 * 15 = 30��ȥ0����3������ȷ��8��
	// ��ʵ�ϣ����Ǵ�����Ӧ��12, 12 * 15 = 180��ȥ0����18����λ����ȷ��8��

	for (long long i = 2; i <= n; ++i) {
		aLast = getLast(i);
		ans = getLast(ans * aLast);
	}

	printf("%lld\n", ans);
	
	return 0;
}


/*


*/



