#include<iostream>
#include "BinarySearchTree.h"
using namespace std;


int main() {

	BinarySearchTree root(10);
	root.add(20);
	root.add(15);
	root.add(100);
	root.add(5);
	root.add(1);
	root.add(6);
	root.add(110);

	root.print();

	root.printSorted();

	return 0;
}
