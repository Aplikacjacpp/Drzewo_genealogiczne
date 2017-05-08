#include "sl_personalys.h"
C_sl_personalys::C_sl_personalys() {}
C_sl_personalys::C_sl_personalys(const C_sl_personalys & sl_personalys) {}
C_sl_personalys& C_sl_personalys::operator=(const C_sl_personalys& sl_personalys) {
	if (this == &sl_personalys) return *this;
	if (*this == sl_personalys) return *this;

	return *this;
}
bool C_sl_personalys::operator==(const C_sl_personalys& sl_personalys) {
	if (true) return true;
	return false;
}
bool C_sl_personalys::operator!=(const C_sl_personalys& sl_personalys) {
	if (true) return true;
	return false;
}
C_sl_personalys::~C_sl_personalys() {}