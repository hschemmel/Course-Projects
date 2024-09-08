/* 
Programming Assignment #6
Filename: queue.h
*/

#include <iostream>
using namespace std;

template<class T>
class QuickQueue 
{
	private:
		// Indicates you need rule of 3
		T** array;
		int capacity, size;
		
	public:
		// default constructor
		QuickQueue();
		
		// copy constructor
		QuickQueue(const QuickQueue<T>& q);
		
		// destructor
		~QuickQueue();
		
		// deep copy assignment operator overload
		QuickQueue<T>& operator=(const QuickQueue<T>& q);

		// Enqueue -- adds an element to the queue
		// Don't want to return anything
		void Enqueue(const T& item);
		
		// Dequeue -- removes an element from the queue and returns it to the caller
		T* Dequeue();
};

#include "queue.hpp"