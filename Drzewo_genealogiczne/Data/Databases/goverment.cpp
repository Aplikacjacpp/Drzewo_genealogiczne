#include "goverment.h"
C_goverment::C_goverment() {}
C_goverment::C_goverment(const C_goverment & goverment) {}
C_goverment& C_goverment::operator=(const C_goverment& goverment) {
	if (this == &goverment) return *this;
	if (*this == goverment) return *this;

	return *this;
}
bool C_goverment::operator==(const C_goverment& goverment) {
	if (true) return true;
	return false;
}
bool C_goverment::operator!=(const C_goverment& goverment) {
	if (true) return true;
	return false;
}
C_goverment::~C_goverment() {}