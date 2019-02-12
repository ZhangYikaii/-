#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;


inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int pre[1010], nodeNum[1010]; // pre[a] == b��ʾa�ĸ�����b, nodeNum[i] == j��ʾ���ڵ�Ϊi��������j���ڵ�

void Init(int n) {
	// ����ʱ����ֹ��ʱ�� �Լ����Լ��ĸ���
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
		nodeNum[i] = 1;
	}
}

// ���Ƿǵݹ���Ҹ���
int Find(int x) // Find(a)�ķ���ֵ����a������ �����Ǹ�
{
	int t = x;

	// ͨ�����ϵ��Ҹ��ײ����������ҵ�x�����ȣ����������Լ����Լ�������
	while (x != pre[x])
		x = pre[x];
	// �����Ѿ��ҵ����ϵ����Ⱦ��� x ��

	// �Ż� ������̫��     ���������ѹ���Ż���
	// ����һ·�ϵ�pre��ֱ��ָ����������
	if (t != x) {
		int tFa = pre[t];  // �ݴ�t�ĸ��� 
		pre[t] = x;        // ֱ��ָ����������
		t = tFa;           // ��һ���μ���û��ָ���������ȵ� һֱ����������
	}

	return x;
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	//a,b������һ������ô�Ͳ���Ҫ������
	if (a == b)
		return;

	// ע�����������ʱ������ѭһ������
	//a��b������b�ӵ�a���� 
	if (nodeNum[a] >= nodeNum[b]) {
		pre[b] = a;
		nodeNum[a] += nodeNum[b];
	}
	else {
		pre[a] = b;
		nodeNum[b] += nodeNum[a];
	}
}

bool Check(int x, int y) // ����
{
	if (Find(x) == Find(y))
		return true;
	else
		return false;
}

int enemy[1010] = { 0 }, n, m;
char ch;
int a, b;

int main() {
	n = read();
	m = read();
	Init(n);

	for (int i = 1; i <= m; ++i) {
		ch = getchar();
		a = read();
		b = read();

		if (ch == 'F')
			Union(a, b);
		else {
			// ���鼯һ��Ҫ�����������˼��, a�ĵ�����һ��, �Ͷ���ΪFind(b)
			if (enemy[a] == 0)
				enemy[a] = Find(b);
			else
				Union(b, enemy[a]);

			if (enemy[b] == 0)
				enemy[b] = Find(a);
			else
				Union(a, enemy[b]);
		}
	}

	// ͳ�������м���, ���൱��ͳ���ж��ٸ���(��ͨ��)
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (pre[i] == i)
			++ans;
	}
	printf("%d", ans);

	return 0;
}

/*


��Ŀ����
1920���֥�Ӹ磬������һȺǿ�����������ǿ�������ˣ���ô����Ҫô�����ѣ�Ҫô�ǵ��ˡ�������һ���ǿ϶��ģ����ǣ�

�����ѵ��������ҵ����ѣ�

�ҵ��˵ĵ���Ҳ���ҵ����ѡ�

����ǿ����ͬһ�Ż�������ǵ��ҽ������������ѡ����ڸ���һЩ����ǿ���ǵ���Ϣ����������ж��ٸ�ǿ���Ż

���������ʽ
�����ʽ��
�����ļ�gangs.in�ĵ�һ����һ������N(2<=N<=1000)����ʾǿ���ĸ�������1��ŵ�N���� �ڶ���M(1<=M<=5000)����ʾ����ǿ������Ϣ������ ����M�У�ÿ�п�����F p q����E p q��1<=p q<=N����F��ʾp��q�����ѣ�E��ʾp��q�ǵ��ˡ��������ݱ�֤���������Ϣ��ì�ܡ�

�����ʽ��
����ļ�gangs.outֻ��һ�У���ʾ�����ܵ��Ż�����

�����������
��������#1��
6
4
E 1 4
F 3 5
F 4 6
E 1 2

�������#1��
3


*/