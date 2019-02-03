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
	return k * base;
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

bool isFir = true;

/*
// ���´�ţ��!!!
// ��ʵ���Ƿ���� 1��ʱ����2(1), 
string run(int x, int i = 0, string s = string("")){
	if (x == 0)
		return string("0");
	do {
		if (x & 1)
			s = (i == 1 ? "2" : "2(" + run(i) + ")") + (s == "" ? "" : "+") + s;
		// ƴ���ַ�����Ӧ���⣬Ҫ�ѵʹη����ں���, ����һֱ������ǰƴ����.
	} while (++i, x >>= 1);	// ÿ��������λ
	return s;
}

int main(){
	int x; 
	cin >> x;
	cout << run(x) << endl;
}
*/

// �ؼ����ǰѼӺŷ�������!!!
void Out(int a) {
	if (a == 0) {
		if (isFir == true)
			isFir = false;
		printf("0");
	}
	else if (a == 1) {
		if (isFir == true)
			isFir = false;
	}
	else if (a == 2) {
		if (isFir == true)
			isFir = false;
		printf("2");
	}

	else {
		int arr[30], ia = 0;
		while (a > 0) {
			if (a & 1)
				arr[ia] = 1;
			else
				arr[ia] = 0;
			++ia;
			a >>= 1;
		}

		isFir = true;
		// ץס�ݹ��ӽṹ, �����滻��������һ��!
		for (int k = ia - 1; k >= 0; --k) {
			if (arr[k] == 1 && isFir == true) {
				if (k != 1) {
					printf("2(");
					Out(k);
					printf(")");
				}
				else {
					if (isFir == true)
						isFir = false;
					printf("2");
				}
			}
			else if (arr[k] == 1 && isFir == false) {
				printf("+");
				if (k != 1) {
					printf("2(");
					Out(k);
					printf(")");
				}
				else {
					if (isFir == true)
						isFir = false;
					printf("2");
				}
			}
		}
	}
}

int main() {
	int a = read();
	if (a == 1)
		cout << "1" << endl;
	Out(a);

	printf("\n");

	return 0;
}

/*
����:
137

���:
2(2(2)+2+2(0))+2(2+2(0))+2(0)

����:
1315

���:
2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
*/