#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define For(i, n, m) for(int i = n;i < m; ++i)
inline int read()
{
	char s;
	int k = 0, base = 1;
	while ((s = getchar()) != '-'&&s != EOF&&!(s >= '0'&&s <= '9'));
	if (s == EOF)exit(0);
	if (s == '-')base = -1, s = getchar();
	while (s >= '0'&&s <= '9')
	{
		k = k * 10 + (s - '0');
		s = getchar();
	}
	return k*base;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		write(-x);
	}
	else
	{
		if (x / 10)write(x / 10);
		putchar(x % 10 + '0');
	}
}

// �ѳ����߼� д��һ�� ע����ô���ж� ��Ҫ�Լ��㸴��
char s;//11���Ƶ�
string a;//����һ��21����
long long w, l, i;
int main(){
	while (cin >> s && s != 'E')//���룬����E��ֹͣ
	{
		if (s == 'W') { w++; a += s; }
		//�����W�����ӷ֣�a+=s��Ϊ21�������ü�¼����ͬ
		if (s == 'L') { l++; a += s; }
		if ((w >= 11 || l >= 11) && (w - l >= 2 || l - w >= 2))//����ж���ƹ��������Ĺ�����
		{
			cout << w << ":" << l << endl;//���
			w = 0;//һ�ֱ�����������ʼ��һ��
			l = 0;
		}
		i++;//���˼���ѭ������¼��
	}
	cout << w << ":" << l << endl << endl;
	//����ж�������һ�Σ���ͬ
	w = 0; l = 0;//׼������21����
	for (int j; j <= i; j++)
		//����forѭ������Ϊa��string�����
	{
		if (a[j] == 'W') w++;//ǰ���¼�õıȷ�����һ��
		if (a[j] == 'L') l++;
		if ((w >= 21 || l >= 21) && (w - l >= 2 || l - w >= 2))//21���Ʊ���
		{
			cout << w << ":" << l << endl;//���
			w = 0;
			l = 0;
		}
	}
	cout << w << ":" << l;
}



/*
int main() {
	char a[30] = "";
	int cur = 0, cur2 = 0;
	int res[20][2], res2[20][2];
	For(i, 0, 20) {
		For(k, 0, 2) {
			res[i][k] = 0;
			res2[i][k] = 0;
		}
	}

	bool BreakFlag = false;

	while (true) {
		cin >> a;

		
		// 11����
		for (int i = 0; a[i] != '\0'; ++i) {
			if (a[i] == 'W')
				++res[cur][0];
			else if (a[i] == 'L')
				++res[cur][1];
			else if (a[i] == 'E') {
				BreakFlag = true;
				break;
			}

			if (res[cur][0] >= 11 && res[cur][0] - res[cur][1] >= 2) {
				++cur;
			}
			if (res[cur][1] >= 11 && res[cur][1] - res[cur][0] >= 2) {
				++cur;
			}
		}

		// 21����
		for (int i = 0; a[i] != '\0'; ++i) {
			if (a[i] == 'W')
				++res2[cur2][0];
			else if (a[i] == 'L')
				++res2[cur2][1];
			else if (a[i] == 'E') {
				BreakFlag = true;
				break;
			}

			if (res2[cur2][0] >= 21 && res2[cur2][0] - res2[cur2][1] >= 2) {
				++cur2;
			}
			if (res2[cur2][1] >= 21 && res2[cur2][1] - res2[cur2][0] >= 2) {
				++cur2;
			}
		}

		if (BreakFlag == true)
			break;

		for (int i = 0; a[i] != '\0'; ++i) {
			a[i] = '\0';
		}
	}

	for (int i = 0; res[i][0] != 0 || res[i][1] != 0; ++i) {
		printf("%d:%d\n", res[i][0], res[i][1]);
	}
	putchar('\n');

	for (int i = 0; res2[i][0] != 0 || res2[i][1] != 0; ++i) {
		printf("%d:%d", res2[i][0], res2[i][1]);
		if (res2[i + 1][0] != 0 || res2[i + 1][1] != 0)
			printf("\n");
	}

	return 0;
}

*/

/*
����:
WWWWWWWWWWWWWWWWWWWW
WWLWE

���:
11:0
11:0
1:1

21:0
2:1

W�����һ��Ӯ L ����ڶ���Ӯ, ���11���ƺ�21�����µıȷ�
*/