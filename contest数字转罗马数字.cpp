#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

// beg: 2019��4��28��18:46:39
// end: 2019��4��28��19:06:21
int main() {
	string mapp[10][20] = {
		{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		{ "", "M", "MM" }
	};

	int n, ia = 0;
	string arr[110];
	in(n);
	while (n != 0) {
		if (n % 10 != 0)
			arr[ia] = mapp[ia][n % 10];
		n /= 10;
		++ia;
	}

	for (int i = ia - 1; i >= 0; --i)
		cout << arr[i];
	cout << endl;


	return 0;
}


/*
���ӣ�https://ac.nowcoder.com/acm/contest/637/A
��Դ��ţ����

����ʦ��Ҫ��������ͳ��ѧ���ǵĵ÷�������������������Ѿ�������������Ҫ���ˣ������������æ��ѧ���ĳɼ�ת�����������֡�
�������������߸���ͬ�ķ�������ʾ��I��V��X��L��C��D��M��������ÿ�����Ŷ�Ӧ��ֵ���±�
���� ֵ
I   1
V   5
X   10
L   50
C   100
D   500
M   1000
��������ͨ�������Ҵ����д����С����ʾ���ǵ��ܺ͡����ǣ�����4���������ֱ�ʾ����IIII������IV����ʾ5-1=4��ͬ���ģ���6��Ӧ����ͬԭ��Ĺ���
I���Է���V��5����X��10��֮ǰ����4��9��
X������L��50����C��100��֮ǰ����40��90��
C���Է���D��500����M��1000��֮ǰ����400��900��
���ڸ���һ������������ʦ�����������������ֵı�ʾ��

��������:
��һ��һ������x(1<=x<=2000)
�������:
���һ�У���ʾ����x����Ӧ���������ֱ�ʾ


*/