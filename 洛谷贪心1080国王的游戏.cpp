#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

// -------------------�����Ǵ� �мӸ߾���ģ��!!!
int now[20010], sum[20010], ans[20010], add[20010];
struct Node {
	int a;
	int b;
	long long a_b;
}node[1010];

int read() {
	int ans = 0, flag = 1;
	char ch = getchar();
	while ((ch>'9' || ch<'0') && ch != '-') ch = getchar();
	if (ch == '-') flag = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans*flag;
}
void times(int x) {
	memset(add, 0, sizeof(add));
	for (int i = 1; i <= ans[0]; i++) {
		ans[i] = ans[i] * x;
		add[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	for (int i = 1; i <= ans[0] + 4; i++) {
		ans[i] += add[i];
		if (ans[i] >= 10) {
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}
		if (ans[i] != 0) {
			ans[0] = max(ans[0], i);
		}
	}
	return;
}
int divition(int x) {
	memset(add, 0, sizeof(add));
	int q = 0;
	for (int i = ans[0]; i >= 1; i--) {
		q *= 10;
		q += ans[i];
		add[i] = q / x;
		if (add[0] == 0 && add[i] != 0) {
			add[0] = i;
		}
		q %= x;
	}
	return 0;
}
bool compare() {
	if (sum[0] == add[0]) {
		for (int i = add[0]; i >= 1; i--) {
			if (add[i]>sum[i]) return 1;
			if (add[i]<sum[i]) return 0;
		}
	}
	if (add[0]>sum[0]) return 1;
	if (add[0]<sum[0]) return 0;
}
void cp() {
	memset(sum, 0, sizeof(sum));
	for (int i = add[0]; i >= 0; i--) {
		sum[i] = add[i];
	}
	return;
}
bool cmp(Node a, Node b) {
	return a.a_b<b.a_b;
}
int main() {
	int n = read();
	for (int i = 0; i <= n; i++) {
		node[i].a = read(), node[i].b = read();
		node[i].a_b = node[i].a * node[i].b;
	}

	sort(node + 1, node + n + 1, cmp);

	// ��Ҫ����������ʱ��Ҫ�߾���
	ans[0] = 1, ans[1] = 1;
	for (int i = 1; i <= n; i++) {
		times(node[i - 1].a);
		divition(node[i].b);         // �����һ���˵�
		// ȡ���ֵ
		if (compare()) {
			cp();
		}
	}
	for (int i = sum[0]; i >= 1; i--)
		printf("%d", sum[i]);
	return 0;
}










// ��������û�п��Ǹ߾��ȵĴ�   long double ����û�õ�
/*
struct Data {
	int l, r;
	long double sum;
	bool operator >(Data a) {
		return sum > a.sum;
	}

	bool operator <(Data a) {
		return sum < a.sum;
	}

};

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
	return k*base;
}

// ������ȫ�����, ֤���Ķ���Ҫȥ��һ��, 
/////////////////////////////// �д������һ��Ҫ�ǵø߾���!!!!!!!

int main() {
	int n = read();
	int l = read(), r = read(), maxx = -1;
	Data arr[1010];
	For(i, 0, n) {
		arr[i].l = read();
		arr[i].r = read();
		arr[i].sum = l * r;
	}

	sort(arr, arr + n);

	For(i, 0, n) {
		long double curLeft = l;
		For(k, 0, i) {
			curLeft *= arr[k].l;
		}
		curLeft = floor(curLeft / arr[i].r);
		maxx = maxx > curLeft ? maxx : curLeft;
	}

	cout << maxx << endl;

	return 0;
}

*/

/*
���� n λ���ų�һ�ţ�����վ�ڶ������ǰ�档�źöӺ����еĴ󳼶����ù������͵����ɽ�ң�ÿλ�󳼻�õĽ�����ֱ��ǣ����ڸô�ǰ��������˵������ϵ����ĳ˻��������Լ������ϵ�����Ȼ������ȡ���õ��Ľ����

������ϣ��ĳһ���󳼻���ر��Ľ��ͣ�������������������°���һ�¶����˳��ʹ�û�ý������Ĵ󳼣������;����ܵ��١�ע�⣬������λ��ʼ���ڶ������ǰ�档


// ��һ���ǹ���

3
1 1
2 3
7 4
4 6

2

*/