//// �����Ǵ�:
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//int n, l, t, ans[10005], maxans;
//int main() {
//	// ע�����ans[] ����ô���ĵ�, �����ת��.
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i){
//		scanf("%d", &i);
//		scanf("%d", &l);
//		int tmp = 0;
//		while (scanf("%d", &t) && t)
//			tmp = max(ans[t], tmp);			// tmp��ʱ������ǰ��, ���������ǰ���Ľ���ʱ��!!!
//		ans[i] = tmp + l;					// "��������k��ǰ���ڵ�һ��С��k�����Զ���ʱ˳�������ǰ������һ������ת�Ƽ���", tmp + l �ǵ�ǰ��dp�Ľ���ʱ��.
//		maxans = max(ans[i], maxans);
//	}
//	printf("%d\n", maxans);
//	return 0;
//}

#include<cstdio>
#include<memory.h>
#include<queue>
#define MAXN 10005
#define MAXM 10000005
using namespace std;

int n, id = 0;
int Y[MAXM];
int nextt[MAXM];
int head[MAXN];
int END[MAXN];//��ʼ��¼���￪ʼʱ�䣬���º��¼�������ʱ�� 
int T[MAXN];

// ע���������ȵ�����!

int idu[MAXN];//���˴� ���  
queue<int> Q;

void ADD(int a, int b)//��ʽǰ���� 
{
	Y[++id] = b;
	nextt[id] = head[a];
	head[a] = id;
	idu[b]++;
}

void SCAN() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		int a, c = 1;
		scanf("%d", &a);
		scanf("%d", &T[a]);
		scanf("%d", &c);
		while (c) {
			ADD(c, a);
			scanf("%d", &c);
		}
	}
}

//�����ǰ���ϸ��½ڵ㿪ʼʱ��
//
//������ʱ���½ڵ����ʱ��
//
//�����ѡ�������ֵ���


//�������� ģ��, ��һ��!!!
int TP() {
	memset(END, 0, sizeof(END));
	int ans = 0;
	int i;

	// �տ�ʼ�� �� Ϊ 0 ��Ū��ȥ.
	for (i = 1; i <= n; i++) {
		if (!idu[i]) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		END[x] += T[x];						// ��ɽ���ʱ��.
		ans = ans > END[x] ? ans : END[x];	// ���´�.
		int i;
		// Y[i] ���ڽӵ�, ��ʽǰ���ǲ�Ҫ������!
		for (i = head[x]; i; i = nextt[i]) {
			idu[Y[i]]--;
			END[Y[i]] = END[Y[i]] > END[x] ? END[Y[i]] : END[x];
			// ����������֮ǰ���ϸ��½ڵ㿪ʼʱ�����ֵ!
			// �����½ڵ㿪ʼʱ��Ϊ ԭ�����½ڵ㿪ʼʱ����ǰ���ڵ����ʱ�� �Ľϴ�ֵ 
			if (!idu[Y[i]]) {
				Q.push(Y[i]);
			}
		}
	}
	return ans;
}

int main()
{
	SCAN();
	printf("%d", TP());
	return 0;
}