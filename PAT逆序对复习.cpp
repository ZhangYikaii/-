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

// ����һ������Ե�����.

// luogu �鲢�������ȵ�ѽ:

#include<cstdio>
#define ll long long 
using namespace std;
const int maxn = 5e5 + 5;
//������� �鲢����������� �Ĺ���==
int a[maxn], tmp[maxn], n;
ll ans = 0;//ans��Ϊȫ�ֱ�������¼����Ե������� 
void msort(int s, int t) {
	if (s == t) 
		return;
	int mid = s + t >> 1;
	
	msort(s, mid); 
	msort(mid + 1, t);//���������������ݹ������
	
	int i = s, j = mid + 1, k = s;

	// i, j ������ָ��, ������ֳ����������ָ��.
	// �����������ֹ鲢����.
	while (i <= mid && j <= t) {
		if (a[i] <= a[j]) 
			tmp[k++] = a[i++];//�ȸ�ֵ��+1 
		else {
			tmp[k++] = a[j++];
			// ��ؼ��ľ���������һ��.
			// ans += (ll)mid - i + 1
			// ans += (ll)mid - i + 1;
			ans += (ll)mid - i + 1;//�������Ϊ�������ѧ���ɰ�qaq��
		}
	}
	while (i <= mid) {
		tmp[k] = a[i];
		k++, i++;
	}
	while (j <= t) {
		tmp[k] = a[j];
		k++, j++;
	}

	for (int i = s; i <= t; i++)
		a[i] = tmp[i];//���ƻ�a������ 
}


inline int read() {//���
	char ch = getchar();
	int x = 0, f = 1;
	while (ch<'0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) a[i] = read();
	msort(1, n);//��1��n��a��������;
	printf("%lld\n", ans);
	return 0;
}

// ��ס��ؼ�����һ�� ans += (ll)mid - i + 1;

int main() {
	


	return 0;
}

/*




*/