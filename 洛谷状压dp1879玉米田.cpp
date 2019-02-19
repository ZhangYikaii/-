#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
#define in(a) a=read()
#define N 1005
#define mod 10007

using namespace std;
const int M = 1e9;
int m, n, f[13][4096], F[13], field[13][13];
// max state: (11111111111)2 = (4095)10
bool state[4096];
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			cin >> field[i][j];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			F[i] = (F[i] << 1) + field[i][j];						// �ѿɲ����ԷŲݵصı�־ת��Ϊÿ�ж����Ʊ�ʾ
	}

	// F[i]: state on line i
	int MAXSTATE = 1 << n;
	for (int i = 0; i < MAXSTATE; i++)
		state[i] = ((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0);	// ��������״̬�Ƿ�����1����������
	f[0][0] = 1;

	// f[i][j] ��ʾ: �ڵ� i ��, �� j ״̬�ķ�����		// ����!!! �������������ӽṹ, ���ǵ� i ��֮ǰҲ������н��
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < MAXSTATE; j++) {
			// �ڵ� i ��, �����ǰ״̬ j(01����) 1. ����1������, 2. ���㲻�ڲ����ֲݵĵط�, ���ֻ�Ǳ�����Ҫ���������.
			if (state[j] && ((j & F[i]) == j)) {
				// ����һ�����п���������һ�е�״̬, ��ʼ����
				for (int k = 0; k < MAXSTATE; k++) {
					if ((k & j) == 0) {
						f[i][j] = (f[i][j] + f[i - 1][k]) % M;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < MAXSTATE; i++)
		ans += f[m][i], ans %= M;
	cout << ans << endl;
	return 0;
}


//
//struct Data {
//	int arr[13];
//	Data() {
//		for (int i = 0; i < 13; ++i)
//			arr[i] = 0;
//	}
//};
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//// ��Ҫ����: ����һ�е�ȷ��ѡ��, ����010100, ����ȷ��������ѡ���µ���һ��ѡ�����.
//int m, n, canDo[15][15];
//
//int main() {
//	in(m);
//	in(n);
//
//	for (int i = 1; i <= m; ++i) {
//		for (int k = 1; k <= n; ++k) {
//			in(canDo[i][k]);
//		}
//	}
//
//
//
//
//	return 0;
//}

/*
ũ����John������һ�鳤���ε���������������������ֳ�M��N��(1 �� M �� 12; 1 �� N �� 12)��ÿһ����һ�������ε����ء�John�����������ϵ�ĳ������������ζ�Ĳݣ���������ţ�����á�

�ź����ǣ���Щ�����൱ƶ񤣬���������ֲݡ����ң���ţ��ϲ����ռһ��ݵصĸо�������John����ѡ���������ڵ����أ�Ҳ����˵��û��������ݵ��й����ߡ�

John��֪������������ǲݵص��ܿ�������ô��һ���ж�������ֲ�����ɹ���ѡ�񣿣���Ȼ������������ȫ�ķ�Ҳ��һ�ַ�����

���������ʽ
�����ʽ��
��һ�У���������M��N���ÿո������

��2����M+1�У�ÿ�а���N���ÿո������������������ÿ�����ص�״̬����i+1�������˵�i�е����أ�����������Ϊ0��1����1�Ļ�����ʾ��������㹻���֣�0���ʾ������ز��ʺ��ֲݡ�

�����ʽ��
һ�������������������ܷ���������100,000,000��������

�����������
��������#1��
2 3
1 1 1
0 1 0
�������#1��
9


*/