#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct Node {
	int n;
	Node* leafs[26];
	Node(int n_) : n(n_) { memset(leafs, 0, sizeof(leafs)); }
};

void insert(Node** head, const char* s, int len) {
	//为0的时候，表示空串，根节点n记录所有的单词个数
	if (len == 0) {
		if (*head == NULL)
			*head = new Node(1);
		else
			(*head)->n++;
		return;
	}
	if (*head == NULL) {
		*head = new Node(1);
	} else
		(*head)->n++;
	insert(&(*head)->leafs[*s - 'a'], s + 1, len - 1);
}
int search(Node* head, const char* s, int len) {
	if (len == 0) {
		if (head == NULL)
			return 0;
		else
			return head->n;
	}
	if (head == NULL)
		return 0;
	return search(head->leafs[*s - 'a'], s + 1, len - 1);
}

int main() {
	string s;
	int n;
	cin >> n;
	Node* head = 0;
	while (n--) {
		cin >> s;
		insert(&head, s.c_str(), s.length());
	}
	cin >> n;
	while (n--) {
		cin >> s;
		cout << search(head, s.c_str(), s.length()) << endl;
	}
	//system("pause");
	return 0;
}
