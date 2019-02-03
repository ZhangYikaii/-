#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

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

string s[40];
// Ԥ����϶�Ҫ����!!! ��yc[i][j]���洢 ��i������ ������ ��j������ �� ��С�ص�����
int yc[40][40], n;

// Ԥ����: ��yc[i][j]���洢 ��i������ ������ ��j������ �� ��С�ص�����
void init() {
	For(i, 0, n) {
		For(k, i, n) {
			int a = s[i].length(), b = s[k].length();
			// �ж� s[k] �ɲ����Խӵ� s[i] �� 
			int ji;
			for (ji = a - 1; i == 0 ? ji >= 0 : ji > 0; --ji) {
				if (s[k][0] == s[i][ji]) {
					int tk = 1, ti = ji + 1;
					while (ti < a && tk < b && s[k][tk] == s[i][ti]) {
						++ti;
						++tk;
					}
					if (ti == a && tk != b) {
						yc[i][k] = tk;
						break;
					}
				}
			}
			if (ji == 0 && i != 0)
				yc[i][k] = 0;
				
			int jk;
			for (jk = b - 1; k == 0 ? jk >= 0 : jk > 0; --jk) {
				if (s[i][0] == s[k][jk]) {
					int ti = 1, tk = jk + 1;
					while (tk < b && ti < a && s[k][tk] == s[i][ti]) {
						++ti;
						++tk;
					}
					if (tk == b && ti != a) {
						yc[k][i] = ti;
						break;
					}
				}
			}
			if (jk == 0 && k != 0)
				yc[k][i] = 0;
		}
	}
}

int used[30] = { 0 };
int maxx = -1;
void dfs(int index, int curNum) {
	bool isProce = false;
	For(i, 0, n) {
		if (yc[index][i] != 0 && used[i] < 2) {
			isProce = true;
			++used[i];
			dfs(i, curNum + s[i].length() - yc[index][i]);
			--used[i];
		}
	}
	if (isProce == false && maxx < curNum) {
		maxx = curNum;
	}
}


int main() {
	n = read() + 1;
	For(i, 1, n) {
		cin >> s[i];
	}

	cin >> s[0];

	init();

	dfs(0, s[0].length());

	cout << maxx << endl;

	// �ܽ�: ע��ע�⿴����Ŀ!!! �����е��ϧ��ѽû��һ��AC, ��Ŀ 1. �������ǿ�ͷ��ĸ, 2. �����Լ������Լ�
	// ��Ҫ�뵱Ȼ!!!

	return 0;
}

/*

�������ʺϲ�ʱ���ϲ�����ȡ������С�ص�����   ע������С!!!

���ڵ������ֲ��ܴ��ڰ�����ϵ  ���� at �� atide �Ͳ�������

ÿ����������������.


����:
5
at
touch
cheat
choose
tact
a

���:
23

���ɵ�����:   atoucheatactactouchoose

*/