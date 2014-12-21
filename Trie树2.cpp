#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct Node {
	int n;
	Node* leafs[26];
	Node(int n_) : n(n_) { memset(leafs, 0, sizeof(leafs)); }
} head(0);
int insert(const char* s) {
	Node* cur = &head;
	for (int i = 0; s[i] != '\0'; ++i) {
		cur->n++;
		if (cur->leafs[s[i]-'a'] == NULL) {
			cur->leafs[s[i]-'a'] = new Node(0);
		}
		cur = cur->leafs[s[i]-'a'];
	}
	cur->n++;
	return 0;
}

int search(const char* s) {
	Node* cur = &head;
	for (int i = 0; s[i] != '\0'; ++i) {
		if (cur->leafs[s[i]-'a'] == NULL) return 0;
		cur = cur->leafs[s[i]-'a'];
	}
	return cur->n;
}

int main() {
	string s;
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		insert(s.c_str());
	}
	cin >> n;
	while (n--) {
		cin >> s;
		cout << search(s.c_str()) << endl;
	}
	//system("pause");
	return 0;
}
