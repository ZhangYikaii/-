#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define in(x) x=read()
#define For(i, a, b) for(int i = a; i < b; ++i)

inline int read() {
	int X = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') w = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') X = (X << 3) + (X << 1) + ch - '0', ch = getchar();
	return X * w;
}

int check(char ch) {
	int tmp = isalpha(ch);
	if (!tmp) {
		return isdigit(ch);
	}
	else {
		return tmp;
	}
}

map<string, int> m;

int main() {
	string input;
	string curWord;
	int curMax = 0;
	getline(cin, input);

	int beg = 0, aft = 0;
	for (; beg < input.size(); beg = aft) {
		while (beg < input.size() && check(input[beg]) == 0)
			++beg;
		if (beg == input.size())
			break;
		aft = beg;
		while (aft < input.size() && check(input[aft]) != 0)
			++aft;

		string word = input.substr(beg, aft - beg);
		// cout << word << endl;
		if (!word.empty()) {
			m[word]++;
		}
	}


	for (map<string, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
		if (curMax < iter->second) {
			curMax = iter->second;
			curWord = iter->first;
		}
		else if (curMax == iter->second && !curWord.empty() && iter->first > curWord) {
			curWord = iter->first;
		}
	}

	cout << curWord << " " << curMax << endl;

	return 0;
}


// �ú�ѧϰһ�´�...?
//
//#include<iostream> 
//#include<string>
//#include<map>  
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int index, len, maxcnt;
//	string line;
//	string word, ans;
//	map<string, int>words;
//	getline(cin, line);
//	len = line.size();
//	line[len++] = '.';/*���ڴ������123 123 e 123������β������һ��������*/
//	for (index = 0, maxcnt = 0, ans = "\0"; index < len; index++) {
//
//		// �������ĸ��������.
//		if (isalpha(line[index]) || isdigit(line[index]))
//			// ��дת����Сд.
//			word += !isdigit(line[index]) && isupper(line[index]) ? line[index] - 'A' + 'a' : line[index];/*�ж�˳���ܻ�*/
//		// ����������, �����˵�����˶ϵ�. ������ȡ��.
//		else if (!word.empty()) {
//			words[word]++;			// map ����++.
//			
//			if (words[word] > maxcnt) {
//				maxcnt = words[word];
//				ans = word;
//			}
//			word.erase();
//		}
//	}
//	cout << ans << " " << maxcnt << endl;
//
//	return 0;
//}
//


/*




*/