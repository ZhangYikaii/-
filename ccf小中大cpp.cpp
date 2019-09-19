//#include <bits/stdc++.h>
//using namespace std;
//
//double arr[100010];
//
//int main() {
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; ++i) {
//		cin >> arr[i];
//	}
//
//	if (n == 1) {
//		cout << arr[0] << " " << arr[0] << " " << arr[0] << endl;
//		return 0;
//	}
//
//	double maxx = max(arr[0], arr[n - 1]), minn = min(arr[0], arr[n - 1]);
//	if (n % 2 != 0) {
//		double tmp = arr[n / 2];
//		cout << maxx << " " << setiosflags(ios::fixed) << setprecision(2) << tmp;
//		cout << resetiosflags(ios::fixed) << " " << minn << endl;
//	}
//	else {
//		double tmp = ((double)arr[n / 2] + (double)arr[n / 2 - 1]) / 2;
//		// printf("%f %.1f %f\n", maxx, tmp, minn);
//		cout << maxx << " ";
//		cout << setiosflags(ios::fixed) << setprecision(2) << tmp << " " << minn << endl;
//		// cout << maxx << " " << tmp << " " << minn << endl;
//	}
//
//	return 0;
//}

#include <cstdio>
#include <algorithm> // max()/min()

using namespace std;

static int s[100000 + 2];

/*
 * 1. ռλ����
 * %g �����ݽϳ���϶�ʱ�����%e����������ÿ�ѧ��������
 * �� %f�򲻴��ڸ����⣬�����С���������0��
 * 2. float���ȣ�
 * float��Ч����Ϊ7~8λ����doubleΪ15~16λ�� ��������Чλ�����򾫶ȶ�ʧ��e.g:
 * 100000000.0f / 211111111.0f = 155555552.0(ERROR)
 *                               155555555.5 (double)
 * 3. ����������ת���ľ��ȶ�ʧ���⣺
 * (int)((double)2.3*100) = 229(ERROR)
 * (int)((float)2.3*100) = 230(?)
 *
 * 4. ͬ3�������򸡵�ת��������洢���ǽ���ֵ���������������ֵ�仯�� ��2����֮��Դ��
 */
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	int n_max = max(s[0], s[n - 1]);
	int n_min = min(s[0], s[n - 1]);

	if (n & 1) {
		printf("%d %d %d\n", n_max, s[n / 2], n_min);
	}
	else {
		if ((s[n / 2 - 1] + s[n / 2]) & 1)
			printf("%d %.1lf %d\n", n_max, (double)(s[n / 2 - 1] + s[n / 2]) / 2.0, n_min);
		else
			printf("%d %d %d\n", n_max, (s[n / 2 - 1] + s[n / 2]) / 2, n_min);
	}

	return 0;
}