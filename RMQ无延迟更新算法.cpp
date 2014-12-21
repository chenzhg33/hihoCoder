#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define lson rt << 1
#define rson (rt << 1) + 1
using namespace std;
const int N = 1000005;
const int INF = 100000;

int a[N*3];

void pushUp(int rt) {
	a[rt] = min(a[lson], a[rson]);
}
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &a[rt]);
		return;
	}
	int m = ((r - l) >> 1) + l;
	build(l, m, lson);
	build(m + 1, r, rson);
	pushUp(rt);
}

void update(int v, int pos, int l, int r, int rt) {
	if (l >= pos && r <= pos) {
		a[rt]= v;
		return;
	}
	int m = ((r - l) >> 1) + l;
	if (pos <= m)
		update(v, pos, l, m, lson);
	if (pos > m)
		update(v, pos, m + 1, r, rson);
	pushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R) return a[rt];
	int m = ((r - l) >> 1) + l;
	int lmin = 1000000, rmin = 1000000;
	if (L <= m)
		lmin = query(L, R, l, m, lson);
	if (R > m)
		rmin = query(L, R, m + 1, r, rson);
	return min(lmin, rmin);
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
			scanf("%d%d", &s, &e);
			update(e, s, 1, n, 1);
		}
	}
	//system("pause");
	return 0;
}
