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

string s[100010];
map<string, int> mapp;


// ��ϣ, �Լ�����:
// ע��: ֮ǰ��O(n)ɨһ��ȫ��������, һ���Դ�����һ�Ե�, ����mapp = 0.
// ������Ե�ƥ��, DNAƥ�䶼����������hash��˼·��.

string Switch(string a) {
	for (int i = 0; i < a.length(); ++i) {
		switch (a[i]) {
		case 'A':
			a[i] = 'T';
			break;

		case 'T':
			a[i] = 'A';
			break;
		case 'C':
			a[i] = 'G';
			break;
		case 'G':
			a[i] = 'C';
			break;

		default:
			break;
		}
	}

	return a;
}

int main() {
	int n;
	in(n);

	int ans = 0;
	string tmp;
	For(i, 0, n) {
		cin >> s[i];
		++mapp[s[i]];
	}

	For(i, 0, n) {
		tmp = Switch(s[i]);
		// cout << tmp << "  " << min(mapp[tmp], mapp[s[i]]) << endl;
		ans += min(mapp[tmp], mapp[s[i]]); // ע������������ʽ��ƥ��.
		mapp[s[i]] = 0;
	}

	printf("%d\n", ans);
	

	return 0;
}


/*

���ӣ�https://ac.nowcoder.com/acm/contest/931/A
��Դ��ţ����

��Ŀ����
DNA������ֻ��ACGT������ĸ��A��T��Ӧ��C��G��Ӧ��
��������ȫ��Ӧ������ָ����ÿһλ�ϵ���ĸһһ��Ӧ������ACG��TGC��ȫ��Ӧ
�������ѡ�����ٶ���ȫ��Ӧ��DNA���С�����Ȼһ��������౻ѡһ�Σ�
��������:
��һ��һ������n��ʾ�ж������С�
������n�У�ÿ��һ������\leq 20��20��ֻ����ACGT���ַ�������ʾ���С�

�������:
һ����������ʾ�����ѡ�����ٶ���ȫ��Ӧ�ġ�
ʾ��1
����
����
4
ATCG
TAGC
TAGG
ACG
���
����
1
˵��
ATCG��TAGC��ȫ��Ӧ��
ʾ��2
����
����
20
CG
C
C
C
A
AG
G
A
CG
A
TA
CA
G
A
GC
TT
GT
GA
CA
G
���
����
5



*/