#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

int n, t = 0, c[1000010];
// c[i]��ʾi��Ϊ���ӵĴ���

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		t = max(t, x);
		// ��¼Ŀǰ�������ֵ
		int m = sqrt(x);
		// ����ֵ�Ŀ���
		for (int i = 1; i <= m; i++) {
			// ��Լ��
			if (x % i == 0) {
				c[i]++;
				// i��Ϊ���ӵĴ���++
				// ������!!! �����ֻ�õ� sqrt(x) �ĺ���
				if (x != i * i)
					c[x / i]++;
				// ���x����i��ƽ����x / i Ҳ�� x ������
				// ���x��i��ƽ��ֻ��¼i��Ϊһ������
			}
		}
	}
	int x = t;
	for (int i = 1; i <= n; i++) {
		// �ܼ�ÿ�α��� �� c[x] < i �Ϳ�����, û�뵽������ô��... 
		while (c[x] < i)
			x--;
		// �ҳ�����Ĭ��ֵ
		cout << x << endl;
		// ���
	}
	return 0;
}
// 
// #define in(x) x=read()
// 
// inline int read()
// {
// 	int X = 0, w = 1;
// 	char ch = getchar();
// 	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
// 	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
// 	return X*w;
// }
// 
// int n, a[10010], tmpAns[110], ans[10010] = { 0 };
// 
// int main() {
// 	in(n);
// 	for (int i = 1; i <= n; ++i)
// 		in(a[i]);
// 
// 	sort(a + 1, a + n + 1);
// 
// 	for (int i = 1; i <= a[n]; ++i) {
// 		for (int k = 1; k <= n; ++k) {
// 			if (a[k] >= i && a[k] % i == 0)
// 				++tmpAns[i];
// 		}
// 	}
// 
// 	for (int i = a[n]; i >= 0; --i) {
// 		if (ans[tmpAns[i]] == 0)
// 			ans[tmpAns[i]] = i;
// 	}
// 
// 	for (int i = a[n] - 1; i >= 1; --i) {
// 		if (ans[i] == 0)
// 			ans[i] = ans[i + 1];
// 	}
// 	for (int i = 1; i <= n; ++i)
// 		printf("%d\n", ans[i]);
// 	return 0;
// }

/*
��Ŀ����
������һ�Σ���ʦ��̫���⡣��Ȼ����ȡÿλͬѧ�ĺ����������Լ����Ȼ��̫����������ʦ��ÿλͬѧ����һ������ֵ���������������Ϊ����n��ѧ��������k����ʹ�����ǵ�Ĭ���̶ȣ�������ֵ�����Լ������󡣵���Ϊ��Ŀ̫���ˣ�����ÿ����Ŀ��Ҫ�������ֲ�֪������ʦ��Ҫ֪������������ܴﵽ�����Ĭ���̶��Ƕ��١������Ӹ��鷳�ˣ����ǽ������~

PS��һ���������Լ��������

���������ʽ
�����ʽ��
��һ��һ��������n��

�ڶ���Ϊn���ո����������������ʾÿ��ѧ��������ֵ��

�����ʽ��
�ܹ�n�У���i��Ϊk=i����µ����Ĭ���̶ȡ�

�����������
��������#1��
4
1 2 3 4
�������#1��
4
2
1
1

*/

