#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int MAXN  = 100005;
vector<string> svec;
vector<string> fvec;
map<string, int> mp;
struct Node {
	int father;
	string name;
	int color;
	vector<Node*> child;
};
struct Re {
	int id;
	int pos;
	Re(int i, int p) : id(i), pos(p) {}
	Re() {}
	bool operator==(const Re& re) {
		return re.id == id;
	}
};
Node arr[MAXN];
int r[MAXN];
int R[MAXN];
vector<Re> qry[MAXN];
int Find(int id) {
	return id == r[id] ? id : r[id] = Find(r[id]);
}
void Union(int i, int j) {
	int fi = Find(i), fj = Find(j);
	r[fi] = r[fj];
}

void dfs(int id) {
	arr[id].color = 1;
	vector<Re>::iterator it = qry[id].begin();
	for (; it != qry[id].end(); ++it) {
		Re re = *it;
		if (arr[re.id].color == 0) continue;
		else {
			if (arr[re.id].color == 1)
				R[re.pos] = re.id;
			else
				R[re.pos] = Find(re.id);
			it = qry[id].erase(it);
			it--;
			qry[R[re.pos]].erase(find(qry[R[re.pos]].begin(), qry[R[re.pos]].end(), Re(id, re.pos)));
		}
	}
	vector<Node*>::iterator it2 = arr[id].child.begin();
	for(; it2 != arr[id].child.end(); ++it2) {
			dfs((*it2) - arr);			
	}
	arr[id].color = 2;
	Union(id, arr[id].father);
}
		
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string fstr, sstr;
	int id = 0;
	typedef map<string, int>::iterator my_iterator;
	for (int i = 0; i < n; ++i) {
		cin >> fstr >> sstr;
		fvec.push_back(fstr);
		svec.push_back(sstr);
		pair<my_iterator, bool> res1 = mp.insert(pair<string, int>(fstr, r[id] = id));
		if (res1.second == true) ++id;
		pair<my_iterator, bool> res2 = mp.insert(pair<string, int>(sstr, r[id] = id));
		if (res2.second == true) ++id;
		arr[res2.first->second].name = sstr;
		arr[res2.first->second].father = res1.first->second;
		arr[res1.first->second].name = fstr;
		arr[res1.first->second].child.push_back(&arr[res2.first->second]);
	}
	cin >> n;
	id = 0;
	for (int i = 0; i < n; ++i) {
		cin >> fstr >> sstr;
		qry[mp[fstr]].push_back(Re(mp[sstr], id));
		qry[mp[sstr]].push_back(Re(mp[fstr], id));
		++id;
	}
	dfs(0);
	for (int i = 0; i < id; ++i) {
		cout << arr[R[i]].name << endl;
	}
	system("pause");
	return 0;
}
	
