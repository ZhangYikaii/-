#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
// ע���������ƶ���� ��һ��f[]��¼�� dfs���仯����!!!
using namespace std;
int n, m, t;
struct Data {
	int tim, mon; 
} a[205];

int f[205][205][205];

int MyMax(int a, int b) {
	return a > b ? a : b;
}
// step��ʾ�ڼ�����money��ʾĿǰ��Ǯ��time��ʾĿǰ��ʱ��
int dfs(int step, int money, int time) {
	// Ҫreturn -1����Ϊ֮ǰ������ʱ��ֱ��������Ҳ���Ǽ�����Եģ�����������ֲ�������������Ҫ��֮ǰ�ļ���ȥ������return -1
	if (money < 0 || time < 0)
		return -1;

	// ���仯
	if (f[step][money][time] != -1)
		return f[step][money][time];

	//Խ�� return
	if (step >= n)
		return 0;

	// dfsѡ���ǲ�ѡ, ���ѡ�˵Ļ�, ��Ʒ��Ҫ��һ
	return f[step][money][time] = MyMax(dfs(step + 1, money - a[step + 1].mon, time - a[step + 1].tim) + 1, dfs(step + 1, money, time));
}

int main() {
	scanf("%d%d%d", &n, &m, &t);
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].tim, &a[i].mon);

	printf("%d\n", dfs(0, m, t));

	return 0;
}


/*

������� 01 ��������, ���������������: ʱ�� + ��Ǯ, ��01�������Ȩֵ��, ��ɶ���1��(�����Ʒ����) ����.

Kkksc03��ʱ��ͽ�Ǯ�����޵ģ�������������������ͬѧ��Ը������������֪�����Լ���������Χ�ڣ���������ɶ���ͬѧ��Ը����

���������ʽ
�����ʽ��
��һ��,n M T����ʾһ����n(n<=100)��Ը����kkksc03 �����ϻ�ʣM(M<=200)Ԫ�����������T(T<=200)����ʱ�䡣

��2~n+1�� mi,ti ��ʾ��i��Ը������Ҫ�Ľ�Ǯ��ʱ�䡣

�����ʽ��
һ�У�һ��������ʾkkksc03������ʵ��Ը���ĸ�����

�����������
��������#1��
6 10 10
1 1
2 3
3 2
2 5
5 2
4 3
�������#1��
4

*/