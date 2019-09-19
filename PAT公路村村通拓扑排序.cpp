#include<stdio.h>
#define num 100
#include<queue>
using namespace std;

//�ڵ����������
int N, M;
//bool isin[num];
//��ȣ����ȣ�ÿ���ڵ���Ҫ����ʱ�䣬�ڵ�֮���ϵ����
int indgree[num];
int outdegree[num];
int cost[num];
int info[num][num];
//��ʼ����
void init() {
	int i, j;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			info[i][j] = -1;
		}
		indgree[i] = 0;
		outdegree[i] = 0;
		cost[i] = 0;
	}
}
//�����ֵ
int max(int x, int y) {
	return x > y ? x : y;
}
//������
int solve() {
	int n = 0;
	int i, front;
	queue<int> Q;
	for (i = 0; i < N; i++) {
		if (indgree[i] == 0) {
			//���Ϊ0�Ľڵ���ӡ�
			Q.push(i);
			//���䲻����0�������Ӱ���������
			indgree[i]--;
		}
	}
	//Q������ѭ����
	while (!Q.empty()) {
		front = Q.front();
		Q.pop();
		n++;//��¼�����ж��ٽڵ����
		//���ӵĶ��ǿ���Ĩ���Ľڵ�
		for (i = 0; i < N; i++) {
			if (info[front][i] >= 0) {//���ҪĨ���Ľڵ���ĳ���ڵ���һ������ߣ�
				//�ñ���ȼ�һ������ñߵ�cost
				indgree[i]--;

				// topo����ԭ��������, ֻ�������в����˼���.
				cost[i] = max(cost[i], cost[front] + info[front][i]);
			}
		}
		//����Ѱ����Ҫ��ӵ�
		for (i = 0; i < N; i++) {
			if (indgree[i] == 0) {
				Q.push(i);
				indgree[i]--;
			}
		}
	}
	//���ɾ��N����˵��û�л���ע��cost[front]�������ս��
	if (n == N)
		return cost[front];
	//����
	return -1;
}

int main() {
	int file = 0;
	FILE* fp;
	init();
	int i, temp1, temp2, temp3;
	if (file) {

		fp = fopen("1.txt", "r");
		if (fp == NULL) {
			puts("ERROR!");
		}
		fscanf(fp, "%d%d", &N, &M);
		for (i = 0; i < M; i++) {
			fscanf(fp, "%d%d%d", &temp1, &temp2, &temp3);
			info[temp1][temp2] = temp3;
			indgree[temp2]++;
			outdegree[temp1]++;
			//printf("%d,%d,%d\n",temp1,temp2,info[temp1][temp2]);
		}
	}
	else {
		scanf("%d%d", &N, &M);
		for (i = 0; i < M; i++) {
			scanf("%d%d%d", &temp1, &temp2, &temp3);
			info[temp1][temp2] = temp3;
			indgree[temp2]++;
			outdegree[temp1]++;
		}
	}
	int res;
	res = solve();
	if (res == -1) {
		puts("Impossible");
	}
	else {
		for (i = 0; i < N; i++) {
			if (outdegree[i] == 0)
				//�����ж���յ㣬��Ҫ�ҵ���ʱ�����Ǹ�
				res = max(cost[i], res);
		}
		printf("%d\n", res);
	}

	return 0;
}
