// ע�����ﻷ�ĸ���, ������: https://blog.csdn.net/w597013296/article/details/51982225
// ��һ�����潻��, һ�Ѿ���һ���ȼ���, �ֳɲ�ͬ�Ķ���ȼ���.
// ����Ŀ����ͨ�� 0 ������Ԫ�صĽ���, �����Ƿֳ�n��������ͬ�ĵȼ���.

// ��Щ�����ϲ��ȼ���, ��Щ�ǶϿ��ȼ���.


#include <iostream>
using namespace std;

int search(int* p, int num)
{
	static int first = 1;
	for (int i = first; i < num; i++)
		if (p[i] != i)
			return first = i;
	return 0;
}

// �� p[0] �� p[n]����.
void swap(int* p, int n)
{
	int temp = p[0];
	p[0] = p[n];
	p[n] = temp;
}

int main()
{
	int n;
	cin >> n;
	int* data = new int[n];


	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		data[temp] = i;
	}

	// data[temp] = i, �±�������, ��ֵ�� i.
	int count = 0;
	while (true)
	{
		// �±��� 0 �� data[0] ����.
		if (data[0])
			swap(data, data[0]);
		else
		{
			temp = search(data, n);
			if (!temp) break;
			swap(data, temp);
		}
		count++;
	}
	cout << count << endl;
	delete[]data;
	return 0;
}