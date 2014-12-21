#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 105;
int dp[N][N];
int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	int num;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> num;
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + num;
		}
	}
	int mx = -1000;
	for (int i = 1; i <= n; ++i) {
		mx = max(mx, dp[n][i]);
	}
	cout << mx << endl;
	//system("pause");
	return 0;
}
