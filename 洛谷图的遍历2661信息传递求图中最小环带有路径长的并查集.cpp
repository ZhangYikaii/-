#include<cstdio>
#include<iostream>
using namespace std;

int min(int a, int b) {
	return a > b ? b : a;
}

int f[200002], d[200002], n, minn, preFather;  // f �������Ƚڵ㣬d ���浽�����Ƚڵ��·������ 

// d�ĳ�ʼֵ�ǵ��Լ����׵ĳ��Ȱ�
// ��ô������һ��ʼ�����ȵĳ��ȣ��Ǿ����Լ���d�����Լ������ף����ϸ��׵�d���Ӹ��׵����ȣ�
int Find(int x) {
	if (f[x] != x) {						  // ����ʱ��;�������Ƚڵ��·������										 
		int preFather = f[x];				  // ��¼���ڵ㣨���ڵݹ��б����£��� 
		f[x] = Find(f[x]);					  // �������Ƚڵ㡣 ���Ͻ�һ�� 
		d[x] += d[preFather];				  // ����·������ԭ�����ڸ��ڵ��ϣ��� ��һ���ܹؼ�!!!
	}

	return f[x];
}
void check(int a, int b) {
	int x = Find(a), y = Find(b);					// �������Ƚڵ㡣 
	// �������������������㣬���¸��ڵ��·������ 
	if (x != y) { 
		f[x] = y; 
		d[a] = d[b] + 1;
	}
	else 
		minn = min(minn, d[a] + d[b] + 1);			// �������ӣ��������С�����ȡ� 
	return;
}
int main()
{
	int i, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) f[i] = i;			// ���Ƚڵ��ʼ��Ϊ�Լ���·����Ϊ0�� 
	minn = 0xfffffff;
	for (i = 1; i <= n; i++) {
		scanf("%d", &t);
		check(i, t);							// ��鵱ǰ�����Ƿ����б������ӡ� 
	}

	printf("%d", minn);

	return 0;
}