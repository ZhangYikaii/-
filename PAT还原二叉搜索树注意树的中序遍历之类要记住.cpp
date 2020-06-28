#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

const int maxn = 105;
int cnt = 0;
/*
���������˳��Ϊ���д�С�����˳��������������ʱ��˳�㸳ֵ��
����α���������ɡ�
*/

// ���������齨��.
struct Node {
	int val;
	int left;
	int right;
}node[maxn];


// �������.
void dfs(int i, int a[]) {
	if (i == -1)
		return;
	dfs(node[i].left, a);
	node[i].val = a[cnt];			// ����������ʵ�ʱ��Žڵ�.
	++cnt;
	dfs(node[i].right, a);
}

int main() {
	int n, l, r;
	int a[maxn];
	scanf("%d", &n);

	// �ؼ��������齨��, ����һ�������.
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l, &r);
		node[i].left = l;
		node[i].right = r;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// ��Ҫ���������С��������.
	sort(a, a + n);

	dfs(0, a);


	// ��α���, ֱ�ӷŽڵ�.
	queue<Node> q;
	q.push(node[0]);

	bool first = true;
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		if (first) {
			printf("%d", tmp.val);
			first = false;
		}
		else {
			printf(" %d", tmp.val);
		}
		if (tmp.left != -1)
			q.push(node[tmp.left]);
		if (tmp.right != -1)
			q.push(node[tmp.right]);
	}

	return 0;
}


/*
��Ŀ����
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST.  You are supposed to output the level order traversal sequence of that tree.  The sample is illustrated by Figure 1 and 2.





��������:
Each input file contains one test case.  For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree.  The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root.  If one child is missing, then -1 will represent the NULL child pointer.  Finally N distinct integer keys are given in the last line.



�������:
For each test case, print in one line the level order traversal sequence of that tree.  All the numbers must be separated by a space, with no extra space at the end of the line.


��������:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42

�������:
58 25 82 11 38 67 45 73 42
*/