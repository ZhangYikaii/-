#include <iostream>
// ��������...
using namespace std;
#define MAX 1000

struct Edge {
	int next, to;
};


int col_num = 0, dfs_num = 0, top = -1;
int head[MAX], dfn[MAX], low[MAX], vis[MAX], stack[MAX], color[MAX];
Edge edge[MAX];


int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Tarjan(int x) {
	dfn[x] = ++dfs_num;
	low[x] = dfs_num;
	vis[x] = true;//�Ƿ���ջ��
	stack[++top] = x;
	for (int i = head[x]; i != 0; i = edge[i].next){
		int temp = edge[i].to;
		if (!dfn[temp]){
			Tarjan(temp);
			low[x] = MyMin(low[x], low[temp]);
		}
		else if (vis[temp])low[x] = MyMin(low[x], dfn[temp]);
	}
	if (dfn[x] == low[x]) {//����ǿ��ͨ����
		vis[x] = false;
		color[x] = ++col_num;//Ⱦɫ
		while (stack[top] != x) {//���
			color[stack[top]] = col_num;
			vis[stack[top--]] = false;
		}
		top--;
	}
}