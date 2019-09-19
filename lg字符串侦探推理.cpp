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

int m, n, p;
string str[50], say[110];
int say2Id[110] = { 0 }, say2Crimimal[50] = { 0 };
int ansArr[1000] = { 0 };

void WhoSaid() {
	for (int i = 1; i <= m; ++i) {
		for (int k = 1; k <= p; ++k) {
			if (say[k].find(str[i]) == 0)
				say2Id[k] = i;
		}
	}
}

void SaidCrimimal() {
	for (int k = 1; k <= p; ++k) {
		for (int i = 1; i <= m; ++i) {
			if (say[k].find(": " + str[i]) != string::npos) {
				say2Crimimal[say2Id[k]] = i;
				break;
			}
			else if (say[k].find(": I") != string::npos) {
				say2Crimimal[say2Id[k]] = say2Id[k];
				break;
			}
		}
	}
}

int main() {
	in(m);
	in(n);
	in(p);

	// ��Ŀ���鷳, ����is not֮���, Ҫ��ȫƥ��.

	for (int i = 1; i <= m; ++i) {
		cin >> str[i];
	}
	getline(cin, say[0]);
	for (int i = 1; i <= p; ++i) {
		getline(cin, say[i]);
	}

	WhoSaid();
	SaidCrimimal();

	// ����ÿ�������ﷸ
	for (int i = 1; i <= m; ++i) {
		int lies[50] = { 0 }, k;
		for (k = 1; k <= m; ++k) {
			if (say2Crimimal[k] == 0)
				continue;

			// ˵����.
			if ((lies[k] == 0 || lies[k] == 1) && say2Crimimal[k] != i) {
				lies[k] = 1;
			}
			// ˵ʵ����.
			else if ((lies[k] == 0 || lies[k] == 2) && say2Crimimal[k] == i) {
				lies[k] = 2;
			}
			else
				break;
		}
		if (k <= m)
			continue;

		// ͳ��˵���˸���
		int ans = 0;
		for (int j = 1; j <= m; ++j) {
			if (lies[j] == 1)
				++ans;
		}
		if (ans == n) {
			ansArr[++ansArr[0]] = i;
		}
	}

	if (ansArr[0] == 1) {
		cout << str[ansArr[1]] << endl;
	}
	else if (ansArr[0] == 0) {
		printf("Impossible\n");
	}
	else {
		printf("Cannot Determine\n");
	}

	return 0;
}


/*

��Ŀ����
����ͬѧ�����������̽���������ϡ���������������Ϸ֮�У��������ټ���һȺͬѧ��������Ϸ����Ϸ�������������ģ�������ͬѧ���������������е�һ���˳䵱�ﷸ����������֪�������£�����������������ҳ�����ﷸ�����ţ��������ѯ��ÿһ��ͬѧ����ѯ���߿��ܻ�˵��



֤���г��ֵ������������������߼���������ݡ�

������֪�����ǣ�����ͬѧ����NN����ʼ��˵�ٻ����������ʼ��˵�档

���ڣ�������Ҫ�����������ͬѧ�Ļ����ƶϳ�˭�����������֣����ס������ֻ��һ����

���������ʽ
�����ʽ��
��������������ɣ���һ��������������M(1��M��20)M(1��M��20)��N(1��N��M)N(1��N��M)��P(1��P��100)P(1��P��100)��MM�ǲμ���Ϸ��������ͬѧ����NN������ʼ��˵�ѵ�������PP��֤�Ե�������

������MM�У�ÿ����������һ��ͬѧ�����֣�Ӣ����ĸ��ɣ�û�пո�ȫ����д����

������PP�У�ÿ�п�ʼ��ĳ��ͬѧ�����������һ��ð�ź�һ���ո񣬺�����һ��֤�ʣ�����ǰ�������и�ʽ��֤��ÿ�в��ᳬ��250250���ַ���

�����в�����������������ո񣬶���ÿ�п�ͷ�ͽ�βҲû�пո�

�����ʽ��
�����ĳ�����ȷ��˭���ﷸ��������������֣���������жϳ���ֹһ���˿������ﷸ������� "Cannot Determine"����������жϳ�û���˿��ܳ�Ϊ�ﷸ������� "Impossible"��

�����������
��������#1��
3 1 5
MIKE
CHARLES
KATE
MIKE: I am guilty.
MIKE: Today is Sunday.
CHARLES: MIKE is guilty.
KATE: I am guilty.
KATE: How are you??
�������#1��
MIKE


*/