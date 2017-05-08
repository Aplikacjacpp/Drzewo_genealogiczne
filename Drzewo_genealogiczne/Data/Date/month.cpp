#include "month.h"
C_month::C_month() :C_data("M0") { i_data_month = 0; }
C_month::C_month(N_striing &month) : C_data("M0") { i_data_month = m_is_there_contens(month).m_atoi(0, month.m_size()); }
C_month::C_month(int month) : C_data("M0") { i_data_month = month; }
C_month::C_month(const C_month &month):C_data(month) {
	if (this != &month) *this = month;
}
C_month& C_month::operator=(const C_month &month) {
	if (*this == month) return *this;
	i_data_month = month.i_data_month;
	return *this;
}
bool C_month::operator==(const C_month &month) {
	if (i_data_month == month.i_data_month) return true;
	return false;
}
bool C_month::operator!=(const C_month &month) {
	if (i_data_month != month.i_data_month) return true;
	return false;
}
C_month::~C_month() {};
bool C_month::m_wchat_is() { if (this->i_data_month != NULL) return true; return false; }
void C_month::m_get_contens(N_striing &contens) { this->i_data_month = m_is_there_contens(contens).m_atoi(0, contens.m_size()); }
N_striing C_month::m_set_contens() { N_striing data; data.m_itoa(this->i_data_month); return data; }
N_striing C_month::m_is_there_contens(N_striing &Word) {
	int y = 0;
	do {
		if (Word[y] >= '0' && Word[y] <= '9') y++;
		else
			return "";
	} while (y != Word.m_size()&&Word.m_size()<=2);
	return Word;
}


