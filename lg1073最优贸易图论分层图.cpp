#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define oo 1<<18;
const int maxn = 100010;
struct u {
	int v, len;
	u() { }
	u(int vv, int ll) : v(vv), len(ll) { }
};

int n, m, v[maxn], d[maxn * 3 + 1];
vector<u> G[maxn * 3 + 1];

// �ֲ�ͼ��ͼ, ��һ��!!! ò�Ʋ�����ʽǰ����
// ���ִ�ͼ��������, G[] �Ǳߵļ���, G[x] ����������� x ���ŵı�, G[x].first �����ŵĵ�, G[x].second�����ŵıߵ�Ȩֵ.
// ���Կ�һ����� spfa�̳�: https://www.bilibili.com/video/av4224493?from=search&seid=12456330677771145271
void addedge(int x, int y) {
	G[x].push_back(u( y, 0 ));
	// �����������������֮��ı���.
	G[x + n].push_back(u( y + n, 0 ));				// �ڶ���ͼ�Ҵ�n+1��2n���б�� 
	G[x + 2 * n].push_back(u( y + 2 * n, 0 ));		// ������ͼ�Ҵ�2*n+1��3*n���б�� 
	G[x].push_back(u( y + n, -v[x] ));				// ������Ǹ���, Ϊ��, ������·.
	G[x + n].push_back(u( y + 2 * n, v[x] ));
	return;
}

queue<int> Q;
bool inq[maxn * 3 + 1];

void spfa() {
	for (int i = 1; i <= n; i++)
		d[i] = -oo;
	d[1] = 0;
	inq[1] = true;
	Q.push(1);
	while (!Q.empty()) {
		int tp = Q.front(); Q.pop();
		inq[tp] = false;
		int len = G[tp].size();
		for (int i = 0; i < len; i++) {
			u x = G[tp][i];
			// �·��������� > �ĳ� <
			if (d[x.v] < d[tp] + x.len) {
				d[x.v] = d[tp] + x.len;
				if (inq[x.v] == false) {
					Q.push(x.v);
					inq[x.v] = true;
				}
			}
		}
	}
}

int main() {
	//    freopen("d.txt","r",stdin);  �����õ� 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1, x, y, z; i <= m; i++) {
		cin >> x >> y >> z;
		addedge(x, y);
		if (z == 2) addedge(y, x);
	}
	G[n].push_back(u( 3 * n + 1, 0 ));
	G[n * 3].push_back(u( 3 * n + 1, 0 ));//�����յ���3*n+1��� 
	n = 3 * n + 1; //��n�ĳɳ����յ�ı�ţ�����spfa���� 

	spfa();
	cout << d[n] << endl;
	return 0;
}

/*
module memo(clk, we, inoutaddr, inoutadd0, din, dout1, dout2);
input clk;
input we;
input [3:0] inoutaddr;
input [3:0] inoutadd0;
wire [3:0] addr;
input [7:0] din;
output [7:0] dout1;
output [7:0] dout2;
assign addr = inoutaddr;
assign add0 = inoutadd0;
ram1 S(.clk(clk), .we(we), .inaddr(inoutaddr), .outaddr(addr), .din(din), .dout(dout1));
ram2port A(.clock(clk), .data(din), .wren(we), .wraddress(inoutadd0), .rdaddress(add0), .q(dout2));
endmodule

*/