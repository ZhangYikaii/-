//#include <bits/stdc++.h>
//using namespace std;
//
//struct Node {
//	int l, r;
//};
//
//int val[100010];
//
//Node arr[100010];
//
//// ��ô���ݸ��ϲ���?
//int check(int left, int right) {
//	if (left == -1 && right == -1)
//		return 1;
//
//	if (val[left] == val[right])
//}
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; ++i) {
//		cin >> val[i];
//	}
//	for (int i = 1; i <= n; ++i) {
//		cin >> arr[i].l >> arr[i].r;
//	}
//
//
//	return 0;
//}

#include <bits/stdc++.h>
#define ll long long

const int maxn = 2000000;

using namespace std;

ll a[maxn], l[maxn], r[maxn];

ll ans, N;
/*
a�����ڵ���ֵ��l[i]��ʾ���Ϊi�Ľڵ�����ӵı�ţ�
r[i]��ʾ���Ϊi�Ľڵ���Һ��ӵı��
*/
bool f;  //ȫ�ֱ���f�ж��Ƿ�Ϊ�Գƶ�������


// �����ʵ���ǵ���дһ���������ڵ�����ĵݹ麯��.
inline ll cnt(ll x) //������xΪ���ڵ�ĶԳƶ��������Ľڵ���  *�ݹ�
{
	ll sum = 0;
	if (l[x] != -1) sum += cnt(l[x]);
	if (r[x] != -1) sum += cnt(r[x]);
	return sum + 1;  //�����˸��ڵ�
}


// ����ȫ�ֱ�־λ�ж��ǲ��ǶԳ�.
void work(ll xx, ll yy)  //�ж϶Գƶ��������ĺ���   *�ݹ�
{
	if (xx == -1 && yy == -1)
		return;  //����Ѿ������ˣ�����
	if (xx == -1 || yy == -1 || a[xx] != a[yy]) { f = 0; return; } //���Գ�
	work(l[xx], r[yy]);
	work(r[xx], l[yy]); //���������ͼ��������qwq
}

int main()
{
	cin >> N;//����n

	for (int i = 1; i <= N; ++i)  //����ÿ���ڵ��ֵ
		scanf("%lld", &a[i]);

	for (int i = 1; i <= N; ++i)   //����ÿ���ڵ�����Һ��ӽڵ���
		scanf("%lld%lld", &l[i], &r[i]);

	ans = 1;      //������һ���Գƣ�һ���ڵ㣩

	for (int i = 1; i <= N; ++i)  //ö�ٶԳƶ��������ĸ��ڵ�
		if (l[i] != -1 && r[i] != -1 && a[l[i]] == a[r[i]])  //������Թ��˵��ܶ಻��Ҫ��ö��
		{
			f = true;     //��Ĭ��Ϊ�ǶԳƶ�������

			work(l[i], r[i]);      //��ʼ�ݹ��ж�

			if (f == true) 
				ans = max(ans, cnt(i));  //����ǶԳƶ��������Ϳ��Լ���ڵ�ȡ���ֵ��
		}

	printf("%lld\n", ans);

	return 0;
}