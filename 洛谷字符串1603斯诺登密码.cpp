#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)

char dic[27][20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third" };
int di[30] = { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 00, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9 };

inline int read() {
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-' && s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}

int main() {
	char a[60] = "";
	int data[10] = { 0 }, iData = 0;
	For(i, 0, 6) {
		scanf("%s", a);
		For(i, 0, 27) {
			if (!strcmp(a, dic[i])) {
				data[iData++] = di[i];
				break;
			}
		}
	}
	if (iData == 0)
		cout << 0 << endl;
	else {
		sort(data, data + iData);

		bool isFir = true;
		For(i, 0, iData) {
			if (isFir == true) {
				if (data[i] != 0) {
					printf("%d", data[i]);
					isFir = false;
				}
			}
			else {
				printf("%.2d", data[i]);
			}
		}

		if (isFir == true) {
			cout << "0" << endl;
		}
		else {
			printf("\n");
		}
	}


	return 0;
}

/*
�ҳ�������������Ӣ�ı�ʾ������(��20)���о����£�

���棺one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty

�����棺a both another first second third

��2������Щ����ƽ����%100����00,05,11,19,86,99��

��3������Щ��λ������λ�ų�һ�У����һ�������������ͷΪ0����ȥ0��

��4���ҳ��������з�������С��һ��������Ϊ���롣


Black Obama is two five zero .

425
*/
