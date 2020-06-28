//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//#include <string.h>
//#include <v_ector>
//#include <set>
//#include <map>
//
//using namespace std;
//
//#define in(x) x=read()
//
//#define FOR(i, s, n) for(int i = s; i < n; ++i)
//
//typedef long long ll;
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//int n, m;
//int need;
//int arr[110] = { 0 }, iArr = 0;
//int used[200] = { 0 };
//
//int res[20010] = { 0 }, ans = 0;
//
//
//v_oid dfs(int cur, int beg, int curArr[], int use[]) {
//	if (cur == need) {
//		int sum = 0;
//		FOR(i, 0, cur) {
//			sum += curArr[i];
//			cout << curArr[i] << " ";
//		}
//		cout << endl;
//
//		if (res[sum] == 0) {
//			++ans;
//			res[sum] = 1;
//		}
//
//		return;
//	}
//
//	FOR(i, beg, iArr) {
//		if (use[i] == 0) {
//			use[i] = 1;
//			curArr[cur] = arr[i];
//			dfs(cur + 1, i + 1, curArr, use);
//			use[i] = 0;
//		}
//	}
//}
//
///*
//6 1
//1 2 3 4 5 6*/
//
//int main() {
//	ios::sync_with_stdio(false);
//	
//	in(n), in(m);
//
//	int tmp;
//	FOR(i, 0, n) {
//		in(tmp);
//		if (used[tmp] != 0)
//			--m;
//		else {
//			used[tmp] = 1;
//			arr[iArr++] = tmp;
//		}
//	}
//
//	FOR(i, 1, iArr - m + 1) {
//		need = i;
//
//		int curArr[30] = { 0 }, use[110] = { 0 };
//		dfs(0, 0, curArr, use);
//	}
//
//	cout << ans << endl;
//
//
//
//
//	return 0;
//}



// �� �̶���k ��������ȡ, ���ԳƳ���������, ������dp, 01������..

// �����Ǵ�:

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 22;
const int maxm = 2010;
int n, m, a[maxn], ans, tot, ret;
bool tf[maxn], f[maxm];


// ע�ⱳ��һ�㶼�� ��һ��ѭ����ǰ����, 
void dp() {
	memset(f, 0, sizeof f); 
	f[0] = true;
	ans = 0; tot = 0;
	for (int i = 0; i<n; i++) {
		// ����Ѿ���ɾ��.
		if (tf[i])
			continue;

		// �Ӻ���ǰ�����ܹؼ�!!!
		for (int j = tot; j >= 0; j--) {
			// �������������Ϊj�Ŀ���, ��ô j + a[i] һ������.
			// ������, ÿ�ν���һ������, ��ɨһ�鵱ǰ���Ե�.
			// ע��һЩ�����ĳ�ʼ��, ��������1, 2, 3  ��Ҫѡ��2, 3 Ҳ�ǿ��Ե�, ��Ϊ 2 ������ʱ��f[2]�� = true;
			if (f[j] && !f[j + a[i]]) {
				f[j + a[i]] = true;
				ans++;
			}
		}
		// ��һ���ǳ�����, ��¼��ǰ�����������.
		tot += a[i];
	}
	ret = max(ans, ret);
}
void dfs(int cur, int now)
{
	if (now>m)return;
	if (cur == n){ if (now == m)dp(); return; }
	dfs(cur + 1, now);
	tf[cur] = true;
	dfs(cur + 1, now + 1);
	tf[cur] = false;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++)scanf("%d", a + i);
	dfs(0, 0);
	printf("%d\n", ret);
	return 0;
}
