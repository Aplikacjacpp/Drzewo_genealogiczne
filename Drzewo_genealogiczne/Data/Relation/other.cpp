#include "other.h"
C_other::C_other() {}
C_other::C_other(const C_other & other) {}
C_other& C_other::operator=(const C_other& other) {
	if (this == &other) return *this;
	if (*this == other) return *this;

	return *this;
}
bool C_other::operator==(const C_other& other) {
	if (true) return true;
	return false;
}
bool C_other::operator!=(const C_other& other) {
	if (true) return true;
	return false;
}
C_other::~C_other() {}
