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


/*
// ��������𰸵ķ������Ǵ���;��ʼdfs, ��Ԥ�����ȫ����, Ȼ����lower_boundȥ���Ǹ�.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sz = 0;
ll a[67000];


// ������־��¼4��7�ĸ���, Ȼ����·�ݹ�. �ֳ� + 4�ĺ� + 7��.
// Ԥ������ȷŵ� a[] ����
void dfs(int p1, int p2, ll now) {
	if (!p1 && !p2) { 
		a[++sz] = now; 
		return; 
	}
	if (p1)
		dfs(p1 - 1, p2, now * 10 + 4);
	if (p2)
		dfs(p1, p2 - 1, now * 10 + 7);
}

int main() {
	for (int i = 1; i <= 9; i++)
		dfs(i, i, 0);
	int T;
	scanf("%d", &T);
	while (T--) {
		ll n; 
		scanf("%lld", &n);
		
		// Ԥ�������������, Ȼ����lower_boundȥ����С�Ĳ�С��X������.
		int pos = lower_bound(a + 1, a + sz + 1, n) - a;
		if (!a[pos])puts("44444444447777777777");
		else printf("%lld\n", a[pos]);
	}
}

*/



// dfs û�ó���, ���skeleton��
// dfs ����һ������, һ��Ҫ��һ����·��ʼdfs��.

int cmp(string a, string b) {
	if (a.length() > b.length())
		return 1;
	else if (a.length() < b.length())
		return 0;

	for (int i = 0; i < a.length(); ++i) {
		if (a[i] > b[i]) {
			return 1;
		}
		else if (a[i] < b[i])
			return 0;
	}

	return 0;
}


// ���������һλ�� 9 ����������.

// ����Ҫ�ľ��ǵ�һ�ε�dfs·��Ҫ����, ����Ҫ����ǰ��һ�仰�˰�, ���ǵ�һ��Ҫ���԰�.

// ����;��ʼ��dfs, �е��鷳, ���Ǻܸ�Ч!!! �Լ�д������, �治����, һ��Ҫϸ��ѽ.

void dfs(int pos, string cur, int four, int seve, string &res, bool isFir, bool &flag) {
	if (flag != false)
		return;

	if (isFir == true) {
		if (res[pos] - '0' == 4 && four != 0) {
			dfs(pos + 1, cur + "4", four - 1, seve, res, isFir, flag);
		}
		if (res[pos] - '0' == 7 && seve != 0) {
			dfs(pos + 1, cur + "7", four, seve - 1, res, isFir, flag);
		}

		if (res[pos] - '0' < 4 && four != 0) {
			dfs(pos + 1, cur + "4", four - 1, seve, res, false, flag);
		}
		if (res[pos] - '0' < 7 && seve != 0) {
			dfs(pos + 1, cur + "7", four, seve - 1, res, false, flag);
		}
	}
	else {
		if (four != 0) {
			dfs(pos + 1, cur + "4", four - 1, seve, res, false, flag);
		}
		if (seve != 0) {
			dfs(pos + 1, cur + "7", four, seve - 1, res, false, flag);
		}

		if (four == 0 && seve == 0 && cmp(res, cur) == 0) {
			flag = true;
			cout << cur << endl;
		}
	}
}

/*
void dfs(int pos, string cur, int four, int seve, string res, bool &flag) {
	if (flag != false)
		return;
	if (res[pos] - '0' <= 4 && four != 0) {
		dfs(pos + 1, cur + "4", four - 1, seve, res, flag);
	}
	if (res[pos] - '0' <= 7 && seve != 0) {
		dfs(pos + 1, cur + "7", four, seve - 1, res, flag);
	}

	if (four == 0 && seve == 0 && cmp(res, cur) == 0) {
		flag = true;
		cout << cur << endl;
	}
}
*/

int main() {
	int t;
	in(t);
	while (t--) {
		string res, aisAdd, bisAdd;
		cin >> res;
		bool isFir = true, flag = false;
		int num = (res.length() + 1) / 2;

		For(i, 0, num)
			aisAdd += "4";
		For(i, 0, num)
			bisAdd += "7";

		if (cmp(res, aisAdd + bisAdd) == 0)
			cout << aisAdd + bisAdd << endl;
		else if (cmp(res, bisAdd + aisAdd) == 1)
			cout << "4"+ aisAdd + bisAdd + "7" << endl;
		else
			dfs(0, "", num, num, res, isFir, flag);
	}
	
	return 0;
}



/*


���ӣ�https://ac.nowcoder.com/acm/contest/931/B
��Դ��ţ����

��Ŀ����
���п���ʱ��X ���� 10min д����ѧ�Ծ���ʼ���ĵ����������� ͻȻ������ʼ�������Լ����������֣����涨����������ʮ������ֻ���� 4 �� 7 �� 4 �ĸ����� 7 �ĸ���һ���ࡣ����֪����С���Ҳ�С������ѧ���Է��������������Ƕ��١�

��������:
��һ��һ������ T����ʾ�� T �����ݡ�

������ T ��ÿ��һ������ ai ��ʾ X ��ѧ���Է�����
�������:
T ��ÿ��һ��������ʾ��С���Ҳ�С�� X ��ѧ���Է������������֡�
ʾ��1
����
����
2
4500
47
���
����
4747
47



*/