#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
// ��һ��sstream�����sscanf���԰����򻯴��롣

// sscanf(ch + 2, "%llu", &tmp);		// ����� 1LL ��ʾ�� long long���͵� 1.
//���ַ����ĵڶ�λ��ʼ�����Ѻ������������ת��Ϊһ��unsigned long long���ͱ���
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)){ if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)){ x = x * 10 + ch - 48; ch = getchar(); }
	return x*f;
}

long long l, r;

int t;

int main()
{
	/*freopen("testdata.in", "r", stdin);
	freopen("testdata.out", "w", stdout);*/
	cin >> l >> r >> t;
	while (t--)
	{
		char ch[1000005];//�����ļ�������128kb���Կ���㡭����Ȼ���ÿ���ô����
		cin >> (ch + 1);
		int len = strlen(ch + 1);
		if (ch[1] == '-')//��Ϊ���ſ�ͷ�����ֻ��һ�������򲻺Ϸ������Ϊ-0Ҳ���Ϸ�
		{
			if (ch[2] == '0' || len == 1)
			{
				puts("1");
				continue;
			}
		}
		if (ch[1] == '0' && len != 1)//�����00�������Ƶĸ�ʽ���Ϸ�
		{
			puts("1");
			continue;
		}
		if (ch[1] == '-' && len>20)//�����һ��-�ܴ�����֣���ôֱ���жϲ��Ϸ����ɡ�
		{
			puts("2");
			continue;
		}
		if (ch[1] != '-' && len>19)//�����һ�����ĺܴ�����֣�Ҳ����ֱ���жϲ��Ϸ�
		{
			puts("2");
			continue;
		}
		//��������������Ϊ��ȷ�����ǵ����ֿ�����ull֮�ڵķ�Χ�ٽ��������������᷽����ࡣ
		unsigned long long tmp = 0;
		long long x = 0;
		if (ch[1] == '-')
		{
			// sscanf(ch + 2, "%llu", &tmp);		// 1LL ��ʾ�� long long���͵� 1.
			sscanf(ch + 2, "%llu", &tmp);	//���ַ����ĵڶ�λ��ʼ�����Ѻ������������ת��Ϊһ��unsigned long long���ͱ���tmp���ٽ��д���
			if (tmp>(1LL << 63))
			{
				puts("2");
				continue;
			}
			x = -tmp;
		}
		else
		{
			sscanf(ch + 1, "%llu", &tmp);
			if (tmp >= (1LL << 63))
			{
				puts("2");
				continue;
			}
			x = tmp;
		}
		puts(x >= l && x <= r ? "0" : "2");
	}
	return 0;
}
//#include <iostream> 
//#include <cstdio> 
//#include <algorithm> 
//#include <cstring>
//#include <cmath>
//using namespace std;
//
//#define in(x) x=read()
//
//#define MAXN 500
//
//inline long long read() {
//	long long X = 0, w = 1;
//	char ch = getchar();
//	while (ch < '0' || ch > '9') {
//		if (ch == '-')
//			w = -1;
//		ch = getchar();
//	}
//	while (ch >= '0' && ch <= '9')
//		X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
//
//	return X*w;
//}
//
//
//
//// ��������治�ø�
//// ������Ǳߵ�������? wuwuwu
//
//int solve(long long &x) {
//	x = 0;						// ע�Ⱑ ��ʼ��������
//	long long w = 1;
//	int isFir = 0, digit = 0, ret = -1;
//	char ch = getchar();
//	if ((ch < '0' || ch > '9') && ch == '-') {
//		w = -1;
//		ch = getchar();
//	}
//
//	while (ch >= '0' && ch <= '9') {
//		if (ret == -1) {
//			if (++digit >= 20)
//				ret = 2;
//
//			// -0 ������
//			if (ch == '0' && isFir == 0 && w == -1)
//				ret = 0;
//
//			// ��һ��Ϊ0, ��Ҫ�жϵڶ���
//			if (ch == '0' && isFir == 0) {
//				isFir = 1;
//			}
//			// ��һ��Ϊ��0, ������
//			else if (ch != '0' && isFir == 0)
//				isFir = 2;
//
//			// �ڶ���Ϊ��0, ������
//			else if (ch != '0' && isFir == 1)
//				isFir = 2;
//			// �ڶ�������0, ������
//			else if (ch == '0' && isFir == 1)
//				ret = 0;
//		}
//
//		// ע�⼴ʹ�жϳ�����ʲô֮��ҲҪȫ������
//		x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
//	}
//
//	if (ret == -1)
//		return 1;
//
//	return ret;
//}
//
//long long n, l, r, input;
//
//int main() {
//	in(l);
//	in(r);
//	in(n);
//	while (n--) {
//		int isNum = solve(input);
//		if (isNum == 1 && input <= r && input >= l)
//			printf("0\n");
//		else if (isNum == 2 || (isNum == 1 && !(input <= r && input >= l)))
//			printf("2\n");
//		else if (isNum == 0)
//			printf("1\n");
//		
//		// cout << endl;
//	}
//	
//	
//	return 0;
//}
//
///*
//��Ŀ����
//��Щʱ����Ҫ�������һ�����⣺�ж�һ���� xx �Ƿ�Ϸ���
//
//xx �Ϸ����ҽ�������������������
//
//xx ��ʽ�Ϸ���һ����ʽ�Ϸ�������Ҫô�� 00��Ҫô��һ����ѡ�ĸ��ţ�һ�� 11 �� 99 ֮������֣������ɸ� 00 �� 99 ֮�������˳�����Ӷ��ɡ�
//xx ������ [l,r][l,r] ��Χ�ڣ��� l \le x \le rl��x��r����
//����Ҫʵ������һ��У���������ڸ����� l, rl,r������ж� xx �Ƿ�Ϸ���
//
//���������ʽ
//�����ʽ��
//��һ���������� l,r,Tl,r,T����ʾУ������У������Ϊ [l,r][l,r]���Լ���ҪУ��� xx �ĸ�����
//
//������ TT �У�ÿ��һ�� xx����ʾҪУ���������֤ xx ��������Ϊ 11 �ҽ��� '0'~'9' �� '-' ���ɣ��� '-' ֻ������ڵ�һ���ַ���
//
//�����ʽ��
//����� TT �У�ÿ��һ����������ʾÿ�� xx ��У������
//
//У�����涨���£�00 ��ʾ xx �Ϸ���11 ��ʾ xx ��ʽ���Ϸ���22 ��ʾ xx ��ʽ�Ϸ��Ҳ��� [l,r][l,r] �����ڡ�
//
//�����������
//��������#1��
//-3 3 4
//0
//00
//-0
//100000000000000000000
//�������#1��
//0
//1
//1
//2
//
//
//*/