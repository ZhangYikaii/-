#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

// vis���������������
// vis�����¼����λ��, ���λ����û���ʹ�.
void permuteUniqueDFS(vector<int> &nums, vector<int> &visited, vector<int> &resVec, vector<vector<int> > &res) {
	if (resVec.size() == nums.size())		// ������.
		res.push_back(resVec);
	else {
		for (int i = 0; i < nums.size(); ++i) {
			if (visited[i] == 0) {
				// ������: �����ǰ��������ͬ ����! ǰ������û�з��ʹ�.
				// ��Ϊ��������ٷ��ʵĻ�, �ȵȻ���ʵ�ǰ��Ԫ��, ���ظ���.
				// ��Ҫ�仯��������, ����vis[] ��¼�����±�, ������һ����.
				if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0)
					continue;
				visited[i] = 1;
				resVec.push_back(nums[i]);
				permuteUniqueDFS(nums, visited, resVec, res);
				resVec.pop_back();				// ע�������ʱ��res����.
				visited[i] = 0;
			}
		}
	}
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
	// write your code here
	vector<vector<int> > res;
	vector<int> resVec;
	vector<int> visited(nums.size(), 0);
	sort(nums.begin(), nums.end());
	permuteUniqueDFS(nums, visited, resVec, res);
	return res;
}
