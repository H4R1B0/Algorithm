#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define endl '\n'
#define MAX 2000+1
#define INF 1e16
#define ll long long

//int xd[4] = { 0,-1,0,1 };
//int yd[4] = { 1,0,-1,0 };
int xd[] = { 0,-1,0,1,1,1,-1,-1 };
int yd[] = { 1,0,-1,0,1,-1,1,-1 };

int N, M;

void postorder(string preorder, string inorder) {
	if (!preorder.size())
		return;
	int num = preorder.size();
	char root = preorder[0];
	int left = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	int right = num - left - 1;
	postorder(preorder.substr(1, left), inorder.substr(0, left));
	postorder(preorder.substr(left+1, num), inorder.substr(left+1, num));
	cout << root;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string preorder = "", inorder = "";
		cin >> preorder >> inorder;
		if (!preorder.length())
			break;
		postorder(preorder, inorder);
		cout << endl;
	}
}