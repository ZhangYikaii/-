#include <bits/stdc++.h>
#define INF 0xfffffff
#define mod 1000000007
#define CLR(a,b,Size) memset((a),(b),sizeof((a[0]))*(Size+1))
#define CPY(a,b) memcpy ((a), (b), sizeof((a)))
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define MAXN 2010

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n, c, a[60], b[60], sumCost = 0, curMin = INF;
bool isLight[60] = { false };
int light[60] = { 0 };

int used[60] = { 0 }, iUsed = 0;

// �ú�����dfs����..
void dfs(int curPos, int curClos, int cost, int curLightCost) {
	if (curClos == n) {
		if (curMin > cost) {
			curMin = cost; 
		}
		return;
	}
	int left = curPos, right = curPos;
	int curCostL = cost, curCostR = cost;
	// ����
	for (; left >= 1; --left) {
		if (isLight[left] != false)
			break;
		curCostL += curLightCost;
	}
	if (curCostL < curMin) {
		if (left >= 1) {
			isLight[left] = false;
			used[iUsed] = curCostL;
			dfs(left, curClos + 1, curCostL, curLightCost - light[left]);
			used[iUsed] = 0;
			isLight[left] = true;
		}
	}

	// ����
	for (; right <= a[n + 1]; ++right) {
		if (isLight[right] != false)
			break;
		curCostR += curLightCost;
	}
	if (curCostR < curMin) {
		if (right <= a[n + 1]) {
			isLight[right] = false;
			used[iUsed] = curCostR;
			dfs(right, curClos + 1, curCostR, curLightCost - light[right]);
			used[iUsed] = 0;
			isLight[right] = true;
		}
	}
}

int main() {
	in(n);
	in(c);

	for (int i = 1; i <= n; ++i) {
		in(a[i]);
		in(b[i]);
		if (i == c)
			continue;
		isLight[a[i]] = true;
		light[a[i]] = b[i];
		sumCost += b[i];
	}
	int used[60] = { 0 };

	--n;
	dfs(a[c], 0, 0, sumCost);

	printf("%d\n", curMin);

	return 0;
}

/*
��Ŀ����
ĳһ��ׯ��һ��·���ϰ�װ��nյ·�ƣ�ÿյ�ƵĹ����д���С����ͬһ��ʱ�������ĵĵ����ж����٣������ž�ס������·�м�ĳһ·���ԣ�����һ�������ÿ����������ʱһյһյ�عص���Щ·�ơ�

Ϊ�˸������ʡ��ѣ����ż�¼����ÿյ·�Ƶ�λ�ú͹��ʣ���ÿ�ιص�ʱҲ���Ǿ����ȥ�أ��������Ų�֪������ȥ�صƲ��ܹ����ʡ�硣��ÿ�춼��������ʱ���ȹص��Լ�����λ�õ�·�ƣ�Ȼ���������Ҳ��������ȥ�صơ���ʼ����Ϊ����һ�����·�Ƶ��ܹ�������һ���ұ�·�Ƶ��ܹ��ʣ�Ȼ��ѡ���ȹص����ʴ��һ�ߣ��ٻع�ͷ���ص���һ�ߵ�·�ƣ�����ʵ������ˣ���Ϊ�ڹصĹ������ʵ��ص�ͷ�п��ܻ��ʡһЩ��

������֪�����ߵ��ٶ�Ϊ1m/s��ÿ��·�Ƶ�λ�ã���һ������������·�����ľ��룬��λ��m�������ʣ�W�������Źص����õ�ʱ��̶ܶ����Ժ��Բ��ơ�

����Ϊ���ű�һ���������ŹصƵ�˳��ʹ�����ſ�ʼ�ص�ʱ���������е����ĵ����٣��ƹص���㲻�����ĵ��ˣ���

���������ʽ
�����ʽ��
�ļ���һ������������n(1<=n<=50����ʾ·�Ƶ�����)��c(1<��c<=n��������λ�õ�·�ƺ�)��

������n�У�ÿ���������ݣ���ʾ��1յ����nյ·�Ƶ�λ�ú͹��ʡ����ݱ�֤·��λ�õ���������

�����ʽ��
һ�����ݣ������ٵĹ���(��λ��J��1J��1W��s)��

�����������
��������#1��
5 3
2 10
3 20
5 20
6 30
8 10
�������#1��
270

*/