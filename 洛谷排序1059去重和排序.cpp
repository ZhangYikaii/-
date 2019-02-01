#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

int a[100010], used[1010] = { 0 };
inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-'&&s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}
void write(int x) {
	if (x<0)
	{
		putchar('-');
		write(-x);
	}
	else
	{
		if (x / 10)write(x / 10);
		putchar(x % 10 + '0');
	}
}

void MyCopyQuickSort(int left, int right) {
	int i, j, temp;
	if (left > right)
		return;

	temp = a[left];		// ȡ����׼��
	i = left;
	j = right;
	// ע��� left �� right ��ʱ�ķ��� i j ����, Ȼ��Ҫ�ȴ��ұ߿�ʼ��
	while (i != j) {
		while (a[j] >= temp && i < j)		// ���������ҵ���һ����С��(Ӧ�÷�����ߵ�)
			--j;
		while (a[i] <= temp && i < j)		// ���������ҵ���һ�������(Ӧ�÷����ұߵ�)
			++i;

		// ����λ��
		if (i < j) {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

	// ���ս���׼����λ
	a[left] = a[i];         // ע����仰!!!
	a[i] = temp;

	MyCopyQuickSort(left, i - 1);			//����������ߵ�
	MyCopyQuickSort(i + 1, right);			//���������ұߵ�
}


int main() {
	int n = read();
	For(i, 0, n) {
		a[i] = read();
		if (used[a[i]] == 1) {
			--n;
			--i;
		}
		else {
			used[a[i]] = 1;
		}
	}

	MyCopyQuickSort(0, n - 1);

	printf("%d\n", n);
	if (n > 0)
		printf("%d", a[0]);
	For(i, 1, n) {
		printf(" %d", a[i]);
	}
	printf("\n");

	return 0;
}
