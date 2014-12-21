#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100005;
const int INF = -100000;
vector<int> vec[N];
int mdis = INF;
int dfs(int cur, int p) {
	if (vec[cur].size() == 1) return 1;
	vector<int>::iterator it = vec[cur].begin();
	int fst = INF, snd = INF;
	for (; it != vec[cur].end(); ++it) {
		if (*it != p) {
			int tmp = dfs(*it, cur);
			if (tmp > fst) { snd = fst; fst = tmp; }
			else if (tmp > snd) { snd = tmp; }
		}
	}
	mdis = max(mdis, fst + snd + 1);
	return fst + 1;
}
int main() {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1, 0);
	cout << mdis - 1;
	//system("pause");
	return 0;
}
