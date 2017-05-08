/***************************************************************************************************************
*"Date.h"
*
*
*
*
*
*CONTENTS:
* "Klasa zawierajaca klasy: C_day, C_month, C_year"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     30.04.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.1	 02.05.2015	 Adding a virtual destructor									  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_DATE_H
#define C_DATE_H
#include "day.h"
#include "month.h"
#include "year.h"
class C_date : virtual public C_day, C_month, C_year
{
public:
	C_date();
	C_date(char value);
	C_date(const C_date &d);
	C_date operator=(const C_date &d);
	bool operator==(const C_date &d);
	bool operator!=(const C_date &d);
	/*C_day m_set_day();
	C_month m_set_month();
	C_year m_set_year();
	N_striing  m_set_DD_MM_YYYY();
	N_striing  m_set_MM_DD_YYYY();
	N_striing  m_set_YYYY_MM_DD();
	N_striing  m_set_YYYY_MM_DD();
	void m_get_DD_MM_YYYY(const C_day& day, const C_month& month, const C_year & year);
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
	virtual ~C_date();
private:
	char c_type_date;
	N_striing m_analitic_date( N_striing& day);
};
#endif //!C_DATE
