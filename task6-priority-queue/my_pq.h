#ifndef MY_PQ_H
#define MY_PQ_H

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class My_PQ{
	int H[50];
	int s = -1;
	int extractMax();
	void shiftUp(int i);
	void shiftDown(int i);
	void insert(int p);
	void changePriority(int i, int p);
	int getMax();
	void remove(int i);
	//int get_h();



public:
    My_PQ(){}
    
    My_PQ(vector<int> arr){}

	int * get_h(){
		return H;
	}
    
	int get_size() {
		return s+1;
	}

	int extract_max(){
		return extractMax();
	}

    void change_priority(int index, int new_priority){
		 changePriority(index, new_priority);
	}

    int peek(){
		return getMax();
	}

    void add(int value){
		insert(value);
	} 

    void deleteE(int index){
		remove(index);
	}

};


int parent(int i)
{

	return (i - 1) / 2;
}

// this function used to return the index of the left child of the given node
int leftChild(int i)
{

	return ((2 * i) + 1);
}

//this function used to return the index of the
// right child of the given node
int rightChild(int i)
{

	return ((2 * i) + 2);
}

//this function used to shift up the node in order to maintain the heap property
void My_PQ::shiftUp(int i)
{
	while (i > 0 && H[parent(i)] < H[i]) {
		swap(H[parent(i)], H[i]);
		i = parent(i);
	}
}

//this function used to shift down the node in order to maintain the heap property
void My_PQ::shiftDown(int i)
{
	int maxIndex = i;

	// Left Child
	int l = leftChild(i);

	if (l <= s && H[l] > H[maxIndex]) {
		maxIndex = l;
	}

	// Right Child
	int r = rightChild(i);

	if (r <= s && H[r] > H[maxIndex]) {
		maxIndex = r;
	}

	// If i not same as maxIndex
	if (i != maxIndex) {
		swap(H[i], H[maxIndex]);
		shiftDown(maxIndex);
	}
}

//this function used to insert a new element in the Binary Heap
void My_PQ::insert(int p)
{
	s = s + 1;
	H[s] = p;

	// Shift Up to maintain heap property
	shiftUp(s);
}

//this function used to extract the element with maximum priority
int My_PQ::extractMax()
{
	int result = H[0];

	// Replace the value at the root with the last leaf
	H[0] = H[s];
	s = s - 1;

	// Shift down the replaced element to maintain the heap property
	shiftDown(0);
	return result;
}

//this function used to change the priority of an element
void My_PQ::changePriority(int i, int p)
{
	int oldp = H[i];
	H[i] = p;

	if (p > oldp) {
		shiftUp(i);
	}
	else {
		shiftDown(i);
	}
}

//this function used to get value of the current maximum element
int My_PQ::getMax()
{
	return H[0];
}

//this function used to remove the element located at given index
void My_PQ::remove(int i)
{
	H[i] = getMax() + 1;
	shiftUp(i);
	extractMax();
}

#endif