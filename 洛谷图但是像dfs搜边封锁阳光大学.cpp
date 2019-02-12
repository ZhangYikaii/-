#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

const double PI = 3.1415926535;

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

struct Data {
	int a, b;
};

int n, m, minAns = 0xfffffff;
Data arr[100010];
bool used[10010] = { false }; // �ĸ���û�з���

// dfs �ѱ� �ܺ�д, ����������һ���TLE
void dfs(int ans) {
	int nextFind = 1;
	for (; nextFind <= m; ++nextFind) {
		if (used[arr[nextFind].a] == false && used[arr[nextFind].b] == false)
			break;
		else if (used[arr[nextFind].a] == true && used[arr[nextFind].b] == true) {
			return;
		}  // ��ô�жϲ����ϵ�ʱ����
	}
	if (nextFind > m) {
		if (minAns > ans)
			minAns = ans;
		return;
	}

	used[arr[nextFind].a] = true;
	dfs(ans + 1);
	used[arr[nextFind].a] = false;

	used[arr[nextFind].b] = true;
	dfs(ans + 1);
	used[arr[nextFind].b] = false;
}

int main() {
	n = read();
	m = read();

	for (int i = 1; i <= m; ++i) {
		arr[i].a = read();
		arr[i].b = read();
	}

	dfs(0);
	if (minAns != 0xfffffff)
		printf("%d\n", minAns);
	else
		printf("Impossible\n");

	return 0;
}

/*
��Ŀ����
����һֻ��ˢ�ֵ��ϲܣ�����ڼ䣬��ÿ�춼������������ѧ��У԰��ˢ�֡���з��������Ĳܣ��е���ˬ����з�������������ѧ�����ò�ˢ�֡�

�����ѧ��У԰��һ����N���㹹�ɵ�����ͼ��N����֮����M����·���ӡ�ÿֻ��з���Զ�һ������з�������ĳ���㱻������������������ĵ�·�ͱ������ˣ��ܾ��޷�������Щ��·��ˢ���ˡ��ǳ������һ���ǣ���з��һ�ֲ���г���������ֻ��з���������ڵ�������ʱ�����ǻᷢ����ͻ��

ѯ�ʣ�������Ҫ����ֻ��з�����Է������е�·���Ҳ�������ͻ��

���������ʽ
�����ʽ��
��һ�У���������N��M

������M�У�ÿ����������A��B����ʾ��A����B֮���е�·������

�����ʽ��
��һ�У������з�޷��������е�·���������Impossible�����������һ����������ʾ������Ҫ����ֻ��з��

�����������
��������#1��
3 3
1 2
1 3
2 3
�������#1��
Impossible
��������#2��
3 2
1 2
2 3
�������#2��
1


*/