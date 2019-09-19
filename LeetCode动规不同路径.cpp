#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}


// �򵥵Ķ���, ע�������ֻ�����һ���������.
int uniquePaths(int m, int n) {
	int used[110][110];
	used[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		if (i != 0)
			used[i][0] = used[i - 1][0];
		for (int j = 1; j < m; ++j) {
			if (i != 0)
				used[i][j] = used[i - 1][j] + used[i][j - 1];
			else used[i][j] = used[i][j - 1];
		}
	}

	return used[n - 1][m - 1];
}

int main() {
	cout << (1 & 7) << endl;
	cout << uniquePaths(7, 3) << endl;

	return 0;
}




/*

һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����

������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������

���ܹ��ж�������ͬ��·����




˵����m �� n ��ֵ�������� 100��

ʾ�� 1:

����: m = 3, n = 2
���: 3
����:
�����Ͻǿ�ʼ���ܹ��� 3 ��·�����Ե������½ǡ�
1. ���� -> ���� -> ����
2. ���� -> ���� -> ����
3. ���� -> ���� -> ����
ʾ�� 2:

����: m = 7, n = 3
���: 28

*/