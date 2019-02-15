#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include <cstring>
using namespace std;

#define in(x) x=read()

inline int read()
{
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}
int n, m;

int gcd(int a, int b) {
	return a == 0 ? b : gcd(b % a, a); 
}

int main() {
	std::ios::sync_with_stdio(0);
	while (cin >> n && cin >> m) {
		printf("%d\n", n * m - n - m);
	}
	
	return 0;
}

/*
С������һ���ǹ��ꡣ������Ĳã���ˮ���ǰ���4��һ����7��һ�������֡��ǹ����ܲ������
С���������ǵ�ʱ�������������ְ�װ����ϡ���Ȼ��Щ�ǹ���Ŀ���޷���ϳ����ģ�����Ҫ��  10  ���ǡ�
������ü��������һ�£������ְ�װ����£�������򵽵�������17������17���κ����ֶ�������4��7��ϳ�����
�����Ҫ���������֪������װ������ʱ�����������ϳ������֡�

����:
4 7

���:
17

*/