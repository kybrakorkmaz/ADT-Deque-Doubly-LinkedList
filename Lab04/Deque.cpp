#include "Deque.h"
#include<iostream>
/*
* @author Kubra Korkmaz
* @date 16.08.2022
*/
///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	head = tail = NULL;
	noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	tail = NULL;
	while (head != NULL) {//deleting nodes step by step
		DequeNode* tmp = head;
		head = head->next;
		delete(tmp);
	}
	noOfItems = 0;
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	DequeNode* node = new DequeNode(item); //create new node
	if (node == NULL) throw std::exception("Overflow---AddFront()\n");
	else {
		if (head == NULL) head = tail = node; //insert fist item to front
		else { //insert new item to front of list
			node->next = head;               
			head->prev = node;
			head = node;
		}
		//increase no of items
		noOfItems++;
	}
} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	DequeNode* node = new DequeNode(item); //create new node
	if (node == NULL) throw std::exception("Overflow---AddRear()\n");
	else {
		if (tail == NULL) head = tail = node; //insert fisrt item to rear
		else {//insert new item to rear of list
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
		//increase no of items
		noOfItems++;
	}
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	int value = 0;
	if (IsEmpty()) throw std::exception("Underflow---RemoveFront()\n");
	else {
		value = head->item; //get the value will be removed from list
		DequeNode* tmp = head;  
		head = head->next;  //removing
		if (head == NULL) tail = NULL;
		else { head->prev = NULL; }
		delete(tmp); 
		noOfItems--;		
	}
	//return removed value from list
	return value;
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	int value = 0;
	if (IsEmpty()) throw std::exception("Underflow---RemoveRear()\n");
	else {
		value = tail->item; //get the value will be removed from list
		DequeNode* tmp = tail;
		tail = tail->prev;  //removing
		if (tail == NULL) head = NULL;
		else { tail->next = NULL; }
		delete tmp;
		noOfItems--;		
	}
	//return removed value from list
	return value;
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	if (IsEmpty()) throw std::exception("Underflow---Front()\n");
	return head->item;
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	if (IsEmpty()) throw std::exception("Underflow---Rear()\n");
	return tail->item;
} //end-Rear
