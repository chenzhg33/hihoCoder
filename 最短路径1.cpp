#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 1003;
const int M = 10004;
const int INF = 10000;
struct Node {
	int id, dis;
	Node() {}
	Node(int i, int d) : id(i), dis(d) {}
};
struct cmp {
	bool operator()(Node a, Node b) {
		return a.dis > b.dis;
	}
};
int mp[N][N];
bool visit[N];
int start, end;

int bfs(int n) {
	priority_queue<Node, vector<Node>, cmp> que;
	que.push(Node(start, 0));
	while (!que.empty()) {
		Node top = que.top();
		//cout << "id: " << top.id << endl;
		if (top.id == end) {
			return top.dis;
		}
		visit[top.id] = true;
		que.pop();
		for (int i = 1; i <= n; ++i) {
			if (mp[top.id][i] == INF) continue;
			if (visit[i]) continue;
			que.push(Node(i, mp[top.id][i] + top.dis));
		}
	}
}

int solve(int n) {
	int dis[N];
	bool visited[N];
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; ++i)
		dis[i] = INF;
	dis[start] = 0;
	int pos = start;
	for (int i = 0; i < n; ++i) {
		int min_value = INF;
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && dis[j] < min_value) {
				pos = j;
				min_value = dis[j];
			}
		}
		if (pos == end) {
			return min_value;
		}
		visited[pos] = true;
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && min_value + mp[pos][j] < dis[j])
				dis[j] = min_value + mp[pos][j];
		}
	}
}

int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin >> n >> m >> start >> end;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			mp[i][j] = INF;
	for (int i = 0; i < m; ++i) {
		int p1, p2, distance;
		cin >> p1 >> p2 >> distance;
		if (mp[p1][p2] > distance) {
			mp[p1][p2] = mp[p2][p1] = distance;
		}
	}
	cout << solve(n) << endl;
	return 0;
}
