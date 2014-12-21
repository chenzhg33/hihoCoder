#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
const int N = 100010;
vector<int> vec[N];
map<string, int> mID;
map<string, int> mPO;
string sname[N];
int cnt = 0;
int minID[2*N][17];

struct Record {
	int id, lev;
	Record(int i, int l) : id(i), lev(l) {}
	Record() {}
} record[N*2];

void dfs(int cur, int level) {
	record[cnt++] = Record(cur, level);
	minID[cnt-1][0] = cur;
	int tmp = level;
	vector<int>::iterator it = vec[cur].begin();
	for(; it != vec[cur].end(); ++it) {
		dfs(*it, level + 1);
		record[cnt++] = Record(cur, level);
		minID[cnt-1][0] = cur;
	}
	mPO[sname[cur]] = cnt-1;
}

int main() {
	ios::sync_with_stdio(false);
	int n, id = 0;
	cin >> n;
	string fName, sName;
	for (int i = 0; i < n; ++i) {
		cin >> fName >> sName;
		pair<map<string, int>::iterator, bool> re1 = mID.insert(pair<string, int>(fName, id));
		if (re1.second) sname[id++] = fName;
		pair<map<string, int>::iterator, bool> re2 = mID.insert(pair<string, int>(sName, id));
		if (re2.second) sname[id++] = sName;
		vec[re1.first->second].push_back(re2.first->second);
	}
	dfs(0, 0);
	for (int i = 1; (1 << i) < cnt; ++i) {
		for (int j = 0; j + (1 << i) - 1 < cnt; ++j) {
			minID[j][i] = min(minID[j][i-1], minID[j + (1 << i - 1)][i-1]);
		}
	}
	cin >> n;
	while (n--) {
		cin >> fName >> sName;
		int id1 = mPO[fName], id2 = mPO[sName];
		if (id1 > id2) {
			int tmp = id1; id1 = id2; id2 = tmp;
		}
		int mi = (int)(log(id2 - id1 + 1) / log(2));
		cout << sname[min(minID[id1][mi], minID[id2-(1 << mi) + 1][mi])] << endl;
	}		
	system("pause");
	return 0;
}
/*
7
a b
b d
e g
b e
c f
a c
a k
*/
