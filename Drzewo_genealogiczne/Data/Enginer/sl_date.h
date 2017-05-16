/***************************************************************************************************************
*"sl_date.h"
*
*
*
*
*
*CONTENTS:
* "Klasa dziecko po klasie C_save_load"
*HISTORY:
*version   Date Changes																	 	Author/Programmer
*1.0     06.05.2017  Orginal design													  Lukasz Witek vel Witkowski
****************************************************************************************************************/
#ifndef C_SL_DATE_H
#define C_SL_DATE_H
#include "save_load.h"
#include "../narzedzia/Vektor.h"
#include "../Databases/goverment_date.h"
class C_sl_date :public C_save_load
{
public:
	C_sl_date();
	C_sl_date(const C_sl_date & sl_date);
	C_sl_date& operator=(const C_sl_date& sl_date);
	bool operator==(const C_sl_date& sl_date);
	bool operator!=(const C_sl_date& sl_date);
	virtual ~C_sl_date();
	void m_load_file();
public:
	N_vektor<C_goverment_date> V_goverment_date;
};
#endif // !C_SL_DATE_H



