//  globals
#include <iostream>
//  internals
#include "Util.h"

template <typename T> Vector<T>::Vector() {
	this->arr = new T[1];
	this->cap = 1;
	this->cur = 0;
}

template <typename T> void Vector<T>::push(T data) {
	if (this->cur == this->cap) {
		T* temp = new T[2 * cap];

		for (int i = 0; i < this->cap; i++) {
			temp[i] = this->arr[i];
		}

		delete[] this->arr;
		this->cap *= 2;
		this->arr = temp;
	}

	this->arr[this->cur] = data;
	this->cur++;
}

template <typename T> void Vector<T>::push(T data, int index) {
	if (index == this->cap)
		push(data);
	else
		this->arr[index] = data;
}

template <typename T> T Vector<T>::get(int index) {
	if (index < this->cur)
		return this->arr[index];
}

template <typename T> void Vector<T>::print() {
	for (int i = 0; i < this->cur; i++) {
		std::cout << this->arr[i] << " ";
	}
	std::cout << std::endl;
}