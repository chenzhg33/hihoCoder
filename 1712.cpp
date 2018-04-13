#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[30];
struct cmp {
    bool operator()(string x, string y) {
        int len1 = x.length(), len2 = y.length();
        int minLen = min(len1, len2);

        for (int i = 0; i < minLen; ++i) {
            if (a[x[i]] < a[y[i]]) {
                return true;
            } else if (a[x[i]] > a[y[i]]) {
                return false;
            }
        }

        return x.length() < y.length();
    }
} ;
int main() {
    int n;
    string pattern;
    cin >> n;
    cin >> pattern;

    for (int i = 0; i < pattern.length(); ++i) {
        a[pattern[i]] = i;
    }

    string ss[1010];

    for (int i = 0; i < n; ++i) {
        cin >> ss[i];
    }

    sort(ss, ss + n, cmp());

    for (int i = 0; i < n; ++i) {
        cout << ss[i] <<  endl;
    }

    return 0;
}

