#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define in(x) x=read()
#define INF 0x7fffff

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

class Solution {
#define For(i, b, e) for(int i = (b); i < (e); ++i)
public:
	int isOver(int curx, int cury, vector<vector<int>>& obstacles, int x, int y) {
		if (curx > x || cury > y)
			return 0;
		if (curx == x && cury == y)
			return 1;

		for (auto i : obstacles) {
			if (i[0] == curx && i[1] == cury)
				return 0;
		}
		return -1;
	}
	//bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
	//	if (command.size() == 0)
	//		return (x == 0) && (y == 0);

	//	vector<int> xvec(command.size() + 5), yvec(command.size() + 5);

	//	// �ʼ�Ĳ���.
	//	xvec[0] = command[0] == 'U' ? 0 : 1;
	//	yvec[0] = command[0] == 'U' ? 1 : 0;
	//	// �߽�(�ʼ)ҲҪ�ж�.
	//	if (isOver(xvec[0], yvec[0], obstacles, x, y) != -1)
	//		return isOver(xvec[0], yvec[0], obstacles, x, y);

	//	For(i, 1, command.size()) {
	//		if (command[i] == 'U')
	//			xvec[i] = xvec[i - 1], yvec[i] = yvec[i - 1] + 1;
	//		else
	//			xvec[i] = xvec[i - 1] + 1, yvec[i] = yvec[i - 1];
	//		// ��������յ�����ϰ�:
	//		// cout << xvec[i] << " " << yvec[i] << endl;
	//		if (isOver(xvec[i], yvec[i], obstacles, x, y) != -1)
	//			return isOver(xvec[i], yvec[i], obstacles, x, y);
	//	}
	//	int xstep = xvec[command.size() - 1], ystep = yvec[command.size() - 1];
	//	while (true) {
	//		For(i, 0, command.size()) {
	//			xvec[i] = xvec[i] + xstep, yvec[i] = yvec[i] + ystep;

	//			// cout << xvec[i] << " " << yvec[i] << endl;
	//			if (isOver(xvec[i], yvec[i], obstacles, x, y) != -1)
	//				return isOver(xvec[i], yvec[i], obstacles, x, y);
	//		}
	//	}
	//}

	// a, c �� b, d �Ƿ�ȱ���.
	// ��Ϊint������ԭ��, �ȱ������ж�Ҫ����Ϊ0�ж�.
	bool isOk(int a, int b, int c, int d) {
		if (a % c != 0 || b % d != 0)
			return false;
		return (a / c == b / d);
	}

	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		// Ҫ����ѧȥ�ж��ǲ��������ϰ�.
			if (command.size() == 0)
			return (x == 0) && (y == 0);

			vector<int> xvec(command.size() + 1), yvec(command.size() + 1);

			// �ʼ�Ĳ���.
			xvec[0] = 0, yvec[0] = 0;
			For(i, 0, command.size()) {
				if (command[i] == 'U')
					xvec[i + 1] = xvec[i], yvec[i + 1] = yvec[i] + 1;
				else
					xvec[i + 1] = xvec[i] + 1, yvec[i + 1] = yvec[i];
				// ��������յ�����ϰ�:
				// cout << xvec[i] << " " << yvec[i] << endl;
				if (isOver(xvec[i + 1], yvec[i + 1], obstacles, x, y) != -1)
					return isOver(xvec[i + 1], yvec[i + 1], obstacles, x, y);
			}
			int xstep = xvec[command.size()], ystep = yvec[command.size()];

			// cout << "step: \n" << xstep << " " << ystep << endl;

			// cout << xvec.size() << endl;
			// ע����C++���� "%" ����a%b ���a<b������Ϊ0, ����a.
			// �����ǵȱ�����OK, ��ѧ����Ҫ�����.
			for (auto i : obstacles) {
				if (i[0] > x || i[1] > y)
					continue;
				For(j, 0, xvec.size()) {
					int xsub = i[0] - xvec[j], ysub = i[1] - yvec[j];
					if (isOk(xsub, ysub, xstep, ystep)) {
						//cout << i[0] << " " << i[1] << endl;
						//cout << xvec[j] << " " << yvec[j] << endl;
						//cout << xstep << " " << ystep << endl;
						return 0;
					}
				}
			}

			// û���ϰ�, ���ڿ��ɲ����Ե��յ�.
			For(j, 0, xvec.size()) {
				// cout << " --- " << endl;
				// cout << xvec[j] << " " << yvec[j] << endl;
				int xsub = x - xvec[j], ysub = y - yvec[j];
				if (isOk(xsub, ysub, xstep, ystep)) {
					return 1;
				}
			}
			return 0;
	}
};

int main() {
	Solution s;
	vector<vector<int> > obs = { {4, 5}, {6, 1}, {7, 10}, {9, 1}, {1, 1}, {5, 0}, {2, 8} };
	//vector<vector<int> >obs = {
	//	{7, 7}, {0, 5}, {2, 7}, {8, 6}, {8, 7}, {6, 5}, {4, 4}, {0, 3}, {3, 6}
	//};
	// vector<vector<int> > obs = { {6, 7}, {1, 7}, {0, 1}, {2, 9}, {5, 5}, {4, 1}, {4, 8} };
	//vector<vector<int> > obs = {
	//	{4, 2}
	//};

	cout << s.robot("UURRUUU", obs, 946, 2365) << endl;
	return 0;
}