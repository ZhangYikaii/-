#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

int MyMin(int a, int b) {
	return a > b ? b : a;
}

void Swap(int arr[], int i, int j) {
	if (i == j)
		return;

	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

int n, m;
int sol[110] = { 0 };
string arr[110];

int main() {
	in(n);
	in(m);
	for (int i = 1; i <= m; ++i) {
		getline(cin, arr[i]);
		int fir = arr[i][0] - 'A', sec = arr[i][2] - 'A';
		if (arr[i][1] == '<') {
			
		}
	}

	return 0;
}


/*

��Ŀ����
һ����ͬ��ֵ��������������ָ����һ��������Ԫ��������������У����磬һ�����������A,B,C,D ��ʾA<B,B<C,C<D����������У����ǽ�����һϵ������A<B�Ĺ�ϵ����Ҫ�����ж��Ƿ��ܹ�������Щ��ϵȷ��������е�˳��

���������ʽ
�����ʽ��
��һ������������n,m��n��ʾ��Ҫ�����Ԫ��������2<=n<=26����1��n��Ԫ�ؽ��ô�д��A,B,C,D....��ʾ��m��ʾ������������A<B�Ĺ�ϵ��������

��������m�У�ÿ����3���ַ����ֱ�Ϊһ����д��ĸ��һ��<���ţ�һ����д��ĸ����ʾ����Ԫ��֮��Ĺ�ϵ��

�����ʽ��
������ǰx����ϵ����ȷ����n��Ԫ�ص�˳��yyy..y����ABC�������

Sorted sequence determined after xxx relations: yyy...y.

������ǰx����ϵ�����ִ���ì�ܣ���A<B,B<C,C<A�������

Inconsistency found after 2 relations.

��������m����ϵ�޷�ȷ����n��Ԫ�ص�˳�����

Sorted sequence cannot be determined.

����ʾ��ȷ��n��Ԫ�ص�˳��󼴿ɽ������򣬿��Բ��ÿ���ȷ��˳��֮�����ì�ܵ������

�����������
��������#1��
4 6
A<B
A<C
B<C
C<D
B<D
A<B
�������#1��
Sorted sequence determined after 4 relations: ABCD.
��������#2��
3 2
A<B
B<A
�������#2��
Inconsistency found after 2 relations.
��������#3��
26 1
A<Z
�������#3��
Sorted sequence cannot be determined.


*/