#include<iostream>
using namespace std;

int main() {
	bool flag = false;
	cout << "2018117297_������" << endl;
	int n, i;
	cout << "������Ҫ�ֽ����������";
	cin >> n;
	cout << "�ֽ��������Ľ��Ϊ��" << endl;
	cout << n << "=";
	for (i = 2; i < n; i++) {
		while (n % i == 0) {
			if (flag == false) {
				flag = true;
				cout << i;
			}
			else
				cout << "*" << i;
			n /= i;
		}
		if (n < i)
			break;
		//if (n % i == 0) {
		//	for (j = 2; j < i; j++) {
		//		if (i % j == 0) {
		//			break;
		//		}
		//	}
		//	if (j = i) {
		//		cout << j;
		//	}
		//}
		//cout << "*";
	}

	if (n != 1) {
		if (flag == false)
			cout << n;
		else
			cout << "*" << n;
	}

	cout << endl;

	return 0;
}