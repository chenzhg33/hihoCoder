#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1005;
const int M = 6;
const int mod = 1000000007;
int dp[N][1 << M];
int n, m;
void dfs(int row, int state, int pos, int num) {
	if (pos == m) {
		dp[row][state] += num;
		dp[row][state] %= mod;
		return;
	}
	dfs(row, state, pos + 1, num);
	if (pos <= m-2 && !(state & (1 << pos)) && !(state & (1 << pos+1)))
		dfs(row, state | (1 << pos) | (1 << pos+1), pos + 2, num);
}

int main() {
	cin >> n >> m;
	if (n < m) swap(n, m);
	memset(dp, 0, sizeof(dp));
	dfs(1, 0, 0, 1);
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < (1 << m); ++j) {
			if (dp[i-1][j]) {
				dfs(i, (~j) & ((1 << m) - 1), 0, dp[i-1][j]);
				//(~j) & ((1 << m) - 1) 之所以要后面的，是要把取反后前面的1去掉 ，只保留m位 
			}
		}
	}
	cout << dp[n][(1 << m)-1] << endl;
	//system("pause");
	return 0;
}
