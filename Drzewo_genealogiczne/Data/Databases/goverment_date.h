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
*1.1     09.05.2017  Pure Virtual Methods Added										  Mateusz Marchelewicz
*1.2     12.05.2017  redbuild m_is_there_contens							   		  Lukasz Witek vel Witkowski
*1.3	 12.05.2017  Adding new mothods												  Lukasz Witek vel Witkowsk
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
	virtual bool m_wchat_is();
	virtual void m_get_contens(N_striing &contens);
	virtual N_striing m_set_contens();
	int m_set_value_id();
private:
	virtual N_striing m_is_there_contens(N_striing &Word);
	N_striing s_goverment_data;
	int m_id_value();
	int i_value_id;
};
#endif // !GOVERMENT_DATE_H



