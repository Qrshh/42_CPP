#include "../inc/Serializer.hpp"

int main(void){
	Data test;
	test.value = 25;

	Data* ptr = &test;
	uintptr_t serializedValue = Serializer::serialize(ptr);
	Data* deserializedValue = Serializer::deserialize(serializedValue);

	if(ptr == deserializedValue)
	{
		std::cout << "SUCCESS !" << std::endl;
		std::cout << "Value : " << deserializedValue->value << std::endl;
		std::cout << "Previous value : " << test.value << std::endl;
	}
	else
		std::cout << "FAILURE !" << std::endl;

	return 0;
}