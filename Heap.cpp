#include "Heap.h"
//<------------------------Constructors------------------------>
//The default constructor function for the maximum heap structure. It only initializes heap size as 0.
Heap::Heap(){
    heap_size = 0;
}

//The constructor function for the maximum heap structure. It gets bids vector that stores bids values in bids.txt file.
Heap::Heap(vector<int> &bids, int size){
    heap_size = 0;
    for (int i = 1; i <= size; i++){
        maxHeap[i] = bids[i-1];
        heap_size++;
    }
}

//<------------------------Getter Methods------------------------>
//It gets index value as a parameter and returns key value of the entered index value in heap structure.
int Heap::getKey(int i){
    return maxHeap[i];
}

//Returns the current heap size as an integer value.
int Heap::getSize(){
    return heap_size;
}

//Firstly, the extractMax function checks whether or not the heap size is less than 1. If our maximum heap vector’s size is less than 1, this function terminates the program. 
//It is required to prevent from underflow.
//If underflow does not occur, it gets element from maximum heap at the first index,
//then decrease the size of heap and calls heapify function and sends first index as an argument.
int Heap::extractMax(){
    if (heap_size < 1){
        cout << "Heap underflow" << endl;
        exit(0);
    }
    int max = maxHeap[1];
    maxHeap[1] = maxHeap[heap_size];
    heap_size--;
    heapify(1);
    return max;
}

//It gets an index value as an integer.  Then it starts to check left and right subtrees of the entered index if any of the child is not in the appropriate locations 
//(which is not ensures the max heap structure). It swaps nodes and makes a recursive call from largest index and it will be iterated until algorithm ensures that max heap structure provided.
//When heapify is called, its running time depends on how far an element can be move down in tree before the termination. In the worst case, the element should move down all the way up.
void Heap::heapify(int i) {
    int lChild = 2*i;
    int rChild = 2*i + 1;
    int largest = i;

    if ((lChild <= heap_size) && (maxHeap[lChild] > maxHeap[i]))
        largest = lChild;
    else 
        largest = i;
    
    if ((rChild <= heap_size) && (maxHeap[rChild] > maxHeap[largest]))
        largest = rChild;
    
    if (largest != i) {
        swap(maxHeap[i], maxHeap[largest]);
        heapify(largest);
    }
}

//It basically calls heapify function size of heap over two times. It’s running time is O(logN) times N/2 equals to O(N/2 * logN) which correspons to O(NlogN).
void Heap::buildHeap() {
    int n = heap_size;
    for (int i = floor(n / 2); i >= 1; i--)
        heapify(i);
}


void Heap::increaseKey(int i, int key){
    maxHeap[i] = key;
    while ((i > key) && maxHeap[i/2] < maxHeap[i]){
        swap(maxHeap[i], maxHeap[i/2]);
        i /= 2;
    }
}


//It gets the key value as an integer parameter, increases heap size and defines last index of max heap as 0. 
//Then calls increase key function and sends last index and key as parameters.
void Heap::insert(int key){
    heap_size++;
    maxHeap[heap_size] = 0;
    increaseKey(heap_size, key);
}