#include<iostream>
#include<cstdio>
#include <algorithm>
#include <string.h>
#define maxn 1000
using namespace std;
int n, m, f[maxn][maxn], head[maxn], cnt;

// ��Ϥ����ʽǰ����
/*
������f[now][j][k]��ʾ��nowΪ���ڵ������, ����ǰj���ڵ�ѡk�ſεķ�����, ǰj�����ѡk�ſεķ�����.

��Ϊ1�Žڵ��Ǹ��ڵ�,��Ȼ�������f[now][1][1]=val[now]

���������׵õ�״̬ת�Ʒ���

ע�������� son, ����ѡ��
f[now][j][k]=max(f[now][j-1][k],f[son][���нڵ���][l]+f[now][j-1][k-l]);
Ȼ�����ǹ۲��ʽ���ߵ��ص�, ��Щ��������֪��?

�ڶ�now���ǰ

���������Ѿ���������ǰ�������, �����Ѿ���������ǰ�������. 

����f[son][���нڵ���][l]�ǿ���ֱ���õ�

Ȼ�� �ڴ����j���ڵ�ǰ

ǰj-1���ڵ��������Ѿ��������

����f[now][j-1][k]��f[now][j-1][k-l]Ҳ���ÿ���ѭ��˳������

������������, ��������ά���鲻��ը�ռ���

Ҳ���ⲻ��

�������ǿ��Ժ���Ȼ�ķ���

�ռ��ǿ����Ż���

ֻҪ���Ըı�ѭ��˳�򼴿�

��Ҫ�õ�j-1������

��������l<k��

���Ե���ѭ��k

�����Ϳ���ʹ������һ�������е�ǰֵ�����������õ���ֵ��ȫ��Ӱ��

�ͽ�~
*/
struct edge {
	int to, pre;
}e[maxn];
inline int in() {
	char a = getchar();
	while (a<'0' || a>'9')
	{
		a = getchar();
	}
	int t = 0;
	while (a >= '0'&&a <= '9')
	{
		t = (t << 1) + (t << 3) + a - '0';
		a = getchar();
	}
	return t;
}
void add(int from, int to) {
	e[++cnt].pre = head[from];
	e[cnt].to = to;
	head[from] = cnt;
}
void dp(int now) {
	//    f[now][0]=0;
	// ������Χ��
	for (int i = head[now]; i; i = e[i].pre) {
		int go = e[i].to;
		//dfs
		dp(go);

		// ע�������dp˳��
		for (int j = m + 1; j >= 1; j--) {
			for (int k = 0; k<j; k++) {
				// go �Ƕ��ӽ��
				f[now][j] = max(f[now][j], f[go][k] + f[now][j - k]);
			}
		}
	}
}

int main() {
	
	n = in(), m = in();
	for (int i = 1; i <= n; i++) {
		int fa = in();
		f[i][1] = in();
		add(fa, i);
	}
	dp(0);
	printf("%d\n", f[0][m + 1]);
	return 0;
}