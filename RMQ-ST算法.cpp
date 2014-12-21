#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int N = 1000005;
int a[N*3];
void push(int rt) {
	a[rt] = min(a[rt << 1], a[(rt << 1) + 1]);
}
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &a[rt]);
		return;
	}
	int m = ((r - l) >> 1) + l;
	build(l, m, rt << 1);
	build(m + 1, r, (rt << 1) + 1);
	push(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if (l >= L && r <= R) return a[rt];
	int m = ((r - l) >> 1) + l;
	int lmin = 1000000, rmin = 1000000;
	if (L <= m)
		lmin = query(L, R, l, m, rt << 1);
	if (R > m)
		rmin = query(L, R, m + 1, r, (rt << 1) + 1);
	return min(lmin, rmin);
}
int main() {
	int n, q;
	scanf("%d", &n);
	build(1, n, 1);
	scanf("%d", &q);
	int s, e;
	while(q--) {
		scanf("%d%d", &s, &e);
		printf("%d\n", query(s, e, 1, n, 1));
	}
	//system("pause");
	return 0;
}
