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

string arr[110];
int leng[110];
int main() {
	int n, minn = 0x7fffff;
	in(n);

	For(i, 0, n) {
		getline(cin, arr[i]);
		leng[i] = arr[i].length() - 1;
		minn = min(minn, leng[i]);
	}

	int i = 0;
	for (i = 0; i <= minn; ++i) {
		char base = arr[0][leng[0] - i];
		bool flag = true;
		For(k, 1, n) {
			if (base != arr[k][leng[k] - i]) {
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
	}

	if (i != 0)
		cout << arr[0].substr(leng[0] - i + 1, i) << endl;
	else
		cout << "nai" << endl;

	return 0;
}

/*


Kuchiguse (20)
ʱ������ 1000 ms �ڴ����� 65536 KB ���볤������ 100 KB �жϳ��� Standard (���� СС)
��Ŀ����
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:
Itai nyan~ (It hurts, nyan~)
Ninjin wa iyada nyan~ (I hate carrots, nyan~)
Now given a few lines spoken by the same character, can you find her Kuchiguse?

��������:
Each input file contains one test case.  For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.


�������:
For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

��������:
3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~

�������:
nyan~


ע����Ч��ʱ��.

��ȷ��ʱ�仨����ȷ��������, ��ȷ�ķ����Ҽ�����, ����ķ������в�ͬ, ��Ŭ����С���һ��ǰ��, Բ��.

����֪ʶ��������ʵ��������, ��ͷ�ϵĹ���һ��Ҫ��.

����Ŭ���д����˸�,����������������,�ڷܶ��г�Խ����,�����ഺ�Ĺ�â,����ͨ��δ���ĵ�·����

������ڵĶ����ܶ�, ��Ҫ�Ҹ�.
*/