#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int N = 100005;
const int K = 200005;
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
ll sum[K];
ll a[N];
int n, k;
map<ll, bool> mp;
void cal() {
	ll s = 0;
	int cnt = 0;
	bool begin = true;
	for (int i = 0; i < n; ++i) {
		s = a[i];
		if (mp[s] == false) {
			mp[s] = true;
			if (cnt < k) sum[cnt++] = s;
			else {
				if (begin) {
					make_heap(sum, sum + k, cmp());
					begin = false;
				}
				if (sum[0] < s) {
					pop_heap(sum, sum + k, cmp());
					sum[k-1] = s;
					push_heap(sum, sum + k, cmp());
				}
			}
	   }
	}
	s = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i];
		if (mp[s] == false) {
			mp[s] = true;
			if (cnt < k) sum[cnt++] = s;
			else {
				if (begin) {
					make_heap(sum, sum + k, cmp());
					begin = false;
				}
				if (sum[0] < s) {
					pop_heap(sum, sum + k, cmp());
					sum[k-1] = s;
					push_heap(sum, sum + k, cmp());
				}
			}
		}
		if (s < 0) { s = 0; }
	}
	make_heap(sum, sum + k, cmp());
	cout << sum[0] << endl;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cal();
	system("pause");
	return 0;
}
