#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <cstring>
using namespace std;
const int N = 100005;
const int INF = 10000000;
int dis[N];
bool visit[N];
vector<int> vec[N];
vector<int>::iterator it;
map<pair<int, int>, int> mp;
int n, m;
int start, end;
int spfa() {
	for (int i = 1; i <= n; ++i) {
		dis[i] = INF;
	}
	memset(visit, 0, sizeof(visit));
	queue<int> que;
	que.push(start);
	dis[start] = 0;
	int tdis;
	while (!que.empty()) {
		int p = que.front();
		visit[p] = false;
		que.pop();
		for (it = vec[p].begin(); it != vec[p].end(); ++it) {
			tdis = mp[make_pair(p, *it)];
			if (dis[*it] > dis[p] + tdis) {
				dis[*it] = dis[p] + tdis;
				if (!visit[*it]) {
					que.push(*it);
					visit[*it] = true;
				}
			}
		}
	}
	return dis[end];
}
int main() {
	//freopen("in.txt", "r", 0);
	scanf("%d%d%d%d", &n, &m, &start, &end);
	int p1, p2, tdis;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &p1, &p2, &tdis);
		pair<int, int> pr = make_pair(p1, p2);
		pair<int, int> pr2 = make_pair(p2, p1);
		if (mp.find(pr) == mp.end()) {
			vec[p1].push_back(p2);
			vec[p2].push_back(p1);
			mp[pr] = tdis;
			mp[pr2] = tdis;
		} else {
			map<pair<int, int>, int>::iterator mit = mp.find(pr);
			if (mit->second > tdis) {
				mit->second = tdis;
				mp[pr2] = tdis;
			}
		}
	}
	printf("%d\n", spfa());
	return 0;
}


