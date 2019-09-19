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

typedef long long ll;

inline ll read() {
	ll X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

ll n;

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


int main() {
	ios::sync_with_stdio(false);
	in(n);

	unordered_map<string, vector<string>> ump;
	string temp, tarr;
	string *res = new string[n];
	ll iRes = 0;

	for (ll i = 0; i < n; ++i) {
		cin >> tarr;
		temp = StringSort(tarr);
		ump[temp].push_back(tarr);
	}



	for (unordered_map<string, vector<string>>::iterator i = ump.begin(); i != ump.end(); ++i) {
		if (i->second.size() > 1) {
			sort(i->second.begin(), i->second.end());
			// cout << i->second[0] << endl;
			res[iRes++] = i->second[0];
		}
	}

	sort(res, res + iRes);

	printf("wo yi yue du guan yu chao xi de shuo ming\n%lld\n", iRes);
	for (ll i = 0; i < iRes; ++i) {
		cout << res[i] << endl;
	}


	delete[] res;

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