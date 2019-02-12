#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#define For(i, n, m) for(int i = n;i < m; ++i)

inline int read(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	if (f) return x;
	return 0 - x;
}

int n, m, a[66], nextArr[66], cnt, sum, len;

bool used[66], ok; //used���鼴�Ż�5��vis���飬��¼ÿ��ľ���Ƿ��ù���ok��¼�Ƿ����ҵ��𰸡� 
bool cmp(int a, int b) {
	return a > b;
}

// k Ϊ����ƴ��ľ���ı��, ����ݹ�����/������last Ϊ����ƴ��ľ����ǰһ�ڱ�ţ�rest Ϊ��ľ����δƴ�ĳ���
void dfs(int k, int last, int rest) {
	int i;

	// δƴ�ĳ���Ϊ0��˵�����ԭʼ����ƴ���ˣ�׼��ƴ��һ��
	// ���������Ŀ�ͷ, ƴ�ĵ�һ��ľ��
	if (!rest) { 
		if (k == m) { ok = 1; return; } //�Ż�6��ȫ��ƴ�겢����Ҫ���ҵ��𰸣�ֱ�ӷ��� 

		// ��һ����û�õ����ľ����ͷ���ɡ�����Ҫ��ȫ��ƴ�ӳɹ���ÿ��ľ���������� 
		for (i = 1; i <= cnt; i++) {
			if (!used[i]) 
				break;
		}

		used[i] = 1;
		dfs(k + 1, i, len - a[i]);			// ����ѡ�˵�һ��ľ��, ������ len - a[i]
		used[i] = 0;

		if (ok) return; //�Ż�6���ҵ��𰸾��˳� 
	}

	else {
		// �Ż�4�������ҵ�һ�� ľ�����Ȳ�����δƴ���� rest ��λ�� 
		int l = last + 1, r = cnt, mid;
		while (l < r) {
			mid = (l + r) >> 1;
			if (a[mid] <= rest)
				r = mid;
			else
				l = mid + 1;
		}

		for (i = l; i <= cnt; i++) {
			if (!used[i]) { //�Ż�5���ж�ľ���Ƿ��ù� 
				used[i] = 1;
				dfs(k, i, rest - a[i]);
				used[i] = 0;

				if (ok) return; //�Ż�6���ҵ��𰸾��˳� 

				// �Ż�7: �����ǰ����ʣ���δƴ���ȵ��ڵ�ǰľ���ĳ��Ȼ�ԭʼ���ȣ�����ƴ��ȥʱȴʧ���ˣ���ֱ�ӻ��ݲ���֮ǰƴ��ľ��
				if (rest == a[i] || rest == len)
					return;
				i = nextArr[i]; //�Ż�3 

				if (i == cnt)
					return;
			}
		}
	}
}
int main(){
	n = read();
	int d;
	for (int i = 1; i <= n; i++){
		d = read();
		if (d > 50) 
			continue;
		a[++cnt] = d;
		sum += d;
	}

	sort(a + 1, a + cnt + 1, cmp); //�Ż�1��ľ�������ȴӴ�С���� 
	
	//�Ż�3��Ԥ����nextArr����, ��֤���������ظ���, �е��񲢲鼯������, ��������ܲ���
	nextArr[cnt] = cnt;
	for (int i = cnt - 1; i>0; i--) {
		if (a[i] == a[i + 1]) 
			nextArr[i] = nextArr[i + 1];
		else 
			nextArr[i] = i;
	}

	// �ܵ�������ʼ, ȷ������ÿһ���len
	for (len = a[1]; len <= sum / 2; len++) { //ö��ԭʼ���� 
		if (sum%len != 0) 
			continue; //�������ƴ�������� ������ 

		m = sum / len; //�Ż�6�е��Ǹ����� 
		ok = 0;

		used[1] = 1;
		dfs(1, 1, len - a[1]);
		used[1] = 0;

		if (ok){ printf("%d\n", len); return 0; } //�Ż�6������𰸣��˳�
	}
	printf("%d\n", sum); return 0;
}