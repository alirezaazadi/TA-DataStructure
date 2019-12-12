#include<iostream>
#include<vector>
#include "LinkedList.h"
#include "AbstractTree.h"
using namespace std;


int main() {

	AbstractTree* root = new AbstractTree(10, nullptr);

	AbstractTree* rootChild1 = root->addChild(20);
	AbstractTree* Child1Child1 = rootChild1->addChild(50);
	AbstractTree* Child1Child2 = rootChild1->addChild(60);
	AbstractTree* Child1Child3 = rootChild1->addChild(70);

	AbstractTree* rootChild2 = root->addChild(30);
	AbstractTree* Child2Child1 = rootChild2->addChild(80);
	AbstractTree* Child2Child2 = rootChild2->addChild(90);

	AbstractTree* rootChild3 = root->addChild(40);

	root->print();
	root->bfs();
	root->dfs();
	root->dfs2();

	return 0;
}
