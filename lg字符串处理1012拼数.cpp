#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()
#define MAX 100010

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}



int n;
string arr[30];

bool cmp(string a, string b) {
	return a + b > b + a;
}

//int num[30][100];

//void Init() {
//	for (int i = 1; i <= n; ++i) {
//		int tmp = arr[i];
//		num[i][0] = 0;
//		while (tmp != 0) {
//			num[i][++num[i][0]] = tmp % 10;
//			tmp /= 10;
//		}
//	}
//}
//
//// ע��ȡ��λ��Ҫ��ôȡ, ���������ȳ�ʼ����ȡ������
//int cmp(int a, int b) {
//	int i = num[a][0], j = num[b][0];
//	while (i >= 0 && j >= 0) {
//		if (num[a][i] > num[b][j])
//			return 1;
//		else if (num[a][i] < num[b][j])
//			return -1;
//		--i;
//		--j;
//	}
//	if (i >= 0)
//}

int main() {
	// ע�����ﲿ�ֵĴ�С��ϵ, ������, a ���� b ǰ������, �Ǿ���a > b ��
	// ע���ֵ�����Աȴ�С, ��ָstringֱ�ӱȴ�С, �ͺܷ���.

	in(n);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + 1 + n, cmp);

	for (int i = 1; i <= n; ++i) {
		cout << arr[i];
	}
	cout << endl;


	
	return 0;
}

/*
��Ŀ����
����nn��������(n��20)(n��20)�����������ӳ�һ�ţ����һ�����Ķ�λ������

���磺n=3n=3ʱ��33������1313,312312,343343���ӳɵ��������Ϊ��3433121334331213
���磺n=4n=4ʱ��44������77,1313,44,246246���ӳɵ��������Ϊ��74246137424613
���������ʽ
�����ʽ��
��һ�У�һ��������nn��

�ڶ��У�nn����������

�����ʽ��
һ������������ʾ��������

�����������
��������#1��
3
13 312 343
�������#1��
34331213

*/