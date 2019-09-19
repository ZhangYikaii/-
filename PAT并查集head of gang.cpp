#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Person
{
	string name; int weight, father;
	Person() {}
	Person(string _name, int _weight, int _father) {
		name = _name; weight = _weight;
		father = _father;
	}
};

struct Group
{
	string head; int numOfPerson;
	int maxWeight, sumWeight;
	Group() {
		numOfPerson = 0; maxWeight = 0;
		sumWeight = 0;
	}
	bool operator<(const Group& that) const {
		return (head < that.head);
	}
};

vector<Person> persons;
// ���鼯����������
int getFather(int x)
{
	if (x != persons[x].father) {
		persons[x].father = getFather(persons[x].father);
	}
	return persons[x].father;
}
void unionSet(int x, int y)
{
	x = getFather(x);
	y = getFather(y);
	if (x != y) {
		persons[x].father = y;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	// ��������
	int N, K; cin >> N >> K;
	map<string, int> link; vector<Group> groups;
	string first, second; int weight, idx1, idx2;
	while (N--) {
		cin >> first >> second >> weight;
		// ����first��second�Ƿ��Ѿ��ڷ�����ֳ��ĸ����
		if (link.count(first) && link.count(second)) {
			idx1 = link[first]; idx2 = link[second];
			persons[idx1].weight += weight;
			persons[idx2].weight += weight;
		}
		else if (link.count(first) && !link.count(second)) {
			idx1 = link[first]; idx2 = persons.size();
			link[second] = idx2;
			persons.push_back(Person(second, weight, idx2));
			groups.push_back(Group());
			persons[idx1].weight += weight;
		}
		else if (!link.count(first) && link.count(second)) {
			idx1 = persons.size(); idx2 = link[second];
			link[first] = idx1;
			persons.push_back(Person(first, weight, idx1));
			groups.push_back(Group());
			persons[idx2].weight += weight;
		}
		else {
			idx1 = persons.size(); link[first] = idx1;
			idx2 = idx1 + 1; link[second] = idx2;
			persons.push_back(Person(first, weight, idx1));
			persons.push_back(Person(second, weight, idx2));
			groups.push_back(Group()); groups.push_back(Group());
		}
		unionSet(idx1, idx2);
		groups[idx1].sumWeight += weight;
	}

	// �������ݣ����鲢�õ����
	int tf; int num = persons.size();
	set<Group> result;
	// ������������Ϣ
	for (int i = 0; i < num; i++) {
		tf = getFather(i);
		groups[tf].numOfPerson++;
		if (tf != i) {
			groups[tf].sumWeight += groups[i].sumWeight;
		}
		if (groups[tf].maxWeight < persons[i].weight) {
			groups[tf].maxWeight = persons[i].weight;
			groups[tf].head = persons[i].name;
		}
	}
	// �ҳ�����Ҫ��ķ���
	for (int i = 0; i < num; i++) {
		if (groups[i].sumWeight > K && groups[i].numOfPerson > 2) {
			result.insert(groups[i]);
		}
	}

	// ������
	cout << result.size() << endl;
	set<Group>::iterator iter = result.begin();
	for (; iter != result.end(); iter++) {
		cout << (*iter).head << " " << (*iter).numOfPerson << endl;
	}
	return 0;
}