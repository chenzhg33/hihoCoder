#include <iostream>
#include <map>
using namespace std;
int m[101][101] = {0};
int v[101] = {0};
int nodeNum = 0;
int maxDis = -1;
void search(int curNode, int dis, map<int, bool> mp, map<int, bool> visited, int sum, int curValue) {
	if (dis == 0) {
		//cout << sum << endl;
		if (sum > maxDis)
			maxDis = sum;
		return;
	}
	if (dis < 0) {
		//cout << sum - curValue << endl;
		if (sum - curValue > maxDis)
			maxDis = sum - curValue;
		return;
	}
	mp[curNode] = true;
	for (int i = 1; i <= nodeNum; ++i) {
		if (m[i][curNode] != -1 && visited.find(i) == visited.end()) {
			int next_sum = mp[i] ? sum : sum + v[i];
			//cout << i << ' ' << curNode << ' ' << m[i][curNode] << endl;
			search(i, dis - m[i][curNode], mp, visited, next_sum, v[i]);
		}
	}
	visited[curNode] = true;
}
int main() {
	std::ios::sync_with_stdio(false);
	int n, q;
	cin >> n;
	nodeNum = n;
	for (int i = 1; i <= n; ++i) cin >> v[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			m[i][j] = -1;
		}
	for (int i = 1; i < n; ++i) {
		int p1, p2, d;
		cin >> p1 >> p2 >> d;
		m[p1][p2] = d;
		m[p2][p1] = d;
	}
	cin >> q;
	for (int i = 0; i < n; ++i) {
		int dis;
		cin >> dis;
		map<int, bool> mp;
		map<int, bool> visited;
		maxDis = -1;
		search(1, dis, mp, visited, 0, 0);
		cout << maxDis << endl;
	}
	system("pause");
	return 0;
}
