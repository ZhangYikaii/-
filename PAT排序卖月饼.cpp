// �� �������, �±��۸������г�����, ���������.

#include <bits/stdc++.h>
using namespace std;

double arr[1010], one[1010], per[1010];

int ind[1010];

bool cmp(int a, int b) {
	return per[a] > per[b];
}

int main() {
	int n;
	double lim;
	double res = 0;
	cin >> n >> lim;

	for (int i = 0; i < n; ++i) {
		ind[i] = i;
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> one[i];
		per[i] = one[i] / arr[i];
	}

	sort(ind, ind + n, cmp);

	for (int i = 0; i < n; ++i) {
		int& cur = ind[i];
		if (lim < arr[cur]) {
			res += lim * per[cur];
			break;
		}
		else {
			// �����ʹ��one[], ֱ�Ӽ���per, �����ٳ�һ���о�����ʧ, ��wa.
			res += one[cur];
			lim -= arr[cur];
		}
	}

	printf("%.2f\n", res);

	return 0;
}