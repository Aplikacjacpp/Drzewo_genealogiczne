#include "aplication.h"
C_aplication::C_aplication() {}
C_aplication::C_aplication(const C_aplication & aplication) {}
C_aplication& C_aplication::operator=(const C_aplication& aplication) {
	if (this == &aplication) return *this;
	if (*this == aplication) return *this;

	return *this;
}
bool C_aplication::operator==(const C_aplication& aplication) {
	if (true) return true;
	return false;
}
bool C_aplication::operator!=(const C_aplication& aplication) {
	if (true) return true;
	return false;
}
C_aplication::~C_aplication() {}