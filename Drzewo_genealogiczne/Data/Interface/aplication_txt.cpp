#include "aplication_txt.h"
C_aplication_txt::C_aplication_txt() {}
C_aplication_txt::C_aplication_txt(const C_aplication_txt & aplication_txt) {}
C_aplication_txt& C_aplication_txt::operator=(const C_aplication_txt& aplication_txt) {
	if (this == &aplication_txt) return *this;
	if (*this == aplication_txt) return *this;

	return *this;
}
bool C_aplication_txt::operator==(const C_aplication_txt& aplication_txt) {
	if (true) return true;
	return false;
}
bool C_aplication_txt::operator!=(const C_aplication_txt& aplication_txt) {
	if (true) return true;
	return false;
}
C_aplication_txt::~C_aplication_txt() {}
