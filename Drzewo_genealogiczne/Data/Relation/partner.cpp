#include "partner.h"
C_partner::C_partner() {}
C_partner::C_partner(const C_partner & partner) {}
C_partner& C_partner::operator=(const C_partner& partner) {
	if (this == &partner) return *this;
	if (*this == partner) return *this;

	return *this;
}
bool C_partner::operator==(const C_partner& partner) {
	if (true) return true;
	return false;
}
bool C_partner::operator!=(const C_partner& partner) {
	if (true) return true;
	return false;
}
C_partner::~C_partner() {}
