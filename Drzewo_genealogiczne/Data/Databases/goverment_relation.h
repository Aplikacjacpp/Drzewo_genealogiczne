/***************************************************************************************************************
*"goverment_relation.h"
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
#ifndef GOVERMENT_RELATION_H
#define GOVERMENT_RELATION_H
#include "goverment.h"
class C_goverment_relation :
	public C_goverment
{
public:
	C_goverment_relation();
	C_goverment_relation(const C_goverment_relation & goverment_relation);
	C_goverment_relation& operator=(const C_goverment_relation& goverment_relation);
	bool operator==(const C_goverment_relation& goverment_relation);
	bool operator!=(const C_goverment_relation& goverment_relation);
	virtual ~C_goverment_relation();
	/*
	virtual bool m_wchat_is() = 0;
	virtual void m_get_contens(N_striing &contens) = 0;
	virtual N_striing m_set_contens() = 0;

	private:
	virtual N_striing m_is_there_contens(N_striing &Word) = 0;
	N_striing s_data_text;
	*/
};
#endif // !GOVERMENT_RELATION_H


//doxygen 
