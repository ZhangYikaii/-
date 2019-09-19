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


// ���ÿ���, ÿ�ζ��ǰѻ�׼Ԫ�ع鵽��ȷ��λ��, ��������ǻ�ȡ��һ��Ԫ��λ��, arr[]: 1 ~ n.
// �������������һ�ֶ���.
int GetRank(int arr[], int n) {
	int pivot = arr[1], l = 1, r = n;
	
	while (l < r) {
		while (l < r && arr[r] >= pivot)		// �ŵ���һ��С��pivot��
			--r;
		arr[l] = arr[r];

		while (l < r && arr[l] <= pivot)		// �ŵ���һ������pivot��
			++l;
		arr[r] = arr[l];
	}
	arr[l] = pivot;					// ��Ҫ���˷Ż�ȥ

	return l;
}

int GetPosVal(int arr[], int n, int pos) {
	int tmp = GetRank(arr, n);		// ��һ�����ڵڼ���, �������ŵ���ȷλ��

	if (tmp == pos)
		return arr[pos];
	else if (tmp < pos)				// �ҵ��ĸ�С, ˵����pos���ҵ����Ǹ�����
		return GetPosVal(arr + tmp, n - tmp, pos - tmp);
	// ע������ tmp - 1, ��Ϊ�� tmp ��ǰ��, ����ֻ�� tmp - 1 ������ ( ������ 1 ��ͷ! )
	else
		return GetPosVal(arr, tmp - 1, pos);
}



int main() {
	int k, n, *arr, mid, midPos;
	in(k);
	in(n);
	arr = new int[n + 10];
	for (int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);

	// д�귢����ʵֻҪ��֤ pivot == ��λ��ֵ �����˿����Ѿ������˾Ϳ�����, ��Ϊ��������֮��ǰ�涼��С��pivot��, ���涼�Ǵ���pivot��, Ȼ����ѡ������һ�¾Ϳ�����

	midPos = (n + 1) / 2;
	mid = GetPosVal(arr, n, midPos);

	for (int i = midPos - 1; i >= midPos - k; --i) {
		// �ҵ�ǰ�벿��ǰ k �����
		int maxx = i;
		for (int j = i - 1; j >= 1; --j) {
			if (arr[j] > arr[maxx])
				maxx = j;
		}
		Swap(arr, i, maxx);
	}
	
	for (int i = midPos + 1; i <= midPos + k; ++i) {
		int minn = i;
		// ע��������ѡ�������ҵ���벿��ǰ k ��С��
		for (int j = i + 1; j <= n; ++j) {
			if (arr[j] < arr[minn])
				minn = j;
		}
		if (minn != i)
			Swap(arr, minn, i);
	}

	printf("%d", arr[midPos - k]);
	for (int i = midPos - k + 1; i <= midPos + k; ++i)
		printf(" %d", arr[i]);
	printf("\n");

	delete[] arr;

	return 0;
}


/*

��Ŀ����
����һ�������� a1,a2,...,an �Լ�һ����С�ĳ��� k���ҳ��⴮������λ�� m ����ӽ� m ��С�ڵ��� m �� k �������Լ���ӽ� m �Ĵ��ڵ��� m �� k ���������� 2k+1 ��������������������


��λ�����壺��������Ĵ�С��ż�� 2j����λ���Ǵ�С�������еĵ� j ��������������Ĵ�С������ 2j+1����λ���Ǵ�С�������еĵ� j+1 ������

����
��һ���� k ��ֵ�������ĳ��� n��

�ڶ������Կո������ n �������������һ���������пո�

���
���������е� 2k+1 �������Կո�ֿ������һ��������û�пո񡣽�����ܳ����ظ�������
��������
2 10
7 2 5 7 2 10 7 7 13 15
�������
5 7 7 7 7


*/