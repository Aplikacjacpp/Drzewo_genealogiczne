#include "year.h"
C_year::C_year() :C_data("&0") { s_data_year = 0; }
C_year::C_year(const C_year &year):C_data(year) {
	if (this != &year) *this = year;
}
C_year& C_year::operator=(const C_year &year) {
	if (*this == year) return *this;
	s_data_year = year.s_data_year;
	return *this;
}
bool C_year::operator==(const C_year &year) {
	if (s_data_year == year.s_data_year) return true;
	return false;
}
bool C_year::operator!=(const C_year &year) {
	if (s_data_year != year.s_data_year) return true;
	return false;
}
C_year::~C_year() {};






