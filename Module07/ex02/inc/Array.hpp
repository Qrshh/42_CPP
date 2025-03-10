#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array() : _array(new T[0]), _size(0){}
		Array(unsigned int size) : _array(new T[size]), _size(size) {}
		Array(const Array &other) : _size(other._size){
			_array = new T[_size];
			for(unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}

		Array &operator=(const Array &other){
			if(this != &other)
			{
				delete[] _array;
				_size = other._size;
				_array = new T[_size];
				for(unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return *this;
		}

		~Array(){
			if(_array)
				delete[] _array;
		}

		T &operator[](unsigned int index){
			if(index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _array[index];
		}

		unsigned int getSize() const {return _size;}
};



#endif
