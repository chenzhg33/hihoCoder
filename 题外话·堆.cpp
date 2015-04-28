#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
int a[N];
int main() {
	int n;
	cin >> n;
	char op;
	int *last = a;
	for (int i = 0; i < n; ++i) {
		cin >> op;
		if (op == 'A') {
			cin >> *last;
			last++;
			push_heap(a, last);
		} else if (op == 'T') {
			cout << *a << endl;
			pop_heap(a, last);
			--last;
		}
	}
	return 0;
}
