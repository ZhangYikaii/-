#include <bits/stdc++.h>
using namespace std;


// ��������λDP�ⷨ..

#include<iostream>
#include<vector>
using namespace std;
int main() {
	long long int n, sum = 0;
	cin >> n;
	int a[100010] = { 0 };
	// vector<int> a(n+1, 0);

	// ����С��n��������.
	// ���ַ������ǰ�С��n����������1�ĸ��������.
	// ��Ϊ���������Ǹ�λ, ���Ծ���ÿ���жϸ�λ.
	for (int i = 1; i <= n; i++) {
		// ��һ�����ƵĹ�ϵ.
		// �����λΪ0, ���λ��û��������, ����1�ĳ��ִ����ͺ� i / 10 һ��.
		// ע����������ܹؼ�.
		if (i % 10 == 0)
			a[i] = a[i / 10];
		// ��һ��, ��Ϊ == i ��ʱ�����һ��.
		else if (i % 10 == 1)
			a[i] = a[i - 1] + 1;
		// ��Ϊ���2��, ����Ӧ�ú�a[i - 2] һ��, ����a[i - 1] - 1.
		else if (i % 10 == 2)
			a[i] = a[i - 1] - 1;
		else
			a[i] = a[i - 1];
		sum += a[i];
	}
	cout << sum << endl;


	return 0;
}


//
//// ����ֱ�ӿ�����...
//// �����Ǿ�˵�Ƚ�ͨ�õ�һ������, ÿһλɨ, �ֳɵ�ǰλ����������.
//#include <iostream>
//using namespace std;
//int main() {
//	int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
//	scanf("%d", &n);
//	while (n / a) {
//		// 
//		// ���� a == 1000, n = 1234567
//		// left = 123, now = 4, right = 567.
//		// �ֳ���������, ��ʵ�����м��Ǹ����־���һλ��.
//
//		left = n / (a * 10), now = n / a % 10, right = n % a;
//		// cout << left << " " << now << " " << right << endl;
//
//		// ��������������ֹ�ʽ����������Ĺ�.
//		if (now == 0)
//			ans += left * a;
//		else if (now == 1)
//			ans += left * a + right + 1;
//		else
//			ans += (left + 1) * a;
//
//		a = a * 10;
//	}
//	printf("%d", ans);
//	return 0;
//}

//int main() {
//	string N;
//	cin >> N;
//
//
//
//
//	return 0;
//}