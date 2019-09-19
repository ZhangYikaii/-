#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

#define in(x) x=read()

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X*w;
}

bool canJump(vector<int>& nums) {
	//int used[10005] = { 0 };
	//used[0] = 1;
	//for (int i = 0; i < nums.size(); ++i) {
	//	if (used[i] == 1) {
	//		for (int k = 1; k < nums[i]; ++k) {
	//			used[i + k] = 1;
	//		}
	//	}
	//}

	//if (used[nums.size() - 1] == 1)
	//	return true;
	//else return false;

	int maxx = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (maxx < i)
			return false;
		maxx = max(nums[i] + i, maxx);
		if (maxx >= nums.size())
			return true;
	}

	return true;
}

int main() {
	

	return 0;
}


/*
��Ծ��Ϸ: ÿ����Ŀ�����Ծ����󳤶���֪, ���ܲ��ܵ����һ����.

�����̰�Ľ��, ��¼��ǰ�ܵ�������·��, ɨһ������, ����±� > �ܵ�������·��, return false.

ע��һ��ϸ��, ����ٽ�

*/