#include <iostream>
#include <string>
using namespace std;

int next[10000];

int calNext(string& s) {
	next[0] = 0;
	int k = 0;
	int len = s.length();
	for (int i = 1; i < len; ++i) {
		while (k > 0 && s[i] != s[k]) {
			k = next[k-1];
		}
		if (s[i] == s[k])
			++k;
		next[i] = k;
	}
}
int kmp(string& s1, string& s2) {
	int len1 = s1.length();
	int len2 = s2.length();
	int sum = 0;
	int k = 0;
	for (int i = 0; i < len1; ++i) {
		while (k > 0 && s1[i] != s2[k]) {
			k = next[k-1];
		}
		if (s1[i] == s2[k])
			++k;
		if (k == len2) {
			++sum;
			k = next[k-1];
		}
	}
	return sum;
}
int main() {
	string s1, s2;
	int n;
	cin >> n;
	while (n--) {
		cin >> s1 >> s2;
		calNext(s1);
		cout << kmp(s2, s1) << endl;
	}
	system("pause");
	return 0;
}

