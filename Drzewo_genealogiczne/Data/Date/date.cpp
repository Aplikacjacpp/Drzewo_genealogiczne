#include "date.h"
C_date::C_date() {}
C_date::C_date(char value) { c_type_date = value; } //dodac znaki oznaczajace typ danych okreslajacych date
C_date::C_date(const C_date &d) { if (this != &d) *this = d; }
C_date C_date::operator=(const C_date &d) {
	if (this == &d) return *this;
	if (*this == d) return *this;
	c_type_date = d.c_type_date;
	return *this;
}
bool C_date::operator==(const C_date &d) {
	if (c_type_date == d.c_type_date) return true;
	return false;
}
bool C_date::operator!=(const C_date &d) {
	if (c_type_date != d.c_type_date) return true;
	return false;
}
C_date::~C_date() {}
C_day C_date::m_set_day() { C_day day(m_day_set()); return day; }
C_month C_date::m_set_month() { C_month month(m_month_set()); return month; }
C_year C_date::m_set_year() { C_year year(m_year_set()); return year; }
N_striing  C_date::m_set_DD_MM_YYYY() { return m_day_set() + m_month_set() + m_year_set(); }
N_striing  C_date::m_set_MM_DD_YYYY() { return m_month_set() + m_day_set()+ m_year_set(); }
N_striing  C_date::m_set_YYYY_MM_DD() { return m_year_set() + m_month_set() + m_day_set(); }
N_striing  C_date::m_set_YYYY_DD_MM() { return m_year_set() + m_day_set() + m_month_set(); }
/*
void m_get_DD_MM_YYYY(const C_day& day, const C_month& month, const C_year & year);
void m_get_DD_MM_YYYY(int day, int month, int year);
void m_get_DD_MM_YYYY(N_striing day, N_striing month, N_striing year);
void m_get_MM_DD_YYYY(const C_month& month, const C_day& day, const C_year& year);
void m_get_MM_DD_YYYY(int month, int day, int year);
void m_get_MM_DD_YYYY(N_striing month, N_striing day, N_striing year);
void m_get_YYYY_MM_DD(const C_year& year, const C_month& month, const C_day& day);
void m_get_YYYY_MM_DDY(int year, int month, int day);
void m_get_YYYY_MM_DD(N_striing myear, N_striing month, N_striing day);
void m_get_YYYY_DD_MM(const C_year& year, const C_day& day, const C_month& month);
void m_get_YYYY_DD_MM(int year, int day, int month);
void m_get_YYYY_DD_MM(N_striing year, N_striing day, N_striing month);
void m_shift_day(const C_day &day);
void m_shift_day(int &day);
void m_shift_day(N_striing &day);
void m_shift_month(const C_month& month);
void m_shift_month(int month);
void m_shift_month(N_striing month);
void m_shift_year(const C_year& year);
void m_shift_year(int year);
void m_shift_year(N_striing year);
void m_clear();*/
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