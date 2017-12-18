#ifndef HEAP_H
#define HEAP_H

using namespace std;

#include <algorithm>    
#include <iostream>
#include <cmath>
#include <stddef.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>

class Heap{
	private:
		int heap_size;
		int maxHeap[1000];
	public:
		Heap();
		Heap(vector<int> &bids, int size);
		int getSize();
		void heapify(int i);
		void buildHeap();
		int extractMax();
		int getKey(int i);
		void increaseKey(int i, int key);
		void insert(int key);
};

#endif