#pragma once
#ifndef UTIL_H

template <typename T> class Vector {
	T* arr;                       // integer pointer to vector address
	int cap;                      // capacity of storage
	int cur;                      // current number of items in storage
public:
	Vector();
	void push(T data);
	void push(T data, int index);
	T get(int index);
	void pop() { this->cur--; }
	int size() { return cur;  }
	int getCap() { return cap; }
	void print();
};

#endif // !UTIL_H
