#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer& other) {
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

Serializer::~Serializer() {

}

unsigned long Serializer::serialize(Data* ptr) {
	return reinterpret_cast<unsigned long>(ptr);
}

Data* Serializer::deserialize(unsigned long raw)  {
	return reinterpret_cast<Data*>(raw);
}