#include "Heap.h"

/*
How To Compile?
--Just copy the commands below. Then paste and press enter. Everything should works fine!

g++ -c Heap.cpp -o Heap.o
g++ -c main.cpp -o main.o
g++ main.o Heap.o -o main
./main 0.25 10000

Tested in
g++ version: 4.9.2 (windows 10)
g++ version: 4.8.5 - ITU SSH
*/

void setVector(vector<int> &tmpBids);
void simulation(vector<int> &tmpBids, float p, int m);

int main(int argc, char* argv[]){

	float p = atof(argv[1]);
	int m 	= atoi(argv[2]);
	// int bids[100000];
	vector<int> bids;
	setVector(bids);

	clock_t t = clock();
	simulation(bids, p, m);
	t = clock() - t;
	// printf("%d",bids.at(2));
	
	printf ("\nIt took me %f miliseconds.\n",((float)t)/CLOCKS_PER_SEC*1000);
    return 0;
}

// Just gets data line by line
// And appends it to bids vector
void setVector(vector<int> &tmpBids){
	string line;
    ifstream FILE ("bids.txt");
    int n; // tmp value
    int counter = 0;
    if (FILE.is_open()){
    	for (int i=0; i < 100000; ++i){
    		getline(FILE, line,'\n');
            istringstream ss(line);
            ss >> n; // the most useful way to convert string to int
            tmpBids.push_back(n);
        }
    }
   	FILE.close();
}

void simulation(vector<int> &tmpBids, float p, int m){
	int counter = 0;
	int bidCounter = 1;
	int max;
	int r;
	Heap myHeap;

	if (m < 100){
		cout << "Please enter a number which is bigger than 100" << endl; return;
	}
	// Maximum bid is removed after every 100 bids.
	for (int i = 0; i < 100; i++){
		myHeap.insert(tmpBids.at(counter));
	}	
	myHeap.buildHeap();

	while(counter <= m){
		if(myHeap.getSize() == 100){
			int maxValue = myHeap.extractMax();
			cout << bidCounter << ". Winner: " <<  maxValue << endl;
			counter++;
			bidCounter++;
		}
		else{
			myHeap.insert(tmpBids.at(counter));
			for (int i = 1; i < 100; i++){
				r = rand()%101;
				int bid = myHeap.getKey(i);
				if (r < p * 100){
					myHeap.increaseKey(i, bid+=bid*0.25); 
					// in hw description, expected increment key is 0.25. For this reason bid+=bid*0,25
					counter++;
				}
				else
					myHeap.increaseKey(i, tmpBids.at(counter));
			}
		}
	}
}