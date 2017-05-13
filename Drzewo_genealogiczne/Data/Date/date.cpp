#include "date.h"
C_date::C_date() {}
C_date::C_date(char value) { c_value = value; } //dodac znaki oznaczajace typ danych okreslajacych date
C_date::C_date(const C_date &d) { if (this != &d) *this = d; }
C_date C_date::operator=(const C_date &d) {
	if (this == &d) return *this;
	if (*this == d) return *this;
	c_value = d.c_value;
	return *this;
}
bool C_date::operator==(const C_date &d) {
	if (c_value == d.c_value) return true;
	return false;
}
bool C_date::operator!=(const C_date &d) {
	if (c_value != d.c_value) return true;
	return false;
}
C_date::~C_date() {}
C_day C_date::m_set_day() { C_day day(m_day_set()); return day; }
C_month C_date::m_set_month() { C_month month(m_month_set()); return month; }
C_year C_date::m_set_year() { C_year year(m_year_set()); return year; }
N_striing  C_date::m_set_DD_MM_YYYY() { return m_day_set() +c_value+ m_month_set() +c_value+ m_year_set(); }
N_striing  C_date::m_set_MM_DD_YYYY() { return m_month_set() +c_value+ m_day_set()+c_value+ m_year_set(); }
N_striing  C_date::m_set_YYYY_MM_DD() { return m_year_set() +c_value+ m_month_set() +c_value+ m_day_set(); }
N_striing  C_date::m_set_YYYY_DD_MM() { return m_year_set() +c_value+ m_day_set() +c_value+ m_month_set(); }
void C_date::m_get_DD_MM_YYYY(C_day& day, C_month& month, C_year & year) {
	m_get_day(day.m_day_set()); m_get_month(month.m_month_set()); m_get_year(year.m_year_set());
}
void C_date::m_shift_day(C_day day)
{
	m_get_day(day.m_day_set());
}
void C_date::m_shift_day(int day) {
	N_striing data;
	data.m_itoa(day);
	m_get_day(data);
}
void C_date::m_shift_day(N_striing day) {
	m_get_day(day);
}
void C_date::m_shift_month(C_month month) {
	m_get_month(month.m_month_set());
}
void C_date::m_shift_month(int month) {
	N_striing data;
	data.m_itoa(month);
	m_get_month(data);
}
void C_date::m_shift_month(N_striing month) {
	m_get_month(month);
}
void C_date::m_shift_year(C_year year) {
	m_get_year(year.m_year_set());
}
void C_date::m_shift_year(int year) {
	N_striing data;
	data.m_itoa(year);
	m_get_year(data);
}
void C_date::m_shift_year(N_striing year) {
	m_get_year(year);
}
void C_date::m_clear() {
	N_striing data = "";
	m_get_day(data);
	m_get_month(data);
	m_get_year(data);
}
N_striing C_date::m_analitic_date(N_striing& day) {
	int X;
	int Return=0;
	for (X = 0; X < day.m_size(); X++)
	{
		Return += (int)day[X];
	}
	switch (Return)
	{
	case 116:
	{
		break;
	}
	case 125:
	{
		break;
	}
	case 137:
	{
		break;
	}
	default:
			break;
	}
	return day;
}