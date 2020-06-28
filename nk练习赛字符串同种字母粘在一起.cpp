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


int used[30] = { 0 };

int main() {
	string s;
	int n;
	in(n);
	cin >> s;

	for (int i = 0; i < n; ++i) {
		if (used[s[i] - 'a'] == 0) {
			used[s[i] - 'a'] = 1;
		}
		else {
			if (s[i - 1] != s[i]) {
				printf("NO\n");
				return 0;
			}
		}
	}

	printf("YES\n");


	return 0;
}

/*

���ӣ�https://ac.nowcoder.com/acm/contest/1080/A
��Դ��ţ����

��Ŀ����
tokitsukaze��һ������Ϊn��ֻ����Сд��ĸ���ַ���S��
����ÿһ����ĸ����ͬ����ĸ������һ��tokitsukaze��е��������á�
��tokitsukaze��е��������ã������"YES"���������"NO"��(���������š�)
��������:
��һ������һ��������n��(1��n��100)��
������һ������һ������Ϊn���ַ���S��'a'��S[i]��'z'��
�������:
���һ�У�"YES",����"NO"��
ʾ��1
����
����
1
a
���
����
YES
ʾ��2
����
����
2
ab
���
����
YES
ʾ��3
����
����
3
aba
���
����
NO


*/