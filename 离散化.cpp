#include <iostream>
#include <algorithm>
#include <cstring>
#define lson rt << 1
#define rson (rt << 1) + 1
using namespace std;
const int N = 100005;
struct Node {
	int left, right;
	int value;
	bool updated;
	Node() : value(0), updated(0) {}
} a[N * 6];
struct Seg {
	int x1, x2;
} s[N];
int num[2 * N], hash[2 * N];
int total = 0;
bool visit[N];

void build(int l, int r, int rt) {
	a[rt].left = l;
	a[rt].right = r;
	if (l == r - 1) {
		a[rt].value = 0;
		a[rt].updated = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lson);
	build(m, r, rson);
}

void pushDown(int rt) {
	a[lson].value = a[rt].value;
	a[rson].value = a[rt].value;
	a[rt].updated = false;
	a[lson].updated = true;
	a[rson].updated = true;
}

void update(int v, int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R) {
		a[rt].value = v;
		a[rt].updated = true;
		return;
	}
	if (a[rt].updated) pushDown(rt);
	int m = (l + r) >> 1;
	if (L < m) update(v, L, R, l, m, lson);
	if (R > m) update(v, L, R, m, r, rson);
}

void solve(int rt) {
	if (a[rt].left == a[rt].right - 1) {
		if (!visit[a[rt].value]) {
			visit[a[rt].value] = true;
			++total;
		}
		return;
	}
	if (a[rt].updated) pushDown(rt);
	solve(lson);
	solve(rson);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(num, 0, sizeof(num));
	memset(hash, 0, sizeof(num));
	memset(visit, 0, sizeof(visit));
	visit[0] = true;
	int n, l, cnt = 1;
	cin >> n >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i].x1 >> s[i].x2;
		s[i].x1++;
		s[i].x2++;
		num[cnt++] = s[i].x1;
		num[cnt++] = s[i].x2;
	}
	sort(num, num + cnt);
	int* last = unique(num, num + cnt);
	int len = last - num - 1;
	for (int i = 1; i <= len; ++i) {
		hash[num[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		s[i].x1 = hash[s[i].x1];
		s[i].x2 = hash[s[i].x2];
		cout << s[i].x1 << ' ' << s[i].x2 << endl;
	}
	build(1, len, 1);
	for (int i = 1; i <= n; ++i) {
		update(i, s[i].x1, s[i].x2, 1, len, 1);
	}
	solve(1);
	cout << total << endl;
	for (int i = 1; i <= 15; ++i) {
		if (a[i].left == a[i].right - 1)	
		cout << "Node: " << i << " [" << a[i].left << ',' << a[i].right << "] " << a[i].value << endl;
	}
	//system("pause");
	return 0;
}
