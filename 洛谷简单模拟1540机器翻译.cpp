#include <iostream>
#include <cstdio>
#include <queue>
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

#define MAX 40

int main() {
	int m, n;
	m = read();
	n = read();
	int input;
	int used[1010] = { false }, res = 0;
	queue<int> q;

	for (int i = 0; i < n; ++i) {
		input = read();
		if (used[input] == false && q.size() < m) {
			used[input] = true;
			q.push(input);
		}
		else if (used[input] == false && q.size() == m) {
			used[input] = true;
			used[q.front()] = false;
			q.pop();
			q.push(input);
		}
		else if (used[input] == true) {
			++res;
		}
	}

	cout << n - res << endl;
	
	return 0;
}


/*
�������ֵ�������£�ÿ�б�ʾһ�����ʵķ��룬ð��ǰΪ���η������ڴ�״����

�գ��ڴ��ʼ״̬Ϊ�ա�

1�� 1�����ҵ���1�������ڴ档

2�� 12�����ҵ���2�������ڴ档

3�� 12�����ڴ����ҵ�����1��

4�� 125�����ҵ���5�������ڴ档

5�� 254�����ҵ���4�������ڴ��������1��

6�� 254�����ڴ����ҵ�����4��

7�� 541�����ҵ���1�������ڴ��������2��

���Ʋ���5�δʵ䡣
*/