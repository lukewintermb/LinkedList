/*
*  Title: LinkedList
*  Abstract: Implements a Linked List with methods and the big 3
*  Author: Luke Winter
*  Email: lwinter@csumb.edu
*  Estimate: 4 hours
*  Date: 12/6/2022
*/

/**
This is base code for Project 2 for CST238 Fall 2020
This file DOES need to be modified and handed in
ONLY RECURSION can be used; any iteration will result
in a zero for the assignment
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;
/**
* Implement these functions IN ORDER
*/

// implement these two first
bool Node::hasNext() const {
    return myNext != nullptr;
}

bool LinkedList::empty() const {
    return myFirst == nullptr;
}

// then these two
void Node::display() const {
	if(!hasNext()){
		cout << myData << "\n";
		return;
	}else{
		cout << myData << " ";
		myNext -> display();
	}
}

void LinkedList::display() const {
	if(empty()){
		cout << "Empty!" << "\n";
		return;
	}
	myFirst -> display();
}

// then these two
// only append if this is the last node
// otherwise, recurse
void Node::append(int data) {
    if(!hasNext()){
		 this -> setNext(new Node(data));
	}else{
		myNext -> append(data);
	}
}

void LinkedList::append(int data) {
    // this won't work after the first time!
	if(empty()){
		myFirst = new Node(data);
	}else{
		myFirst -> append(data);
	}
}

// then these two
bool Node::search(int data) const {
    if(myData == data){
		return true;
	}else if(!hasNext()){
		return false;
	}else{
		return myNext -> search(data);
	}
}

bool LinkedList::search(int data) const {
    if(empty()){
		return false;
	}else{
		return myFirst -> search(data);
	}
}

// then these two
bool Node::insertAfter(int oldData, int newData) {
    if(myData == oldData){
		Node * temp = myNext;
		this -> setNext(new Node(newData));
		myNext -> setNext(temp);
		return true;
	}else if(myNext == nullptr){
		return false;
	}else{
		return myNext -> insertAfter(oldData, newData);
	}
}

bool LinkedList::insertAfter(int oldData, int newData) {
    if(empty()){
		return false;
	}else{
		return myFirst -> insertAfter(oldData, newData);
	}
}

// then these two
bool Node::removeNext(int data) {
    if(myNext -> getData() == data){
		Node * temp = myNext;
		myNext = myNext -> myNext;
		temp -> myNext = nullptr;
		delete temp;
		return true;
	}else if(!myNext -> hasNext()){
		return false;
	}else{
		return myNext -> removeNext(data);
	}
}

bool LinkedList::remove(int data) {
    if(myFirst -> myData == data){
		myFirst = myFirst -> getNext();
		return true;
	}else{
		return myFirst -> removeNext(data);
	}
}

// then these two
Node::~Node() {
	// cout << "Deleting ";
	delete myNext;
}

LinkedList::~LinkedList() {
	// cout << "Deleting ";
	delete myFirst;
	myFirst = nullptr;
}

// then these two
Node::Node(const Node & source) {
	if(source.myNext == nullptr){
		myData = source.myData;
		myNext = nullptr;
		return;
	}else{
		myData = source.myData;
		myNext = new Node(*source.myNext);
	}
}

LinkedList::LinkedList(const LinkedList & source) {
	if(source.myFirst == nullptr){
		myFirst = nullptr;
	}else{
		myFirst = new Node(*source.myFirst);
	}
}

// then this one
LinkedList &LinkedList::operator=(const LinkedList & source) {
	if(source.myFirst == nullptr){
		myFirst = nullptr;
	}else{
		myFirst = new Node(*source.myFirst);
	}	
    return * this;
}

/**
* Implement the functions above, shouldn't need to change anything below,
but look at this for good examples!
*/

Node::Node(int data) {
    myData = data;
}

void Node::setNext(Node * next) {
    myNext = next;
}

LinkedList::LinkedList() {
    myFirst = nullptr; 
}

