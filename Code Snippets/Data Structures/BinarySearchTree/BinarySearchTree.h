#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include<iostream>
#include<stack>
using namespace std;

class BinarySearchTree {

public:
	BinarySearchTree(int val) :
		left(nullptr),
		right(nullptr),
		parent(nullptr),
		value(val) {
	}

	bool add(int val) {
		BinarySearchTree* currNode = searchNode(val);
		if (currNode->value == val) {
			return false;
		}
		else {
			BinarySearchTree* newNode = new BinarySearchTree(val);
			newNode->parent = currNode;
			if (val > currNode->value) currNode->right = newNode;
			else currNode->left = newNode;

			return true;
		}
	}

	bool remove(int val) {
		BinarySearchTree* currNode = searchNode(val);
		if (currNode->value == val) {
			// check leaf
			if (currNode->left == nullptr && currNode->right == nullptr) {
				currNode->removeFromParent();
			}
			else if (currNode->left != nullptr && currNode->right != nullptr) {
				BinarySearchTree* rightMostNodeOfLeftChild = currNode->left->findRightmostNode();
				currNode->value = rightMostNodeOfLeftChild->value;

				rightMostNodeOfLeftChild->removeFromParent();
			}
			else {
				currNode->removeFromParent();
			}
			return true;
		}
		else {
			return false;
		}
	}

	int findMin(int i) {
		int leftChilds = left == nullptr ? 0 : left->countChildren();
		int rightChilds = right == nullptr ? 0 : right->countChildren();

		if (i <= leftChilds) return left->findMin(i);
		if (i > leftChilds + 1 && right != nullptr) return right->findMin(i - leftChilds - 1);
		return value;

	}

	bool search(int val) {
		BinarySearchTree* node = searchNode(val);
		return node->value == val;
	}

	void print() {
		cout << value << " [" << (left == nullptr ? 0 : left->value) << ", " << (right == nullptr ? 0 : right->value) << "]" << endl;
		if (left != nullptr) left->print();
		if (right != nullptr) right->print();
	}

	int front() {
		return findLeftmostNode()->value;
	}

	int back() {
		return findRightmostNode()->value;
	}

	void printSorted() {
		inOrder();
		cout << endl;
	}

private:
	BinarySearchTree *left, *right, *parent;
	int value;

	BinarySearchTree* searchNode(int val) {
		if (value == val) return this;
		if (val > value) {
			if (right != nullptr) return right->searchNode(val);
			return this;
		}
		else {
			if (left != nullptr) return left->searchNode(val);
			return this;
		}
	}

	BinarySearchTree* findRightmostNode() {
		if (right == nullptr) return this;

		BinarySearchTree* temp = right;
		while (temp->right != nullptr) temp = temp->right;
		return temp;
	}


	BinarySearchTree* findLeftmostNode() {
		if (left == nullptr) return this;

		BinarySearchTree* temp = left;
		while (temp->left != nullptr) temp = temp->left;
		return temp;
	}

	void removeFromParent() {
		if (parent == nullptr) return;

		if (value > parent->value) {
			if (left != nullptr) {
				parent->right = left;
				left->parent = parent;
			}
			else if (right != nullptr) {
				parent->right = right;
				right->parent = parent;
			}
			else {
				parent->right = nullptr;
			}
			delete parent->right;
		}
		else {
			if (left != nullptr) {
				parent->left = left;
				left->parent = parent;
			}
			else if (right != nullptr) {
				parent->left = right;
				right->parent = parent;
			}
			else {
				parent->left = nullptr;
			}
			delete parent->left;
		}
	}

	int countChildren() {
		stack<BinarySearchTree*> stack;
		stack.push(this);

		int counter = 0;
		while (!stack.empty()) {
			BinarySearchTree* node = stack.top();
			stack.pop();
			counter++;

			if (node->left != nullptr) stack.push(node->left);
			if (node->right != nullptr) stack.push(node->right);
		}
		return counter;
	}

	void inOrder() {
		if (left != nullptr) left->inOrder();
		cout << value << " ";
		if (right != nullptr) right->inOrder();
	}
};

#endif
