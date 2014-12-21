#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 505;
const int M = 100005;
int dp[M];
int w[N], v[N];
int main() {
	int n, m;
	cin >> n >> m;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= w[i]; --j) {
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
		}
	}
	cout << dp[m] << endl;
	//system("pause");
	return 0;
}
