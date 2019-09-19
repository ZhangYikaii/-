//#include <bits/stdc++.h>
//using namespace std;
//
//// ע�⵽ÿһλ����Ӱ��, ��setȥ��, ���ÿһλ���Ա任�ĸ����Ϳ�����.
//set<int> ma[12];
//
//void dfs(int used[], int self, int des) {
//	for (set<int>::iterator iter = ma[des].begin(); iter != ma[des].end(); ++iter) {
//		if (used[*iter] == 0) {
//			used[*iter] = 1;
//			ma[self].insert(*iter);
//			dfs(used, self, *iter);
//		}
//	}
//}
//int main() {
//	string n;
//	int num;
//	cin >> n >> num;
//
//	for (int i = 1; i <= num; ++i) {
//		int a, b;
//		cin >> a >> b;
//
//		ma[a].insert(b);
//	}
//
//	for (int i = 0; i <= 9; ++i) {
//		int used[15] = { 0 };
//		for (set<int>::iterator iter = ma[i].begin(); iter != ma[i].end(); ++iter) {
//			used[*iter] = 1;
//			dfs(used, i, *iter);
//		}
//		ma[i].insert(i);
//	}
//
//	long long res = 1;
//	for (int i = 0; i < n.size(); ++i) {
//		res *= (long long)ma[n[i] - '0'].size();
//	}
//
//	printf("%lld\n", res);
//
//	
//
//	return 0;
//}

// �Լ�д��û�и߾� wa��һ����

#include <iostream>
#include <string>
using namespace std;
string str;
int k, vis[10][10], f[10], num[101];

inline void floyd() {  //��������
	for (int k = 0; k <= 9; k++)
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j <= 9; j++)
				vis[i][j] = vis[i][j] || (vis[i][k] && vis[k][j]);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> str >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		vis[a][b] = true;  //a���Ա��b
	}
	// ��һ���任����, ����a -> b֮����һ��ͨ·.

	for (int i = 0; i <= 9; i++)
		vis[i][i] = true;  //�Լ����Ա���Լ�, �Լ����Լ���һ��ͨ·.

	floyd();
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			if (vis[i][j]) f[i]++;  //���i���Ա�ɶ���������
	int len = 2; num[1] = 1;
	for (int i = 0; i < (int)str.length(); i++) {  //�߾���
		for (int j = 1; j <= 100; j++) num[j] *= f[str[i] - '0'];
		for (int j = 1; j <= 100; j++)
			if (num[j] >= 10) {  //��λ
				num[j + 1] += num[j] / 10;
				num[j] %= 10;
			}
		while (num[len]) len++;  //�������
	}
	for (int i = len - 1; i >= 1; i--) cout << num[i];  //���
	return 0;
}