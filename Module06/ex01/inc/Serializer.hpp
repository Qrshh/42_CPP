#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.h"
# include <iostream>
#include <cstddef>
#include <stdint.h>

class Serializer {
	private:
		Serializer();
	public:
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif
