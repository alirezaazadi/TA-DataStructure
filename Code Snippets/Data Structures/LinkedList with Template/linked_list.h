#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include<iostream>

using namespace std;

template <typename A>
class LinkedList {
public:
	template <typename B>
	class Node {
	public:
		Node(B = 0, Node* = nullptr);

		B getValue() const;
		Node<B>* getNext() const;
	private:
		B value;
		Node<B>* next;

		friend class LinkedList;
	};

	LinkedList();
	~LinkedList();

	bool pushFront(A);
	A popFront();
	int size();
	bool isEmpty();
	Node<A>* begin() const;
	void print();
private:
	Node<A>* head;
	int length;
};

template <typename A>
template <typename B>
LinkedList<A>::Node<B>::Node(B v, Node<B>* n) :
value(v), next(n) {
}

template <typename A>
template <typename B>
B LinkedList<A>::Node<B>::getValue() const {
	return value;
}

template <typename A>
template <typename B>
typename LinkedList<A>::Node<B>* LinkedList<A>::Node<B>::getNext() const {
	return next;
}

template <typename A>
LinkedList<A>::LinkedList() : head(nullptr), length(0) {
}

template <typename A>
LinkedList<A>::~LinkedList() {
	while (!isEmpty()) popFront();
}

template <typename A>
bool LinkedList<A>::isEmpty() {
	return head == nullptr;
}

template <typename A>
int LinkedList<A>::size() {
	return length;
}

template <typename A>
bool LinkedList<A>::pushFront(A value) {
	Node<A>* newNode = new Node<A>(value, head);
	head = newNode;
	length++;

	return true;
}

template <typename A>
A LinkedList<A>::popFront() {
	if (head == nullptr) return -1;

	A value = head->value;
	Node<A>* temp = head;

	head = head->next;
	delete temp;

	length--;
	return value;
}

template <typename A>
typename LinkedList<A>::Node<A>* LinkedList<A>::begin() const {
	return head;
}

template <typename A>
void LinkedList<A>::print(){
	Node<A>* temp = head;
	while (temp != nullptr) {
		cout << temp->value << "->";
		temp = temp->next;
	}
	cout << endl;
}

#endif