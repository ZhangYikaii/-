#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()
#define xw x+xway[i]
#define yw y+yway[i]

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
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


// ��һ���..

const int maxn = 5e5 + 10;

int mergeResTmp[maxn] = { 0 }, iResTmp = 0;			// ��ʱ��Ź鲢���.
long long ans = 0;
int a[maxn];
void MergeSort(int l, int r) {
	// ��ֹ����
	if (l >= r)
		return;

	int mid = (l + r) / 2;

	// �ȵݹ�!
	MergeSort(l, mid);
	MergeSort(mid + 1, r);

	// ��ʼ�鲢
	//for (int i = l; i <= r; ++i)
	//	printf("%d ", a[i]);
	//printf("\n");

	int i = l, j = mid + 1;
	iResTmp = l - 1;						// ע���������м���һ���ִ���!
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) {
			mergeResTmp[++iResTmp] = a[i++];
		}
		else {
			mergeResTmp[++iResTmp] = a[j++];
			ans += mid - i + 1;				// ע������ ans �Ĵ���, �鲢�ڶ�����ʱ��, ǰ���ȫ������С, ���������
		}
	}

	// ʣ������Ū��ȥ
	while (i <= mid)
		mergeResTmp[++iResTmp] = a[i++];
	while (j <= r)
		mergeResTmp[++iResTmp] = a[j++];

	// �м���һ���ַŻ�ȥ, �����Ǵ� l ��ʼ�� r.
	for (int t = l; t <= r; ++t)
		a[t] = mergeResTmp[t];
}

int n;

int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(a[i]);
	}

	MergeSort(1, n);

	printf("%lld\n", ans);


	return 0;
}
//
//
//
//// �����Ǵ�, ��һ���Լ�д.
//using namespace std;
//const int maxn = 5e5 + 10;
//int n, a[maxn], r[maxn];
//long long ans = 0;
//void mergesort(int s, int t)
//{
//	int i, j, k, m;
//	if (s == t) return;
//	m = (s + t) / 2; //ȡ�е�
//	mergesort(s, m); //�ݹ�������
//	mergesort(m + 1, t); //�ݹ�������
//	i = s, j = m + 1, k = s;
//	//��·�鲢�����򣩹���
//	while (i <= m && j <= t) {
//		if (a[i] <= a[j]) {
//			r[k] = a[i]; i++; k++;
//		}
//		else {
//			r[k] = a[j]; j++; k++;
//			ans += m - i + 1;				// ע������ ans �Ĵ���
//		}
//	} //��������ʣ���Ԫ�ؽ���r����
//	while (i <= m) { 
//		r[k] = a[i]; 
//		i++;
//		k++;
//	}
//	while (j <= t) { r[k] = a[j]; j++; k++; }
//	for (int i = s; i <= t; i++) a[i] = r[i]; //���鸳��
//}
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//	mergesort(1, n); //�鲢��������
//	printf("%lld\n", ans); //������long long
//	return 0;
//}
//


/*

��Ŀ����
�ƽ��˷���֮�СFF������ͨ�����µĵ�·�������ߵ���ײ�ʱ��������ǰ����һ�Ⱦ�ʯ�ţ����ϵ����һ���Ŵ��˽���ĳ�ֻ��ͼ������ʯ���Ϸ��ùŴ���д�š���ĵ��á���СFF��������Ӧ�þ������ҵ��Ų��ˡ������ڵ���������δ������š���

��ϸ�о������������ϵ�ͼ�������˵���Ŵ�����Ϊֻ�����߲��������׽ӽ������ġ����������������ͨ��һ����ʽѡ�γ�������ʽ�����ָ���������˵�����Ϊ���ĺ�ѡ��д��һ����������֣��������ǽ���һ�ֲ��������������������ڵ�����Ԫ�ء��������ٵĽ�������ʹԭ���б�ɲ��½����е��˼�����һ�����ߡ�

СFF��������ͬ������n�����֡���������Ϊ�������ŵ��ؾ������ҵ���������б�ɲ��½���������Ҫ����С��������СFF���ᡭ��ֻ�����ҵ����㣬����Ӧ�³�֮���������߷֡���

���������ʽ
�����ʽ��
��һ��Ϊһ������n����ʾ���г���

�ڶ���Ϊn����������ʾ������ÿ��Ԫ�ء�

�����ʽ��
һ������ans�������ٲ���������

�����������
��������#1��
4
2 8 0 3
�������#1��
3

*/
