/***************************************************************************************************************
*"goverment_personaly.h"
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
#ifndef GOVERMENT_PERSONALY_H
#define GOVERMENT_PERSONALY_H
#include "goverment.h"
class C_goverment_personaly :
	public C_goverment
{
public:
	C_goverment_personaly();
	C_goverment_personaly(const C_goverment_personaly & goverment_personaly);
	C_goverment_personaly& operator=(const C_goverment_personaly& goverment_personaly);
	bool operator==(const C_goverment_personaly& goverment_personaly);
	bool operator!=(const C_goverment_personaly& goverment_personaly);
	virtual ~C_goverment_personaly();
	/*
	virtual bool m_wchat_is() = 0;
	virtual void m_get_contens(N_striing &contens) = 0;
	virtual N_striing m_set_contens() = 0;

private:
	virtual N_striing m_is_there_contens(N_striing &Word) = 0;
	N_striing s_data_text; 
	*/
};
#endif // !GOVERMENT_PERSONALY_H



