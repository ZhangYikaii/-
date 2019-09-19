#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

#define in(x) x=read()

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

int main() {
	int k, n, *arr, mid, midPos;
	in(n);
	arr = new int[n + 10];
	for (int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);

	in(k);

	// ��ȡ��������? ��Ϊ����

	int bef = 1, aft = n;
	while (bef < aft) {
		if (arr[bef] + arr[aft] < k)
			++bef;
		else if (arr[bef] + arr[aft] > k)
			--aft;
		else {
			printf("%d %d\n", arr[bef], arr[aft]);
			++bef;
			--aft;
		}
	}

	delete[] arr;

	return 0;
}


/*

��Ŀ����
����һ�� int ���� arr��Ԫ�ذ������������Ҹ�����ͬ��������һ��Ŀ���� c�������ҳ� arr �����е����� a, b��ʹ�� a + b = c��
����
����Ϊ���У���һ��Ϊ arr ��Ԫ�ظ������ڶ���Ϊ arr��Ԫ���Կո�ָ���������ΪĿ���� c��
���
���з������������� a, b��a �� b �Կո�ֿ���ÿ������ռ��һ�С�ÿ���� a < b���������������ĵ�һ������Ҳ���� a ��ֵ���������С�
��������
9
-2 0 1 2 3 5 6 8 10
8
�������
-2 10
0 8
2 6
3 5

*/