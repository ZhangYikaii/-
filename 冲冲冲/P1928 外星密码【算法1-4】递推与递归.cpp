#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define For(i, b, e) for(int i = (b); i < (e); ++i)
#define Fee(i, b, e) for(int i = (b); i <= (e); ++i)
#define Ree(i, b, e) for(int i = (b); i >= (e); --i)

#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

//string deco(string s) {
//	int beg = s.find_first_of("["), aft = s.find_last_of("]");
//	if (beg == -1 && aft == -1)
//		return s;
//	string cur = s.substr(beg + 1, aft - beg - 1);
//	if 
//	return cur;
//}

// �������޼�, ˲��GG, �ú�ѧϰһ�����:

string solve()
{
	int n;
	string s = "", s1;
	char c;
	while (cin >> c)//һֱ�����ַ���ֱ��Ctrl+z
	{
		if (c == '[') {
			cin >> n;// ����D, �������뿴��һ������Ĺ���, ������Ҳ�Ǻ�˳��.
			s1 = solve();//����X // �ǳ��ؼ�, ţ! �ݹ������.
			while (n--) s += s1;// �ظ�D��X
			// ע�����治��д��while (n--) s+=solve();
		}
		else {
			if (c == ']') return s;//����X
			else s += c;//�������'['��']'���Ǿ���X��һ���ַ������Լӽ�X
		}
	}
}
int main() {
	cout << solve();
	return 0;
}