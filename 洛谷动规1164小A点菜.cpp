#include <iostream>
using namespace std;

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

#define MAX 110

int n, m, a[MAX], f[MAX][10010];
int f1[10010] = { 0 };


int main() {
	n = read();
	m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	// ������һ�����߽�������
	f1[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; --j) {
			f1[j] += f1[j];					// # ����� i ����Ʒ#������ָ���ǵ�ǰ�Ѿ����� j Ԫ ��� j < a[i] ��Ȼ�����������˵� i ����Ʒ
			if (j >= a[i])
				f1[j] += f1[j - a[i]];		// # ���˵� i ����Ʒ# Ҳ����˵ f[j - a[i]] ��ʾ�ķ���������ǰ i ����Ʒ���� j - a[i] Ԫ��������ĵ� i �� �������ķ���
		}
	}
	cout << f1[m] << endl;
	return 0;
}