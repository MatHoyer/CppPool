#pragma once

#include <exception>
#include <iostream>
#include <stdexcept>

template < typename T >
class Array {
	public:
		Array() : _arr(new T), _size(0) {}
		Array(unsigned int size) : _arr(new T[size]), _size(size) {}
		Array(const Array& other) {
			this->_size = other._size;
			this->_arr = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_arr[i] = other._arr[i];
			}
		}
		Array& operator=(const Array& other) {
			if (this == &other) 
				return *this;
			delete [] this->_arr;
			this->_size = other._size;
			this->_arr = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++) {
				this->_arr[i] = other._arr[i];
			}
			return *this;
		}
		~Array() { delete [] this->_arr; }

		T& operator[](unsigned int index) {
			if (index >= this->_size)
				throw std::out_of_range("Bad index");
			return this->_arr[index];
		}

		unsigned int size() const { return this->_size; }

	private:
		T* _arr;
		unsigned int _size;
};

// template < typename T >
// std::ostream& operator<<( std::ostream& os, const Array<T>& arr ) {
//     for (unsigned int i = 0; i < arr.getSize(); i++)
//         os << arr[i] << " ";
//     return os;
// }
