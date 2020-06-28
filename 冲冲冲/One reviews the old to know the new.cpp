#include <bits/stdc++.h>
using namespace std;

// One reviews the old to know the new
class Solution {
public:
	/**
	 * @param n: An integer
	 * @param nums: An array
	 * @return: the Kth largest element
	 */
	////////////////////////////REVIEW///////////////////////////////////////////////////
	int reviewPartion(int l, int r, int m, vector<int>& nums) {
		int guard = nums[m]; // �Դ�Ϊ����.
		swap(nums, l, m); // �ŵ���һ��.
		int j = l;
		// for-loop �ѱ�guard��С�Ķ��ŵ�ǰ��.
		for (int i = l + 1; i <= r; ++i) {
			if (nums[i] < guard) {
				++j;
				swap(nums, j, i);
			}
		}
		swap(nums, j, l); // ��guard�ŵ��м�.
		return j; // ����idx.
	}

	// ??? �����ƺ����㷨���������Ǹ�����λ�����㷨:
	int findMedia(vector<int>& nums, int l, int r) {
		if (l == r)
			return nums[l];
		int i = l;
		int n;
		for (i = l; i <= r - 5; i += 5)
		{
			sort(nums.begin() + l, nums.begin() + 5 + l);
			n = i - l;
			swap(nums, l + n / 5, i + 2);
		}
		int a = r - i + 1;
		if (a > 0)
		{
			sort(nums.begin() + i, nums.begin() + r + 1);
			n = i - l;
			swap(nums, l + n / 5, i + a / 2);
		}
		n = n / 5;
		return findMedia(nums, l, l + n);
	}
	////////////////////////////REVIEW///////////////////////////////////////////////////

	void swap(vector<int>& nums, int i, int j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

	int partion(vector<int>& nums, int l, int r, int m) {
		int s = nums[m];
		swap(nums, l, m);
		int j = l;
		for (int i = l + 1; i <= r; i++) {
			if (nums[i] < s) {
				j++;
				swap(nums, j, i);
			}
		}
		swap(nums, j, l);
		return j;
	}

	//��һ������nums�����е�λ��
	int findId(vector<int>& nums, int l, int r, int val) {
		for (int i = l; i <= r; i++) {
			if (nums[i] == val)
				return i;
		}
		return -1;
	}
	int findMedia(vector<int>& nums, int l, int r) {
		if (l == r)
			return nums[l];
		int i = l;
		int n;
		for (i = l; i <= r - 5; i += 5)
		{
			sort(nums.begin() + l, nums.begin() + 5 + l);
			n = i - l;
			swap(nums, l + n / 5, i + 2);
		}
		int a = r - i + 1;
		if (a > 0)
		{
			sort(nums.begin() + i, nums.begin() + r + 1);
			n = i - l;
			swap(nums, l + n / 5, i + a / 2);
		}
		n = n / 5;
		return findMedia(nums, l, l + n);
	}
	int bfptr(vector<int>& nums, int l, int r, int k) {
		int n = findMedia(nums, l, r);
		int id = findId(nums, l, r, n);
		int i = partion(nums, l, r, id);

		int m = i - l + 1;
		if (m == k)
			return nums[i];
		// ˵���� k ����ں�벿��.
		else if (m < k) {
			return bfptr(nums, i + 1, r, k - m);
		}
		else {
			return bfptr(nums, l, i - 1, k);
		}
	}

	int kthLargestElement(int n, vector<int>& nums) {
		return bfptr(nums, 0, nums.size() - 1, nums.size() - n + 1);
	}

};


// 8. Rotate String
// ����ȫ��, ����ǰoffset��, �����n - offset��.
class Solution {
public:
	/**
	 * @param str: An array of char
	 * @param offset: An integer
	 * @return: nothing
	 */

	void rotate(int i, int n, string& str) {
		char tmp = str[i];
		str[i] = str[n - 1 - i];
		str[n - 1 - i] = tmp;
	}
	void rotateString(string& str, int offset) {
		// write your code here
		int n = str.size();
		if (n <= 1)
			return;
		offset %= n;
		for (int i = 0; i < n / 2; ++i) {
			rotate(i, n, str);
		}

		for (int i = 0; i < offset / 2; ++i) {
			rotate(i, offset, str);
		}

		int nn = n - offset;
		for (int i = offset, k = 0; k < (n - offset) / 2; ++k) {
			char tmp = str[i + k];
			str[i + k] = str[i + nn - 1 - k];
			str[i + nn - 1 - k] = tmp;
		}
	}
};




// 16. Permutations II

class Solution {
public:
	/*
	 * @param :  A list of integers
	 * @return: A list of unique permutations
	 */

