#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int used[510] = { 0 };

void dfs(int curSum, int curPos, int &tar, vector<vector<int> > &res, vector<int> &curRes, vector<int> &num) {
	if (curSum > tar)
		return;
	if (curSum == tar) {
		/*for (auto i : curRes) {
			cout << i << " ";
		}
		cout << endl;*/
		res.push_back(curRes);
		return;
	}

	for (int i = curPos; i < num.size(); ++i) {
		if (used[i] == 0 && num[i] + curSum <= tar) {
			if (i != 0 && used[i - 1] == 0 && num[i - 1] == num[i])			// ע���˰� �ظ�Ԫ�ص�ȫ���о�����仰 ����tmǰ���������ͬԪ��, ����! ֮ǰû�о���, ���������Ԫ�ؾͲ��ñ�����.
				continue;
			used[i] = 1;
			curRes.push_back(num[i]);
			dfs(curSum + num[i], i + 1, tar, res, curRes, num);
			curRes.pop_back();
			used[i] = 0;
		}
	}

}

vector<vector<int>> combinationSum2(vector<int> &num, int target) {
	vector<vector<int>> res;
	vector<int> curRes;
	sort(num.begin(), num.end());
	dfs(0, 0, target, res, curRes, num);

	return res;
}
int main() {
	vector<int> v = { 10, 1, 6, 7, 2, 1, 5 };
	vector<int> curRes;
	vector<vector<int>> res;
	int tar = 8;
	combinationSum2(v, tar);

	return 0;
}