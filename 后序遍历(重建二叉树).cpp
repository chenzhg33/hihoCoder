#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
struct Node {
	char v;
	Node* left;
	Node* right;
	Node(char ch) : v(ch), left(0), right(0) {}
} *rt;

void build(const char* pre, const char* in, int len, Node** root) {
	if (pre == NULL || in == NULL) return;
	if (len == 0) return;
	*root = new Node(*pre);
	const char* p = in;
	int i = 0;
	for (; i < len && *p != *pre; ++i, ++p);
	int left_len = i;
	int right_len = len - i - 1;
	build(pre + 1, in, left_len, &((*root)->left));
	build(pre + left_len + 1, p + 1, right_len, &((*root)->right));
}

void post_order(Node* root) {
	if (root == NULL) return;
	post_order(root->left);
	post_order(root->right);
	cout << root->v;
}

int main() {
	string pre, in;
	cin >> pre >> in;
	build(pre.c_str(), in.c_str(), pre.length(), &rt);
	post_order(rt);
	cout << endl;
	//system("pause");
	return 0;
}
/*
ABDCEF
DBAECF
*/
