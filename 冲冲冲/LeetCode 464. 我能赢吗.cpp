#include <bits/stdc++.h>
using namespace std;
#include <unordered_map>

class Solution {
public:
	int maxChoosableInteger, desiredTotal;
	std::unordered_map<unsigned long long, bool> mp;

	// ��ǰ���״̬��, �ܷ���Ӯ. total_sum��¼��ǰ�ĺ�, bitset��¼��Щ���Ѿ���ѡ�����
	bool dfs(int total_sum, std::bitset<25> bs) {
		// �ݹ�ı߽�
		if (total_sum >= desiredTotal)
			return true;
		// ���仯
		if (mp.find(bs.to_ullong()) != mp.end()) return mp[bs.to_ullong()];

		bool ret = true;
		// ���赱ǰ״̬��A
		// �����������˵��, ö��B�ߵ����������(��һ��for), ֻ��ѭ����B��������Ӯ, A������Ӯ. 
		for (int i = 1; i <= maxChoosableInteger; ++i) {
			if (bs[i]) continue;
			std::bitset<25> bs_tmp = bs;
			bs_tmp[i] = 1;
			// �������ö��B 
			if (dfs(total_sum + i, bs_tmp)) {
				ret = false;
				break;
			}
		}
		return mp[bs.to_ullong()] = ret;
	}

	bool canIWin(int a_, int b_) {
		maxChoosableInteger = a_;
		desiredTotal = b_;
		// ��������������С��desiredTotal, ������
		if ((maxChoosableInteger + 1) * maxChoosableInteger * 0.5 < desiredTotal)
			return false;
		for (int i = 1; i <= maxChoosableInteger; ++i) {
			bitset<25> bs;
			bs[i] = 1;
			if (dfs(i, bs)) return true;
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<int> nums = { 2, 2, 3, 3, 3, 4 };
	cout << s.deleteAndEarn(nums) << endl;

	return 0;
}