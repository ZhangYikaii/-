#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

int a[14] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
int t[14] = { 0 };

// �ú����
// �鲢˳����� ������, Ȼ��ÿһ���ٷ�, ֱ��ֻ��������������ʱ��

void MergeSort(int *a, int left, int right, int *t) {
	if (right - left > 1) {
		int mid = left + (right - left) / 2;
		int tmpLeft = left, tmpMid = mid, iTarr = left;

		// �ݹ�
		MergeSort(a, left, mid, t);
		MergeSort(a, mid, right, t);

		while (tmpLeft < mid || tmpMid < right) {
			// ������鸴�Ƶ���ʱ�ռ�
			if (tmpMid >= right || (tmpLeft < mid && a[tmpLeft] <= a[tmpMid]))     // ע�����������!!!
				t[iTarr++] = a[tmpLeft++];
			// �Ұ����鸴�Ƶ���ʱ�ռ�
			else
				t[iTarr++] = a[tmpMid++];
		}
		// ��ʵֻ���ĸ��ȷ� �ĸ���ŵ�����? ������м�Ĵ� ���Ǻ����ٷ�, ֻ��ȫ��������������    ( ���԰ѵݹ�Ĵ�ע��, Ȼ����� 9 - 1 ���е�, Ȼ�󿴿���������)
		/*For(i, 0, 13)
			cout << t[i] << " ";*/
		// �Ӹ����ռ临�ƻ�A����
		for (iTarr = left; iTarr < right; ++iTarr) {
			a[iTarr] = t[iTarr];
			cout << a[iTarr] << " ";
		}
		cout << endl;
	}
}

int main() {
	MergeSort(a, 0, 9, t);
	
	return 0;
}
