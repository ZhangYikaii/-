#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;
typedef long long ll;

struct Data {
	long long next, to;
	Data() : next(0), to(0) { }
};

#define in(x) x=read()

inline long long read() {
	long long X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

long long MyMin(long long a, long long b) {
	return a > b ? b : a;
}

void Swap(long long arr[], long long i, long long j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

long long n, head[300000] = { 0 }, cnt = 0, w[300000] = { 0 };
Data arr[1000000];
long long ans = 0, maxx = -1;
bool used[300000] = { false };

void add(long long a, long long b) {
	arr[++cnt].next = head[a];
	head[a] = cnt;

	arr[cnt].to = b;
}

int main() {
	long long xt, yt;
	in(n);
	for (long long i = 1; i <= n - 1; ++i) {
		in(xt);
		in(yt);
		add(xt, yt);
		add(yt, xt);
	}

	for (long long i = 1; i <= n; ++i) {
		in(w[i]);
	}

	for (long long i = 1; i <= n; ++i) {
		used[i] = true;
		//  cout << "-" << i << endl;
		for (long long nei = head[i]; nei != 0; nei = arr[nei].next) {
			long long &neiPoint = arr[nei].to;
			for (long long goal = head[neiPoint]; goal != 0; goal = arr[goal].next) {
				if (used[arr[goal].to] == false) {
					//  cout << arr[goal].to << "   ";
					//  used[arr[goal].to] = true;
					long long tmp = w[arr[goal].to] * w[i];
					//  cout << tmp << endl;
					ans += tmp;
					//  cout << ans << endl;
					ans %= 10007;
					if (tmp > maxx)
						maxx = tmp;
				}
			}
		}
		//  cout << endl;
	}

	ans = (ans * 2) % 10007;
	printf("%lld %lld\n", maxx, ans);

	return 0;
}



#include<cstdio>
#include<cmath>
using namespace std;
struct Edge
{
	int t, nexty;
	Edge(){ t = nexty = 0; }
}edge[1000000];// ��ʽǰ�����ڽӱ�
int head[300000] = { 0 }, cnt = 0;// ��ʽǰ�����������
void add(int a, int b)// �ӱ�
{
	cnt++;
	edge[cnt].t = b, edge[cnt].nexty = head[a];
	head[a] = cnt;// �ӱ߹��̣����������ʽǰ���ǣ����԰ٶ�һ�£�
}
long long w[300000] = { 0 };// ÿ�����Ȩֵ
int main()
{
	int n;
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i<n - 1; i++) {
		scanf("%d%d", &a, &b);
		add(a, b), add(b, a);// �ӱ�
	}
	for (int i = 1; i <= n; i++)scanf("%lld", &w[i]);// ����Ȩֵ
	long long sum = 0, maxn = 0;// ȫ�ֵĺͣ����ֵ
	long long he, rmax;// һ�εĺ���һ�ε����ֵ
	int node;
	for (int i = 1; i <= n; i++) {
		node = head[i];// ��һ��Ԫ��
		he = (rmax = w[edge[node].t]) % 10007;// �õ���ʼֵ
		node = edge[node].nexty;// ��һ��
		// ö����֮�����ĵ�
		for (; node != 0; node = edge[node].nexty) {
			cout << he << endl;
			sum = (sum + he * w[edge[node].t]) % 10007;// �˷������
			maxn = max(maxn, rmax*w[edge[node].t]);// ̰�ģ�ȡ���ֵ
			he = (he + w[edge[node].t]) % 10007;
			rmax = max(rmax, w[edge[node].t]);// ����
		}
		cout << "---" << endl;
	}
	printf("%lld %lld", maxn, (sum * 2) % 10007);// �ǵ� * 2
	return 0;
}
/*

*/