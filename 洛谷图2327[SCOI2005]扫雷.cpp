#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include <cstring>
using namespace std;

#define in(x) x=read()
#define MAXN 2010

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
int n, a[10010] = { 0 }, b[10010] = { 0 }, ans = 0;

bool check() {
	for (int i = 2; i <= n - 1; ++i) {
		b[i + 1] = a[i] - b[i] - b[i - 1];
		if (b[i + 1] != 0 && b[i + 1] != 1)
			return false;
	}

	if (b[n] + b[n - 1] == a[n])
		return true;

	return false;
}
int main() {
	in(n);
	for (int i = 1; i <= n; ++i) {
		in(a[i]);
	}

	if (a[1] == 3) {
		printf("0\n");
		return 0;
	}
	else if (a[1] == 2) {
		b[1] = b[2] = 1;
		if (check() == true)
			++ans;
	}
	else if (a[1] == 1) {
		b[1] = 1, b[2] = 0;
		if (check() == true)
			++ans;
		b[1] = 0, b[2] = 1;
		if (check() == true)
			++ans;
	}
	else if (a[1] == 0) {
		b[1] = b[2] = 0;
		if (check() == true)
			++ans;
	}

	printf("%d\n", ans);

	return 0;
}

/*

// ע��ÿ�����ɨ����Ϣ��Ҫ�����ж�, ����������������׵İڷ�����.

���Ŵ�Ҷ����ɨ�׵���Ϸ��������һ��n��m�ľ���������һЩ�ף�Ҫ�����һЩ��Ϣ�ҳ���������ʥ�ڵ��ˣ����ࡱ�˹���������һ�ּ򵥵�ɨ����Ϸ�������Ϸ�����ɨ��һ�������ĳ������û���ף���ô����������ֱ�ʾ����8��ͨ�ĸ��������׵���Ŀ������������n��2�ģ���һ������ĳЩ�������ף����ڶ���û���ף�����ͼ��


���ڵ�һ�е��׿����ж��ַ�������ڶ��е��������ƣ�������񼴸��ݵڶ��е���Ϣȷ����һ�����ж����ְڷŷ�����

���������ʽ
�����ʽ��
��һ��ΪN���ڶ�����N����������Ϊ�ڶ��еĸ����е�������1<= N <= 10000��

�����ʽ��
һ����������һ�����׵İڷŷ�������

�����������
��������#1��
2
1  1
�������#1��
2

*/