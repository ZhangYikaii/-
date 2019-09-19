#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <assert.h>
#include <istream>
#include <queue>
using namespace std;

#define in(x) x=read()

#define FOR(i, s, n) for(int i = s; i < n; ++i)

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}



// ˼·:
// dp[] ����i�������ѡ����, dp[i] = 0, ���û�б�ѡ�е������Ķ��ӻ��߸��ױ�ѡ��, dp[i] = 1;
// dp[] ��ʼ���ܴ��ֵ

// �����������, ��ȴӴ�С������;
// 1. ��������İְ�û�б�ѡ�� �Լ� ������dp[]��ֵ����1(��������㸽����û�б�ѡ��), ��ô̰�ĵذ����İְ�ѡ��;
// 2. ������Լ�������ѡ�й�(dp[] == 0), ����
// 3. ������İְֱ�ѡ�й�, �����Լ�ŪΪ1, ����




// int fa[10010], deep[10010], indexx[10010], dp[10010];
int *indexx, *dp;
int deep[100010] = { 0 }, fa[100010] = { 0 };

bool cmp(int a, int b) {
	return deep[a] > deep[b];
}

int main() {
	int n = 0;
	char buf[100010] = "";
	int tmp;
	int res = 0;

	// ����:
	while (cin.getline(buf, 100010)) {
		int i = 0, flag = 0, father = 0;

		++n;
		if (buf[0] == '\0')
			continue;

		for (i = 0; buf[i] != '\0';) {
			if (buf[i] == ' ') {
				++i;
				continue;
			}
			tmp = atoi(buf + i) + 1;

			if (flag == 0) {
				flag = 1;
				father = tmp;
			}
			else {
				fa[tmp] = father;
				deep[tmp] = deep[father] + 1;
			}
			while (buf[i] != '\0' && buf[i] != ' ')
				++i;
		}

		memset(buf, 0, sizeof(buf));
	}

	dp = new int[n + 10];
	indexx = new int[n + 10];


	// ��ʼ��:
	for (int i = 0; i <= n + 3; ++i) {
		dp[i] = 0x7fffff;
		indexx[i] = i;
	}

	fa[1] = 1;

	// �������:
	sort(indexx + 1, indexx + 1 + n, cmp);

	// ��ʼ����:
	for (int i = 1; i <= n; ++i) {
		int cur = indexx[i], father = fa[cur];

		if (dp[father] == 0) {
			dp[cur] = 1;
			continue;
		}
		if (dp[cur] > 1) {
			// cout << "cur: " << father - 1 << endl;
			dp[father] = 0;						// ̰�� �ڰְ����︲��
			dp[cur] = 1;						// �Լ����Ǿ���1��

			//// ��©�ˣ� ֱ��dp���ְֵİְ�
			//if (dp[fa[father]] > 1)
			//	dp[fa[father]] = 1;
			++res;
		}
	}

	//for (int i = 1; i <= n; ++i) {
	//	cout << "dp: " << dp[i] << " fa: " << fa[i] << endl;
	//}


	printf("I have read the rules about plagiarism punishment\n");
	printf("%d\n", res);

	return 0;
}
