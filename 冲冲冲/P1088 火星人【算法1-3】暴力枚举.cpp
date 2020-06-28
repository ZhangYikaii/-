#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
const int maxn = 10000 + 10;
int n, m, a[maxn], flagAdd = 0, flagFinish = 0;
bool curNumUsed[maxn];
void dfs(int step) {
	if (flagFinish == 1)
		return;
	// �������������
	if (step > n) {
		++flagAdd;
		// ���ڵ�������Ҫ���ϵ��Ǹ�����ȫ���е�ʱ�����Ǿ�ֱ�ӵ������Ȼ����flagFinish��һֱreturn����������
		if (flagAdd == m + 1) {
			for (int j = 1; j <= n; j++)
				printf("%d ", a[j]);
			printf("\n");
			flagFinish = 1;
		}
		return;
	}
	
	// ��ע��: �趨dfs�����Ҫ�ڵݹ��for����.
	for (int i = 1; i <= n; i++) {
		// �����������˸�������������׶ε�ʱ�����Ǿ�ֱָ�����˸����������е��� 
		// ��һ���ܹؼ�, �����൱�ڰ������˸����Ǹ�����Ϊdfs�����!
		
		// ��ע��: �����õ�ǰѭ�������ֵΪ���, �ݹ黹��Ҫ�����ݹ��, ѹջ����Ҫ����ѹջ��.
		if (flagAdd == 0)
			i = a[step];
		if (curNumUsed[i] == 0) {
			curNumUsed[i] = 1;
			a[step] = i;     // ������!
			dfs(step + 1);
			curNumUsed[i] = 0;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs(1);
	return 0;
}

//int tmp[20], used[20], record[20];
//int n, m;
//
//void dfs(int tot, bool &flag) {
//	if (tot == n) {
//		bool isRecord = true;
//		Fee(i, 1, n) {
//			if (tmp[i] != record[i]) {
//				isRecord = false;
//				break;
//			}
//		}
//		if (isRecord == true) {
//			flag = true;
//			return;
//		}
//		Fee(i, 1, n)
//			cout << setw(5) << tmp[i];
//		cout << endl;
//		return;
//	}
//
//	if (flag == false) {
//		used[record[tot + 1]] = 1;
//		tmp[tot + 1] = record[tot + 1];
//		dfs(tot + 1, flag);
//		used[record[tot + 1]] = 0;
//	}
//	Fee(i, 1, n) {
//		if (used[i] == 0) {
//			used[i] = 1;
//			tmp[tot + 1] = i;
//			dfs(tot + 1, flag);
//			used[i] = 0;
//		}
//	}
//}
//int main() {
//	in(n), in(m);
//	Fee(i, 1, n) {
//		in(record[i]);
//	}
//
//	bool flag = false;
//	dfs(0, flag);
//	return 0;
//}