#include "last_name.h"

C_last_name::C_last_name():C_data("@0"){
	s_data_last_name = "";
}
C_last_name::C_last_name(N_striing &last):C_data("@0") {
	s_data_last_name = last;
}
C_last_name::C_last_name(const C_last_name &last_name):C_data(last_name) {
	if (this != &last_name) *this = last_name;
}
C_last_name& C_last_name::operator=(const C_last_name &last_name) {
	if (*this == last_name) return *this;
	s_data_last_name = last_name.s_data_last_name;
	return *this;
}
bool C_last_name::operator==(const C_last_name &last_name) {
	if (s_data_last_name == last_name.s_data_last_name) return true;
	return false;
}
bool C_last_name::operator!=(const C_last_name &last_name) {
	if (s_data_last_name != last_name.s_data_last_name) return true;
	return false;
}
C_last_name::~C_last_name() {};


