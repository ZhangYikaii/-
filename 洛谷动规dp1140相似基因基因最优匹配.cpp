#define N 105
#include<cstdio>
#include<string>
#include<iostream>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int tab[5][5] =
{
	{ 5, -1, -2, -1, -3 },
	{ -1, 5, -3, -2, -4 },
	{ -2, -3, 5, -2, -2 },
	{ -1, -2, -2, 5, -1 },
	{ -3, -4, -2, -1, 0 }
};
int la, lb;
std::string sa, sb;
int a[N], b[N];
int dp[N][N];
int main()
{
	std::ios::sync_with_stdio(0);
	std::cin >> la >> sa >> lb >> sb;

	// ��ʼ��Ϊ���ܴ���� ��Ϊ��Ե�Ȩֵ�����и���
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++)
			dp[i][j] = -2e8;
	}
	for (int i = 1; i <= la; i++) {
		if (sa[i - 1] == 'A') 
			a[i] = 0;
		if (sa[i - 1] == 'C')
			a[i] = 1;
		if (sa[i - 1] == 'G') 
			a[i] = 2;
		if (sa[i - 1] == 'T') 
			a[i] = 3;
	}
	for (int i = 1; i <= lb; i++) {
		if (sb[i - 1] == 'A') 
			b[i] = 0;
		if (sb[i - 1] == 'C') 
			b[i] = 1;
		if (sb[i - 1] == 'G')
			b[i] = 2;
		if (sb[i - 1] == 'T') 
			b[i] = 3;
	}

	// ��Ϊ��һ���������Ϊ0ʱ�������൱����һ���������ȫ���Ϳո��Ӧ
	for (int i = 1; i <= la; i++) 
		dp[i][0] = dp[i - 1][0] + tab[a[i]][4];
	for (int i = 1; i <= lb; i++) 
		dp[0][i] = dp[0][i - 1] + tab[b[i]][4];

	// ���ʼ����� �������dp
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + tab[b[j]][4]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + tab[a[i]][4]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + tab[a[i]][b[j]]);
		}
	}

	printf("%d", dp[la][lb]);
	return 0;
}

/*
������������ƶȵļ��㷽�����£�

����������֪�������� AGTGATG �� GTTAG �������ǵļ�������Ӧ����Ȼ���м���Լ���һЩ�ռ�� -�����磺

�����������:
AGTGAT_G
_GT__TAG

��ô���ƶȾ��ǣ� (-3)+5+5+(-2)+(-3)+5+(-3)+5=9 ����Ϊ��������Ķ�Ӧ������Ψһ

�涨������������ƶ�Ϊ���ж�Ӧ�����У����ƶ������Ǹ���


���������ʽ
�����ʽ��

�����С�ÿ��������һ����������ʾ����ĳ��ȣ���һ���ո����һ���������У�������ֻ�� A,C,G,T �ĸ���ĸ�� 1 �� ���еĳ��� ��100 ��

�����ʽ��

��һ�У��������������ƶȡ�

��������#1��

7 AGTGATG
5 GTTAG

�������#1��

14


*/