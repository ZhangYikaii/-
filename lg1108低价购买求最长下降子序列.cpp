//#include <bits/stdc++.h>
//using namespace std;
//
//int arr[5010], dp[5010];
//
//vector<int> ve[5010];
//
//int main() {
//	int n;
//	cin >> n;
//	
//	for (int i = 1; i <= n; ++i) {
//		cin >> arr[i];
//		dp[i] = 1;
//	}
//
//	for (int i = 1; i <= n; ++i) {
//		for (int k = 1; k < i; ++k) {
//			if (arr[k] > arr[i]) {
//				if (dp[i] > dp[k] + 1) {
//					ve[i].clear();
//					dp[i] = dp[k] + 1;
//					ve[i].push_back(k);
//				}
//				else if (dp[i] == dp[k] + 1)
//					ve[i].push_back(k);
//			}
//		}
//	}
//
//	int maxx = dp[1], indMax = 1;
//	vector<int> res;
//	for (int i = 1; i <= n; ++i) {
//		if (maxx < dp[i]) {
//			maxx = dp[i];
//			indMax = i;
//			res.clear();
//			res.push_back(indMax);
//		}
//		else if (maxx == dp[i]) {
//			res.push_back(indMax);
//		}
//	}
//
//	return 0;
//}


#include<cstdio>
#include<cstring>
int max(int x, int y) { return x > y ? x : y; }
int a[5001], f[5001], t[5001];
// a[i]����ǵ�i���Ʊ�ļ۸�
// f[i]����ǵ�i����½������еĳ���
// t[i]�������i��β����½������е����ࣨ������ ����ֱ�ӿ�һ������������෽������.
int main()
{
	memset(f, 0, sizeof(f));//��ʼ������
	memset(t, 0, sizeof(t));//��ʼ������
	int n, maxx = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
			if (a[i] < a[j])//�ӳ��Ѿ����ڵ���½�������
				f[i] = max(f[i], f[j] + 1);
		if (f[i] == 0)
			f[i]++;//�����ǰ������ĿǰΪֹ���ģ�����½����������Լ�
		if (f[i] > maxx)
			maxx = f[i];//��f���������Ϻ󣬴�����½������еĳ���
		for (int j = 1; j < i; j++)
			// ע����һ����ͬ��ʱ��Ҫ��ȥ, ���Ǽ�¼�����������Զ�Ǽ�¼�ڸ��������Ԫ����.
			if (f[i] == f[j] && a[i] == a[j])
				t[j] = 0;//�����ǰ���������ͬ������ȥǰ������У���ֹ�ظ�����
			else if (f[i] == f[j] + 1 && a[i] < a[j])
				t[i] += t[j];//������Խ���ǰ������У���̳��䷽����
		if (!t[i])//�����ǰ������ĿǰΪֹ���ģ����ǳ�ʼ����
			t[i] = 1;
	}
	int sum = 0;//sum���������ڴ���½������У��������ĸ���
	for (int i = 1; i <= n; i++)
		if (f[i] == maxx)
			sum += t[i];
	printf("%d %d", maxx, sum);
	return 0;
}