#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


#define in(x) x=read()

#define MAXN 1000000

string *arr, *tmp;

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int n;

string StringSort(string &s) {
	int cou[30] = { 0 }, n = s.length();
	for (int i = 0; i < n; ++i) {
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

bool cmpTmp(int &a, int &b) {
	return tmp[a] < tmp[b];
}

bool cmpArr(int &a, int &b) {
	return arr[a] < arr[b];
}


int main() {
	ios::sync_with_stdio(false);
	in(n);

	arr = new string[n];
	tmp = new string[n];
	int *rankTmp = new int[n], *rankArr = new int[n];
	bool *isOk = new bool[n];
	int resNum = 0;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		tmp[i] = StringSort(arr[i]);
		rankTmp[i] = i;
		rankArr[i] = i;
		isOk[i] = false;
	}

	sort(rankTmp, rankTmp + n, cmpTmp);
	for (int i = 0; i < n - 1; ++i) {
		// cout << rankTmp[i] << "  ";
		if (tmp[rankTmp[i]] == tmp[rankTmp[i + 1]]) {
			isOk[rankTmp[i]] = true;
			isOk[rankTmp[i + 1]] = true;
		}
	}
	sort(rankArr, rankArr + n, cmpArr);
	for (int i = 0; i < n; ++i) {
		if (isOk[i] == true)
			++resNum;
	}

	printf("wo yi yue du guan yu chao xi de shuo ming\n%d\n", resNum);
	for (int i = 0; i < n; ++i) {
		if (isOk[i] == true)
	}

	


/*
9
a ew vc tea oe eat zoo el le
0  3  5  2  7  8  4  1  6
0  5  7  1  8  4  3  2  6
*/

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