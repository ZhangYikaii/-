#include <cstdio> 
#include <cstdlib> 
#include <iostream>
using namespace std;

// ����������� DataLab ÿһ���ı仯
char str[100] = "";

void TwoPrint(int t) {
	cout << "10����: " << t << endl;
	for (int i = 0; i < 100; ++i)
		str[i] = '\0';

	_itoa(t, str, 2);
	for (int i = 0; i < 32 - strlen(str); ++i)
		printf("0");
	printf("%s\n", str);
}

int main() {
	int x = 0x80000000;
	TwoPrint(x);
	int y = 0xffffffff;
	TwoPrint(y);

				
	return 0;
}