#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include <cstring>
using namespace std;

#define in(x) x=read()

#define MAXN 2010

// ע��sort�����ַ��� cmp

struct Data {
	int index, v;
	bool operator<(Data a) {
		if (v == a.v)
			return index < a.index;
		return v > a.v;
	}
};

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, k, E[15], D[20010];
Data arr[20010];

bool cmp(int a, int b) {
	if (arr[a].v == arr[b].v)
		return arr[a].index < arr[b].index;
	return arr[a].v > arr[b].v;
}

int main() {
	for (int i = 0; i <= 20000; ++i)
		D[i] = i;
	in(n);
	in(k);

	for (int i = 1; i <= 10; ++i) {
		in(E[i]);
	}

	for (int i = 1; i <= n; ++i) {
		in(arr[i].v);
		arr[i].index = i;
	}

	sort(D + 1, D + 1 + n, cmp);

	for (int i = 1; i <= n; ++i) {
		arr[D[i]].v += E[(i - 1) % 10 + 1];			// ע��������������Ϊ���, D[i] or i, D[i]��¼��������ǰ���±�, ���ַ����ܲ���
	}

	sort(arr + 1, arr + 1 + n);

	printf("%d", arr[1].index);
	for (int i = 2; i <= k; ++i)
		printf(" %d", arr[i].index);
	

	return 0;
}

/*

��Ŀ����
һ����n��n��20000�����ˣ���1--n��ţ���Ѽ�Ҫ��Ƭ�����Ѽ�ֻ�ܰ���Ƭ�����е�k���ˡ��ѼѰ��������ǵĹ�ϵ�û��ĳ̶ȸ�ÿ���˸�����һ����ʼȨֵW[i]��Ȼ�󽫳�ʼȨֵ�Ӵ�С��������ÿ�˾�����һ�����D[i]��ȡֵͬ����1--n�������������Ŷ�10ȡģ��ֵ����Щ�˷�Ϊ10�ࡣҲ����˵����ÿ���˵�������C[i]��ֵΪ(D[i]-1) mod 10 +1����Ȼ�����ŵ�ȡֵΪ1--10����i����˽������õ�E[i]��Ȩֵ������Ҫ���ľ���������϶���Ȩֵ�Ժ����յ�Ȩֵ����k���ˣ���������ǵı�š��������У�������˵�W[i]��ͬ�����С�����ȡ�

���������ʽ
�����ʽ��
��һ�������ÿո�����������������ֱ���n��k��

�ڶ��и�����10�����������ֱ���E[1]��E[10]��

�����и�����n������������i������ʾ���Ϊi���˵�ȨֵW[i]��

�����ʽ��
ֻ�����һ���ÿո������k���������ֱ��ʾ���յ�W[i]�Ӹߵ��͵��˵ı�š�

�����������
��������#1��
10 10
1 2 3 4 5 6 7 8 9 10
2 4 6 8 10 12 14 16 18 20
�������#1��
10 9 8 7 6 5 4 3 2 1

*/