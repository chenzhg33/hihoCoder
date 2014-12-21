#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char s[1004];
int r[1004];
int Find(int i) {
	return i == r[i] ? i : r[i] = Find(r[i]);
}
void Union(int i, int j) {
	int a = Find(i), b = Find(j);
	if (a < b) r[b] = a;
	else r[a] = b;
}
void cal(int len, int k) {
	if (k <= 0) return;
	int mid = k * 2 - len;
	if (mid <= 0) {
		for (int i = 0; i < k; ++i) Union(i, i + len - k);
		return;
	} else {
		for (int i = 0; i < len - k; ++i) Union(i, i + k);
	}
	cal(k, mid);
}
int main() {
	int T, k;
	cin >> T;
	while (T--) {
		cin >> s >> k;
		int len = strlen(s);
		for (int i = 0; i < len; ++i) r[i] = i;
		cal(len, k);
		vector<int> vec[501];
		//for (int i = 0; i < 500; ++i) vec[i].clear();
		for (int i = 0; i < len; ++i) {
			vec[Find(i)].push_back(i);
		}
		int sum = 0;
		for (int i = 0; i < len / 2; ++i) {
			if (vec[i].size() > 1) {
				vector<char> vectmp;
				vector<int>::iterator it = vec[i].begin();
				for (; it != vec[i].end(); ++it) vectmp.push_back(s[*it]);
				sort(vectmp.begin(), vectmp.end());
				vector<char>::iterator it2 = vectmp.begin();
				char last = 0;
				int cnt = 1, mx = -10;
				for (; it2 != vectmp.end(); ++it2) {
					if (last == *it2) ++cnt;
					else { last = *it2; mx = max(cnt, mx); cnt = 1; }
				}
				mx = max(cnt, mx);
				//cout << "mx: " << mx << endl;
				sum += (vec[i].size() - mx);
			}
		}
		cout << sum << endl;
	}
	//system("pause");
	return 0;
}
