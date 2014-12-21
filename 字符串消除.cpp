#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
char ABC[4] = "ABC";
int cal(char* s) {
	int len = strlen(s);
	if (len == 1) return 1;
	bool flag[105], finish = true;
	memset(flag, 0, sizeof(flag));
	char r[105];
	for (int i = 1; i < len; ++i) {
		if (s[i] == s[i-1]) {
			finish = false;
			flag[i] = flag[i-1] = true;
		}
	}
	if (finish) return len;
	int cnt = 0, k = 0;
	while (s[k] != '\0') {
		if (!flag[k]) r[cnt++] = s[k];
		k++;
	}
	r[cnt] = '\0';
	return cal(r);
}
int slove(char* s) {
	int len = strlen(s);
	if (len == 1) return 0;
	char tmp[105];
	int m = 10000;
	for (int i = 0; i < 3; ++i) {
		tmp[0] = ABC[i];
		memcpy(tmp + 1, s, len + 1);
		m = min(cal(tmp), m);
	}
	for (int i = 0; i < 3; ++i) {
		memcpy(tmp, s, len);
		tmp[len] = ABC[i];
		tmp[len+1] = '\0';
		m = min(cal(tmp), m);
	}
	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < 3; ++j) {
			memcpy(tmp, s, i + 1);
			tmp[i+1] = ABC[j];
			memcpy(tmp + i + 2, s + i + 1, len - i);
			tmp[len + 1] = '\0';
			m = min(cal(tmp), m);
		}
	}
	return m;
}

int main() {
	char s[105];
	int n;
	cin >> n;
	while(n--){
		cin >> s;
		cout << strlen(s) - slove(s) + 1 << endl;
	}
	//system("pause");
	return 0;
}