	// dfs��Ҫ����ֹ����, ��Ҫȫ���е�����, ��¼visit��һ������, �м�����һ������.
	void reviewDFS(vector<int>& nums, vector<int>& visited, vector<int>& resVec) {
		// ��ֹ�ж�...

		// else:
		// ���ﲻ�ܼ���DFS������:
		// 1. ??? û����, ��ϰluogu������.
	}

	 // vis���������������
	 // vis�����¼����λ��, ���λ����û���ʹ�.
	void permuteUniqueDFS(vector<int>& nums, vector<int>& visited, vector<int>& resVec, vector<vector<int> >& res) {
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

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		// write your code here
		vector<vector<int> > res;
		vector<int> resVec;
		vector<int> visited(nums.size(), 0);
		sort(nums.begin(), nums.end());
		permuteUniqueDFS(nums, visited, resVec, res);
		return res;
	}

};



// 33. N-Queens

class Solution {
public:
	/*
	 * @param n: The number of queens
	 * @return: All distinct solutions
	 */

	vector<vector<string> > solveNQueens(int n) {
		// write your code here
		vector<vector<string> > result;
		if (n <= 0) {
			return result;
		}
		vector<int> cols;
		search(n, cols, result);
		return result;
	}

	void search(int n, vector<int>& cols, vector<vector<string> >& result) {
		if (cols.size() == n) {
			result.push_back(drawResult(cols, n));
			return;
		}

		// Review Notes: ����ÿһ�е�״̬�������ĸ�λ��.
		for (int col = 0; col < n; col++) {
			// Review Notes: �����������������.
			if (!isValid(cols, col)) {
				continue;
			}
			cols.push_back(col);
			search(n, cols, result);
			cols.pop_back();
		}
	}
	bool isValid(vector<int>& cols, int col) {
		int row = cols.size();
		for (int i = 0; i < row; ++i) {
			if (cols[i] == col) {
				return false;
			}
			if (i - cols[i] == row - col) {
				return false;
			}
			if (i + cols[i] == row + col) {
				return false;
			}
		}
		return true;
	}

	// ����ֵ��дһ������.
	vector<string> drawResult(vector<int>& cols, int n) {
		vector<string> result;
		for (int i = 0; i < cols.size(); ++i) {
			// ע�����string �ĳ�ʼ��.
			string temp(n, '.');
			temp[cols[i]] = 'Q';
			result.push_back(temp);
		}
		return result;
	}
};

// 60. Search Insert Position

class Solution {
public:
	/**
	 * @param A: an integer sorted array
	 * @param target: an integer to be inserted
	 * @return: An integer
	 */
	int searchInsert(vector<int>& A, int target) {
		// write your code here
		if (A.empty())
			return 0;
		int l = 0, r = A.size() - 1, mid;
		if (A[r] < target)
			return r + 1;
		else if (A[l] > target)
			return 0;

		// RN: ���while���Ⱥ�.
		while (l <= r) {
			mid = (l + r) >> 1;

			// RN: �������ƿ���.
			if (A[mid] < target && A[mid + 1] > target)
				return mid + 1;

			// ������ʱ���� - 1 and + 1.
			if (A[mid] > target)
				r = mid - 1;
			else if (A[mid] < target)
				l = mid + 1;
			else
				return mid;
		}
	}
};

// 69. Binary Tree Level Order Traversal

// Definition of TreeNode:
class TreeNode {
public:
	int val;
	TreeNode* left, * right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution {
public:
	/**
	 * @param root: A Tree
	 * @return: Level order a list of lists of integer
	 */
	struct Data {
		TreeNode* ptr;
		int level;
		Data() { };
		Data(TreeNode* t, int l) : ptr(t), level(l) { }
	};
	vector<vector<int>> levelOrder(TreeNode* root) {
		// Write your code here
		vector<vector<int>> res;
		if (root == NULL)
			return res;

		// RN: ���л���ʹ�÷���.
		queue<Data> RNq;
		// push root �����1.
		RNq.push(Data(root, 1));
		while (!RNq.empty()) {
			Data tmp = RNq.front();
			RNq.pop();

			// do ..

			// ����һ�������� push �µ�.
		}



		queue<Data> q;
		q.push(Data(root, 1));
		while (!q.empty()) {
			Data tmp = q.front();
			q.pop();
			if (res.size() < tmp.level) {
				vector<int> tmpVec;
				tmpVec.push_back(tmp.ptr->val);
				res.push_back(tmpVec);
			}
			else {
				res[tmp.level - 1].push_back(tmp.ptr->val);
			}

			if (tmp.ptr->left != NULL)
				q.push(Data(tmp.ptr->left, tmp.level + 1));
			if (tmp.ptr->right != NULL)
				q.push(Data(tmp.ptr->right, tmp.level + 1));
		}

		return res;
	}
};

// 82. Single Number
// �ҵ�һ��ֻ����һ�ε�����.

class Solution {
public:
	/**
	 * @param A: An integer array
	 * @return: An integer
	 */
	int singleNumber(vector<int>& A) {
		// write your code here
		int ans = A[0];
		for (int i = 1; i < A.size(); ++i) {
			ans ^= A[i];
		}
		return ans;
	}
};

// 97. Maximum Depth of Binary Tree

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
	/**
	 * @param root: The root of binary tree.
	 * @return: An integer
	 */
	int maxDepth(TreeNode* root) {
		// write your code here
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL) {
			return 1;
		}

