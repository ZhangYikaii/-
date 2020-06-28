#include<cstdio>
int fa[300005];
int n, k, ans;
inline int read()
{
	int sum = 0;
	char ch = getchar();
	while (ch > '9' || ch < '0') ch = getchar();
	while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
	return sum;
}//�����Ż�
int find(int x)
{
	if (x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}//��ѯ
int unity(int x, int y)
{
	int r1 = find(fa[x]), r2 = find(fa[y]);
	fa[r1] = r2;
}//�ϲ�
int main()
{
	int x, y, z;
	n = read(), k = read();
	for (int i = 1; i <= 3 * n; ++i) 
		fa[i] = i; //����ÿ������� x Ϊ����x+n Ϊ���x+2*n Ϊ���
	for (int i = 1; i <= k; ++i)
	{
		z = read(), x = read(), y = read();
		if (x > n || y > n) { ans++; continue; } // �����ڸ�ʳ������ȻΪ��
		if (z == 1) {
			if (find(x + n) == find(y) || find(x + 2 * n) == find(y)) { 
				ans++; continue; 
			}

			//���1��2����л������ȻΪ����
			unity(x, y); unity(x + n, y + n); unity(x + 2 * n, y + 2 * n);
			//���Ϊ�棬��ô1��ͬ���2��ͬ�࣬1��������2�����1�������2�����
		}
		else if (z == 2)
		{
			if (x == y) { ans++; continue; } //��ʵ�Ƿϻ����ǿ�����΢ʡ��ʱ��
			if (find(x) == find(y) || find(x + 2 * n) == find(y)) { ans++; continue; }
			//���1��2��ͬ��������ȻΪ����
			unity(x, y + 2 * n); unity(x + n, y); unity(x + 2 * n, y + n);
			//���Ϊ�棬��ô1��ͬ����2����У�1��������2��ͬ�࣬1�������2������
		}
	}
	printf("%d\n", ans);
	return 0;
}
