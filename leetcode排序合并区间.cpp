#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp1(Interval a, Interval b) {
	return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &intervals) {
	vector<Interval> ans;
	int n = intervals.size(), curEnd = -1, curStart = -1;
	sort(intervals.begin(), intervals.end(), cmp1);
	for (auto it = intervals.begin(); it != intervals.end(); ++it) {
		// cout << it->start << " \\" << it->end << endl;
		// ��ʼ��
		if (curStart == -1)
			curStart = it->start;
		if (curEnd == -1) {
			curEnd = it->end;
		}

		else {
			// �ϲ�
			// ���￨�˺þ�!!!
			// ����������Ҫд���, ע���������: [1, 4], [1, 4] �� [1, 4], [2, 3] ������
			// ΪʲôҪelse if, ΪʲôҪ && curEnd <= it->end), �����е����, Ҫ���ǵ�!
			if (it->start <= curEnd && curEnd <= it->end)
				curEnd = it->end;
			else if (it->start > curEnd) {
				ans.push_back(Interval(curStart, curEnd));
				curStart = it->start;
				curEnd = it->end;
			}
		}
		// ע���������һ������Ҫ���
		if (it == intervals.end() - 1)
			ans.push_back(Interval(curStart, curEnd));
	}


	return ans;
}

int main() {
	vector<Interval> test;
	test.push_back(Interval(1, 4));
	test.push_back(Interval(1, 4));
	/*test.push_back(Interval(8, 10));
	test.push_back(Interval(15, 18));*/

	test = merge(test);
	for (auto it = test.begin(); it != test.end(); ++it) {
		cout << it->start << " " << it->end << endl;
	}



	return 0;
}

/*

����: ��һ������list���ϲ��غϵ����䣬ʾ����ͼ

*/
