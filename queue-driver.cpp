/* 
Programming Assignment #6
Filename: queue-driver.cpp
*/

#include "queue.h"

int main() {
	QuickQueue<int> qi1, qi2;
	QuickQueue<double> qd4;
	
	cout << "Adding 5 elements to the qi1 Queue" << endl;
	qi1.Enqueue(1);
	qi1.Enqueue(2);
	qi1.Enqueue(3);
	qi1.Enqueue(4);
	qi1.Enqueue(5);
	
	cout << "Adding 5 elements to the qd4 Queue" << endl;
	qd4.Enqueue(1.2);
	qd4.Enqueue(2.3);
	qd4.Enqueue(3.4);
	qd4.Enqueue(4.5);
	qd4.Enqueue(5.6);
	
	cout << "Using the deep copy assignment operator overload to copy everything from qi1 into qi2" << endl;
	qi2 = qi1;
	
	cout << "Using the copy constructor to copy everything from qi2 into qi3" << endl;
	QuickQueue<int> qi3 = qi2;
	
	cout << "qi1: " << endl;
	// creates an int pointer called nextInt that stores the pointer that Dequeue() returns 
	int* nextInt = qi1.Dequeue();
	int counter = 0;
	
	// cycles through the array while there are still items in the array
	while(nextInt != nullptr) {
		// increments the counter by 1 for each additional item and dereferences nextInt
		cout << ++counter <<": " << *nextInt << endl;
		nextInt = qi1.Dequeue();
	}
	
	// Doing the same as above for qi2, qi3, and qd4
	
	cout << "qi2: " << endl;
	nextInt = qi2.Dequeue();
	counter = 0;
	
	while(nextInt != nullptr) {
		cout << ++counter <<": " << *nextInt << endl;
		nextInt = qi2.Dequeue();
	}
	
	cout << "qi3: " << endl;
	nextInt = qi3.Dequeue();
	counter = 0;
	
	while(nextInt != nullptr) {
		cout << ++counter <<": " << *nextInt << endl;
		nextInt = qi3.Dequeue();
	}
	
	cout << "qd4: " << endl;
	double* nextDouble = qd4.Dequeue();
	counter = 0;
	
	while(nextDouble != nullptr) {
		cout << ++counter <<": " << *nextDouble << endl;
		nextDouble = qd4.Dequeue();
	}
	
	cout << "Confirming all 4 queues are empty now" << endl;
	cout << qi1.Dequeue() << endl;
	cout << qi2.Dequeue() << endl;
	cout << qi3.Dequeue() << endl;
	cout << qd4.Dequeue() << endl;
}