		return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
	}
};



// ��������ֱ��:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int getHeight(TreeNode* root, int& maxWeight) {
		if (root != NULL) {
			int ah = 0, bh = 0, t = 0;
			if (root->left != NULL)
				ah = getHeight(root->left, maxWeight);
			if (root->right != NULL)
				bh = getHeight(root->right, maxWeight);
			t = ah + bh;
			if (maxWeight < t)
				maxWeight = t;
			return max(ah + 1, bh + 1);
		}
		return 0;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		int t = 0;
		getHeight(root, t);
		return t;
	}
};


// ������������·��:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:


	void doit(TreeNode* root, vector<string>& vec, string ss) {
		ss += to_string(root->val) + "->";

		// ����Ҷ�ӽڵ� ����ֹ.
		if (root->left == NULL && root->right == NULL && !ss.empty()) {
			ss = ss.substr(0, ss.length() - 2);
			// cout << ss << endl;
			vec.push_back(ss);
		}

		if (root->left != NULL)
			doit(root->left, vec, ss);

		if (root->right != NULL)
			doit(root->right, vec, ss);
	}


	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> vec;

		if (root == NULL)
			return vec;

		doit(root, vec, "");
		return vec;
	}
};


// �������Ĳ�ƽ��ֵ:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	vector<double> averageOfLevels(TreeNode* root) {
		double arr[2005][2];
		for (int i = 0; i < 2005; ++i) {
			for (int k = 0; k < 2; ++k)
				arr[i][k] = 0;
		}

		queue<pair<TreeNode*, int>> que;
		vector<double> res;
		que.push(make_pair(root, 0));
		double sum = 0;

		// ������һ����ѵ�ζ����
		while (!que.empty()) {
			TreeNode* tmp = que.front().first;
			int tmpn = que.front().second;
			que.pop();

			if (tmp != NULL) {
				sum += tmp->val;
				que.push(make_pair(tmp->left, tmpn + 1));
				que.push(make_pair(tmp->right, tmpn + 1));

				// �ѵ���ÿ����ٵļ�����
				// ��α�����ͬʱ��¼ÿ���ж��ٸ��Լ�ÿ����ܺ�.
				arr[tmpn][0]++;
				arr[tmpn][1] += tmp->val;
			}
		}

		for (int i = 0; arr[i][0] != 0; ++i) {
			res.push_back(arr[i][1] / arr[i][0]);
		}

		return res;
	}
};


