#include<iostream> 
#define MaxSize 100 //��ඥ���� 
#define INF 65535  //int�����ֵ 
using namespace std;

struct MGraph {
	int n;
	int m;
	int s[MaxSize][MaxSize];
};
MGraph g;


void FindAnimal() {
	//Floyd�㷨������ѭ�� ���������������̾������ 
	for (int k = 0; k < g.n; k++) {
		for (int i = 0; i < g.n; i++) {
			for (int j = 0; j < g.n; j++) {
				// (i != k) && (j != i) Ϊ�β��ֱ�Ϊѭ�� i �� j ������ ==> ���ܣ�����Ϊ for ѭ��������һ�������㣬����ֹѭ���ˣ��������������Ҳ��ִ����
				//���� if ����Ͼ�ִ�У������Ͼ�����ִ���¸� 

				// ��ס�� k: ���м��, �� i, j.
				if ((i != k) && (j != i) && (g.s[i][k] + g.s[k][j] < g.s[i][j])) {
					g.s[i][j] = g.s[i][k] + g.s[k][j];
				}
			}
		}
	}

	int animal;
	//�������������̾��� 
	int MinDist = INF;
	for (int i = 0; i < g.n; i++) {
		//������� 
		int MaxDist = 0;
		for (int j = 0; j < g.n; j++) {
			if ((i != j) && (g.s[i][j] > MaxDist)) { //i!=jȥ�����Խ���Ԫ����Ϊ���Խ���Ԫ�϶���INF
				MaxDist = g.s[i][j];
				//cout<<"("<<i<<","<<j<<")="<<g.s[i][j]<<" ";			
			}
		}

		if (MaxDist == INF) {//����һ������ͨ�������Ƕ���ֵ���ͨ����������i�޷�����Ķ��� 
			cout << "0" << endl;
			return;//ֱ���˳� 
		}
		if (MaxDist < MinDist) {
			MinDist = MaxDist;
			animal = i + 1;//i+1����Ϊ�����±ߴ�1��ʼ 
		}
	}
	cout << animal << " " << MinDist << endl;
}


int main()
{
	//freopen("input.txt","r",stdin);
	int n, m, i, j, v1, v2, weight;
	cin >> n >> m;
	g.n = n;
	g.m = m;
	//1��ʼ���ڽӾ��� 
	for (i = 0; i < g.n; i++) {
		for (j = 0; j < g.n; j++) {
			g.s[i][j] = INF;
		}
	}
	//2�����
	while (g.m--) {
		cin >> v1 >> v2 >> weight;
		--v1; --v2;//�����1��ʼ��ͼ��0��ʼ
		g.s[v1][v2] = weight;
		g.s[v2][v1] = weight;
	}


	//3.��������е���̾����Ӧ�ĵ㼰�����̾���
	FindAnimal();

	return 0;
}


