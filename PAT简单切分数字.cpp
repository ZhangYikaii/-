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

#define MAX 100010

// ע����C�����뷽ʽ;

// ���￴�����ܼ�, ������ʵ�кܶิ�ӵ����Ҫ�������, ��ؼ���Ҫ����Ǹ���Чλ�ĺ���.

int n;
string arr, brr;

int main() {
	cin >> n >> arr >> brr;

	int ap = arr.find("."), bp = brr.find("."), ia = 0, ib = 0;
	if (ap == string::npos)
		ap = arr.size();
	if (bp == string::npos)
		bp = brr.size();
	for (; ia < arr.size(); ++ia) {
		if (arr[ia] != '0' && arr[ia] != '.')
			break;
	}
	for (; ib < brr.size(); ++ib) {
		if (brr[ib] != '0' && brr[ib] != '.')
			break;
	}

	// �����м���һ��С����, ����arr, brrҪ����ָ��ֱ����.
	int af = ia, bf = ib;
	int cnt = 0;
	for (; cnt < n && af < arr.size() && bf < brr.size(); ++cnt) {
		if (arr[af] == '.' && brr[bf] == '.')
			++af, ++bf;

		if (arr[af] != brr[bf])
			break;
		++af, ++bf;
	}


	if (cnt != n) {
		int tmpn = n;
		cout << "NO 0.";
		for (int k = 0; k < tmpn && k + ia < arr.size(); ++k) {
			if (arr[ia + k] == '.') {
				++tmpn;
				continue;
			}
			cout << arr[ia + k];
		}
		cout << "*10^" << ap - ia << " 0.";

		tmpn = n;
		for (int k = 0; k < tmpn && k + ib < brr.size(); ++k) {
			if (brr[ib + k] == '.') {
				++tmpn;
				continue;
			}
			cout << brr[ib + k];
		}
		cout << "*10^" << bp - ib << endl;
	}
	else {
		cout << "YES 0.";
		for (int k = 0; k < n; ++k) {
			if (arr[ia + k] == '.') {
				++n;
				continue;
			}
			cout << arr[ia + k];
		}	
		cout << "*10^" << ap - ia << endl;
	}
	return 0;
}

/*

Are They Equal (25)
ʱ������ 1000 ms �ڴ����� 65536 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123*105 with simple chopping.  Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.

��������:
Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared.  Each float number is non-negative, no greater than 10100, and that its total digit number is less than 100.


�������:
For each test case, print in a line "YES" if the two numbers are treated equal, and then the number in the standard form "0.d1...dN*10^k" (d1>0 unless the number is 0); or "NO" if they are not treated equal, and then the two numbers in their standard form.  All the terms must be separated by a space, with no extra space at the end of a line.
Note: Simple chopping is assumed without rounding.

��������:
3 12300 12358.9

�������:
YES 0.123*10^5


*/