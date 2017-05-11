#include "sl_personalys.h"
C_sl_personalys::C_sl_personalys() {}
C_sl_personalys::C_sl_personalys(const C_sl_personalys & sl_personalys) {}
C_sl_personalys& C_sl_personalys::operator=(const C_sl_personalys& sl_personalys) {
	if (this == &sl_personalys) return *this;
	if (*this == sl_personalys) return *this;
	V_goverment_personaly = sl_personalys.V_goverment_personaly;
	return *this;
}
bool C_sl_personalys::operator==(const C_sl_personalys& sl_personalys) {
	if (V_goverment_personaly == sl_personalys.V_goverment_personaly) return true;
	return false;
}
bool C_sl_personalys::operator!=(const C_sl_personalys& sl_personalys) {
	if (V_goverment_personaly != sl_personalys.V_goverment_personaly) return true;
	return false;
}
C_sl_personalys::~C_sl_personalys() {}