// ���������¶�:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	// ���ǵݹ�����ܺ͵ĺ���, �ݹ����һ�����ܺ�.
	int countChild(TreeNode* node) {
		if (node == NULL)
			return 0;
		return node->val + countChild(node->left) + countChild(node->right);
	}

	// �ؼ�������ļ���return
	int findTilt(TreeNode* root) {
		if (root == nullptr)
			return 0;

		// ���� ���ڵ���¶� ���� �����¶��Һ����¶� �������ʱ���Ǵ�ͷ��ʼ���Ǵ������濪ʼ Ȼ�����һ��㷵�ؾ����ܵ���
		// ���ص���Ҫ����ǰ��ļӺ� ����һ��Ҫ return ������ + ...
		// ����, return �ݹ麯�� + ����ֵ.. �ݹ鿴�ɼ���õ�.
		return abs(countChild(root->left) - countChild(root->right)) + findTilt(root->left) + findTilt(root->right);
	}

};


// �ϲ�������:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
	{
		// ����ǿ���Ͳ��ü���
		if (t1 == NULL)
			return t2;
		if (t2 == NULL)
			return t1;

		// ȫ�����ӵ�һ������ȥ
		// ע����merge��ʱ�� ��������α�ִ�е�.
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}

};

// ��ת������:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	void exchange(TreeNode* root) {
		TreeNode* node = root;
		// �������ҽ��.
		if (node != NULL) {
			TreeNode* temp = node->left;
			node->left = node->right;
			node->right = temp;
		}
		/*cout << "---:";
		if (node->left != NULL)
			cout << node->left->val << "   ";
		if (node->right != NULL)
			cout << node->right->val;
		cout << endl;*/
	}

	// ����ݹ�ܲ�����Ⱑ
	// ����ʵ���ϻ�������µ��Ƚ���
	// ע�⺯��invertTree���ص�ʱ�� ������������ʱ�� ���������Ϊ�յ�ʱ�� ����root == NULL ��ʱ��
	TreeNode* invertTree(TreeNode* root) {
		TreeNode* node = root;
		if (root == NULL) {
			return root;
		}

		// ��������ȴ���ݹ�, �ٴ����Լ���.
		// ��Ϊ�ݹ鴦����Ҫ����ײ�Ŀ�ʼ��ת, Ȼ�����Ϸ�ת����, �������ϲ��Ҫ�������.
		invertTree(node->left);//��ת������
		invertTree(node->right);//��ת������
		exchange(node);//�������ӽڵ������ӽڵ�
		return root;
	}

};


// �Գƶ�����:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool compRoot(TreeNode* l, TreeNode* r) {
		// ǰ��Ҫ��NULL���жϺ�.
		if (l == NULL)
			return (r == NULL);

		if (r == NULL)
			return false;

		if (r->val != l->val)
			return false;

		// ע��ԳƵıȽ�, ��l->left �� r->right�Ƚ� Ȼ�� l->right, r->left �ıȽ�.
		return (compRoot(l->left, r->right) && compRoot(l->right, r->left));
	}

	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;

		return compRoot(root->left, root->right);
	}

};




// K��һ�鷭ת����
// ע�����˼·�Լ�����:


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 1)
			return head;
		int num = 0;
		for (ListNode* t = head; t != NULL; t = t->next, ++num);
		ListNode* tHead = head, * tTail = head->next, * reaHead = head, * coneHead = head;
		for (int j = 0; j < num / k; ++j) {
			for (int i = 0; i < k - 1; ++i) {
				/*if (tTail->next == NULL) {    // ���ﱾ����������ʱ��Ϳ���ֱ������ ���Ǻ�����һ��û�б�Ҫ
					tTail->next = reaHead;
					tHead->next = NULL;

					reaHead = tTail;

					tTail = NULL;
					break;
				}*/
				tHead->next = tTail->next;
				tTail->next = reaHead;
				reaHead = tTail;
				if (coneHead != head)
					coneHead->next = reaHead;
				tTail = tHead->next;
			}
			if (coneHead == head)
				head = reaHead;
			if (j == num / k - 1)
				break;
			coneHead = tHead;
			tHead = tTail;
			tTail = tTail->next;
			reaHead = tHead;
		}
		// ʣ�µķ�ת����
		/*if (tTail != NULL) {
			while (tTail != NULL) {
				tHead->next = tTail->next;
				tTail->next = reaHead;
				reaHead = tTail;
				tTail = tHead->next;
			}
		}*/

		return head;
	}

};


