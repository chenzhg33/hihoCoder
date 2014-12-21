#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define lson rt << 1
#define rson (rt << 1) + 1
using namespace std;
const int N = 100005;
struct Node {
	int minValue;
	bool update;
	Node() : minValue(0), update(0) {}
	Node(int v, bool u) : minValue(v), update(u) {}
} a[N*3];

void pushUp(int rt) {
	a[rt].minValue = a[lson].minValue + a[rson].minValue;
}

void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &a[rt].minValue);
		a[rt].update = 0;
		return;
	}
	int m = ((r - l) >> 1) + l;
	build(l, m, lson);
	build(m + 1, r, rson);
	pushUp(rt);
}

void pushDown(int rt, int l, int r) {
	int m = (l + r) >> 1;
	a[rt].update = 0;
	a[lson].minValue = a[rt].minValue / (r - l + 1) * (m - l + 1);
	a[rson].minValue = a[rt].minValue / (r - l + 1) * (r - m);
	a[lson].update = 1;
	a[rson].update = 1;
}

void update(int v, int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R) {
		a[rt].minValue = v * (r - l + 1);
		a[rt].update = 1;
		return;
	}
	if (a[rt].update) pushDown(rt, l, r);
	int m = ((r - l) >> 1) + l;
	if (L <= m)
		update(v, L, R, l, m, lson);
	if (R > m)
		update(v, L, R, m + 1, r, rson);
	pushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R) return a[rt].minValue;
	if (a[rt].update) pushDown(rt, l, r);
	int m = ((r - l) >> 1) + l;
	int lmin = 0, rmin = 0;
	if (L <= m)
		lmin = query(L, R, l, m, lson);
	if (R > m)
		rmin = query(L, R, m + 1, r, rson);
	return lmin + rmin;
}
int main() {
	int n, q;
	scanf("%d", &n);
	build(1, n, 1);
	scanf("%d", &q);
	int s, e;
	while(q--) {
		int op;
		scanf("%d", &op);
		if (op == 0) {
			scanf("%d%d", &s, &e);
			printf("%d\n", query(s, e, 1, n, 1));
		} else {
			scanf("%d%d%d", &s, &e, &op);
			update(op, s, e, 1, n, 1);
		}
	}
	//system("pause");
	return 0;
}
