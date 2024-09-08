/* 
Programming Assignment #6
Filename: queue.hpp
*/

// Default constructor- initializing everything
template <class T>
QuickQueue<T>::QuickQueue() {
	size = 0;
	capacity = 4;
	array = new T*[capacity];
}

// Copy constructor
template <class T>
QuickQueue<T>::QuickQueue(const QuickQueue<T>& q) {
	size = q.size;
	capacity = q.capacity;
	
	// Makes a new array of T pointers on the heap
	array = new T*[capacity];
	
	for (int i = 0; i < size; i++) {
		// dynamically allocates the result of dereferencing q.array[i] and stores the address in the pointer at array[i]
		array[i] = new T(*q.array[i]);
	}
}

// Destructor
template <class T>
QuickQueue<T>::~QuickQueue() {
	// deallocating everything within the array and the array itself
	for (int i = 0; i < size; i++) {
		if (array[i] != nullptr) {
			delete array[i];
		}
	}
	
	delete [] array;
}

// Deep copy assignment operator overload
template <class T>
QuickQueue<T>& QuickQueue<T>::operator=(const QuickQueue<T>& q) {
	if (this != &q) {
		size = q.size;
		capacity = q.capacity;
	
		// deallocating everything within the old array and the old array itself
		for (int i = 0; i < size; i++) {
			if (array[i] != nullptr) {
				delete array[i];
			}
		}
		delete [] array;
		
		// Makes a new array of T pointers on the heap
		array = new T*[capacity];
		
		for (int i = 0; i < size; i++) {
			// dynamically allocates the result of dereferencing q.array[i] and stores the address in the pointer at array[i]
			array[i] = new T(*q.array[i]);
		}
	}
		
	return *this;
}

// Enqueue -- adds an element to the queue (to the "back of the line")
template <class T>
void QuickQueue<T>::Enqueue(const T& item) {
	if (size >= capacity) {
		capacity += 5;
		
		// Makes a new array of T pointers on the heap
		T** temp = new T*[capacity];
		
		for (int i = 0; i < size; i++) {
			// dynamically allocates the result of dereferencing array[i] and stores the address in the pointer at temp[i]
			temp[i] = new T(*array[i]);
		}
		
		// deallocating everything within the old array and the old array itself
		for (int i = 0; i < size; i++) {
			if (array[i] != nullptr) {
				delete array[i];
			}
		}
		delete [] array;
		
		array = temp;
	}
	// dynamically allocates the item passed in and stores the address in the pointer at array[i]
	array[size++] = new T(item);
}

// Dequeue -- removes an element from the queue (from the "front of the line") and returns it to the caller
template <class T>
T* QuickQueue<T>::Dequeue() {
	if (size > 0) {
		// stores the item from the "front of the line"
		T* temp = array[0];
		
		// shifts everything in the array over by one
		for (int i = 0; i < size - 1; i++) {
			array[i] = array[i+1];
		}
		
		// decrementing size because removed an item from the queue
		size--;
		return temp;
	}
	
	// Best option if no elements in the array to return:
	return nullptr;
}