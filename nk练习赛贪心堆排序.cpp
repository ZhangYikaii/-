#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

/*

int v[100010], s[100010];
int indv[100010], inds[100010];


// bq�Ǵ����, sq��С����.
priority_queue<int> bq;
priority_queue<int, vector<int>, greater<int> > sq;

bool cmps(int a, int b) {
	return s[a] > s[b];
}

bool cmpv(int a, int b) {
	return v[a] < v[b];
}

int main() {
	int n;
	in(n);
	
	For(i, 0, n) {
		indv[i] = i;
		inds[i] = i;
	}

	For(i, 0, n) {
		in(v[i]);
		in(s[i]);
	}

	sort(indv, indv + n, cmpv);
	sort(inds, inds + n, cmps);

	int curLimit = 0;
	for (int i = n - 1; i >= 0; --i) {

	}
	For(i, 0, n) {
		curLimit = s[inds[i]];

	}
	return 0;
}

*/


// д����, �����Ǵ�:
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std; 

int n;
long long ans, curLimit, res;

// һ��ʿ�������ƺ�valҪ��������, ����һ���ṹ�� + ����.
struct node { 
	long long v, s;
}a[100001];

inline bool cmp(node x, node y) { 
	return x.s > y.s; 
}

priority_queue<long long> q;

int main()
{
	scanf("%d", &n);
	for (register int i = 1; i <= n; i++) 
		scanf("%lld%lld", &a[i].v, &a[i].s);

	sort(a + 1, a + 1 + n, cmp);
	curLimit = n;

	// ���� s[] (limit) �Ӵ�С˳�����.
	for (register int i = 1; i <= n; i++) {
		curLimit = a[i].s;

		// ��̬ά��һ��С����. �����Ҫ, ��Ϊÿһʱ�̶�ÿһ�Ӵ�С��������, ɾ�˾��ǴӶ�̬��С��������ɾ��.
		q.push(-a[i].v);
		ans += a[i].v;

		// ���������������, �ʹ�С��������ɾ.
		while (q.size() > curLimit)
			ans += q.top(), q.pop();
		res = max(res, ans);
	}
	printf("%lld", res);
}

/*

���ӣ�https://ac.nowcoder.com/acm/contest/1080/C
��Դ��ţ����

��Ŀ����
��һ����Ϸ�У�tokitsukaze��Ҫ��n��ʿ����ѡ��һЩʿ�����һ����ȥ�򸱱���
��i��ʿ����ս��Ϊv[i]���ŵ�ս������������ʿ����ս��֮�͡�
������Щʿ���������Ҫ�����ѡ�˵�i��ʿ�������ʿ��ϣ���ŵ�����������s[i]��(�����ѡ��i��ʿ������û��������ơ�)
tokitsukaze��֪�����ŵ�ս�����Ϊ���١�
��������:
��һ�а���һ��������n(1��n��10^5)��
������n�У�ÿ�а���2��������v,s(1��v��10^9,1��s��n)��
�������:
���һ������������ʾ�ŵ����ս����
ʾ��1
����
����
2
1 2
2 2
���
����
3
ʾ��2
����
����
3
1 3
2 3
100 1
���
����
100

*/