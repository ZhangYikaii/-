#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>


using namespace std;

// ��������.
int main() {
	int n;
	scanf("%d ", &n); // �������ݸ�����ע��%d ����Ŀո����̵�ƥ�����������κο��ַ�
	int *arr = (int *)malloc(sizeof(int)* n); // ������̬����
	for (int i = 0; i < n && scanf("%d ", arr + i) > 0; i++); // ����n ���������� i < n ���ö��� n ������Ҳ��������Խ��

	for (int i = 0; i < n && cin >> arr[i]; i++); // C++ ʹ��cin ��������



	int a;
	vector<int> input;
	while (cin >> a)
		input.push_back(a);

	return 0;
}