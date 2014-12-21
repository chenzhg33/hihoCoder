#include <iostream>
#include <algorithm>
#include <cstring>
#define lson rt << 1
#define rson (rt << 1) + 1
using namespace std;
const int N = 100005;
struct Node {
	bool set_last;
	int add, set, sum;
	Node() : set_last(0), add(0), set(-1), sum(0) {}
} a[4 * N];

void pushUp(int rt) {
	a[rt].sum = a[lson].sum + a[rson].sum;
}

void build(int l, int r, int rt) {
	if (l == r) {
		cin >> a[rt].sum;
		a[rt].add = 0;
		a[rt].set = -1;
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lson);
	build(m + 1, r, rson);
	pushUp(rt);
}

void pushDown(int l, int r, int rt) {
	if (l == r) return;
	int m = (l + r) >> 1;
	if (a[rt].set != -1) {
		a[lson].set = a[rson].set = a[rt].set;
		a[rt].set = -1;
		a[lson].add = a[rson].add = 0;
		a[lson].sum = (m - l + 1) * a[lson].set;
		a[rson].sum = (r - m) * a[rson].set;
	}
	if (a[rt].add != 0) {
		a[lson].add += a[rt].add;
		a[rson].add += a[rt].add;
		a[lson].sum += a[rt].add * (m - l + 1);
		a[rson].sum += a[rt].add * (r - m);
		a[rt].add = 0;
	}
}

void update(bool is_set, int value, int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R) {
		if (is_set) {
			a[rt].set = value;
			a[rt].add = 0;
			a[rt].sum = (r - l + 1) * value;
		} else {
			a[rt].add += value;
			a[rt].sum += (r - l + 1) * value;
		}
		return;
	}
	pushDown(l, r, rt);
	int m = (l + r) >> 1;
	if (L <= m)
		update(is_set, value, L, R, l, m, lson);
	if (R > m)
		update(is_set, value, L, R, m + 1, r, rson);
	pushUp(rt);
}

int main() {
	int n, m;
	cin >> n >> m;
	n++;
	build(1, n, 1);
	for (int i = 0; i < m; ++i) {
		int op, s, e, v;
		cin >> op >> s >> e >> v;
		update(op, v, s + 1, e + 1, 1, n, 1);
		cout << a[1].sum << endl;
	}
	//system("pause");
	return 0;
}
