#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<map>
#define INF 0xfffffff

#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
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

int ruleMap[15];
int used[15][15];


// �𰸴���:���ύ�ĳ���û��ͨ�����еĲ�������
// �����Ĵ���ֻ���ж������ظ�. ������Ŀ˵���ұ߲���Ϊ0, �Ͳ�Ҫ�жϵ�һ��Ϊ0���������ֵ���.
int main() {
	string n;
	int kk, res = 1;
	int atmp, btmp;
	cin >> n;
	in(kk);

	for (int i = 0; i < 11; ++i) {
		ruleMap[i] = 1;
	}
	For(i, 0, kk) {
		in(atmp);
		in(btmp);
		if (used[atmp][btmp] == 0) {
			ruleMap[atmp]++;
			used[atmp][btmp] = 1;
		}
	}

	for (int i = 0; i < n.length(); ++i) {
		res *= (ruleMap[n[i] - '0']);
	}

	printf("%d\n", res);
	return 0;
}

/*

���ӣ�https://ac.nowcoder.com/acm/contest/1077/C
��Դ��ţ����

��Ŀ����
����һ������ n��n<1030) �� k ���任����k<=15����
����
һλ���ɱ任����һ��һλ����������Ҳ�����Ϊ�㡣
���磺n=234���й���k��2����
2��> 5
3��> 6
��������� 234 �����任����ܲ�����������Ϊ������ԭ����:
234
534
264
564
�� 4 �ֲ�ͬ�Ĳ�����
���⣺
����һ������ n �� k ������
�����
��������εı任��0�λ��Σ����ܲ��������ٸ���ͬ��������Ҫ�����������
��������:
�����ʽΪ��
n k
x1 y1
x2 y2
... ...
xn yn
�������:
һ�����������������ĸ�����
ʾ��1
����
����
234 2
2 5
3 6
���
����
4
*/

