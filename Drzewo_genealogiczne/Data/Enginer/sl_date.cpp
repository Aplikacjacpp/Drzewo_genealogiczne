#include "sl_date.h"
C_sl_date::C_sl_date() {}
C_sl_date::C_sl_date(const C_sl_date & sl_date) {}
C_sl_date& C_sl_date::operator=(const C_sl_date& sl_date) {
	if (this == &sl_date) return *this;
	if (*this == sl_date) return *this;

	return *this;
}
bool C_sl_date::operator==(const C_sl_date& sl_date) {
	if (true) return true;
	return false;
}
bool C_sl_date::operator!=(const C_sl_date& sl_date) {
	if (true) return true;
	return false;
}
C_sl_date::~C_sl_date() {}