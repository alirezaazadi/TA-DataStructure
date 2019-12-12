#include<iostream>
#include "linked_list.h"

using namespace std;

int main() {

	LinkedList<int> ll1;
	ll1.pushFront(10);
	ll1.pushFront(20);
	ll1.pushFront(30);
	ll1.pushFront(40);
	ll1.pushFront(50);
	ll1.print();
	ll1.popFront();
	ll1.popFront();
	ll1.print();

	LinkedList<char> ll2;
	ll2.pushFront('A');
	ll2.pushFront('B');
	ll2.pushFront('C');
	ll2.pushFront('D');
	ll2.pushFront('E');
	ll2.print();
	ll2.popFront();
	ll2.popFront();
	ll2.print();

	return 0;
}