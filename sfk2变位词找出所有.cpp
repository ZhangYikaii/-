#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


struct Data {
	string str;
	int index;
	Data() : index(0) { }
	bool operator<(const Data &c) const {
		return this->str < c.str;
	}
};

#define in(x) x=read()

#define MAXN 1000000

typedef long long ll;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;
Data *arr;
int minEqual, curEqual;



void ResQuickSort(int left, int right, string resArr[]) {
	int i, j;
	string temp;
	if (left > right)
		return;

	temp = resArr[left];		// ȡ����׼��
	i = left;
	j = right;
	// ע��� left �� right ��ʱ�ķ��� i j ����, Ȼ��Ҫ�ȴ��ұ߿�ʼ��
	while (i != j) {
		while (resArr[j] >= temp && i < j)		// ���������ҵ���һ����С��(Ӧ�÷�����ߵ�)
			--j;
		while (resArr[i] <= temp && i < j)		// ���������ҵ���һ�������(Ӧ�÷����ұߵ�)
			++i;

		// ����λ��
		if (i < j) {
			string t = resArr[i];
			resArr[i] = resArr[j];
			resArr[j] = t;
		}
	}

	// ���ս���׼����λ
	resArr[left] = resArr[i];         // ע����仰!!!
	resArr[i] = temp;

	ResQuickSort(left, i - 1, resArr);			//����������ߵ�
	ResQuickSort(i + 1, right, resArr);			//���������ұߵ�
}


string StringSort(string &s) {
	int cou[30] = { 0 }, nn = s.length();
	for (int i = 0; i < nn; ++i) {
		++cou[s[i] - 'a'];
	}
	string res = "";
	for (int i = 0; i < 26; ++i) {
		while (cou[i]--) {
			res += ('a' + i);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	in(n);

	arr = new Data[n];
	string *tmp = new string[n];
	string *resArr = new string[n];
	int *ress = new int[n], iRes = 0;

	for (int i = 0; i < n; ++i) {
		cin >> tmp[i];
		arr[i].str = StringSort(tmp[i]);
		arr[i].index = i;
	}
	

	sort(arr, arr + n);

	/*for (int i = 0; i < n; ++i) {
		cout << rank[i] << " ";
	}
	cout << endl;

	cout << endl;*/

	curEqual = 0;
	int ti;
	for (ti = 1; ti < n; ++ti) {
		if (arr[curEqual].str == arr[ti].str)
			continue;
		else {
			if (curEqual + 1 != ti) {
				minEqual = curEqual;
				cout << tmp[arr[minEqual].index] << " ";
				for (int k = curEqual + 1; k < ti; ++k) {
					cout << tmp[arr[k].index] << " ";
					if (tmp[arr[k].index] < tmp[arr[minEqual].index]) {
						minEqual = k;
					}
				}
				ress[iRes++] = minEqual;
			}
			curEqual = ti;
		}
	}
	if (curEqual + 1 != ti) {
		minEqual = curEqual;
		for (int k = curEqual + 1; k < ti; ++k) {
			if (tmp[arr[k].index] < tmp[arr[minEqual].index]) {
				minEqual = k;
			}
		}
		ress[iRes++] = minEqual;
	}

	printf("wo yi yue du guan yu chao xi de shuo ming\n");
	cout << iRes << endl;
	for (int i = 0; i < iRes; ++i) {
		resArr[i] = tmp[arr[ress[i]].index];
	}

	/*for (int i = 0; i < iRes; ++i) {
		cout << resArr[i] << endl;
	}*/

	sort(resArr, resArr + iRes);
	for (int i = 0; i < iRes; ++i) {
		cout << resArr[i] << endl;
	}
	

	delete[] arr;
	delete[] ress;
	delete[] tmp;
	delete[] resArr;

	return 0;
}

/*

��Ŀ����
��������oj��֮ǰ����ϸ�Ķ����ڳ�Ϯ��˵��http://www.bigoh.net/JudgeOnline/.


��λ����ָ����ͬ����ĸ��ɵĵ��ʣ���eat��tea�Ǳ�λ�ʡ������������һ�����ʣ�����Ҫ�ҵ����еı�λ�ʡ�

����
������������ɣ���һ�������е��ʵ��������ڶ������ɿո�ָ��ĵ����б�����ĩβ���пո�

ע��Ϊ�����壬����ĵ��ʶ���Сд

���
�����Ҫ��������һ���ַ��������ǡ������Ķ����ڳ�Ϯ��˵�����ĺ���ƴ��.������е��ύ���ǽ���Ϊ�Ѿ���ȫ�Ķ����˽��ˡ����ڳ�Ϯ��˵��������.

�ڶ����Ǳ�λ����ĸ��������������еı�λ�ʡ�ÿ������ı�λ��ռһ�С�һ���λ��ֻ��Ҫ���һ���ֵ�����С�Ĵ����ɣ���eat��tea��eat�ֵ���С��tea���������eat����λ�����λ��Ҳ�����ֵ����С�������У���eat��el��eat�ֵ���С��el����eat��elǰ�档

�����ÿһ�����û�пո�

��������
9
a ew vc tea oe eat zoo el le
�������
wo yi yue du guan yu chao xi de shuo ming
2
eat
el

*/