/***************************************************************************************************************
*"goverment_date.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klascie C_goverment"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
*1.01    09.05.2017  Pure Virtual Methods Added										  Mateusz Marchelewicz
****************************************************************************************************************/
#ifndef GOVERMENT_DATE_H
#define GOVERMENT_DATE_H
#include "goverment.h"
class C_goverment_date :
	public C_goverment
{
public:
	C_goverment_date();
	C_goverment_date(const C_goverment_date & goverment_date);
	C_goverment_date& operator=(const C_goverment_date& goverment_date);
	bool operator==(const C_goverment_date& goverment_date);
	bool operator!=(const C_goverment_date& goverment_date);
	virtual ~C_goverment_date();
	/*
	virtual bool m_wchat_is() = 0;
	virtual void m_get_contens(N_striing &contens) = 0;
	virtual N_striing m_set_contens() = 0;

	private:
	virtual N_striing m_is_there_contens(N_striing &Word) = 0;
	N_striing s_data_text;
	*/
};
#endif // !GOVERMENT_DATE_H



