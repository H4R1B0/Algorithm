#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 10001
#define INF 987654321

struct Node {
	int data;
	Node* left;
	Node* right;
};

int xd[4] = { 0,0,1,-1 };
int yd[4] = { 1,-1,0,0 };

int T;
int N, M;

Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

void postorder(Node* node) {
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	cout << node->data << endl;
}

int main() {
	Node* root = NULL;
	int val;
	while (cin >> val) {
		if (val == EOF)
			break;
		root = insert(root, val);
	}
	postorder(root);
}