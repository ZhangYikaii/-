#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}


int main() {
	int n, k, *arr, res = 0;
	in(n);
	in(k);

	arr = new int[n + 10];
	for (int i = 0; i < n; ++i) {
		in(arr[i]);
	}
	
	sort(arr, arr + n);

	for (int i = 0; i < n; ++i) {
		int l = i + 1, r = n - 1;
		arr[i] = -arr[i] + k;
		// ��ȡ
		while (l < r) {
			if (arr[l] + arr[r] > arr[i]) {
				--r;
				if (r <= l)
					break;
			}
			else if (arr[l] + arr[r] < arr[i]) {
				++l;
				if (r <= l)
					break;
			}
			else {
				++res;
				--r;
				++l;
				if (r <= l)
					break;
			}
		}
	}

	printf("wo yi yue du guan yu chao xi de shuo ming\n%d\n", res);

	delete[] arr;
	return 0;
}


/*

��Ŀ����
һ��û���ظ�Ԫ�ص��������飬����ĳ���������ҵ�����triple֮�͵��ڸ������ĸ���������triple�������еĲ�ͬ��3������
����
���鳤�ȣ��Լ�Ҫ�������֮�ͣ�

û���ظ�Ԫ�ص����顣

���
���Ķ���Ϯ��˵����

����triple�ĸ�����

��������
6 3
8 0 -5 -2 6 -1
�������
wo yi yue du guan yu chao xi de shuo ming
2


*/