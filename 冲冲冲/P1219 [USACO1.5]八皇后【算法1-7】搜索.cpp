#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}


const int MAX = 1005;     // ������󳤶�
int n = 0, queenNum = 8;  // ������� �ʺ����
int vis[MAX] = { 0 };     // �ж��Ƿ��ظ�������

int res = 0;

// �жϵ�i���ɲ����Էŵ�pos���λ����
bool check(int i, int pos) {
	for (int iFind = 0; iFind < pos; ++iFind) {
		if (vis[iFind] == i || abs(vis[iFind] - i) == abs(iFind - pos)) {       // ���λ���Ѿ���ȡ����
			//for (int i = 0; i < 8; ++i)
			//cout << vis[i];
			//cout << endl;
			return false;
		}
	}

	return true;
}

int cou = 2;

// dfs���
void dfs(int pos) {
	// �����������
	if (pos == queenNum) {
		// cou �������������.
		
		if (cou >= 0) {
			--cou;
			for (int i = 0; i < queenNum; ++i)
				cout << vis[i] << " ";
			cout << endl;
		}
		++res;
		return;
	}

	for (int i = 1; i <= queenNum; ++i) {
		if (i == n)
			continue;

		if (check(i, pos)) {
			vis[pos] = i;   // ���Է�
			dfs(pos + 1);   // �ݹ����һ��
			vis[pos] = 0;   // ����
		}
	}
}


int main() {
	cin >> queenNum;
	dfs(0);
	cout << res << endl;

	return 0;
}




