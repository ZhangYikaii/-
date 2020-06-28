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


// ͼ����:

#include<iostream>
#include<map>
#include<string>
using namespace std;
const int maxn = 2020;

map<string, int>stringToint;
map<string, int>gang;
map<int, string>intTostring;
int numPerson = 0;                 //������ 
int G[maxn][maxn] = { 0 }, weight[maxn] = { 0 };//�ڽӱ�  ��Ȩ����Ȩ 
bool inq[maxn] = { false };
int n, k;//�绰������ֵ 

void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
	numMember++;
	inq[nowVisit] = true;
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++) {
		if (G[nowVisit][i] > 0) {
			totalValue += G[nowVisit][i];   //�ӱ�Ȩ���ӵ�Ȩ 
			G[nowVisit][i] = G[i][nowVisit] = 0;
			if (inq[i] == false) {
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}

void DFSTrave() {
	for (int i = 0; i < numPerson; i++) {
		if (inq[i] == false) {
			int head = i, numMember = 0, totalValue = 0;
			DFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k) {
				gang[intTostring[head]] = numMember; //��head��str �͸�gang��������Ӧ 
			}
		}
	}
}

// map find �Ҳ����ͷ���end().

int change(string str) {  //�����������ַ������ֶ�Ӧ 
	if (stringToint.find(str) != stringToint.end()) {
		return stringToint[str];
	}
	else {
		stringToint[str] = numPerson;
		intTostring[numPerson] = str;
		return numPerson++;
	}
}
int main() {
	string str1, str2;    //��ǰc�����������ַ�������char[maxn]�洢 
	int w;               //map����string��scanf��printf���޷�ʵ��������� 
						 //��Ҫ��iostream��ʽ�µ�cin��cout 
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> str1 >> str2 >> w;

		int id1 = change(str1);
		int id2 = change(str2);

		// ����Ȩֵ, ��Ҳ��Ȩֵ.
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}

	DFSTrave();
	
	cout << gang.size() << endl;
	map<string, int>::iterator it;
	for (it = gang.begin(); it != gang.end(); it++) {

		cout << it->first << " " << it->second << endl;
	}
	return 0;
}


//
//int f[100010], weight[100010];
//
//int find(int a) {
//	while (f[a] != a)
//		a = f[a];
//
//	return a;
//}
//
//void Union(int a, int b) {
//	int atmp = find(a), btmp = find(b);
//	if (atmp != btmp) {
//		f[atmp] = btmp;
//	}
//}
//
//int getNum(string& a) {
//	return a[0] - 'A';
//}
//
//
//// ����ÿ�������ϸ�����ҲҪ��.
//int main() {
//	int n, m;
//	in(n);
//	in(m);
//
//	int maxn = -1;
//	For(i, 0, n) {
//		string atmp, btmp;
//		int num, an, bn;
//		cin >> atmp >> btmp >> num;
//		an = getNum(atmp), bn = getNum(btmp);
//		int maxn = max(maxn, max(an, bn));
//
//		int fan = find(an), fbn = find(bn);
//		if (fan != fbn) {
//			Union(an, bn);
//			weight[find(an)] = weight[fbn] + weight[fan] + num;
//		}
//		else {
//			weight[fan] += num;
//		}
//	}
//
//	int res = 0;
//	for (int i = 1; i <= maxn; ++i) {
//		if (weight[i] > res)
//			res = weight[i];
//	}
//
//	return 0;
//}