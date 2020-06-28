#include<cstdio>
#include<cstring>
#include<stack>
#include<bits/stdc++.h>

using namespace std;


int n;
char str[10];

stack<int> num;
stack<char> sign;

int main() {
	scanf("%d", &n);
	getchar(); //��ȡ���ڻ������Ļ��з�
	for (int i = 0; i < n; i++) {
		gets(str);

		while (!num.empty()) num.pop();	//���ջ
		while (!sign.empty()) sign.pop();

		int j = 0;
		while (j < strlen(str)) {
			if (str[j] > '0' && str[j] <= '9') {
				num.push(str[j] - '0');
			}
			else {
				if (str[j] == '+') {
					sign.push('+');
				}
				else if (str[j] == '-') { //������ת���ɼӷ� 
					num.push((str[j + 1] - '0') * (-1));
					sign.push('+');
					j++;
				}

				// �˷��������ȼ��Ƚϸ�, ��������ֱ����.
				// �����ѹջ��������.
				// �ó���, ����ѹ��ȥ.
				else if (str[j] == 'x') { //ֱ�Ӽ���˷� 
					int lhs = num.top();
					num.pop();
					num.push(lhs * (str[j + 1] - '0'));
					j++;
				}
				else if (str[j] == '/') { //ֱ�Ӽ������ 
					int lhs = num.top();
					num.pop();
					num.push(lhs / (str[j + 1] - '0'));
					j++;
				}
			}
			j++;
		}

		while (!sign.empty()) { //����ʣ��ļӷ� 
			int rhs = num.top();
			num.pop();
			int lhs = num.top();
			num.pop();
			sign.pop();
			num.push(lhs + rhs);
		}

		int ans = num.top();
		if (ans == 24) printf("Yes\n");
		else printf("No\n");

	}

	return 0;
}
