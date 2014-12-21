#include <cstdio>
#include <cstring> 
#include <algorithm>
using namespace std;
int manacher(const char* s) {
	int len = strlen(s), mx = 0, mid = 1;
	int* p = new int[len];
	p[0] = 1;
	for (int i = 1; i < len; ++i) {
		if (mx > i) p[i] = min(mx - i, p[2 * mid - i]);
		else p[i] = 1;
		while (s[i - p[i]] == s[i + p[i]] && i - p[i] >= 0 && i + p[i] < len)
			++p[i];
		if (p[i] + i > mx) {
			mx = p[i] + i;
			mid = i;
		}
	}
	int r = 0;
	for (int i = 0; i < len; ++i) {
		if (r < p[i]) r = p[i];
	}
	delete []p;
	return r - 1;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char buf[1000005];
		scanf("%s", buf);
		int len = strlen(buf);
		char* s = new char[len * 2 + 2];
		char* cur = s;
		*cur = '#';
		for (int i = 0; i < len; ++i) {
			*(++cur) = buf[i];
			*(++cur) = '#';
		}
		*(cur + 1) = '\0';
		printf("%d\n", manacher(s));
		delete []s;
	}
	return 0;
}
