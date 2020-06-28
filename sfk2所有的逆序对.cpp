#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;
int iQui, jQui, tQui, iResTmp;
ll ans = 0;

bool cmp(int a, int b, char **arr) {
	for (int i = 0; i < 10; ++i) {
		if (arr[a][i] > arr[b][i])
			return true;
		else if (arr[a][i] < arr[b][i])
			return false;
	}

	return true;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

void MyQuickSort(int left, int right, int rank[], char **arr) {
	if (left > right)
		return;

	tQui = rank[left];		// ȡ����׼��
	iQui = left;
	jQui = right;
	// ע��� left �� right ��ʱ�ķ��� iQui jQui ����, Ȼ��Ҫ�ȴ��ұ߿�ʼ��
	while (iQui != jQui) {
		while (cmp(rank[jQui], tQui, arr) && iQui < jQui)		// ���������ҵ���һ����С��(Ӧ�÷�����ߵ�)
			--jQui;
		while (cmp(tQui, rank[iQui], arr) && iQui < jQui)		// ���������ҵ���һ�������(Ӧ�÷����ұߵ�)
			++iQui;

		// ����λ��
		if (iQui < jQui) {
			Swap(rank, iQui, jQui);
		}
	}

	// ���ս���׼����λ
	rank[left] = rank[iQui];         // ע����仰!!!
	rank[iQui] = tQui;

	MyQuickSort(left, iQui - 1, rank, arr);				//����������ߵ�
	MyQuickSort(iQui + 1, right, rank, arr);				//���������ұߵ�
}


void MergeSort(int l, int r, int rank[], int mergeResTmp[]) {
	// ��ֹ����
	if (l >= r)
		return;

	int mid = (l + r) / 2;

	// �ȵݹ�!
	MergeSort(l, mid, rank, mergeResTmp);
	MergeSort(mid + 1, r, rank, mergeResTmp);
	
	// ��ʼ�鲢
	//for (int i = l; i <= r; ++i)
	//	printf("%d ", rank[i]);
	//printf("\n");

	for (int i = l; i < r; ++i) {
		cout << rank[i] << " ";
	}
	int i = l, j = mid + 1;
	iResTmp = l - 1;						// ע���������м���һ���ִ���!
	while (i <= mid && j <= r) {
		if (rank[i] <= rank[j]) {
			mergeResTmp[++iResTmp] = rank[i++];
		}
		else {
			mergeResTmp[++iResTmp] = rank[j++];
			ans += (mid - i + 1);				// ע������ ans �Ĵ���, �鲢�ڶ�����ʱ��, ǰ���ȫ������С, ���������
		}
	}

	// ʣ������Ū��ȥ
	while (i <= mid)
		mergeResTmp[++iResTmp] = rank[i++];
	while (j <= r)
		mergeResTmp[++iResTmp] = rank[j++];

	// �м���һ���ַŻ�ȥ, �����Ǵ� l ��ʼ�� r.
	for (int t = l; t <= r; ++t)
		rank[t] = mergeResTmp[t];
}


int main() {
	in(n);

	char **arr = new char*[n];
	int *rank = new int[n], *mergeResTmp = new int[n];

	for (int i = 0; i < n; ++i) {
		arr[i] = new char[12];
	}


	for (int i = 0; i < n; ++i) {
		scanf("%s", arr[i]);
		rank[i] = i;
	}
	
	MyQuickSort(0, n - 1, rank, arr);
	MergeSort(0, n - 1, rank, mergeResTmp);
	
	
	printf("wo yi yue du guan yu chao xi de shuo ming\n%lld\n", ans);

	for (int i = 0; i < n; ++i) {
		delete []arr[i];
	}
	delete[] rank;
	delete[] mergeResTmp;

	return 0;
}

/*

����һ���ַ������飬����������ֵ���һ������ַ����ڱ���С���ַ���ǰ�����ǳ��������ַ������һ��������ԡ�������Ҫ�ҵ����е�����Եĸ�����

����
��һ���������С���ڶ������Կո�ָ����ַ�������.

ע��Ԥ��֪��ÿ���ַ����ĳ��ȶ��� 10.

���
���е�����Ը���. �����Ҫ��������һ���ַ��������ǡ������Ķ����ڳ�Ϯ��˵�����ĺ���ƴ��.������е��ύ���ǽ���Ϊ�Ѿ���ȫ�Ķ����˽��ˡ����ڳ�Ϯ��˵��������.

ע�⣺����Ƚϴ����� long ���ͱ���.

��������
3
aaaaaaaaaa cccccccccc bbbbbbbbbb
�������
wo yi yue du guan yu chao xi de shuo ming
1


*/