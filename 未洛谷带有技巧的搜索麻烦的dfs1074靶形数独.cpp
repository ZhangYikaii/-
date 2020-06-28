#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 10;

int a[N][N], ans[N][N], vis[3][N][N], b[82], maxn, flag;

struct Row {
	int h, zero_cnt;
}row[N];

// �������:�����е�0�ĸ�����С����
// ������0�����Ƚ��ٵ�
int cmp(Row row1, Row row2) {
	return row1.zero_cnt < row2.zero_cnt;
}

// ��ȡx��y����һ��С�Ź�������, �������ǾŸ�С�Ź�������
int getGrid(int x, int y) {
	if (x >= 1 && x <= 3) {
		if (y >= 1 && y <= 3)  return 1;
		else if (y >= 4 && y <= 6) return 2;
		else    return 3;
	}
	if (x >= 4 && x <= 6) {
		if (y >= 1 && y <= 3)  return 4;
		else if (y >= 4 && y <= 6) return 5;
		else    return 6;
	}
	if (x >= 7 && x <= 9) {
		if (y >= 1 && y <= 3)  return 7;
		else if (y >= 4 && y <= 6) return 8;
		else    return 9;
	}
}

// ��ȡx��yλ�ö�Ӧ�ķ���
int getScore(int x, int y) {
	if (x == 1 || y == 1 || x == 9 || y == 9)   return 6;
	else if (x == 2 || y == 2 || x == 8 || y == 8)     return 7;
	else if (x == 3 || y == 3 || x == 7 || y == 7)   return 8;
	else if (x == 4 || y == 4 || x == 6 || y == 6)   return 9;
	else    return 10;
}

// ���㵱ǰ��ϰ��չ����������Ľ��
int cal() {
	int sum = 0;
	for (int i = 1; i <= 9; i++)
	for (int j = 1; j <= 9; j++)
		sum += ans[i][j] * getScore(i, j);
	return sum;
}
void dfs(int xh) {        // xh:b��������
	if (xh == 82) {
		flag = 1;
		maxn = max(maxn, cal());
		return;
	}
	int x = b[xh] / 9 + 1;    // ���������Ŷ�Ӧ���ǵ�x�У���y��
	int y = b[xh] % 9;
	if (y == 0)
		x = b[xh] / 9, y = 9;
	if (!a[x][y]) {       // �����ǰ���������0������Ҫ��
		for (int j = 1; j <= 9; j++) {  // �ж�1-9�ܲ�����
			int g = getGrid(x, y);
			if (!vis[0][x][j] && !vis[1][y][j] && !vis[2][g][j]) {
				ans[x][y] = j;
				vis[0][x][j] = 1, vis[1][y][j] = 1, vis[2][g][j] = 1;
				dfs(xh + 1);
				vis[0][x][j] = 0, vis[1][y][j] = 0, vis[2][g][j] = 0;
			}
		}
	}
	else
		dfs(xh + 1);
}
void init() {
	for (int i = 1; i <= 9; i++) {
		int cnt = 0;                  // cnt:��¼����0�ĸ���
		for (int j = 1; j <= 9; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0)
				cnt++;
			else {
				int v = a[i][j];
				int g = getGrid(i, j);
				ans[i][j] = v;       // �Ѿ���õ���������������������/��/С���������ʹ��
				vis[0][i][v] = 1, vis[1][j][v] = 1, vis[2][g][v] = 1;
			}
		}
		row[i].h = i, row[i].zero_cnt = cnt;   // ��¼ÿһ���м���0
	}
	sort(row + 1, row + 1 + 9, cmp);              // ���Ȱ���0�ٵ���
	int num = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int x = row[i].h, y = j;
			num++;
			b[num] = (x - 1) * 9 + y;           // �洢���������ӵ�����˳��
		}
	}
}
int main() {
	init();
	dfs(1);
	if (flag)
		cout << maxn << endl;
	else
		cout << -1 << endl;
	return 0;
}