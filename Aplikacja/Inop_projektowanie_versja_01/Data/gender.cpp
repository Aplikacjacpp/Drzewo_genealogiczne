#include "gender.h"
C_gender::C_gender() :C_data("~0") { s_data_gender = ""; }
C_gender::C_gender(const C_gender &gender):C_data(gender) {
	if (this != &gender) *this = gender;
}
C_gender& C_gender::operator=(const C_gender &gender) {
	if (*this == gender) return *this;
	s_data_gender = gender.s_data_gender;
	return *this;
}
bool C_gender::operator==(const C_gender &gender) {
	if (s_data_gender == gender.s_data_gender) return true;
	return false;
}
bool C_gender::operator!=(const C_gender &gender) {
	if (s_data_gender != gender.s_data_gender) return true;
	return false;
}
C_gender::~C_gender() {};






