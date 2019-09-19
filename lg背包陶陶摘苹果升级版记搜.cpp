#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

//
//
//int n, s, a, b, ans;
//int xi[5005], yi[5005];
//bool visit[5005][1001];//�洢�Ƿ���ʹ����������������ĺ���
//int mem[5005][1001];//�洢���������������ĺ����ķ���ֵ
//int dfs(int num, int rest){
//	if (num>n) return 0;
//	if (visit[num][rest]) return mem[num][rest];//������������������ĺ����Ѿ������ʹ�����ôֱ�ӷ���֮ǰ�洢��ֵ����
//	visit[num][rest] = true;
//	int maxn = dfs(num + 1, rest);
//	if (xi[num] <= a + b&&rest >= yi[num]){
//		int  t = dfs(num + 1, rest - yi[num]) + 1;
//		maxn = t>maxn ? t : maxn;
//	}
//	return mem[num][rest] = maxn;//����ֵ��ͬʱ�洢�������ķ���ֵ
//}
//int main(){
//	cin >> n >> s >> a >> b;
//	for (int i = 1; i <= n; i++){
//		cin >> xi[i] >> yi[i];
//	}
//	cout << dfs(1, s);
//	return 0;
//}


int n, s;
int a, b;

struct Data {
	int x, y;
};

Data arr[10010];



int mem[5005][1005], vis[5010][1010];

// num ��ʾ�������ڼ���ƻ��, rest ��ʾʣ�¶���.
int dfs(int num, int rest) {
	if (num > n)
		return 0;
	if (vis[num][rest] != 0)
		return mem[num][rest];

	vis[num][rest] = 1;
	int maxx = dfs(num + 1, rest);

	if (arr[num].x <= a + b && rest >= arr[num].y) {
		int tmp = dfs(num + 1, rest - arr[num].y) + 1;
		maxx = maxx > tmp ? maxx : tmp;
	}

	mem[num][rest] = maxx;
	return maxx;
}

int main() {
	FOR(i, 0, 5005) {
		FOR(j, 0, 5005) {
			vis[i][j] = 0;
			mem[i][j] = 0;
		}
	}
	in(n), in(s);
	in(a), in(b);
	FOR(i, 1, n + 1) {
		in(arr[i].x), in(arr[i].y);
	}
	
	printf("%d\n", dfs(1, s));

	return 0;
}