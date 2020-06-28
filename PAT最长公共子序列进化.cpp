#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

//�˴���ʹ��ǰ����ɾ����������+�����system("PAUSE")
ifstream fin("in.txt");
#define cin fin

int like[201] = { 0 };
int given[10001] = { 0 };
int len[201][10001] = { 0 };

int LCS(int row, int col)
{
	int i, j;
	int max;
	// ע�������ʵ�����ڱ���˳���������ֽ�.
	for (i = 1; i <= row; i++) {
		for (j = 1; j <= col; j++) {
			max = len[i - 1][j - 1];
			if (max < len[i][j - 1])
				max = len[i][j - 1];
			if (max < len[i - 1][j])
				max = len[i - 1][j];	//�������ߡ��ϱߡ����ϱ� ����ֵ�е����ֵ
			if (like[i] == given[j]) {				//�����ȣ������ֵ+1
				len[i][j] = max + 1;
			}
			else {
				len[i][j] = max;
			}
		}
	}
	return len[row][col];
}


int main()
{
	int n, m, l;
	cin >> n >> m;
	int i;
	for (i = 0; i < m; i++)cin >> like[i + 1];
	cin >> l;
	for (i = 0; i < l; i++)cin >> given[i + 1];

	cout << LCS(m, l) << endl;

	return 0;
}