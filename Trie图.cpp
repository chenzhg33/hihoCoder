#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
struct Node {
	Node* pre;
	bool is_end;
	Node* leafs[26];
	Node(bool f) : is_end(f), pre(0) { memset(leafs, 0, sizeof(leafs)); }
} head(0);
int insert(const char* s) {
	Node* cur = &head;
	for (int i = 0; s[i] != '\0'; ++i) {
		if (cur->leafs[s[i]-'a'] == NULL) {
			cur->leafs[s[i]-'a'] = new Node(0);
		}
		cur = cur->leafs[s[i]-'a'];
	}
	cur->is_end = true;
	return 0;
}

void build() {
	Node* root = &head;
	root->pre = root;
	Node* cur = 0, * next = 0;
	queue<Node*> que;
	for (int i = 0; i < 26; ++i) {
		if (root->leafs[i]) {
			root->leafs[i]->pre = root;
			que.push(root->leafs[i]);
		} else {
			root->leafs[i] = root;
		}
	}
	while (!que.empty()) {
		cur = que.front();
		que.pop();
		for (int i = 0; i < 26; ++i) {
			next = cur->leafs[i];
			if (!next) {
				cur->leafs[i] = cur->pre->leafs[i];
			} else {
				next->pre = cur->pre->leafs[i];
				if (next->pre->is_end) next->is_end = true;
				que.push(next);
			}
		}
	}
}		

bool search(const char* s) {
	Node* root = &head;
	Node* cur = root;
	Node* pre;
	for (int i = 0; s[i] != '\0'; ++i) {
		cur = cur->leafs[s[i]-'a'];
		if (cur->is_end) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	string s;
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		insert(s.c_str());
	}
	build();
	cin >> s;
	if (search(s.c_str())) cout << "YES" << endl;
	else cout << "NO" << endl;
	//system("pause");
	return 0;
}
