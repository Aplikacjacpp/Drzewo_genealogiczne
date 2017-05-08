#include "month.h"
C_month::C_month() :C_data("~0") { s_data_month = 0; }
C_month::C_month(const C_month &month):C_data(month) {
	if (this != &month) *this = month;
}
C_month& C_month::operator=(const C_month &month) {
	if (*this == month) return *this;
	s_data_month = month.s_data_month;
	return *this;
}
bool C_month::operator==(const C_month &month) {
	if (s_data_month == month.s_data_month) return true;
	return false;
}
bool C_month::operator!=(const C_month &month) {
	if (s_data_month != month.s_data_month) return true;
	return false;
}
C_month::~C_month() {};





