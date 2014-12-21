#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 1003;
const int M = 10004;
const int INF = 10000;
int dis[N][N];
int n, m;
int floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (i != j) dis[i][j] = INF;
			else dis[i][j] = 0;
		}
	for (int i = 0; i < m; ++i) {
		int p1, p2, distance;
		cin >> p1 >> p2 >> distance;
		if (dis[p1][p2] > distance) {
			dis[p1][p2] = dis[p2][p1] = distance;
		}
	}
	floyd();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", dis[i][j]);
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}
