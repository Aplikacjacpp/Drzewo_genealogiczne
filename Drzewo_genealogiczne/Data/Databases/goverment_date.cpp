#include "goverment_date.h"
C_goverment_date::C_goverment_date() {}
C_goverment_date::C_goverment_date(const C_goverment_date & goverment_date) {}
C_goverment_date& C_goverment_date::operator=(const C_goverment_date& goverment_date) {
	if (this == &goverment_date) return *this;
	if (*this == goverment_date) return *this;

	return *this;
}
bool C_goverment_date::operator==(const C_goverment_date& goverment_date) {
	if (true) return true;
	return false;
}
bool C_goverment_date::operator!=(const C_goverment_date& goverment_date) {
	if (true) return true;
	return false;
}
C_goverment_date::~C_goverment_date() {}