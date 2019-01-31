#include <iostream>
using namespace std;
#define MAX 105

bool isPrime[MAX] = { 0 };
int prime[MAX] = { 0 };

// isPrime �±���ĳ���� = true��ʾ������ false��ʾ����
// prime ��˳�������

void init() {
	int cnt = 1;
	memset(isPrime, 1, sizeof(isPrime));			// ��ʼ����Ϊ��������Ϊ����
	isPrime[0] = isPrime[1] = 0;					// 0��1��������
	for (long long i = 2; i <= MAX; i++) {
		if (isPrime[i])
			prime[cnt++] = i;						// ��������i
		for (long long j = 1; j<cnt && prime[j] * i < MAX; j++) { 
			isPrime[prime[j] * i] = 0;				// ɸ��С�ڵ���i��������i�Ļ����ɵĺ��� !
		}
	}
}

int main() {
	init();
	

	return 0;
}



/*
���һ�������ڵ��� 10 ������������λ������������ô�ͳ�֮Ϊ Wish ������Ȼ����һ�� Wish ���� 11�� ���� 97��111��131��119 ���� Wish ������ 12��136 ���ǡ� �ʵ� N �� Wish ���Ƕ��١�
*/