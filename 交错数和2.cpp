#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 20;
typedef long long ll;
struct Node {
	ll s, n;
	Node(ll s_, ll n_) : s(s_), n(n_) {}
	Node() : s(0), n(-1) {}
};
ll mod = 1000000007;
ll l, r, k, bit[20], base[20];
Node dp[N][N][205];
int mp[3][3][4];

void init_base() {
	base[1] = 1;
	for (int i = 2; i < N; ++i)
		base[i] = base[i-1] * 10;
}
int init_bit(ll num) {
	int len = 1;
	while (num) {
		bit[len++] = num % 10;
		num /= 10;
	}
	return len;
}

Node dfs(int cur, int sign, int zero, int limit, int sum) {
	Node r(0, 0);
	if (cur == 0) {
		return Node(0, sum == k);
	}
	if (dp[ mp[zero][limit][sign+1] ][cur][sum+100].n != -1)
		return dp[ mp[zero][limit][sign+1] ][cur][sum+100];
	int end = limit == 1 ? bit[cur] : 9;
	Node tmp;
	for (int i = 0; i <= end; ++i) {
		if (zero) {
			if (i == 0) tmp = dfs(cur-1, 1, 1, limit && i == end, sum);
			else tmp = dfs(cur-1, -sign, 0, limit && i == end, sum + i);
		} else
			tmp = dfs(cur-1, -sign, 0, limit && i == end, sum + i * sign);
		if (tmp.n > 0) {
			ll tt = i * base[cur] % mod;
			r.n = (r.n + tmp.n) % mod;
			r.s = (r.s + tmp.s) % mod;
			r.s = (r.s + tt * tmp.n % mod) % mod;
		}
	}
	dp[ mp[zero][limit][sign+1] ][cur][sum+100] = r;
	return r;
}

ll solve(ll num) {
	int len = init_bit(num);
	memset(dp, -1, sizeof(dp));
	return dfs(len-1, 1, 1, 1, 0).s;
}

int main() {
	int index = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int m = 0; m < 3; ++m)
				mp[i][j][m] = index++;
	init_base();
	//cin >> l >> k;
	//cout << solve(l) << endl;
	while (cin >> l >> r >> k) {
		cout << (solve(r) - solve(l) + mod) % mod << endl;
	}
	//system("pause");
}
	
	
