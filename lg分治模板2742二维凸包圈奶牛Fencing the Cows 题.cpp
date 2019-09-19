//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//#include <cstdlib>
//#include <string>
//using namespace std;
//
//#define in(x) x=read()
//
//inline int read() {
//	int X = 0, w = 1;
//	char ch = getchar();
//	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//	return X*w;
//}
//
//int MyMin(int a, int b) {
//	return a > b ? b : a;
//}
//
//void Swap(int arr[], int i, int j) {
//	if (i == j)
//		return;
//
//	arr[i] = arr[i] ^ arr[j];
//	arr[j] = arr[i] ^ arr[j];
//	arr[i] = arr[i] ^ arr[j];
//}
//
//
//int main() {
//
//
//	return 0;
//}


#include <iostream>
#include <algorithm>
using namespace std;

#define N 10001

struct node { 
	double x, y; 
}point[N];

int n, top = 2, st[N];//top->ջ����st->��¼͹���ϵ��ջ��
double ans, data_x, data_y;
inline double power(double x) { return x*x; }
inline double dis(int a, int b) { return sqrt(power(point[a].x - point[b].x) + power(point[a].y - point[b].y)); }//�������롣

// �Ƚ�a, b �� b, c ֮��б��
inline bool judge(int a, int b, int c) {
	return (point[a].y - point[b].y)*(point[b].x - point[c].x)>(point[a].x - point[b].x)*(point[b].y - point[c].y);//��б�ʣ�����һ��������
}
inline bool cmp(node a, node b){ return (a.y == b.y) ? (a.x<b.x) : (a.y<b.y); }//������С����ǰ������ȣ���ȡ������С�ġ�
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &point[i].x, &point[i].y);
	}
	sort(point + 1, point + n + 1, cmp);
	st[1] = 1, st[2] = 2;//ǰ�����Ѿ�ȷ������ջ��
	for (int i = 3; i <= n; i++)//ö�������Ľڵ��3��ʼ��
	{
		while (top>1 && !judge(i, st[top], st[top - 1]))top--;//����б�ʣ����ǣ�С��
		st[++top] = i;//������ջ��
	}
	for (int i = 1; i <= top - 1; i++)ans += dis(st[i], st[i + 1]);
	top = 2;
	memset(st, 0, sizeof(st));//���memsetһ�£��п��ܳ����⡣
	st[1] = 1, st[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		while (top>1 && judge(i, st[top], st[top - 1]))top--;//�ѣ�ȥ���Ϳ����ˡ�
		st[++top] = i;
	}
	for (int i = 1; i <= top - 1; i++)ans += dis(st[i], st[i + 1]);//��һ�߻���һ����
	printf("%.2lf", ans);
	return 0;
}


/*

��Ŀ����
ũ��Լ����Ҫ����һ��Χ������Χס������ţ���������ʽ��ѷ����������Χ���������������ţϲ���Բݵ����еص㡣���ڸ�������Щ�ص�����꣬������̵��ܹ�Χס��Щ���Χ���ĳ��ȡ�

���������ʽ
�����ʽ��
�������ݵĵ�һ�а���һ������ N��N��0 <= N <= 10,000����ʾũ��Լ����ҪΧס�ķ��������Ŀ�������� N �У�ÿ��������ʵ����ɣ�Xi �� Yi,��Ӧƽ���ϵķ��������꣨-1,000,000 <= Xi,Yi <= 1,000,000����������С����ʾ��

�����ʽ��
����������һ��ʵ������ʾ�����Χ���ĳ��ȡ��𰸱�����λС����

�����������
��������#1��
4
4 8
4 12
5 9.3
7 8
�������#1��
12.00

*/