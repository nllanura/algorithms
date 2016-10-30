#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
	int value;
	Node* left;
	Node* right;

	Node() {
		value = 0;
		left = NULL;
		right = NULL;
	}

};

void visit(Node* node) {
	cout << node->value << " ";
}

void in_order(Node* root) {
	if(root) {
		in_order(root->left);
		visit(root);
		in_order(root->right);
	}
}

void pre_order(Node* root) {
	if(root) {
		visit(root);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void post_order(Node* root) {
	if(root) {
		post_order(root->left);
		post_order(root->right);
		visit(root);
	}
}

Node* bfs(Node* root, int value) {
	queue<Node*> queue;
	queue.push(root);
	
	while(!queue.empty()) {
		Node* temp = queue.front();
		queue.pop();
		visit(temp);
		if(temp->value == value) 
			return temp;
		if(temp->left) 
			queue.push(temp->left);
		if(temp->right) 
			queue.push(temp->right);
	}
	return NULL;
}

Node* dfs(Node* root, int value) {
	stack<Node*> stack;
	stack.push(root);

	while(!stack.empty()) {
		Node* temp = stack.top();
		stack.pop();
		visit(temp);
		if(temp->value == value)
			return temp;
		if(temp->left)
			stack.push(temp->left);
		if(temp->right)
			stack.push(temp->right);
	}
	return NULL;
}

int main() {
	Node root;
	Node a, b, c, d, e, f, g;

	root.value = 8;
	a.value = 3;
	b.value = 6;
	c.value = 9;
	d.value = 69;
	e.value = 420;
	f.value = 666;
	g.value = 6969;

	root.left = &d;
	root.right = &e;
	d.left = &b;
	d.right = &g;
	g.left = &f;
	e.right = &a;
	a.left = &c;

	in_order(&root);
	cout << endl;
	pre_order(&root);
	cout << endl;
	post_order(&root);
	cout << endl;
	cout << endl;

	cout << dfs(&root, 9)->value << endl;
	cout << bfs(&root, 9)->value << endl;

	return 0;
}
