#ifndef _ABSTRACT_TREE_H
#define _ABSTRACT_TREE_H

#include<vector>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define MAX_DEGREE 2

class AbstractTree {

public:
	AbstractTree(int val, AbstractTree const * par) {
		value = val;
		parent = par;
	}

	int getValue() const {
		return value;
	}

	AbstractTree const * getParent() const {
		return parent;
	}

	int getDegree() const {
		return children.size();
	}

	int getDepth() const {
		if (parent == nullptr) return 0;
		return parent->getDepth() + 1;
	}

	int getHeight() const {
		int maxHeight = 0;
		for (int i = 0; i < children.size(); i++) {
			maxHeight = max(maxHeight, children[i]->getHeight());
		}
		return children.size() == 0 ? 0 : maxHeight + 1;
	}

	AbstractTree* addChild(int value) {
		AbstractTree* subTree = new AbstractTree(value, this);
		children.push_back(subTree);
		return subTree;
	}

	bool removeChild(int index) {
		if (index >= 0 && index < children.size()) {
			/*vector<AbstractTree*>::iterator it = children.begin();
			advance(it, index);
			children.erase(it);*/

			children.erase(children.begin() + index);
			return true;
		}
		return false;
	}

	void print() {
		printWithSpace(0);
	}

	void bfs() {
		queue<AbstractTree*> queue;
		queue.push(this);

		while (!queue.empty()) {
			AbstractTree* currNode = queue.front();
			cout << currNode->getValue() << "->";
			for (int i = 0; i < currNode->children.size(); i++)
				queue.push(currNode->children[i]);
			queue.pop();
		}
		cout << "|" << endl;
	}

	void dfs() {
		stack<AbstractTree*> stack;
		stack.push(this);

		while (!stack.empty()) {
			AbstractTree* currNode = stack.top();
			stack.pop();
			cout << currNode->getValue() << "->";
			for (int i = currNode->children.size() - 1; i >=0; i--)
				stack.push(currNode->children[i]);
		}
		cout << "|" << endl;
	}

	void dfs2() {
		cout << "<" << getValue() << "> ";
		for (int i = children.size() - 1; i >= 0; i--)
			children[i]->dfs2();
		cout << "</" << getValue() << "> ";
	}

private:
	int value;
	vector<AbstractTree*> children;
	AbstractTree const * parent;

	void printWithSpace(int space) {
		for (int i = 0; i < space; i++)
			cout << " ";
		cout << value << "[" << getHeight() << "]" << endl;

		for (int i = 0; i < children.size(); i++)
			children[i]->printWithSpace(space + 2);
	}
};


#endif _ABSTRACT_TREE_H
