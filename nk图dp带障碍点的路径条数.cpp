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

int horseCtrl[10][2] = {
	{-2, -1},
	{-2, 1},
	{-1, -2},
	{-1, 2},
	{1, -2},
	{1, 2},
	{2, -1},
	{2, 1},
};

int mmap[10010][10010], dp[10010][10010];


// �𰸴���:���ύ�ĳ���û��ͨ�����еĲ�������
int main() {
	int bpx, bpy, hpx, hpy;
	in(bpx);
	in(bpy);
	in(hpx);
	in(hpy);

	For(i, 0, 8) {
		int tx = hpx + horseCtrl[i][0], ty = hpy + horseCtrl[i][1];
		if (tx <= bpx && tx >= 0 && ty <= bpy && ty >= 0) {
			mmap[tx][ty] = 1;   // obstacle.
		}
	}
	
	mmap[hpx][hpy] = 1;			// ���Լ��ĵ�ҲҪ.
	// dp boundary.
	for (int i = 0; i <= bpy; ++i) {
		if (mmap[0][i] != 1)
			dp[0][i] = 1;
		else
			break;
	}
	for (int i = 0; i <= bpx; ++i) {
		if (mmap[i][0] != 1)
			dp[i][0] = 1;
		else				// ע���ʼ��, ��Ϊ��һ���ϰ�֮�����Ķ���������, �Ͷ��� 0.
			break;
	}

	// dp.
	for (int i = 1; i <= bpx; ++i) {
		for (int k = 1; k <= bpy; ++k) {
			if (mmap[i][k] == 1)
				dp[i][k] = 0;
			else {
				dp[i][k] = dp[i - 1][k] + dp[i][k - 1];
			}
		}
	}

	//for (int i = 0; i <= bpx; ++i) {
	//	for (int k = 0; k <= bpy; ++k) {
	//		printf("%d\t", mmap[i][k]);
	//	}
	//	printf("\n");
	//}
	//cout << endl << endl;
	//for (int i = 0; i <= bpx; ++i) {
	//	for (int k = 0; k <= bpy; ++k) {
	//		printf("%d\t", dp[i][k]);
	//	}
	//	printf("\n");
	//}

	printf("%d\n", dp[bpx][bpy]);

	return 0;
}


/*

���ӣ�https://ac.nowcoder.com/acm/contest/1077/H
��Դ��ţ����

��Ŀ����
��ͼ��A ����һ�������䣬��Ҫ�ߵ�Ŀ�� B �㡣�����߹��򣺿������¡��������ҡ�ͬʱ�������ϵ���һ����һ���Է���������ͼ��C�㣩���������ڵĵ��������Ծһ���ɴ�ĵ��Ϊ�Է���Ŀ��Ƶ㡣������ͼ C ���ϵ�����Կ��� 9 ���㣨ͼ�е�P1��P2 �� P8 �� C�����䲻��ͨ���Է���Ŀ��Ƶ㡣

�����������ʾ��A �㣨0,0����B �㣨n,m��(n,m Ϊ������ 20 �����������ɼ�������)��ͬ�����λ����������Ҫ�����ģ�Լ��: C<>A��ͬʱC<>B��������Ҫ����������� A ���ܹ����� B ���·����������
��������:
����B������꣨n,m���Լ��Է�������꣨X,Y��{�����д�}
�������:
���һ��������·������������
ʾ��1
����
����
6 6 3 2
���
����
17

*/