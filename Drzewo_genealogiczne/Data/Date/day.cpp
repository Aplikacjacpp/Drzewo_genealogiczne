#include "day.h"
C_day::C_day() :C_data("D0") { i_data_day = 0; }
C_day::C_day(N_striing &day):C_data("D0") { i_data_day = m_is_there_contens(day).m_atoi(0, day.m_size()); }
C_day::C_day(int day):C_data("D0") { i_data_day = day; }
C_day::C_day(const C_day &day):C_data(day) {
	if (this != &day) *this = day;
}
C_day& C_day::operator=(const C_day &day) {
	if (*this == day) return *this;
	i_data_day = day.i_data_day;
	return *this;
}
bool C_day::operator==(const C_day &day) {
	if (i_data_day == day.i_data_day) return true;
	return false;
}
bool C_day::operator!=(const C_day &day) {
	if (i_data_day != day.i_data_day) return true;
	return false;
}
C_day::~C_day() {};
bool C_day::m_wchat_is() { if (this->i_data_day != NULL) return true; return false; }
void C_day::m_get_contens(N_striing &contens) { this->i_data_day = m_is_there_contens(contens).m_atoi(0, contens.m_size()); }
N_striing C_day::m_set_contens() { N_striing data; data.m_itoa(this->i_data_day); return data; }
N_striing C_day::m_is_there_contens(N_striing &Word) { 
	int y = 0;
	do {
		if (Word[y] >= '0' && Word[y] <= '9') y++;
		else
			return "";
	} while (y != Word.m_size() && Word.m_size() <= 2);
	return Word;
} //do rozwiniecia


