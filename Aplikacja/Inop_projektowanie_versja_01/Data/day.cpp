#include "day.h"
C_day::C_day() :C_data("^0") { s_data_day = 0; }
C_day::C_day(const C_day &day):C_data(day) {
	if (this != &day) *this = day;
}
C_day& C_day::operator=(const C_day &day) {
	if (*this == day) return *this;
	s_data_day = day.s_data_day;
	return *this;
}
bool C_day::operator==(const C_day &day) {
	if (s_data_day == day.s_data_day) return true;
	return false;
}
bool C_day::operator!=(const C_day &day) {
	if (s_data_day != day.s_data_day) return true;
	return false;
}
C_day::~C_day() {};




