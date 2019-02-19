#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

// ����

int read() {
	int f = 1, x = 0;
	char ss = getchar();
	while (ss<'0' || ss>'9'){ if (ss == '-')f = -1; ss = getchar(); }
	while (ss >= '0'&&ss <= '9'){ x = x * 10 + ss - '0'; ss = getchar(); }
	return f*x;
}

void print(int x) {
	if (x<0){ putchar('-'); x = -x; }
	if (x>9)print(x / 10);
	putchar(x % 10 + '0');
}

int n, m;
int a[110][1010];
struct node{ 
	int s, step;
	node() {}
	node(int ss, int stt) : s(ss), step(stt) { }
};// s�洢״̬��step�洢��ǰ����
bool vis[1000010];

int spfa() {
	int ss;
	queue<node> q;
	q.push(node((1 << n) - 1, 0 ));
	vis[(1 << n) - 1] = true;// ȫ��Ϊ��ʼ״̬(����)��������Ϊn��1��ʮ���������

	while (!q.empty()) {
		node u = q.front();
		q.pop();
		// ȫ���ص���:
		if (u.s == 0) {
			return u.step;
		}// ��״̬Ϊ0���򷵻ص�ǰ����

		// һ�ΰ����ز���, ����m����ť.
		// ÿ�����ذ��º�ʲô�仯��Ҫ��һ��
		for (int i = 1; i <= m; i++) {
			ss = u.s;
			// ���ڿ��ض����еƶ�Ӱ�죬����ÿ���ƶ�����, �����������ϵ�ÿһλ
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 1 && (ss & (1 << j - 1)))
					ss ^= (1 << j - 1);
				else if (a[i][j] == -1 && !(ss & (1 << j - 1)))
					ss |= (1 << j - 1);
			}
			// ����״̬δ���ʣ��ͼ������
			if (!vis[ss]) {
				q.push(node(ss, u.step + 1));
				vis[ss] = true;
			}
		}
	}
	return -1;
}

int main()
{
	n = read(); m = read();
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		a[i][j] = read();// ����ÿ�����ز����ԵƵ�Ӱ��

	print(spfa());
	return 0;
}

/*
// ����ֻ��һ�ŵ�, ���ǲ�ͬ���ذ���֮������ǵ�Ч����ͬ.
��Ŀ����
����nյ�ƣ��Լ�m����ť��ÿ����ť����ͬʱ������nյ�ơ��������˵�i����ť���������еĵƶ���һ��Ч��������i��ť���ڵ�jյ�ƣ�������3��Ч��֮һ�����a[i][j]Ϊ1����ô����յ�ƿ��˵�ʱ�򣬰������ϣ����򲻹ܣ����Ϊ-1�Ļ��������յ���ǹصģ���ô�����򿪣�����Ҳ���ܣ������0����������Ƿ񿪣������ܡ�

������Щ�ƶ��ǿ��ģ��������п��ض����еƵĿ���Ч������������Ҫ�����°�ť����ȫ���ص���

���������ʽ
�����ʽ��
ǰ������������n m

������m�У�ÿ��n����,a[i][j]��ʾ��i�����ضԵ�j���Ƶ�Ч����

�����ʽ��
һ����������ʾ���ٰ���ť���������û���κΰ취ʹ��ȫ���رգ����-1

�����������
��������#1��
3
2
1 0 1
-1 1 0
�������#1��
2
*/