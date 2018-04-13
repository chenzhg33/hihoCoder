#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#define MAX 30
typedef long long ll;
using namespace std;

int a[MAX][MAX];
int zero, n, m;
ll cnt;
map<string, ll> mp;

string h() {
    string s;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s += (a[i][j] + '0');
        }
    }

    return s;
}

ll  dfs(int d) {
    if (d == zero) {
        //cout << endl;
        return 1;
    }

    string s = h();

    if (mp[s] != 0) {
        return mp[s];
    }

    ll tmp = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 0) {
                if (a[i][j - 1] == 1 || a[i + 1][j] == 1 || a[i - 1][j] == 1 || a[i + 1][j] == 1) {
                    //cout << i << ' ' << j << endl;
                    a[i][j] = 1;
                    tmp += dfs(d + 1);
                    a[i][j] = 0;
                }
            }
        }
    }

    mp[s] = tmp;
    return tmp;
}

int main() {

    while (cin >> n >> m) {
        int  one = 0;
        cnt = 0;
        string s;
        mp.clear();
        memset(a, 0, MAX * MAX);

        for (int i = 1; i <= n; ++i) {
            cin >> s;

            for (int j = 1; j <= m; ++j) {
                a[i][j] = s[j - 1] - '0';
                one += a[i][j];
            }
        }

        zero = n * m - one;

        if (zero == 0) {
            cout << 0 << endl;
        } else {
            cout << dfs(1) << endl;
        }
    }

    return 0;
}

