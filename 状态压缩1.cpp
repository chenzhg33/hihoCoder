#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
const int M = 10;
const int INF = -1000000;
int dp[N][1 << M];
int w[N];
bool ok[1 << M];
int cal(int n) {
	if (n == 0) return 0;
	int cnt = 1;
	while (n &= n-1) cnt++;
	return cnt;
}
int init(int m, int q) {
	memset(ok, 0, sizeof(ok));
	for (int i = 0; i < (1 << m-1); ++i) {
		if (cal(i) < q) ok[i] = true;
	}
}
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	init(m, q);
	for (int i = 1; i <= n; ++i) cin >> w[i];
	memset(dp, -1, sizeof(dp));
	dp[1][0] = 0;
	dp[1][1 << m-2] = w[1];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < (1 << m-1); ++j) {
			if (dp[i][j] >= 0) {
				if (ok[j])
					dp[i+1][(1 << m - 2) + (j >> 1)] = max(dp[i][j] + w[i+1], dp[i+1][(1 << m - 2) + (j >> 1)]);
				dp[i+1][j >> 1] = max(dp[i][j], dp[i+1][j >> 1]);
			}
		}
	}
	int mx = INF;
	for (int i = 0; i < (1 << m); ++i) {
		mx = max(mx, dp[n][i]);
	}
	cout << mx << endl;
	//system("pause");
}


