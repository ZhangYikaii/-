// ����ͺ���1090�ϲ�������������С, ֮ǰ���ö�����̰��, ��ξ������Եı�ɻ��ε�
// ��������ϲ���������!!!
// ��һ��������һ�۾͸о�������dp��
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define in(x) x = read()

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int main() {
	

	return 0;
}

/*
ÿ��������ͷβ��, ֻ��ͷ����β����һ���Ĳſ��Ժϲ�, ��������1 ��(m, r) ����2 ��(r, n) �ϲ���� m * r * n

�����������
��������#1��
4
2 3 5 10
�������#1��
710
*/